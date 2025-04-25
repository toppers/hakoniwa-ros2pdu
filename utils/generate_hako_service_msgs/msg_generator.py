class MsgGenerator:
    def __init__(self, context):
        self.context = context

    def generate_request_msg(self, fields):
        return self._generate_fields_text(fields)

    def generate_response_msg(self, fields):
        return self._generate_fields_text(fields)

    def generate_request_packet_msg(self):
        lines = [
            "ServiceRequestHeader header",
            f"{self.context.service_name}Request body"
        ]
        return "\n".join(lines)

    def generate_response_packet_msg(self):
        lines = [
            "ServiceResponseHeader header",
            f"{self.context.service_name}Response body"
        ]
        return "\n".join(lines)

    def _generate_fields_text(self, fields):
        lines = []
        for field in fields:
            typename = field["type"]
            if field["package"] and field["package"] != self.context.msg_package_name:
                typename = f"{field['package']}/{typename}"
            if field["is_array"]:
                if field["array_size"] is not None:
                    typename = f"{typename}[{field['array_size']}]"
                else:
                    typename = f"{typename}[]"
            lines.append(f"{typename} {field['name']}")
        return "\n".join(lines)
