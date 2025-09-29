import * as PduUtils from '../pdu_utils.js';
import { Quaternion } from './pdu_jstype_Quaternion.js';


/**
 * Deserializes a binary PDU into a Quaternion object.
 * @param {ArrayBuffer} binary_data
 * @returns { Quaternion }
 */
export function pduToJs_Quaternion(binary_data) {
    const js_obj = new Quaternion();
    const meta_parser = new PduUtils.PduMetaDataParser();
    const meta = meta_parser.load_pdu_meta(binary_data);
    if (meta === null) {
        throw new Error("Invalid PDU binary data: MetaData not found or corrupted");
    }
    binary_read_recursive_Quaternion(meta, binary_data, js_obj, meta.base_off);
    return js_obj;
}

export function binary_read_recursive_Quaternion(meta, binary_data, js_obj, base_off) {
    const view = new DataView(binary_data);
    const littleEndian = true;
    // member: x, type: float64 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 0, 8);
        js_obj.x = PduUtils.binToValue("float64", bin);
    }
    
    // member: y, type: float64 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 8, 8);
        js_obj.y = PduUtils.binToValue("float64", bin);
    }
    
    // member: z, type: float64 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 16, 8);
        js_obj.z = PduUtils.binToValue("float64", bin);
    }
    
    // member: w, type: float64 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 24, 8);
        js_obj.w = PduUtils.binToValue("float64", bin);
    }
    
    return js_obj;
}

/**
 * Serializes a Quaternion object into a binary PDU.
 * @param { Quaternion } js_obj
 * @returns {ArrayBuffer}
 */
export function jsToPdu_Quaternion(js_obj) {
    const base_allocator = new PduUtils.DynamicAllocator();
    const bw_container = new PduUtils.BinaryWriterContainer(new PduUtils.PduMetaData());

    binary_write_recursive_Quaternion(0, bw_container, base_allocator, js_obj);

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

export function binary_write_recursive_Quaternion(parent_off, bw_container, allocator, js_obj) {
    const littleEndian = true;
    // member: x, type: float64 (primitive)

    
    {
        const bin = PduUtils.typeToBin("float64", js_obj.x, 8);
        allocator.add(bin, parent_off + 0);
    }
    
    // member: y, type: float64 (primitive)

    
    {
        const bin = PduUtils.typeToBin("float64", js_obj.y, 8);
        allocator.add(bin, parent_off + 8);
    }
    
    // member: z, type: float64 (primitive)

    
    {
        const bin = PduUtils.typeToBin("float64", js_obj.z, 8);
        allocator.add(bin, parent_off + 16);
    }
    
    // member: w, type: float64 (primitive)

    
    {
        const bin = PduUtils.typeToBin("float64", js_obj.w, 8);
        allocator.add(bin, parent_off + 24);
    }
    
}
