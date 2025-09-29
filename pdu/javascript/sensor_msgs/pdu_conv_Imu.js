import * as PduUtils from '../pdu_utils.js';
import { Imu } from './pdu_jstype_Imu.js';
import { Header } from '../std_msgs/pdu_jstype_Header.js';
import { binary_read_recursive_Header, binary_write_recursive_Header } from '../std_msgs/pdu_conv_Header.js';
import { Quaternion } from '../geometry_msgs/pdu_jstype_Quaternion.js';
import { binary_read_recursive_Quaternion, binary_write_recursive_Quaternion } from '../geometry_msgs/pdu_conv_Quaternion.js';
import { Vector3 } from '../geometry_msgs/pdu_jstype_Vector3.js';
import { binary_read_recursive_Vector3, binary_write_recursive_Vector3 } from '../geometry_msgs/pdu_conv_Vector3.js';


/**
 * Deserializes a binary PDU into a Imu object.
 * @param {ArrayBuffer} binary_data
 * @returns { Imu }
 */
export function pduToJs_Imu(binary_data) {
    const js_obj = new Imu();
    const meta_parser = new PduUtils.PduMetaDataParser();
    const meta = meta_parser.load_pdu_meta(binary_data);
    if (meta === null) {
        throw new Error("Invalid PDU binary data: MetaData not found or corrupted");
    }
    binary_read_recursive_Imu(meta, binary_data, js_obj, meta.base_off);
    return js_obj;
}

export function binary_read_recursive_Imu(meta, binary_data, js_obj, base_off) {
    const view = new DataView(binary_data);
    const littleEndian = true;
    // member: header, type: std_msgs/Header (struct)

    {
        const tmp_obj = new Header();
        binary_read_recursive_Header(meta, binary_data, tmp_obj, base_off + 0);
        js_obj.header = tmp_obj;
    }
    
    // member: orientation, type: geometry_msgs/Quaternion (struct)

    {
        const tmp_obj = new Quaternion();
        binary_read_recursive_Quaternion(meta, binary_data, tmp_obj, base_off + 136);
        js_obj.orientation = tmp_obj;
    }
    
    // member: orientation_covariance, type: float64 (primitive)

    
    {
        const array_bin = PduUtils.readBinary(binary_data, base_off + 168, 72);
        js_obj.orientation_covariance = PduUtils.binToArrayValues("float64", array_bin, 9);
    }
    
    // member: angular_velocity, type: geometry_msgs/Vector3 (struct)

    {
        const tmp_obj = new Vector3();
        binary_read_recursive_Vector3(meta, binary_data, tmp_obj, base_off + 240);
        js_obj.angular_velocity = tmp_obj;
    }
    
    // member: angular_velocity_covariance, type: float64 (primitive)

    
    {
        const array_bin = PduUtils.readBinary(binary_data, base_off + 264, 72);
        js_obj.angular_velocity_covariance = PduUtils.binToArrayValues("float64", array_bin, 9);
    }
    
    // member: linear_acceleration, type: geometry_msgs/Vector3 (struct)

    {
        const tmp_obj = new Vector3();
        binary_read_recursive_Vector3(meta, binary_data, tmp_obj, base_off + 336);
        js_obj.linear_acceleration = tmp_obj;
    }
    
    // member: linear_acceleration_covariance, type: float64 (primitive)

    
    {
        const array_bin = PduUtils.readBinary(binary_data, base_off + 360, 72);
        js_obj.linear_acceleration_covariance = PduUtils.binToArrayValues("float64", array_bin, 9);
    }
    
    return js_obj;
}

/**
 * Serializes a Imu object into a binary PDU.
 * @param { Imu } js_obj
 * @returns {ArrayBuffer}
 */
export function jsToPdu_Imu(js_obj) {
    const base_allocator = new PduUtils.DynamicAllocator();
    const bw_container = new PduUtils.BinaryWriterContainer(new PduUtils.PduMetaData());

    binary_write_recursive_Imu(0, bw_container, base_allocator, js_obj);

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

export function binary_write_recursive_Imu(parent_off, bw_container, allocator, js_obj) {
    const littleEndian = true;
    // member: header, type: std_msgs/Header (struct)

    {
        binary_write_recursive_Header(parent_off + 0, bw_container, allocator, js_obj.header);
    }
    
    // member: orientation, type: geometry_msgs/Quaternion (struct)

    {
        binary_write_recursive_Quaternion(parent_off + 136, bw_container, allocator, js_obj.orientation);
    }
    
    // member: orientation_covariance, type: float64 (primitive)

    
    {
        const buffer = PduUtils.typesToBin("float64", js_obj.orientation_covariance);
        allocator.add(buffer, parent_off + 168);
    }
    
    // member: angular_velocity, type: geometry_msgs/Vector3 (struct)

    {
        binary_write_recursive_Vector3(parent_off + 240, bw_container, allocator, js_obj.angular_velocity);
    }
    
    // member: angular_velocity_covariance, type: float64 (primitive)

    
    {
        const buffer = PduUtils.typesToBin("float64", js_obj.angular_velocity_covariance);
        allocator.add(buffer, parent_off + 264);
    }
    
    // member: linear_acceleration, type: geometry_msgs/Vector3 (struct)

    {
        binary_write_recursive_Vector3(parent_off + 336, bw_container, allocator, js_obj.linear_acceleration);
    }
    
    // member: linear_acceleration_covariance, type: float64 (primitive)

    
    {
        const buffer = PduUtils.typesToBin("float64", js_obj.linear_acceleration_covariance);
        allocator.add(buffer, parent_off + 360);
    }
    
}
