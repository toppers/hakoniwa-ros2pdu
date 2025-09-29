import * as PduUtils from '../pdu_utils.js';
import { Collision } from './pdu_jstype_Collision.js';
import { Vector3 } from '../geometry_msgs/pdu_jstype_Vector3.js';
import { binary_read_recursive_Vector3, binary_write_recursive_Vector3 } from '../geometry_msgs/pdu_conv_Vector3.js';
import { Point } from '../geometry_msgs/pdu_jstype_Point.js';
import { binary_read_recursive_Point, binary_write_recursive_Point } from '../geometry_msgs/pdu_conv_Point.js';


/**
 * Deserializes a binary PDU into a Collision object.
 * @param {ArrayBuffer} binary_data
 * @returns { Collision }
 */
export function pduToJs_Collision(binary_data) {
    const js_obj = new Collision();
    const meta_parser = new PduUtils.PduMetaDataParser();
    const meta = meta_parser.load_pdu_meta(binary_data);
    if (meta === null) {
        throw new Error("Invalid PDU binary data: MetaData not found or corrupted");
    }
    binary_read_recursive_Collision(meta, binary_data, js_obj, meta.base_off);
    return js_obj;
}

export function binary_read_recursive_Collision(meta, binary_data, js_obj, base_off) {
    const view = new DataView(binary_data);
    const littleEndian = true;
    // member: collision, type: bool (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 0, 4);
        js_obj.collision = PduUtils.binToValue("bool", bin);
    }
    
    // member: contact_num, type: uint32 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 4, 4);
        js_obj.contact_num = PduUtils.binToValue("uint32", bin);
    }
    
    // member: relative_velocity, type: geometry_msgs/Vector3 (struct)

    {
        const tmp_obj = new Vector3();
        binary_read_recursive_Vector3(meta, binary_data, tmp_obj, base_off + 8);
        js_obj.relative_velocity = tmp_obj;
    }
    
    // member: contact_position, type: geometry_msgs/Point (struct)

    {
        const array_size = 10;
        const one_elm_size = 240 / array_size;
        const array_value = [];
        for (let i = 0; i < array_size; i++) {
            const tmp_obj = new Point();
            const item_offset = base_off + 32 + (i * one_elm_size);
            binary_read_recursive_Point(meta, binary_data, tmp_obj, item_offset);
            array_value.push(tmp_obj);
        }
        js_obj.contact_position = array_value;
    }
    
    // member: restitution_coefficient, type: float64 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 272, 8);
        js_obj.restitution_coefficient = PduUtils.binToValue("float64", bin);
    }
    
    return js_obj;
}

/**
 * Serializes a Collision object into a binary PDU.
 * @param { Collision } js_obj
 * @returns {ArrayBuffer}
 */
export function jsToPdu_Collision(js_obj) {
    const base_allocator = new PduUtils.DynamicAllocator();
    const bw_container = new PduUtils.BinaryWriterContainer(new PduUtils.PduMetaData());

    binary_write_recursive_Collision(0, bw_container, base_allocator, js_obj);

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

export function binary_write_recursive_Collision(parent_off, bw_container, allocator, js_obj) {
    const littleEndian = true;
    // member: collision, type: bool (primitive)

    
    {
        const bin = PduUtils.typeToBin("bool", js_obj.collision, 4);
        allocator.add(bin, parent_off + 0);
    }
    
    // member: contact_num, type: uint32 (primitive)

    
    {
        const bin = PduUtils.typeToBin("uint32", js_obj.contact_num, 4);
        allocator.add(bin, parent_off + 4);
    }
    
    // member: relative_velocity, type: geometry_msgs/Vector3 (struct)

    {
        binary_write_recursive_Vector3(parent_off + 8, bw_container, allocator, js_obj.relative_velocity);
    }
    
    // member: contact_position, type: geometry_msgs/Point (struct)

    {
        const one_elm_size = 240 / 10;
        for (let i = 0; i < 10; i++) {
            binary_write_recursive_Point(parent_off + 32 + (i * one_elm_size), bw_container, allocator, js_obj.contact_position[i]);
        }
    }
    
    // member: restitution_coefficient, type: float64 (primitive)

    
    {
        const bin = PduUtils.typeToBin("float64", js_obj.restitution_coefficient, 8);
        allocator.add(bin, parent_off + 272);
    }
    
}
