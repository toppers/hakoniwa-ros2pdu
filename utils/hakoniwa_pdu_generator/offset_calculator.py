import os
import subprocess
from pathlib import Path
import jinja2

class OffsetCalculator:
    def __init__(self, template_dir, base_dir):
        self.template_env = jinja2.Environment(loader=jinja2.FileSystemLoader(template_dir))
        self.template_env.undefined = jinja2.StrictUndefined
        self.base_dir = Path(base_dir)

    def _render_template(self, template_name, context):
        template = self.template_env.get_template(template_name)
        return template.render(context)

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
        include_path = self.base_dir / 'pdu' / 'types'
        compile_command = [
            'gcc', '-o', str(executable_path), str(c_file_path),
            f"-I{include_path}"
        ]
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
            c_file_path.unlink()
            executable_path.unlink()

        # オフセットファイルを出力
        output_path = Path(output_dir) / pkg_name
        output_path.mkdir(parents=True, exist_ok=True)
        offset_file_path = output_path / f"{msg_name}.offset"
        with open(offset_file_path, 'w') as f:
            f.write(offset_data)
        print(f"Generated offset file: {offset_file_path}")