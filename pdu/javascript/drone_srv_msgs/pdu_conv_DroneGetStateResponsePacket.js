import * as PduUtils from '../pdu_utils.js';
import { DroneGetStateResponsePacket } from './pdu_jstype_DroneGetStateResponsePacket.js';
import { ServiceResponseHeader } from '../hako_srv_msgs/pdu_jstype_ServiceResponseHeader.js';
import { binary_read_recursive_ServiceResponseHeader, binary_write_recursive_ServiceResponseHeader } from '../hako_srv_msgs/pdu_conv_ServiceResponseHeader.js';
import { DroneGetStateResponse } from './pdu_jstype_DroneGetStateResponse.js';
import { binary_read_recursive_DroneGetStateResponse, binary_write_recursive_DroneGetStateResponse } from './pdu_conv_DroneGetStateResponse.js';


/**
 * Deserializes a binary PDU into a DroneGetStateResponsePacket object.
 * @param {ArrayBuffer} binary_data
 * @returns { DroneGetStateResponsePacket }
 */
export function pduToJs_DroneGetStateResponsePacket(binary_data) {
    const js_obj = new DroneGetStateResponsePacket();
    const meta_parser = new PduUtils.PduMetaDataParser();
    const meta = meta_parser.load_pdu_meta(binary_data);
    if (meta === null) {
        throw new Error("Invalid PDU binary data: MetaData not found or corrupted");
    }
    binary_read_recursive_DroneGetStateResponsePacket(meta, binary_data, js_obj, meta.base_off);
    return js_obj;
}

export function binary_read_recursive_DroneGetStateResponsePacket(meta, binary_data, js_obj, base_off) {
    const view = new DataView(binary_data);
    const littleEndian = true;
    // member: header, type: hako_srv_msgs/ServiceResponseHeader (struct)

    {
        const tmp_obj = new ServiceResponseHeader();
        binary_read_recursive_ServiceResponseHeader(meta, binary_data, tmp_obj, base_off + 0);
        js_obj.header = tmp_obj;
    }
    
    // member: body, type: DroneGetStateResponse (struct)

    {
        const tmp_obj = new DroneGetStateResponse();
        binary_read_recursive_DroneGetStateResponse(meta, binary_data, tmp_obj, base_off + 272);
        js_obj.body = tmp_obj;
    }
    
    return js_obj;
}

/**
 * Serializes a DroneGetStateResponsePacket object into a binary PDU.
 * @param { DroneGetStateResponsePacket } js_obj
 * @returns {ArrayBuffer}
 */
export function jsToPdu_DroneGetStateResponsePacket(js_obj) {
    const base_allocator = new PduUtils.DynamicAllocator();
    const bw_container = new PduUtils.BinaryWriterContainer(new PduUtils.PduMetaData());

    binary_write_recursive_DroneGetStateResponsePacket(0, bw_container, base_allocator, js_obj);

    const base_data_size = base_allocator.size();
    const heap_data_size = bw_container.heap_allocator.size();
    
    bw_container.meta.heap_off = PduUtils.PDU_META_DATA_SIZE + base_data_size;
    bw_container.meta.total_size = bw_container.meta.heap_off + heap_data_size;

    const final_buffer = new ArrayBuffer(bw_container.meta.total_size);
    const final_view = new Uint8Array(final_buffer);

    PduUtils.writeBinary(final_view, 0, bw_container.meta.to_bytes());
    PduUtils.writeBinary(final_view, bw_container.meta.base_off, base_allocator.toArray());
    PduUtils.writeBinary(final_view, bw_container.meta.heap_off, bw_container.heap_allocator.toArray());

    return final_buffer;
}

export function binary_write_recursive_DroneGetStateResponsePacket(parent_off, bw_container, allocator, js_obj) {
    const littleEndian = true;
    // member: header, type: hako_srv_msgs/ServiceResponseHeader (struct)

    {
        binary_write_recursive_ServiceResponseHeader(parent_off + 0, bw_container, allocator, js_obj.header);
    }
    
    // member: body, type: DroneGetStateResponse (struct)

    {
        binary_write_recursive_DroneGetStateResponse(parent_off + 272, bw_container, allocator, js_obj.body);
    }
    
}
