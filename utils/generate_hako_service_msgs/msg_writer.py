import os

class MsgWriter:
    def __init__(self, context, output_base_dir):
        self.output_dir = os.path.join(output_base_dir, context.msg_package_name, "msg")
        os.makedirs(self.output_dir, exist_ok=True)

    def write(self, filename, content):
        path = os.path.join(self.output_dir, filename)
        with open(path, "w") as f:
            f.write(content + "\n")
