import argparse
from utils.generate_hako_service_msgs.service_context import ServiceContext
from utils.generate_hako_service_msgs.srv_parser import SrvParser
from utils.generate_hako_service_msgs.msg_generator import MsgGenerator
from utils.generate_hako_service_msgs.msg_writer import MsgWriter
from utils.generate_hako_service_msgs.common import validate_fields

def main():
    parser = argparse.ArgumentParser(description="Generate Hakoniwa Service .msg files from a ROS .srv file")
    parser.add_argument("srv_file", help="Path to the input .srv file")
    parser.add_argument("--out", required=True, help="Base output directory")
    args = parser.parse_args()

    context = ServiceContext(args.srv_file)
    fields_request, fields_response = SrvParser(context).parse()

    validate_fields(context.service_name, fields_request, fields_response)

    generator = MsgGenerator(context)
    writer = MsgWriter(context, args.out)

    writer.write(f"{context.service_name}Request.msg", generator.generate_request_msg(fields_request))
    writer.write(f"{context.service_name}Response.msg", generator.generate_response_msg(fields_response))
    writer.write(f"{context.service_name}RequestPacket.msg", generator.generate_request_packet_msg())
    writer.write(f"{context.service_name}ResponsePacket.msg", generator.generate_response_packet_msg())

if __name__ == "__main__":
    main()
