class SrvParser:
    def __init__(self, context):
        self.context = context

    def parse(self):
        fields_request = []
        fields_response = []
        current_fields = fields_request

        with open(self.context.srv_file_path, "r") as f:
            for line in f:
                line = line.strip()
                if not line or line.startswith("#"):
                    continue
                if line == "---":
                    current_fields = fields_response
                    continue
                if "=" in line:
                    # Constant definition, ignore
                    continue
                current_fields.append(self._parse_field(line))
        
        return fields_request, fields_response

    def _parse_field(self, line):
        tokens = line.split()
        if len(tokens) != 2:
            raise ValueError(f"Invalid field line: '{line}'")

        field_type, field_name = tokens
        is_array = False
        array_size = None

        if field_type.endswith("]"):
            if "[" in field_type:
                base_type, arr = field_type.split("[", 1)
                arr = arr.strip("]")
                is_array = True
                if arr:
                    array_size = int(arr)
                field_type = base_type

        package = None
        if "/" in field_type:
            package, base_type = field_type.split("/", 1)
            field_type = base_type

        return {
            "type": field_type,
            "name": field_name,
            "package": package,
            "is_array": is_array,
            "array_size": array_size
        }
