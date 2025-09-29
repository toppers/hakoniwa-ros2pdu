import * as PduUtils from '../pdu_utils.js';
import { CameraSetTiltResponsePacket } from './pdu_jstype_CameraSetTiltResponsePacket.js';
import { ServiceResponseHeader } from '../hako_srv_msgs/pdu_jstype_ServiceResponseHeader.js';
import { binary_read_recursive_ServiceResponseHeader, binary_write_recursive_ServiceResponseHeader } from '../hako_srv_msgs/pdu_conv_ServiceResponseHeader.js';
import { CameraSetTiltResponse } from './pdu_jstype_CameraSetTiltResponse.js';
import { binary_read_recursive_CameraSetTiltResponse, binary_write_recursive_CameraSetTiltResponse } from './pdu_conv_CameraSetTiltResponse.js';


/**
 * Deserializes a binary PDU into a CameraSetTiltResponsePacket object.
 * @param {ArrayBuffer} binary_data
 * @returns { CameraSetTiltResponsePacket }
 */
export function pduToJs_CameraSetTiltResponsePacket(binary_data) {
    const js_obj = new CameraSetTiltResponsePacket();
    const meta_parser = new PduUtils.PduMetaDataParser();
    const meta = meta_parser.load_pdu_meta(binary_data);
    if (meta === null) {
        throw new Error("Invalid PDU binary data: MetaData not found or corrupted");
    }
    binary_read_recursive_CameraSetTiltResponsePacket(meta, binary_data, js_obj, meta.base_off);
    return js_obj;
}

export function binary_read_recursive_CameraSetTiltResponsePacket(meta, binary_data, js_obj, base_off) {
    const view = new DataView(binary_data);
    const littleEndian = true;
    // member: header, type: hako_srv_msgs/ServiceResponseHeader (struct)

    {
        const tmp_obj = new ServiceResponseHeader();
        binary_read_recursive_ServiceResponseHeader(meta, binary_data, tmp_obj, base_off + 0);
        js_obj.header = tmp_obj;
    }
    
    // member: body, type: CameraSetTiltResponse (struct)

    {
        const tmp_obj = new CameraSetTiltResponse();
        binary_read_recursive_CameraSetTiltResponse(meta, binary_data, tmp_obj, base_off + 268);
        js_obj.body = tmp_obj;
    }
    
    return js_obj;
}

/**
 * Serializes a CameraSetTiltResponsePacket object into a binary PDU.
 * @param { CameraSetTiltResponsePacket } js_obj
 * @returns {ArrayBuffer}
 */
export function jsToPdu_CameraSetTiltResponsePacket(js_obj) {
    const base_allocator = new PduUtils.DynamicAllocator();
    const bw_container = new PduUtils.BinaryWriterContainer(new PduUtils.PduMetaData());

    binary_write_recursive_CameraSetTiltResponsePacket(0, bw_container, base_allocator, js_obj);

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

export function binary_write_recursive_CameraSetTiltResponsePacket(parent_off, bw_container, allocator, js_obj) {
    const littleEndian = true;
    // member: header, type: hako_srv_msgs/ServiceResponseHeader (struct)

    {
        binary_write_recursive_ServiceResponseHeader(parent_off + 0, bw_container, allocator, js_obj.header);
    }
    
    // member: body, type: CameraSetTiltResponse (struct)

    {
        binary_write_recursive_CameraSetTiltResponse(parent_off + 268, bw_container, allocator, js_obj.body);
    }
    
}
