from . import ros_message_parser

# ROSのプリミティブ型
ROS_PRIMITIVE_TYPES = [
    'bool', 'byte', 'char', 'float32', 'float64', 'int8', 'uint8',
    'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64', 'string'
]

class DependencyResolver:
    def __init__(self, search_paths):
        self.search_paths = search_paths
        self.message_cache = {} # メッセージ定義のキャッシュ

    def resolve_dependencies(self, package_msg):
        """
        指定されたメッセージの依存関係を再帰的に解決する
        """
        # 配列型などが含まれている場合、基本型を抽出
        base_package_msg = package_msg.split('[', 1)[0].strip()

        if base_package_msg in self.message_cache:
            return # 既に解決済み

        # プリミティブ型は解決不要
        if base_package_msg in ROS_PRIMITIVE_TYPES:
            return

        # メッセージ定義を取得
        msg_def = ros_message_parser.get_ros_message_definition(self.search_paths, base_package_msg)
        if not msg_def:
            print(f"Warning: Could not resolve dependencies for {package_msg}. Skipping.")
            return # 見つからなかった場合はスキップ

        self.message_cache[base_package_msg] = msg_def

        # 依存関係を再帰的に解決
        for field in msg_def.get('fields', []):
            field_type = field['type'].split('[', 1)[0].strip() # 配列から基本型を抽出
            
            if '/' not in field_type:
                if field_type not in ROS_PRIMITIVE_TYPES and field_type != 'string':
                    dependent_pkg_msg = f"{msg_def['package']}/{field_type}"
                    self.resolve_dependencies(dependent_pkg_msg)
            else:
                self.resolve_dependencies(field_type)

    def get_all_dependencies(self, initial_messages):
        """
        起点となるメッセージリストから全ての依存関係を解決し、キャッシュを返す
        """
        for msg in initial_messages:
            self.resolve_dependencies(msg)
        return self.message_cache
