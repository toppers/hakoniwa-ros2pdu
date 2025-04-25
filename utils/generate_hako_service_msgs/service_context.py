import os

class ServiceContext:
    def __init__(self, srv_file_path):
        if not os.path.isfile(srv_file_path):
            raise ValueError(f"Error: '{srv_file_path}' is not a valid .srv file (file does not exist or is not a regular file).")
        self.srv_file_path = srv_file_path
        self.service_name = self._extract_service_name()
        self.srv_package_name = self._extract_srv_package_name()
        self.msg_package_name = f"{self.srv_package_name}_msgs"

    def _extract_service_name(self):
        basename = os.path.basename(self.srv_file_path)
        service_name, _ = os.path.splitext(basename)
        return service_name

    def _extract_srv_package_name(self):
        parent = os.path.dirname(self.srv_file_path)
        package_name = os.path.basename(parent)
        return package_name
