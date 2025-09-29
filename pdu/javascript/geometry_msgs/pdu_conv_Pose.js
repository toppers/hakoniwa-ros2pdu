import * as PduUtils from '../pdu_utils.js';
import { Pose } from './pdu_jstype_Pose.js';
import { Point } from './pdu_jstype_Point.js';
import { binary_read_recursive_Point, binary_write_recursive_Point } from './pdu_conv_Point.js';
import { Quaternion } from './pdu_jstype_Quaternion.js';
import { binary_read_recursive_Quaternion, binary_write_recursive_Quaternion } from './pdu_conv_Quaternion.js';


/**
 * Deserializes a binary PDU into a Pose object.
 * @param {ArrayBuffer} binary_data
 * @returns { Pose }
 */
export function pduToJs_Pose(binary_data) {
    const js_obj = new Pose();
    const meta_parser = new PduUtils.PduMetaDataParser();
    const meta = meta_parser.load_pdu_meta(binary_data);
    if (meta === null) {
        throw new Error("Invalid PDU binary data: MetaData not found or corrupted");
    }
    binary_read_recursive_Pose(meta, binary_data, js_obj, meta.base_off);
    return js_obj;
}

export function binary_read_recursive_Pose(meta, binary_data, js_obj, base_off) {
    const view = new DataView(binary_data);
    const littleEndian = true;
    // member: position, type: Point (struct)

    {
        const tmp_obj = new Point();
        binary_read_recursive_Point(meta, binary_data, tmp_obj, base_off + 0);
        js_obj.position = tmp_obj;
    }
    
    // member: orientation, type: Quaternion (struct)

    {
        const tmp_obj = new Quaternion();
        binary_read_recursive_Quaternion(meta, binary_data, tmp_obj, base_off + 24);
        js_obj.orientation = tmp_obj;
    }
    
    return js_obj;
}

/**
 * Serializes a Pose object into a binary PDU.
 * @param { Pose } js_obj
 * @returns {ArrayBuffer}
 */
export function jsToPdu_Pose(js_obj) {
    const base_allocator = new PduUtils.DynamicAllocator();
    const bw_container = new PduUtils.BinaryWriterContainer(new PduUtils.PduMetaData());

    binary_write_recursive_Pose(0, bw_container, base_allocator, js_obj);

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

export function binary_write_recursive_Pose(parent_off, bw_container, allocator, js_obj) {
    const littleEndian = true;
    // member: position, type: Point (struct)

    {
        binary_write_recursive_Point(parent_off + 0, bw_container, allocator, js_obj.position);
    }
    
    // member: orientation, type: Quaternion (struct)

    {
        binary_write_recursive_Quaternion(parent_off + 24, bw_container, allocator, js_obj.orientation);
    }
    
}
