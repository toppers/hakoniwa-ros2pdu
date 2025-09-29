import * as PduUtils from '../pdu_utils.js';
import { HakoHilStateQuaternion } from './pdu_jstype_HakoHilStateQuaternion.js';


/**
 * Deserializes a binary PDU into a HakoHilStateQuaternion object.
 * @param {ArrayBuffer} binary_data
 * @returns { HakoHilStateQuaternion }
 */
export function pduToJs_HakoHilStateQuaternion(binary_data) {
    const js_obj = new HakoHilStateQuaternion();
    const meta_parser = new PduUtils.PduMetaDataParser();
    const meta = meta_parser.load_pdu_meta(binary_data);
    if (meta === null) {
        throw new Error("Invalid PDU binary data: MetaData not found or corrupted");
    }
    binary_read_recursive_HakoHilStateQuaternion(meta, binary_data, js_obj, meta.base_off);
    return js_obj;
}

export function binary_read_recursive_HakoHilStateQuaternion(meta, binary_data, js_obj, base_off) {
    const view = new DataView(binary_data);
    const littleEndian = true;
    // member: time_usec, type: uint64 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 0, 8);
        js_obj.time_usec = PduUtils.binToValue("uint64", bin);
    }
    
    // member: attitude_quaternion, type: float32 (primitive)

    
    {
        const array_bin = PduUtils.readBinary(binary_data, base_off + 8, 16);
        js_obj.attitude_quaternion = PduUtils.binToArrayValues("float32", array_bin, 4);
    }
    
    // member: rollspeed, type: float32 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 24, 4);
        js_obj.rollspeed = PduUtils.binToValue("float32", bin);
    }
    
    // member: pitchspeed, type: float32 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 28, 4);
        js_obj.pitchspeed = PduUtils.binToValue("float32", bin);
    }
    
    // member: yawspeed, type: float32 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 32, 4);
        js_obj.yawspeed = PduUtils.binToValue("float32", bin);
    }
    
    // member: lat, type: int32 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 36, 4);
        js_obj.lat = PduUtils.binToValue("int32", bin);
    }
    
    // member: lon, type: int32 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 40, 4);
        js_obj.lon = PduUtils.binToValue("int32", bin);
    }
    
    // member: alt, type: int32 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 44, 4);
        js_obj.alt = PduUtils.binToValue("int32", bin);
    }
    
    // member: vx, type: int16 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 48, 2);
        js_obj.vx = PduUtils.binToValue("int16", bin);
    }
    
    // member: vy, type: int16 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 50, 2);
        js_obj.vy = PduUtils.binToValue("int16", bin);
    }
    
    // member: vz, type: int16 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 52, 2);
        js_obj.vz = PduUtils.binToValue("int16", bin);
    }
    
    // member: ind_airspeed, type: uint16 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 54, 2);
        js_obj.ind_airspeed = PduUtils.binToValue("uint16", bin);
    }
    
    // member: true_airspeed, type: uint16 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 56, 2);
        js_obj.true_airspeed = PduUtils.binToValue("uint16", bin);
    }
    
    // member: xacc, type: int16 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 58, 2);
        js_obj.xacc = PduUtils.binToValue("int16", bin);
    }
    
    // member: yacc, type: int16 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 60, 2);
        js_obj.yacc = PduUtils.binToValue("int16", bin);
    }
    
    // member: zacc, type: int16 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 62, 2);
        js_obj.zacc = PduUtils.binToValue("int16", bin);
    }
    
    return js_obj;
}

/**
 * Serializes a HakoHilStateQuaternion object into a binary PDU.
 * @param { HakoHilStateQuaternion } js_obj
 * @returns {ArrayBuffer}
 */
export function jsToPdu_HakoHilStateQuaternion(js_obj) {
    const base_allocator = new PduUtils.DynamicAllocator();
    const bw_container = new PduUtils.BinaryWriterContainer(new PduUtils.PduMetaData());

    binary_write_recursive_HakoHilStateQuaternion(0, bw_container, base_allocator, js_obj);

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

export function binary_write_recursive_HakoHilStateQuaternion(parent_off, bw_container, allocator, js_obj) {
    const littleEndian = true;
    // member: time_usec, type: uint64 (primitive)

    
    {
        const bin = PduUtils.typeToBin("uint64", js_obj.time_usec, 8);
        allocator.add(bin, parent_off + 0);
    }
    
    // member: attitude_quaternion, type: float32 (primitive)

    
    {
        const buffer = PduUtils.typesToBin("float32", js_obj.attitude_quaternion);
        allocator.add(buffer, parent_off + 8);
    }
    
    // member: rollspeed, type: float32 (primitive)

    
    {
        const bin = PduUtils.typeToBin("float32", js_obj.rollspeed, 4);
        allocator.add(bin, parent_off + 24);
    }
    
    // member: pitchspeed, type: float32 (primitive)

    
    {
        const bin = PduUtils.typeToBin("float32", js_obj.pitchspeed, 4);
        allocator.add(bin, parent_off + 28);
    }
    
    // member: yawspeed, type: float32 (primitive)

    
    {
        const bin = PduUtils.typeToBin("float32", js_obj.yawspeed, 4);
        allocator.add(bin, parent_off + 32);
    }
    
    // member: lat, type: int32 (primitive)

    
    {
        const bin = PduUtils.typeToBin("int32", js_obj.lat, 4);
        allocator.add(bin, parent_off + 36);
    }
    
    // member: lon, type: int32 (primitive)

    
    {
        const bin = PduUtils.typeToBin("int32", js_obj.lon, 4);
        allocator.add(bin, parent_off + 40);
    }
    
    // member: alt, type: int32 (primitive)

    
    {
        const bin = PduUtils.typeToBin("int32", js_obj.alt, 4);
        allocator.add(bin, parent_off + 44);
    }
    
    // member: vx, type: int16 (primitive)

    
    {
        const bin = PduUtils.typeToBin("int16", js_obj.vx, 2);
        allocator.add(bin, parent_off + 48);
    }
    
    // member: vy, type: int16 (primitive)

    
    {
        const bin = PduUtils.typeToBin("int16", js_obj.vy, 2);
        allocator.add(bin, parent_off + 50);
    }
    
    // member: vz, type: int16 (primitive)

    
    {
        const bin = PduUtils.typeToBin("int16", js_obj.vz, 2);
        allocator.add(bin, parent_off + 52);
    }
    
    // member: ind_airspeed, type: uint16 (primitive)

    
    {
        const bin = PduUtils.typeToBin("uint16", js_obj.ind_airspeed, 2);
        allocator.add(bin, parent_off + 54);
    }
    
    // member: true_airspeed, type: uint16 (primitive)

    
    {
        const bin = PduUtils.typeToBin("uint16", js_obj.true_airspeed, 2);
        allocator.add(bin, parent_off + 56);
    }
    
    // member: xacc, type: int16 (primitive)

    
    {
        const bin = PduUtils.typeToBin("int16", js_obj.xacc, 2);
        allocator.add(bin, parent_off + 58);
    }
    
    // member: yacc, type: int16 (primitive)

    
    {
        const bin = PduUtils.typeToBin("int16", js_obj.yacc, 2);
        allocator.add(bin, parent_off + 60);
    }
    
    // member: zacc, type: int16 (primitive)

    
    {
        const bin = PduUtils.typeToBin("int16", js_obj.zacc, 2);
        allocator.add(bin, parent_off + 62);
    }
    
}
