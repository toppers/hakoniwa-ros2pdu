import * as PduUtils from '../pdu_utils.js';
import { DroneSetReadyRequestPacket } from './pdu_jstype_DroneSetReadyRequestPacket.js';
import { ServiceRequestHeader } from '../hako_srv_msgs/pdu_jstype_ServiceRequestHeader.js';
import { binary_read_recursive_ServiceRequestHeader, binary_write_recursive_ServiceRequestHeader } from '../hako_srv_msgs/pdu_conv_ServiceRequestHeader.js';
import { DroneSetReadyRequest } from './pdu_jstype_DroneSetReadyRequest.js';
import { binary_read_recursive_DroneSetReadyRequest, binary_write_recursive_DroneSetReadyRequest } from './pdu_conv_DroneSetReadyRequest.js';


/**
 * Deserializes a binary PDU into a DroneSetReadyRequestPacket object.
 * @param {ArrayBuffer} binary_data
 * @returns { DroneSetReadyRequestPacket }
 */
export function pduToJs_DroneSetReadyRequestPacket(binary_data) {
    const js_obj = new DroneSetReadyRequestPacket();
    const meta_parser = new PduUtils.PduMetaDataParser();
    const meta = meta_parser.load_pdu_meta(binary_data);
    if (meta === null) {
        throw new Error("Invalid PDU binary data: MetaData not found or corrupted");
    }
    binary_read_recursive_DroneSetReadyRequestPacket(meta, binary_data, js_obj, meta.base_off);
    return js_obj;
}

export function binary_read_recursive_DroneSetReadyRequestPacket(meta, binary_data, js_obj, base_off) {
    const view = new DataView(binary_data);
    const littleEndian = true;
    // member: header, type: hako_srv_msgs/ServiceRequestHeader (struct)

    {
        const tmp_obj = new ServiceRequestHeader();
        binary_read_recursive_ServiceRequestHeader(meta, binary_data, tmp_obj, base_off + 0);
        js_obj.header = tmp_obj;
    }
    
    // member: body, type: DroneSetReadyRequest (struct)

    {
        const tmp_obj = new DroneSetReadyRequest();
        binary_read_recursive_DroneSetReadyRequest(meta, binary_data, tmp_obj, base_off + 268);
        js_obj.body = tmp_obj;
    }
    
    return js_obj;
}

/**
 * Serializes a DroneSetReadyRequestPacket object into a binary PDU.
 * @param { DroneSetReadyRequestPacket } js_obj
 * @returns {ArrayBuffer}
 */
export function jsToPdu_DroneSetReadyRequestPacket(js_obj) {
    const base_allocator = new PduUtils.DynamicAllocator();
    const bw_container = new PduUtils.BinaryWriterContainer(new PduUtils.PduMetaData());

    binary_write_recursive_DroneSetReadyRequestPacket(0, bw_container, base_allocator, js_obj);

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

export function binary_write_recursive_DroneSetReadyRequestPacket(parent_off, bw_container, allocator, js_obj) {
    const littleEndian = true;
    // member: header, type: hako_srv_msgs/ServiceRequestHeader (struct)

    {
        binary_write_recursive_ServiceRequestHeader(parent_off + 0, bw_container, allocator, js_obj.header);
    }
    
    // member: body, type: DroneSetReadyRequest (struct)

    {
        binary_write_recursive_DroneSetReadyRequest(parent_off + 268, bw_container, allocator, js_obj.body);
    }
    
}
