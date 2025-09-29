import * as PduUtils from '../pdu_utils.js';
import { ImpulseCollision } from './pdu_jstype_ImpulseCollision.js';
import { Point } from '../geometry_msgs/pdu_jstype_Point.js';
import { binary_read_recursive_Point, binary_write_recursive_Point } from '../geometry_msgs/pdu_conv_Point.js';
import { Vector3 } from '../geometry_msgs/pdu_jstype_Vector3.js';
import { binary_read_recursive_Vector3, binary_write_recursive_Vector3 } from '../geometry_msgs/pdu_conv_Vector3.js';


/**
 * Deserializes a binary PDU into a ImpulseCollision object.
 * @param {ArrayBuffer} binary_data
 * @returns { ImpulseCollision }
 */
export function pduToJs_ImpulseCollision(binary_data) {
    const js_obj = new ImpulseCollision();
    const meta_parser = new PduUtils.PduMetaDataParser();
    const meta = meta_parser.load_pdu_meta(binary_data);
    if (meta === null) {
        throw new Error("Invalid PDU binary data: MetaData not found or corrupted");
    }
    binary_read_recursive_ImpulseCollision(meta, binary_data, js_obj, meta.base_off);
    return js_obj;
}

export function binary_read_recursive_ImpulseCollision(meta, binary_data, js_obj, base_off) {
    const view = new DataView(binary_data);
    const littleEndian = true;
    // member: collision, type: bool (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 0, 4);
        js_obj.collision = PduUtils.binToValue("bool", bin);
    }
    
    // member: is_target_static, type: bool (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 4, 4);
        js_obj.is_target_static = PduUtils.binToValue("bool", bin);
    }
    
    // member: restitution_coefficient, type: float64 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 8, 8);
        js_obj.restitution_coefficient = PduUtils.binToValue("float64", bin);
    }
    
    // member: self_contact_vector, type: geometry_msgs/Point (struct)

    {
        const tmp_obj = new Point();
        binary_read_recursive_Point(meta, binary_data, tmp_obj, base_off + 16);
        js_obj.self_contact_vector = tmp_obj;
    }
    
    // member: normal, type: geometry_msgs/Vector3 (struct)

    {
        const tmp_obj = new Vector3();
        binary_read_recursive_Vector3(meta, binary_data, tmp_obj, base_off + 40);
        js_obj.normal = tmp_obj;
    }
    
    // member: target_contact_vector, type: geometry_msgs/Point (struct)

    {
        const tmp_obj = new Point();
        binary_read_recursive_Point(meta, binary_data, tmp_obj, base_off + 64);
        js_obj.target_contact_vector = tmp_obj;
    }
    
    // member: target_velocity, type: geometry_msgs/Vector3 (struct)

    {
        const tmp_obj = new Vector3();
        binary_read_recursive_Vector3(meta, binary_data, tmp_obj, base_off + 88);
        js_obj.target_velocity = tmp_obj;
    }
    
    // member: target_angular_velocity, type: geometry_msgs/Vector3 (struct)

    {
        const tmp_obj = new Vector3();
        binary_read_recursive_Vector3(meta, binary_data, tmp_obj, base_off + 112);
        js_obj.target_angular_velocity = tmp_obj;
    }
    
    // member: target_euler, type: geometry_msgs/Vector3 (struct)

    {
        const tmp_obj = new Vector3();
        binary_read_recursive_Vector3(meta, binary_data, tmp_obj, base_off + 136);
        js_obj.target_euler = tmp_obj;
    }
    
    // member: target_inertia, type: geometry_msgs/Vector3 (struct)

    {
        const tmp_obj = new Vector3();
        binary_read_recursive_Vector3(meta, binary_data, tmp_obj, base_off + 160);
        js_obj.target_inertia = tmp_obj;
    }
    
    // member: target_mass, type: float64 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 184, 8);
        js_obj.target_mass = PduUtils.binToValue("float64", bin);
    }
    
    return js_obj;
}

/**
 * Serializes a ImpulseCollision object into a binary PDU.
 * @param { ImpulseCollision } js_obj
 * @returns {ArrayBuffer}
 */
export function jsToPdu_ImpulseCollision(js_obj) {
    const base_allocator = new PduUtils.DynamicAllocator();
    const bw_container = new PduUtils.BinaryWriterContainer(new PduUtils.PduMetaData());

    binary_write_recursive_ImpulseCollision(0, bw_container, base_allocator, js_obj);

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

export function binary_write_recursive_ImpulseCollision(parent_off, bw_container, allocator, js_obj) {
    const littleEndian = true;
    // member: collision, type: bool (primitive)

    
    {
        const bin = PduUtils.typeToBin("bool", js_obj.collision, 4);
        allocator.add(bin, parent_off + 0);
    }
    
    // member: is_target_static, type: bool (primitive)

    
    {
        const bin = PduUtils.typeToBin("bool", js_obj.is_target_static, 4);
        allocator.add(bin, parent_off + 4);
    }
    
    // member: restitution_coefficient, type: float64 (primitive)

    
    {
        const bin = PduUtils.typeToBin("float64", js_obj.restitution_coefficient, 8);
        allocator.add(bin, parent_off + 8);
    }
    
    // member: self_contact_vector, type: geometry_msgs/Point (struct)

    {
        binary_write_recursive_Point(parent_off + 16, bw_container, allocator, js_obj.self_contact_vector);
    }
    
    // member: normal, type: geometry_msgs/Vector3 (struct)

    {
        binary_write_recursive_Vector3(parent_off + 40, bw_container, allocator, js_obj.normal);
    }
    
    // member: target_contact_vector, type: geometry_msgs/Point (struct)

    {
        binary_write_recursive_Point(parent_off + 64, bw_container, allocator, js_obj.target_contact_vector);
    }
    
    // member: target_velocity, type: geometry_msgs/Vector3 (struct)

    {
        binary_write_recursive_Vector3(parent_off + 88, bw_container, allocator, js_obj.target_velocity);
    }
    
    // member: target_angular_velocity, type: geometry_msgs/Vector3 (struct)

    {
        binary_write_recursive_Vector3(parent_off + 112, bw_container, allocator, js_obj.target_angular_velocity);
    }
    
    // member: target_euler, type: geometry_msgs/Vector3 (struct)

    {
        binary_write_recursive_Vector3(parent_off + 136, bw_container, allocator, js_obj.target_euler);
    }
    
    // member: target_inertia, type: geometry_msgs/Vector3 (struct)

    {
        binary_write_recursive_Vector3(parent_off + 160, bw_container, allocator, js_obj.target_inertia);
    }
    
    // member: target_mass, type: float64 (primitive)

    
    {
        const bin = PduUtils.typeToBin("float64", js_obj.target_mass, 8);
        allocator.add(bin, parent_off + 184);
    }
    
}
