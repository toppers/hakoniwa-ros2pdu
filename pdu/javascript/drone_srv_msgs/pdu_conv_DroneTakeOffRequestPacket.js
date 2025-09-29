import * as PduUtils from '../pdu_utils.js';
import { DroneTakeOffRequestPacket } from './pdu_jstype_DroneTakeOffRequestPacket.js';
import { ServiceRequestHeader } from '../hako_srv_msgs/pdu_jstype_ServiceRequestHeader.js';
import { binary_read_recursive_ServiceRequestHeader, binary_write_recursive_ServiceRequestHeader } from '../hako_srv_msgs/pdu_conv_ServiceRequestHeader.js';
import { DroneTakeOffRequest } from './pdu_jstype_DroneTakeOffRequest.js';
import { binary_read_recursive_DroneTakeOffRequest, binary_write_recursive_DroneTakeOffRequest } from './pdu_conv_DroneTakeOffRequest.js';


/**
 * Deserializes a binary PDU into a DroneTakeOffRequestPacket object.
 * @param {ArrayBuffer} binary_data
 * @returns { DroneTakeOffRequestPacket }
 */
export function pduToJs_DroneTakeOffRequestPacket(binary_data) {
    const js_obj = new DroneTakeOffRequestPacket();
    const meta_parser = new PduUtils.PduMetaDataParser();
    const meta = meta_parser.load_pdu_meta(binary_data);
    if (meta === null) {
        throw new Error("Invalid PDU binary data: MetaData not found or corrupted");
    }
    binary_read_recursive_DroneTakeOffRequestPacket(meta, binary_data, js_obj, meta.base_off);
    return js_obj;
}

export function binary_read_recursive_DroneTakeOffRequestPacket(meta, binary_data, js_obj, base_off) {
    const view = new DataView(binary_data);
    const littleEndian = true;
    // member: header, type: hako_srv_msgs/ServiceRequestHeader (struct)

    {
        const tmp_obj = new ServiceRequestHeader();
        binary_read_recursive_ServiceRequestHeader(meta, binary_data, tmp_obj, base_off + 0);
        js_obj.header = tmp_obj;
    }
    
    // member: body, type: DroneTakeOffRequest (struct)

    {
        const tmp_obj = new DroneTakeOffRequest();
        binary_read_recursive_DroneTakeOffRequest(meta, binary_data, tmp_obj, base_off + 272);
        js_obj.body = tmp_obj;
    }
    
    return js_obj;
}

/**
 * Serializes a DroneTakeOffRequestPacket object into a binary PDU.
 * @param { DroneTakeOffRequestPacket } js_obj
 * @returns {ArrayBuffer}
 */
export function jsToPdu_DroneTakeOffRequestPacket(js_obj) {
    const base_allocator = new PduUtils.DynamicAllocator();
    const bw_container = new PduUtils.BinaryWriterContainer(new PduUtils.PduMetaData());

    binary_write_recursive_DroneTakeOffRequestPacket(0, bw_container, base_allocator, js_obj);

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

export function binary_write_recursive_DroneTakeOffRequestPacket(parent_off, bw_container, allocator, js_obj) {
    const littleEndian = true;
    // member: header, type: hako_srv_msgs/ServiceRequestHeader (struct)

    {
        binary_write_recursive_ServiceRequestHeader(parent_off + 0, bw_container, allocator, js_obj.header);
    }
    
    // member: body, type: DroneTakeOffRequest (struct)

    {
        binary_write_recursive_DroneTakeOffRequest(parent_off + 272, bw_container, allocator, js_obj.body);
    }
    
}
