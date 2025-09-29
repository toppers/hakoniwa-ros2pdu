import * as PduUtils from '../pdu_utils.js';
import { HakoHilSensor } from './pdu_jstype_HakoHilSensor.js';


/**
 * Deserializes a binary PDU into a HakoHilSensor object.
 * @param {ArrayBuffer} binary_data
 * @returns { HakoHilSensor }
 */
export function pduToJs_HakoHilSensor(binary_data) {
    const js_obj = new HakoHilSensor();
    const meta_parser = new PduUtils.PduMetaDataParser();
    const meta = meta_parser.load_pdu_meta(binary_data);
    if (meta === null) {
        throw new Error("Invalid PDU binary data: MetaData not found or corrupted");
    }
    binary_read_recursive_HakoHilSensor(meta, binary_data, js_obj, meta.base_off);
    return js_obj;
}

export function binary_read_recursive_HakoHilSensor(meta, binary_data, js_obj, base_off) {
    const view = new DataView(binary_data);
    const littleEndian = true;
    // member: time_usec, type: uint64 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 0, 8);
        js_obj.time_usec = PduUtils.binToValue("uint64", bin);
    }
    
    // member: xacc, type: float32 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 8, 4);
        js_obj.xacc = PduUtils.binToValue("float32", bin);
    }
    
    // member: yacc, type: float32 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 12, 4);
        js_obj.yacc = PduUtils.binToValue("float32", bin);
    }
    
    // member: zacc, type: float32 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 16, 4);
        js_obj.zacc = PduUtils.binToValue("float32", bin);
    }
    
    // member: xgyro, type: float32 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 20, 4);
        js_obj.xgyro = PduUtils.binToValue("float32", bin);
    }
    
    // member: ygyro, type: float32 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 24, 4);
        js_obj.ygyro = PduUtils.binToValue("float32", bin);
    }
    
    // member: zgyro, type: float32 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 28, 4);
        js_obj.zgyro = PduUtils.binToValue("float32", bin);
    }
    
    // member: xmag, type: float32 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 32, 4);
        js_obj.xmag = PduUtils.binToValue("float32", bin);
    }
    
    // member: ymag, type: float32 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 36, 4);
        js_obj.ymag = PduUtils.binToValue("float32", bin);
    }
    
    // member: zmag, type: float32 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 40, 4);
        js_obj.zmag = PduUtils.binToValue("float32", bin);
    }
    
    // member: abs_pressure, type: float32 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 44, 4);
        js_obj.abs_pressure = PduUtils.binToValue("float32", bin);
    }
    
    // member: diff_pressure, type: float32 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 48, 4);
        js_obj.diff_pressure = PduUtils.binToValue("float32", bin);
    }
    
    // member: pressure_alt, type: float32 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 52, 4);
        js_obj.pressure_alt = PduUtils.binToValue("float32", bin);
    }
    
    // member: temperature, type: float32 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 56, 4);
        js_obj.temperature = PduUtils.binToValue("float32", bin);
    }
    
    // member: fields_updated, type: uint32 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 60, 4);
        js_obj.fields_updated = PduUtils.binToValue("uint32", bin);
    }
    
    // member: id, type: uint8 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 64, 1);
        js_obj.id = PduUtils.binToValue("uint8", bin);
    }
    
    return js_obj;
}

/**
 * Serializes a HakoHilSensor object into a binary PDU.
 * @param { HakoHilSensor } js_obj
 * @returns {ArrayBuffer}
 */
export function jsToPdu_HakoHilSensor(js_obj) {
    const base_allocator = new PduUtils.DynamicAllocator();
    const bw_container = new PduUtils.BinaryWriterContainer(new PduUtils.PduMetaData());

    binary_write_recursive_HakoHilSensor(0, bw_container, base_allocator, js_obj);

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

export function binary_write_recursive_HakoHilSensor(parent_off, bw_container, allocator, js_obj) {
    const littleEndian = true;
    // member: time_usec, type: uint64 (primitive)

    
    {
        const bin = PduUtils.typeToBin("uint64", js_obj.time_usec, 8);
        allocator.add(bin, parent_off + 0);
    }
    
    // member: xacc, type: float32 (primitive)

    
    {
        const bin = PduUtils.typeToBin("float32", js_obj.xacc, 4);
        allocator.add(bin, parent_off + 8);
    }
    
    // member: yacc, type: float32 (primitive)

    
    {
        const bin = PduUtils.typeToBin("float32", js_obj.yacc, 4);
        allocator.add(bin, parent_off + 12);
    }
    
    // member: zacc, type: float32 (primitive)

    
    {
        const bin = PduUtils.typeToBin("float32", js_obj.zacc, 4);
        allocator.add(bin, parent_off + 16);
    }
    
    // member: xgyro, type: float32 (primitive)

    
    {
        const bin = PduUtils.typeToBin("float32", js_obj.xgyro, 4);
        allocator.add(bin, parent_off + 20);
    }
    
    // member: ygyro, type: float32 (primitive)

    
    {
        const bin = PduUtils.typeToBin("float32", js_obj.ygyro, 4);
        allocator.add(bin, parent_off + 24);
    }
    
    // member: zgyro, type: float32 (primitive)

    
    {
        const bin = PduUtils.typeToBin("float32", js_obj.zgyro, 4);
        allocator.add(bin, parent_off + 28);
    }
    
    // member: xmag, type: float32 (primitive)

    
    {
        const bin = PduUtils.typeToBin("float32", js_obj.xmag, 4);
        allocator.add(bin, parent_off + 32);
    }
    
    // member: ymag, type: float32 (primitive)

    
    {
        const bin = PduUtils.typeToBin("float32", js_obj.ymag, 4);
        allocator.add(bin, parent_off + 36);
    }
    
    // member: zmag, type: float32 (primitive)

    
    {
        const bin = PduUtils.typeToBin("float32", js_obj.zmag, 4);
        allocator.add(bin, parent_off + 40);
    }
    
    // member: abs_pressure, type: float32 (primitive)

    
    {
        const bin = PduUtils.typeToBin("float32", js_obj.abs_pressure, 4);
        allocator.add(bin, parent_off + 44);
    }
    
    // member: diff_pressure, type: float32 (primitive)

    
    {
        const bin = PduUtils.typeToBin("float32", js_obj.diff_pressure, 4);
        allocator.add(bin, parent_off + 48);
    }
    
    // member: pressure_alt, type: float32 (primitive)

    
    {
        const bin = PduUtils.typeToBin("float32", js_obj.pressure_alt, 4);
        allocator.add(bin, parent_off + 52);
    }
    
    // member: temperature, type: float32 (primitive)

    
    {
        const bin = PduUtils.typeToBin("float32", js_obj.temperature, 4);
        allocator.add(bin, parent_off + 56);
    }
    
    // member: fields_updated, type: uint32 (primitive)

    
    {
        const bin = PduUtils.typeToBin("uint32", js_obj.fields_updated, 4);
        allocator.add(bin, parent_off + 60);
    }
    
    // member: id, type: uint8 (primitive)

    
    {
        const bin = PduUtils.typeToBin("uint8", js_obj.id, 1);
        allocator.add(bin, parent_off + 64);
    }
    
}
