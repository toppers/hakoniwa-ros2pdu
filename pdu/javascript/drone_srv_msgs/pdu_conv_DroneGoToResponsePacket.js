import * as PduUtils from '../pdu_utils.js';
import { DroneGoToResponsePacket } from './pdu_jstype_DroneGoToResponsePacket.js';
import { ServiceResponseHeader } from '../hako_srv_msgs/pdu_jstype_ServiceResponseHeader.js';
import { binary_read_recursive_ServiceResponseHeader, binary_write_recursive_ServiceResponseHeader } from '../hako_srv_msgs/pdu_conv_ServiceResponseHeader.js';
import { DroneGoToResponse } from './pdu_jstype_DroneGoToResponse.js';
import { binary_read_recursive_DroneGoToResponse, binary_write_recursive_DroneGoToResponse } from './pdu_conv_DroneGoToResponse.js';


/**
 * Deserializes a binary PDU into a DroneGoToResponsePacket object.
 * @param {ArrayBuffer} binary_data
 * @returns { DroneGoToResponsePacket }
 */
export function pduToJs_DroneGoToResponsePacket(binary_data) {
    const js_obj = new DroneGoToResponsePacket();
    const meta_parser = new PduUtils.PduMetaDataParser();
    const meta = meta_parser.load_pdu_meta(binary_data);
    if (meta === null) {
        throw new Error("Invalid PDU binary data: MetaData not found or corrupted");
    }
    binary_read_recursive_DroneGoToResponsePacket(meta, binary_data, js_obj, meta.base_off);
    return js_obj;
}

export function binary_read_recursive_DroneGoToResponsePacket(meta, binary_data, js_obj, base_off) {
    const view = new DataView(binary_data);
    const littleEndian = true;
    // member: header, type: hako_srv_msgs/ServiceResponseHeader (struct)

    {
        const tmp_obj = new ServiceResponseHeader();
        binary_read_recursive_ServiceResponseHeader(meta, binary_data, tmp_obj, base_off + 0);
        js_obj.header = tmp_obj;
    }
    
    // member: body, type: DroneGoToResponse (struct)

    {
        const tmp_obj = new DroneGoToResponse();
        binary_read_recursive_DroneGoToResponse(meta, binary_data, tmp_obj, base_off + 268);
        js_obj.body = tmp_obj;
    }
    
    return js_obj;
}

/**
 * Serializes a DroneGoToResponsePacket object into a binary PDU.
 * @param { DroneGoToResponsePacket } js_obj
 * @returns {ArrayBuffer}
 */
export function jsToPdu_DroneGoToResponsePacket(js_obj) {
    const base_allocator = new PduUtils.DynamicAllocator();
    const bw_container = new PduUtils.BinaryWriterContainer(new PduUtils.PduMetaData());

    binary_write_recursive_DroneGoToResponsePacket(0, bw_container, base_allocator, js_obj);

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

export function binary_write_recursive_DroneGoToResponsePacket(parent_off, bw_container, allocator, js_obj) {
    const littleEndian = true;
    // member: header, type: hako_srv_msgs/ServiceResponseHeader (struct)

    {
        binary_write_recursive_ServiceResponseHeader(parent_off + 0, bw_container, allocator, js_obj.header);
    }
    
    // member: body, type: DroneGoToResponse (struct)

    {
        binary_write_recursive_DroneGoToResponse(parent_off + 268, bw_container, allocator, js_obj.body);
    }
    
}
