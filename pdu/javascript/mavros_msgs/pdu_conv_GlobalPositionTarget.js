import * as PduUtils from '../pdu_utils.js';
import { GlobalPositionTarget } from './pdu_jstype_GlobalPositionTarget.js';
import { Header } from '../std_msgs/pdu_jstype_Header.js';
import { binary_read_recursive_Header, binary_write_recursive_Header } from '../std_msgs/pdu_conv_Header.js';
import { Vector3 } from '../geometry_msgs/pdu_jstype_Vector3.js';
import { binary_read_recursive_Vector3, binary_write_recursive_Vector3 } from '../geometry_msgs/pdu_conv_Vector3.js';


/**
 * Deserializes a binary PDU into a GlobalPositionTarget object.
 * @param {ArrayBuffer} binary_data
 * @returns { GlobalPositionTarget }
 */
export function pduToJs_GlobalPositionTarget(binary_data) {
    const js_obj = new GlobalPositionTarget();
    const meta_parser = new PduUtils.PduMetaDataParser();
    const meta = meta_parser.load_pdu_meta(binary_data);
    if (meta === null) {
        throw new Error("Invalid PDU binary data: MetaData not found or corrupted");
    }
    binary_read_recursive_GlobalPositionTarget(meta, binary_data, js_obj, meta.base_off);
    return js_obj;
}

export function binary_read_recursive_GlobalPositionTarget(meta, binary_data, js_obj, base_off) {
    const view = new DataView(binary_data);
    const littleEndian = true;
    // member: header, type: std_msgs/Header (struct)

    {
        const tmp_obj = new Header();
        binary_read_recursive_Header(meta, binary_data, tmp_obj, base_off + 0);
        js_obj.header = tmp_obj;
    }
    
    // member: coordinate_frame, type: uint8 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 136, 1);
        js_obj.coordinate_frame = PduUtils.binToValue("uint8", bin);
    }
    
    // member: type_mask, type: uint16 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 138, 2);
        js_obj.type_mask = PduUtils.binToValue("uint16", bin);
    }
    
    // member: latitude, type: float64 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 144, 8);
        js_obj.latitude = PduUtils.binToValue("float64", bin);
    }
    
    // member: longitude, type: float64 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 152, 8);
        js_obj.longitude = PduUtils.binToValue("float64", bin);
    }
    
    // member: altitude, type: float32 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 160, 4);
        js_obj.altitude = PduUtils.binToValue("float32", bin);
    }
    
    // member: velocity, type: geometry_msgs/Vector3 (struct)

    {
        const tmp_obj = new Vector3();
        binary_read_recursive_Vector3(meta, binary_data, tmp_obj, base_off + 168);
        js_obj.velocity = tmp_obj;
    }
    
    // member: acceleration_or_force, type: geometry_msgs/Vector3 (struct)

    {
        const tmp_obj = new Vector3();
        binary_read_recursive_Vector3(meta, binary_data, tmp_obj, base_off + 192);
        js_obj.acceleration_or_force = tmp_obj;
    }
    
    // member: yaw, type: float32 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 216, 4);
        js_obj.yaw = PduUtils.binToValue("float32", bin);
    }
    
    // member: yaw_rate, type: float32 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 220, 4);
        js_obj.yaw_rate = PduUtils.binToValue("float32", bin);
    }
    
    return js_obj;
}

/**
 * Serializes a GlobalPositionTarget object into a binary PDU.
 * @param { GlobalPositionTarget } js_obj
 * @returns {ArrayBuffer}
 */
export function jsToPdu_GlobalPositionTarget(js_obj) {
    const base_allocator = new PduUtils.DynamicAllocator();
    const bw_container = new PduUtils.BinaryWriterContainer(new PduUtils.PduMetaData());

    binary_write_recursive_GlobalPositionTarget(0, bw_container, base_allocator, js_obj);

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

export function binary_write_recursive_GlobalPositionTarget(parent_off, bw_container, allocator, js_obj) {
    const littleEndian = true;
    // member: header, type: std_msgs/Header (struct)

    {
        binary_write_recursive_Header(parent_off + 0, bw_container, allocator, js_obj.header);
    }
    
    // member: coordinate_frame, type: uint8 (primitive)

    
    {
        const bin = PduUtils.typeToBin("uint8", js_obj.coordinate_frame, 1);
        allocator.add(bin, parent_off + 136);
    }
    
    // member: type_mask, type: uint16 (primitive)

    
    {
        const bin = PduUtils.typeToBin("uint16", js_obj.type_mask, 2);
        allocator.add(bin, parent_off + 138);
    }
    
    // member: latitude, type: float64 (primitive)

    
    {
        const bin = PduUtils.typeToBin("float64", js_obj.latitude, 8);
        allocator.add(bin, parent_off + 144);
    }
    
    // member: longitude, type: float64 (primitive)

    
    {
        const bin = PduUtils.typeToBin("float64", js_obj.longitude, 8);
        allocator.add(bin, parent_off + 152);
    }
    
    // member: altitude, type: float32 (primitive)

    
    {
        const bin = PduUtils.typeToBin("float32", js_obj.altitude, 4);
        allocator.add(bin, parent_off + 160);
    }
    
    // member: velocity, type: geometry_msgs/Vector3 (struct)

    {
        binary_write_recursive_Vector3(parent_off + 168, bw_container, allocator, js_obj.velocity);
    }
    
    // member: acceleration_or_force, type: geometry_msgs/Vector3 (struct)

    {
        binary_write_recursive_Vector3(parent_off + 192, bw_container, allocator, js_obj.acceleration_or_force);
    }
    
    // member: yaw, type: float32 (primitive)

    
    {
        const bin = PduUtils.typeToBin("float32", js_obj.yaw, 4);
        allocator.add(bin, parent_off + 216);
    }
    
    // member: yaw_rate, type: float32 (primitive)

    
    {
        const bin = PduUtils.typeToBin("float32", js_obj.yaw_rate, 4);
        allocator.add(bin, parent_off + 220);
    }
    
}
