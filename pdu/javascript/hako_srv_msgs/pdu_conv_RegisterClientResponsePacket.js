import * as PduUtils from '../pdu_utils.js';
import { RegisterClientResponsePacket } from './pdu_jstype_RegisterClientResponsePacket.js';
import { ServiceResponseHeader } from './pdu_jstype_ServiceResponseHeader.js';
import { binary_read_recursive_ServiceResponseHeader, binary_write_recursive_ServiceResponseHeader } from './pdu_conv_ServiceResponseHeader.js';
import { RegisterClientResponse } from './pdu_jstype_RegisterClientResponse.js';
import { binary_read_recursive_RegisterClientResponse, binary_write_recursive_RegisterClientResponse } from './pdu_conv_RegisterClientResponse.js';


/**
 * Deserializes a binary PDU into a RegisterClientResponsePacket object.
 * @param {ArrayBuffer} binary_data
 * @returns { RegisterClientResponsePacket }
 */
export function pduToJs_RegisterClientResponsePacket(binary_data) {
    const js_obj = new RegisterClientResponsePacket();
    const meta_parser = new PduUtils.PduMetaDataParser();
    const meta = meta_parser.load_pdu_meta(binary_data);
    if (meta === null) {
        throw new Error("Invalid PDU binary data: MetaData not found or corrupted");
    }
    binary_read_recursive_RegisterClientResponsePacket(meta, binary_data, js_obj, meta.base_off);
    return js_obj;
}

export function binary_read_recursive_RegisterClientResponsePacket(meta, binary_data, js_obj, base_off) {
    const view = new DataView(binary_data);
    const littleEndian = true;
    // member: header, type: ServiceResponseHeader (struct)

    {
        const tmp_obj = new ServiceResponseHeader();
        binary_read_recursive_ServiceResponseHeader(meta, binary_data, tmp_obj, base_off + 0);
        js_obj.header = tmp_obj;
    }
    
    // member: body, type: RegisterClientResponse (struct)

    {
        const tmp_obj = new RegisterClientResponse();
        binary_read_recursive_RegisterClientResponse(meta, binary_data, tmp_obj, base_off + 268);
        js_obj.body = tmp_obj;
    }
    
    return js_obj;
}

/**
 * Serializes a RegisterClientResponsePacket object into a binary PDU.
 * @param { RegisterClientResponsePacket } js_obj
 * @returns {ArrayBuffer}
 */
export function jsToPdu_RegisterClientResponsePacket(js_obj) {
    const base_allocator = new PduUtils.DynamicAllocator();
    const bw_container = new PduUtils.BinaryWriterContainer(new PduUtils.PduMetaData());

    binary_write_recursive_RegisterClientResponsePacket(0, bw_container, base_allocator, js_obj);

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

export function binary_write_recursive_RegisterClientResponsePacket(parent_off, bw_container, allocator, js_obj) {
    const littleEndian = true;
    // member: header, type: ServiceResponseHeader (struct)

    {
        binary_write_recursive_ServiceResponseHeader(parent_off + 0, bw_container, allocator, js_obj.header);
    }
    
    // member: body, type: RegisterClientResponse (struct)

    {
        binary_write_recursive_RegisterClientResponse(parent_off + 268, bw_container, allocator, js_obj.body);
    }
    
}
