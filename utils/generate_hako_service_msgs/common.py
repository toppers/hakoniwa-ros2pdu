def validate_fields(service_name, fields_request, fields_response):
    if len(fields_request) == 0:
        raise ValueError(f"Error: Request message for '{service_name}' has no fields (constants are ignored).")
    if len(fields_response) == 0:
        raise ValueError(f"Error: Response message for '{service_name}' has no fields (constants are ignored).")
