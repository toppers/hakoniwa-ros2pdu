import * as PduUtils from '../pdu_utils.js';
import { ShareObjectOwnerRequest } from './pdu_jstype_ShareObjectOwnerRequest.js';


/**
 * Deserializes a binary PDU into a ShareObjectOwnerRequest object.
 * @param {ArrayBuffer} binary_data
 * @returns { ShareObjectOwnerRequest }
 */
export function pduToJs_ShareObjectOwnerRequest(binary_data) {
    const js_obj = new ShareObjectOwnerRequest();
    const meta_parser = new PduUtils.PduMetaDataParser();
    const meta = meta_parser.load_pdu_meta(binary_data);
    if (meta === null) {
        throw new Error("Invalid PDU binary data: MetaData not found or corrupted");
    }
    binary_read_recursive_ShareObjectOwnerRequest(meta, binary_data, js_obj, meta.base_off);
    return js_obj;
}

export function binary_read_recursive_ShareObjectOwnerRequest(meta, binary_data, js_obj, base_off) {
    const view = new DataView(binary_data);
    const littleEndian = true;
    // member: object_name, type: string (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 0, 128);
        js_obj.object_name = PduUtils.binToValue("string", bin);
    }
    
    // member: request_type, type: uint32 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 128, 4);
        js_obj.request_type = PduUtils.binToValue("uint32", bin);
    }
    
    // member: new_owner_id, type: uint32 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 132, 4);
        js_obj.new_owner_id = PduUtils.binToValue("uint32", bin);
    }
    
    // member: request_time, type: uint64 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 136, 8);
        js_obj.request_time = PduUtils.binToValue("uint64", bin);
    }
    
    return js_obj;
}

/**
 * Serializes a ShareObjectOwnerRequest object into a binary PDU.
 * @param { ShareObjectOwnerRequest } js_obj
 * @returns {ArrayBuffer}
 */
export function jsToPdu_ShareObjectOwnerRequest(js_obj) {
    const base_allocator = new PduUtils.DynamicAllocator();
    const bw_container = new PduUtils.BinaryWriterContainer(new PduUtils.PduMetaData());

    binary_write_recursive_ShareObjectOwnerRequest(0, bw_container, base_allocator, js_obj);

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

export function binary_write_recursive_ShareObjectOwnerRequest(parent_off, bw_container, allocator, js_obj) {
    const littleEndian = true;
    // member: object_name, type: string (primitive)

    
    {
        const bin = PduUtils.typeToBin("string", js_obj.object_name, 128);
        allocator.add(bin, parent_off + 0);
    }
    
    // member: request_type, type: uint32 (primitive)

    
    {
        const bin = PduUtils.typeToBin("uint32", js_obj.request_type, 4);
        allocator.add(bin, parent_off + 128);
    }
    
    // member: new_owner_id, type: uint32 (primitive)

    
    {
        const bin = PduUtils.typeToBin("uint32", js_obj.new_owner_id, 4);
        allocator.add(bin, parent_off + 132);
    }
    
    // member: request_time, type: uint64 (primitive)

    
    {
        const bin = PduUtils.typeToBin("uint64", js_obj.request_time, 8);
        allocator.add(bin, parent_off + 136);
    }
    
}
