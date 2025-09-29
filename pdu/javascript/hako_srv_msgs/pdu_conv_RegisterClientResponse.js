import * as PduUtils from '../pdu_utils.js';
import { RegisterClientResponse } from './pdu_jstype_RegisterClientResponse.js';


/**
 * Deserializes a binary PDU into a RegisterClientResponse object.
 * @param {ArrayBuffer} binary_data
 * @returns { RegisterClientResponse }
 */
export function pduToJs_RegisterClientResponse(binary_data) {
    const js_obj = new RegisterClientResponse();
    const meta_parser = new PduUtils.PduMetaDataParser();
    const meta = meta_parser.load_pdu_meta(binary_data);
    if (meta === null) {
        throw new Error("Invalid PDU binary data: MetaData not found or corrupted");
    }
    binary_read_recursive_RegisterClientResponse(meta, binary_data, js_obj, meta.base_off);
    return js_obj;
}

export function binary_read_recursive_RegisterClientResponse(meta, binary_data, js_obj, base_off) {
    const view = new DataView(binary_data);
    const littleEndian = true;
    // member: service_id, type: uint32 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 0, 4);
        js_obj.service_id = PduUtils.binToValue("uint32", bin);
    }
    
    // member: client_id, type: uint32 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 4, 4);
        js_obj.client_id = PduUtils.binToValue("uint32", bin);
    }
    
    // member: request_channel_id, type: uint32 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 8, 4);
        js_obj.request_channel_id = PduUtils.binToValue("uint32", bin);
    }
    
    // member: response_channel_id, type: uint32 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 12, 4);
        js_obj.response_channel_id = PduUtils.binToValue("uint32", bin);
    }
    
    return js_obj;
}

/**
 * Serializes a RegisterClientResponse object into a binary PDU.
 * @param { RegisterClientResponse } js_obj
 * @returns {ArrayBuffer}
 */
export function jsToPdu_RegisterClientResponse(js_obj) {
    const base_allocator = new PduUtils.DynamicAllocator();
    const bw_container = new PduUtils.BinaryWriterContainer(new PduUtils.PduMetaData());

    binary_write_recursive_RegisterClientResponse(0, bw_container, base_allocator, js_obj);

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

export function binary_write_recursive_RegisterClientResponse(parent_off, bw_container, allocator, js_obj) {
    const littleEndian = true;
    // member: service_id, type: uint32 (primitive)

    
    {
        const bin = PduUtils.typeToBin("uint32", js_obj.service_id, 4);
        allocator.add(bin, parent_off + 0);
    }
    
    // member: client_id, type: uint32 (primitive)

    
    {
        const bin = PduUtils.typeToBin("uint32", js_obj.client_id, 4);
        allocator.add(bin, parent_off + 4);
    }
    
    // member: request_channel_id, type: uint32 (primitive)

    
    {
        const bin = PduUtils.typeToBin("uint32", js_obj.request_channel_id, 4);
        allocator.add(bin, parent_off + 8);
    }
    
    // member: response_channel_id, type: uint32 (primitive)

    
    {
        const bin = PduUtils.typeToBin("uint32", js_obj.response_channel_id, 4);
        allocator.add(bin, parent_off + 12);
    }
    
}
