PRIMITIVES = {
    "bool","int8","uint8","int16","uint16","int32","uint32","int64","uint64",
    "float32","float64","string","char","byte","time","duration"
}
class MsgGenerator:
    def __init__(self, context):
        self.context = context

    def generate_request_msg(self, fields):
        return self._generate_fields_text(fields)

    def generate_response_msg(self, fields):
        return self._generate_fields_text(fields)

    def generate_request_packet_msg(self):
        lines = [
            f"{self._qualify('ServiceRequestHeader', self.context.header_package_name)} header",
            f"{self._qualify(self.context.service_name + 'Request', self.context.msg_package_name)} body",
        ]
        return "\n".join(lines)

    def generate_response_packet_msg(self):
        lines = [
            f"{self._qualify('ServiceResponseHeader', self.context.header_package_name)} header",
            f"{self._qualify(self.context.service_name + 'Response', self.context.msg_package_name)} body",
        ]
        return "\n".join(lines)
# --- internal ----------------------------------------------
    def _qualify(self, typename: str, pkg_fallback: str) -> str:
        """未修飾 & 非プリミティブなら pkg/Type に昇格。既に pkg/Type ならそのまま。"""
        if "/" in typename:             # 既に完全修飾
            return typename
        if typename in PRIMITIVES:       # プリミティブ
            return typename
        if pkg_fallback == self.context.msg_package_name:
            return typename
        if pkg_fallback:                 # 非プリミティブでパッケージ未指定
            return f"{pkg_fallback}/{typename}"
        return typename                  # 念のため

    def _generate_fields_text(self, fields):
        lines = []
        for field in fields:
            base = field["type"]  # 例: "float32" or "geometry_msgs/Vector3" or "Pose"
            # 1) パッケージ決定（フィールドにpackageがあればそれ、なければ現在のmsgパッケージ）
            pkg = field.get("package") or self.context.msg_package_name
            # 2) 完全修飾へ
            typename = self._qualify(base, pkg)

            # 3) 配列修飾
            if field.get("is_array"):
                if field.get("array_size") is not None:
                    typename = f"{typename}[{field['array_size']}]"
                else:
                    typename = f"{typename}[]"

            lines.append(f"{typename} {field['name']}")
        return "\n".join(lines)
