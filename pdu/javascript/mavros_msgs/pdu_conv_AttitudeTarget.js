import * as PduUtils from '../pdu_utils.js';
import { AttitudeTarget } from './pdu_jstype_AttitudeTarget.js';
import { Header } from '../std_msgs/pdu_jstype_Header.js';
import { binary_read_recursive_Header, binary_write_recursive_Header } from '../std_msgs/pdu_conv_Header.js';
import { Quaternion } from '../geometry_msgs/pdu_jstype_Quaternion.js';
import { binary_read_recursive_Quaternion, binary_write_recursive_Quaternion } from '../geometry_msgs/pdu_conv_Quaternion.js';
import { Vector3 } from '../geometry_msgs/pdu_jstype_Vector3.js';
import { binary_read_recursive_Vector3, binary_write_recursive_Vector3 } from '../geometry_msgs/pdu_conv_Vector3.js';


/**
 * Deserializes a binary PDU into a AttitudeTarget object.
 * @param {ArrayBuffer} binary_data
 * @returns { AttitudeTarget }
 */
export function pduToJs_AttitudeTarget(binary_data) {
    const js_obj = new AttitudeTarget();
    const meta_parser = new PduUtils.PduMetaDataParser();
    const meta = meta_parser.load_pdu_meta(binary_data);
    if (meta === null) {
        throw new Error("Invalid PDU binary data: MetaData not found or corrupted");
    }
    binary_read_recursive_AttitudeTarget(meta, binary_data, js_obj, meta.base_off);
    return js_obj;
}

export function binary_read_recursive_AttitudeTarget(meta, binary_data, js_obj, base_off) {
    const view = new DataView(binary_data);
    const littleEndian = true;
    // member: header, type: std_msgs/Header (struct)

    {
        const tmp_obj = new Header();
        binary_read_recursive_Header(meta, binary_data, tmp_obj, base_off + 0);
        js_obj.header = tmp_obj;
    }
    
    // member: type_mask, type: uint8 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 136, 1);
        js_obj.type_mask = PduUtils.binToValue("uint8", bin);
    }
    
    // member: orientation, type: geometry_msgs/Quaternion (struct)

    {
        const tmp_obj = new Quaternion();
        binary_read_recursive_Quaternion(meta, binary_data, tmp_obj, base_off + 144);
        js_obj.orientation = tmp_obj;
    }
    
    // member: body_rate, type: geometry_msgs/Vector3 (struct)

    {
        const tmp_obj = new Vector3();
        binary_read_recursive_Vector3(meta, binary_data, tmp_obj, base_off + 176);
        js_obj.body_rate = tmp_obj;
    }
    
    // member: thrust, type: float32 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 200, 4);
        js_obj.thrust = PduUtils.binToValue("float32", bin);
    }
    
    return js_obj;
}

/**
 * Serializes a AttitudeTarget object into a binary PDU.
 * @param { AttitudeTarget } js_obj
 * @returns {ArrayBuffer}
 */
export function jsToPdu_AttitudeTarget(js_obj) {
    const base_allocator = new PduUtils.DynamicAllocator();
    const bw_container = new PduUtils.BinaryWriterContainer(new PduUtils.PduMetaData());

    binary_write_recursive_AttitudeTarget(0, bw_container, base_allocator, js_obj);

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

export function binary_write_recursive_AttitudeTarget(parent_off, bw_container, allocator, js_obj) {
    const littleEndian = true;
    // member: header, type: std_msgs/Header (struct)

    {
        binary_write_recursive_Header(parent_off + 0, bw_container, allocator, js_obj.header);
    }
    
    // member: type_mask, type: uint8 (primitive)

    
    {
        const bin = PduUtils.typeToBin("uint8", js_obj.type_mask, 1);
        allocator.add(bin, parent_off + 136);
    }
    
    // member: orientation, type: geometry_msgs/Quaternion (struct)

    {
        binary_write_recursive_Quaternion(parent_off + 144, bw_container, allocator, js_obj.orientation);
    }
    
    // member: body_rate, type: geometry_msgs/Vector3 (struct)

    {
        binary_write_recursive_Vector3(parent_off + 176, bw_container, allocator, js_obj.body_rate);
    }
    
    // member: thrust, type: float32 (primitive)

    
    {
        const bin = PduUtils.typeToBin("float32", js_obj.thrust, 4);
        allocator.add(bin, parent_off + 200);
    }
    
}
