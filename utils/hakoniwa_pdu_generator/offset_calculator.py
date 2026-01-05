import os
import subprocess
from pathlib import Path
import jinja2

class OffsetCalculator:
    def __init__(self, template_dir, base_dir, additional_include_paths=None):
        self.template_env = jinja2.Environment(loader=jinja2.FileSystemLoader(template_dir))
        self.template_env.undefined = jinja2.StrictUndefined
        self.base_dir = Path(base_dir)
        self.additional_include_paths = additional_include_paths if additional_include_paths is not None else []

    def _render_template(self, template_name, context):
        template = self.template_env.get_template(template_name)
        return template.render(context)

    def _calculate_and_write_size(self, offset_file_path, pkg_name, msg_name, output_dir):
        with open(offset_file_path, 'r') as f:
            lines = f.readlines()

        if not lines:
            print(f"Warning: Offset file is empty, cannot calculate size for {pkg_name}/{msg_name}")
            return

        last_line = lines[-1].strip()
        parts = last_line.split(':')
        
        if len(parts) < 2:
            print(f"Warning: Unexpected format in offset file: {offset_file_path}")
            print(f"Line: {last_line}")
            return
            
        try:
            # The last entry should be the size, and the second to last should be the offset.
            size = int(parts[-1])
            offset = int(parts[-2])
        except (ValueError, IndexError):
            print(f"Warning: Could not parse offset/size from line: {last_line}")
            return

        total_size = offset + size
        # 8-byte alignment roundup
        aligned_size = (total_size + 7) & ~7

        # Output the size file
        base_output_dir = Path(output_dir).parent
        size_output_dir = base_output_dir / 'pdu_size' / pkg_name
        size_output_dir.mkdir(parents=True, exist_ok=True)
        size_file_path = size_output_dir / f"{msg_name}.txt"

        with open(size_file_path, 'w') as f:
            f.write(str(aligned_size))
        
        print(f"Generated size file: {size_file_path}")

    def calculate_offsets(self, context, output_dir):
        pkg_name = context['container']['pkg_name']
        msg_name = context['container']['msg_type_name']
        
        # オフセット計算用のCコードを生成
        c_code = self._render_template('pdu_ctypes_offset_c.tpl', context)
        
        # 一時ファイルを作成
        tmp_dir = self.base_dir / 'tmp_offset_files'
        tmp_dir.mkdir(exist_ok=True)
        c_file_path = tmp_dir / f"tmp_offset_{pkg_name}_{msg_name}.c"
        executable_path = tmp_dir / f"tmp_offset_{pkg_name}_{msg_name}"

        with open(c_file_path, 'w') as f:
            f.write(c_code)

        # Cコードをコンパイル
        include_paths = [self.base_dir / 'pdu' / 'types']
        include_paths.extend([Path(p) for p in self.additional_include_paths])
        
        compile_command = [
            'gcc', '-o', str(executable_path), str(c_file_path)
        ]
        for ipath in include_paths:
            print(f"Adding include path for compilation: {ipath}")
            compile_command.append(f"-I{ipath}")

        try:
            subprocess.run(compile_command, check=True, capture_output=True, text=True)
        except subprocess.CalledProcessError as e:
            print(f"Error compiling {c_file_path}:")
            print(e.stderr)
            return

        # 実行してオフセットを取得
        try:
            result = subprocess.run([str(executable_path)], check=True, capture_output=True, text=True)
            offset_data = result.stdout
        except subprocess.CalledProcessError as e:
            print(f"Error running {executable_path}:")
            print(e.stderr)
            return
        finally:
            # 一時ファイルをクリーンアップ
            if c_file_path.exists():
                c_file_path.unlink()
            if executable_path.exists():
                executable_path.unlink()

        # オフセットファイルを出力
        output_path = Path(output_dir) / pkg_name
        output_path.mkdir(parents=True, exist_ok=True)
        offset_file_path = output_path / f"{msg_name}.offset"
        with open(offset_file_path, 'w') as f:
            f.write(offset_data)
        print(f"Generated offset file: {offset_file_path}")
        self._calculate_and_write_size(offset_file_path, pkg_name, msg_name, output_dir)