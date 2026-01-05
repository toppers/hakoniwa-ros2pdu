import argparse
import sys
import json
import shutil
from pathlib import Path

# 同じパッケージ内のモジュールをインポート
from .ros_message_parser import get_ros_message_definition
from .dependency_resolver import DependencyResolver
from .code_generator import CodeGenerator
from .offset_calculator import OffsetCalculator
from .offset_parser import parse_offset_file

def get_search_paths(search_path_file, project_root, ros_root=None):
    """
    search_path.txtを読み込み、実行環境に合わせてパスを調整する
    """
    with open(search_path_file, 'r') as f:
        paths = [line.strip() for line in f if line.strip()]
    
    adjusted_paths = []
    for p in paths:
        if p.startswith('/root/workspace/hakoniwa-ros2pdu'):
            adjusted_paths.append(str(project_root / Path(p).relative_to('/root/workspace/hakoniwa-ros2pdu')))
        elif ros_root and p.startswith('/opt/ros/foxy'):
            adjusted_paths.append(str(Path(ros_root) / Path(p).relative_to('/opt/ros/foxy')))
        else:
            adjusted_paths.append(p)
            
    return adjusted_paths

def run_generation(ros_msgs_file, search_path_file, output_dir, template_dir, ros_root, offset_include_path_file):
    output_root_dir = Path(output_dir)
    template_dir = Path(template_dir)
    project_root = Path.cwd()
    
    print("--- Hakoniwa PDU Generator ---")
    print(f"ROS Messages File: {ros_msgs_file}")
    print(f"Output Directory: {output_root_dir.resolve()}")
    if ros_root:
        print(f"Local ROS Root: {ros_root}")
    
    try:
        with open(ros_msgs_file, 'r') as f:
            initial_messages = [line.strip() for line in f if line.strip()]
        
        search_paths = get_search_paths(search_path_file, project_root, ros_root)
        print("\nUsing Search Paths:")
        for p in search_paths:
            print(f"  - {p}")

        # varray_size_def is no longer needed
        varray_size_def = {}

        print("\n1. Resolving dependencies...")
        resolver = DependencyResolver(search_paths)
        message_cache = resolver.get_all_dependencies(initial_messages)
        
        unresolved_msgs = {msg for msg in initial_messages if msg.split('[',1)[0] not in resolver.message_cache}
        if unresolved_msgs:
            print("\nWarning: The following messages could not be fully resolved:", file=sys.stderr)
            for msg in sorted(list(unresolved_msgs)):
                print(f"  - {msg}", file=sys.stderr)
            
            common_ros_pkgs = ['std_msgs', 'geometry_msgs', 'sensor_msgs', 'nav_msgs']
            if any(pkg in msg for msg in unresolved_msgs for pkg in common_ros_pkgs):
                print("\nHint: If you are running outside Docker, try using the --ros-root option.", file=sys.stderr)
                print("      Example: --ros-root /path/to/your/ros2_foxy/install", file=sys.stderr)
        
        print(f"-> Found {len(message_cache)} total messages to process.")

        print("\n2. Generating code for all languages...")
        code_gen = CodeGenerator(template_dir)
        code_gen.generate_all(message_cache, varray_size_def, output_root_dir)
        
        print("\n3. Calculating offsets...")
        additional_offset_includes = []
        if offset_include_path_file:
            print(f"\nUsing Additional Offset Include Paths from: {offset_include_path_file}")
            additional_offset_includes = get_search_paths(offset_include_path_file, project_root, ros_root)
            for p in additional_offset_includes:
                print(f"  - {p}")

        offset_calculator = OffsetCalculator(template_dir, project_root, additional_include_paths=additional_offset_includes)
        offset_output_dir = output_root_dir / 'offset'
        
        for package_msg in message_cache.keys():
            context = code_gen._prepare_context(package_msg, message_cache, varray_size_def)
            offset_calculator.calculate_offsets(context, offset_output_dir)

        print("\n4. Creating __init__.py for Python packages...")
        python_dir = output_root_dir / 'python'
        for package_dir in python_dir.iterdir():
            if package_dir.is_dir():
                (package_dir / '__init__.py').touch()

        print("\n5. Generating Python converters from offset files...")
        for package_msg, msg_def in message_cache.items():
            pkg_name = msg_def['package']
            msg_name = msg_def['message']
            offset_file = offset_output_dir / pkg_name / f"{msg_name}.offset"
            
            offset_data = parse_offset_file(offset_file)
            if offset_data:
                code_gen.generate_python_converter(msg_def, offset_data, output_root_dir)

        print("\n6. Generating JavaScript converters from offset files...")
        for package_msg, msg_def in message_cache.items():
            pkg_name = msg_def['package']
            msg_name = msg_def['message']
            offset_file = offset_output_dir / pkg_name / f"{msg_name}.offset"
            
            offset_data = parse_offset_file(offset_file)
            if offset_data:
                code_gen.generate_javascript_converter(msg_def, offset_data, output_root_dir)

        print("\n--- Generation Complete! ---")

    except FileNotFoundError as e:
        print(f"\nError: {e}", file=sys.stderr)
        sys.exit(1)
    except Exception as e:
        print(f"\nAn unexpected error occurred: {e}", file=sys.stderr)
        sys.exit(1)

def main():
    parser = argparse.ArgumentParser(description="Hakoniwa PDU Generator")
    parser.add_argument('ros_msgs_file', type=str, help="Path to the file listing ROS messages to process (e.g., config/ros_msgs.txt)")
    parser.add_argument('--search-path-file', type=str, default='config/search_path.txt', help="Path to the search path file")
    # varray-size-file is obsolete
    # parser.add_argument('--varray-size-file', type=str, default='config/varray_size.json', help="Path to the varray size definition file")
    parser.add_argument('--output-dir', type=str, default='pdu', help="Root directory for the generated PDU files")
    parser.add_argument('--template-dir', type=str, default='utils/hakoniwa_pdu_generator/templates', help="Directory of the template files")
    parser.add_argument('--ros-root', type=str, help="(Optional) Root path of your local ROS 2 installation for testing.")
    parser.add_argument('--offset-include-path-file', type=str, help="Path to a file listing additional include paths for offset calculation.")
    
    args = parser.parse_args()
    run_generation(args.ros_msgs_file, args.search_path_file, args.output_dir, args.template_dir, args.ros_root, args.offset_include_path_file)
if __name__ == '__main__':
    main()
