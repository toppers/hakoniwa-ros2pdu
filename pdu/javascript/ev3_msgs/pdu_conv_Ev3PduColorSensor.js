import * as PduUtils from '../pdu_utils.js';
import { Ev3PduColorSensor } from './pdu_jstype_Ev3PduColorSensor.js';


/**
 * Deserializes a binary PDU into a Ev3PduColorSensor object.
 * @param {ArrayBuffer} binary_data
 * @returns { Ev3PduColorSensor }
 */
export function pduToJs_Ev3PduColorSensor(binary_data) {
    const js_obj = new Ev3PduColorSensor();
    const meta_parser = new PduUtils.PduMetaDataParser();
    const meta = meta_parser.load_pdu_meta(binary_data);
    if (meta === null) {
        throw new Error("Invalid PDU binary data: MetaData not found or corrupted");
    }
    binary_read_recursive_Ev3PduColorSensor(meta, binary_data, js_obj, meta.base_off);
    return js_obj;
}

export function binary_read_recursive_Ev3PduColorSensor(meta, binary_data, js_obj, base_off) {
    const view = new DataView(binary_data);
    const littleEndian = true;
    // member: color, type: uint32 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 0, 4);
        js_obj.color = PduUtils.binToValue("uint32", bin);
    }
    
    // member: reflect, type: uint32 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 4, 4);
        js_obj.reflect = PduUtils.binToValue("uint32", bin);
    }
    
    // member: rgb_r, type: uint32 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 8, 4);
        js_obj.rgb_r = PduUtils.binToValue("uint32", bin);
    }
    
    // member: rgb_g, type: uint32 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 12, 4);
        js_obj.rgb_g = PduUtils.binToValue("uint32", bin);
    }
    
    // member: rgb_b, type: uint32 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 16, 4);
        js_obj.rgb_b = PduUtils.binToValue("uint32", bin);
    }
    
    return js_obj;
}

/**
 * Serializes a Ev3PduColorSensor object into a binary PDU.
 * @param { Ev3PduColorSensor } js_obj
 * @returns {ArrayBuffer}
 */
export function jsToPdu_Ev3PduColorSensor(js_obj) {
    const base_allocator = new PduUtils.DynamicAllocator();
    const bw_container = new PduUtils.BinaryWriterContainer(new PduUtils.PduMetaData());

    binary_write_recursive_Ev3PduColorSensor(0, bw_container, base_allocator, js_obj);

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

export function binary_write_recursive_Ev3PduColorSensor(parent_off, bw_container, allocator, js_obj) {
    const littleEndian = true;
    // member: color, type: uint32 (primitive)

    
    {
        const bin = PduUtils.typeToBin("uint32", js_obj.color, 4);
        allocator.add(bin, parent_off + 0);
    }
    
    // member: reflect, type: uint32 (primitive)

    
    {
        const bin = PduUtils.typeToBin("uint32", js_obj.reflect, 4);
        allocator.add(bin, parent_off + 4);
    }
    
    // member: rgb_r, type: uint32 (primitive)

    
    {
        const bin = PduUtils.typeToBin("uint32", js_obj.rgb_r, 4);
        allocator.add(bin, parent_off + 8);
    }
    
    // member: rgb_g, type: uint32 (primitive)

    
    {
        const bin = PduUtils.typeToBin("uint32", js_obj.rgb_g, 4);
        allocator.add(bin, parent_off + 12);
    }
    
    // member: rgb_b, type: uint32 (primitive)

    
    {
        const bin = PduUtils.typeToBin("uint32", js_obj.rgb_b, 4);
        allocator.add(bin, parent_off + 16);
    }
    
}
