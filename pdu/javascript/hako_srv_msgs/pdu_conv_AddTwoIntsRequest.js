import * as PduUtils from '../pdu_utils.js';
import { AddTwoIntsRequest } from './pdu_jstype_AddTwoIntsRequest.js';


/**
 * Deserializes a binary PDU into a AddTwoIntsRequest object.
 * @param {ArrayBuffer} binary_data
 * @returns { AddTwoIntsRequest }
 */
export function pduToJs_AddTwoIntsRequest(binary_data) {
    const js_obj = new AddTwoIntsRequest();
    const meta_parser = new PduUtils.PduMetaDataParser();
    const meta = meta_parser.load_pdu_meta(binary_data);
    if (meta === null) {
        throw new Error("Invalid PDU binary data: MetaData not found or corrupted");
    }
    binary_read_recursive_AddTwoIntsRequest(meta, binary_data, js_obj, meta.base_off);
    return js_obj;
}

export function binary_read_recursive_AddTwoIntsRequest(meta, binary_data, js_obj, base_off) {
    const view = new DataView(binary_data);
    const littleEndian = true;
    // member: a, type: int64 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 0, 8);
        js_obj.a = PduUtils.binToValue("int64", bin);
    }
    
    // member: b, type: int64 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 8, 8);
        js_obj.b = PduUtils.binToValue("int64", bin);
    }
    
    return js_obj;
}

/**
 * Serializes a AddTwoIntsRequest object into a binary PDU.
 * @param { AddTwoIntsRequest } js_obj
 * @returns {ArrayBuffer}
 */
export function jsToPdu_AddTwoIntsRequest(js_obj) {
    const base_allocator = new PduUtils.DynamicAllocator();
    const bw_container = new PduUtils.BinaryWriterContainer(new PduUtils.PduMetaData());

    binary_write_recursive_AddTwoIntsRequest(0, bw_container, base_allocator, js_obj);

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

export function binary_write_recursive_AddTwoIntsRequest(parent_off, bw_container, allocator, js_obj) {
    const littleEndian = true;
    // member: a, type: int64 (primitive)

    
    {
        const bin = PduUtils.typeToBin("int64", js_obj.a, 8);
        allocator.add(bin, parent_off + 0);
    }
    
    // member: b, type: int64 (primitive)

    
    {
        const bin = PduUtils.typeToBin("int64", js_obj.b, 8);
        allocator.add(bin, parent_off + 8);
    }
    
}
