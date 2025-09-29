import * as PduUtils from '../pdu_utils.js';
import { HakoSERVO_OUTPUT_RAW } from './pdu_jstype_HakoSERVO_OUTPUT_RAW.js';


/**
 * Deserializes a binary PDU into a HakoSERVO_OUTPUT_RAW object.
 * @param {ArrayBuffer} binary_data
 * @returns { HakoSERVO_OUTPUT_RAW }
 */
export function pduToJs_HakoSERVO_OUTPUT_RAW(binary_data) {
    const js_obj = new HakoSERVO_OUTPUT_RAW();
    const meta_parser = new PduUtils.PduMetaDataParser();
    const meta = meta_parser.load_pdu_meta(binary_data);
    if (meta === null) {
        throw new Error("Invalid PDU binary data: MetaData not found or corrupted");
    }
    binary_read_recursive_HakoSERVO_OUTPUT_RAW(meta, binary_data, js_obj, meta.base_off);
    return js_obj;
}

export function binary_read_recursive_HakoSERVO_OUTPUT_RAW(meta, binary_data, js_obj, base_off) {
    const view = new DataView(binary_data);
    const littleEndian = true;
    // member: time_usec, type: uint32 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 0, 4);
        js_obj.time_usec = PduUtils.binToValue("uint32", bin);
    }
    
    // member: port, type: uint8 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 4, 1);
        js_obj.port = PduUtils.binToValue("uint8", bin);
    }
    
    // member: servo1_raw, type: uint16 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 6, 2);
        js_obj.servo1_raw = PduUtils.binToValue("uint16", bin);
    }
    
    // member: servo2_raw, type: uint16 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 8, 2);
        js_obj.servo2_raw = PduUtils.binToValue("uint16", bin);
    }
    
    // member: servo3_raw, type: uint16 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 10, 2);
        js_obj.servo3_raw = PduUtils.binToValue("uint16", bin);
    }
    
    // member: servo4_raw, type: uint16 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 12, 2);
        js_obj.servo4_raw = PduUtils.binToValue("uint16", bin);
    }
    
    // member: servo5_raw, type: uint16 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 14, 2);
        js_obj.servo5_raw = PduUtils.binToValue("uint16", bin);
    }
    
    // member: servo6_raw, type: uint16 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 16, 2);
        js_obj.servo6_raw = PduUtils.binToValue("uint16", bin);
    }
    
    // member: servo7_raw, type: uint16 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 18, 2);
        js_obj.servo7_raw = PduUtils.binToValue("uint16", bin);
    }
    
    // member: servo8_raw, type: uint16 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 20, 2);
        js_obj.servo8_raw = PduUtils.binToValue("uint16", bin);
    }
    
    return js_obj;
}

/**
 * Serializes a HakoSERVO_OUTPUT_RAW object into a binary PDU.
 * @param { HakoSERVO_OUTPUT_RAW } js_obj
 * @returns {ArrayBuffer}
 */
export function jsToPdu_HakoSERVO_OUTPUT_RAW(js_obj) {
    const base_allocator = new PduUtils.DynamicAllocator();
    const bw_container = new PduUtils.BinaryWriterContainer(new PduUtils.PduMetaData());

    binary_write_recursive_HakoSERVO_OUTPUT_RAW(0, bw_container, base_allocator, js_obj);

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

export function binary_write_recursive_HakoSERVO_OUTPUT_RAW(parent_off, bw_container, allocator, js_obj) {
    const littleEndian = true;
    // member: time_usec, type: uint32 (primitive)

    
    {
        const bin = PduUtils.typeToBin("uint32", js_obj.time_usec, 4);
        allocator.add(bin, parent_off + 0);
    }
    
    // member: port, type: uint8 (primitive)

    
    {
        const bin = PduUtils.typeToBin("uint8", js_obj.port, 1);
        allocator.add(bin, parent_off + 4);
    }
    
    // member: servo1_raw, type: uint16 (primitive)

    
    {
        const bin = PduUtils.typeToBin("uint16", js_obj.servo1_raw, 2);
        allocator.add(bin, parent_off + 6);
    }
    
    // member: servo2_raw, type: uint16 (primitive)

    
    {
        const bin = PduUtils.typeToBin("uint16", js_obj.servo2_raw, 2);
        allocator.add(bin, parent_off + 8);
    }
    
    // member: servo3_raw, type: uint16 (primitive)

    
    {
        const bin = PduUtils.typeToBin("uint16", js_obj.servo3_raw, 2);
        allocator.add(bin, parent_off + 10);
    }
    
    // member: servo4_raw, type: uint16 (primitive)

    
    {
        const bin = PduUtils.typeToBin("uint16", js_obj.servo4_raw, 2);
        allocator.add(bin, parent_off + 12);
    }
    
    // member: servo5_raw, type: uint16 (primitive)

    
    {
        const bin = PduUtils.typeToBin("uint16", js_obj.servo5_raw, 2);
        allocator.add(bin, parent_off + 14);
    }
    
    // member: servo6_raw, type: uint16 (primitive)

    
    {
        const bin = PduUtils.typeToBin("uint16", js_obj.servo6_raw, 2);
        allocator.add(bin, parent_off + 16);
    }
    
    // member: servo7_raw, type: uint16 (primitive)

    
    {
        const bin = PduUtils.typeToBin("uint16", js_obj.servo7_raw, 2);
        allocator.add(bin, parent_off + 18);
    }
    
    // member: servo8_raw, type: uint16 (primitive)

    
    {
        const bin = PduUtils.typeToBin("uint16", js_obj.servo8_raw, 2);
        allocator.add(bin, parent_off + 20);
    }
    
}
