import * as PduUtils from '../pdu_utils.js';
import { DisturbanceBoundary } from './pdu_jstype_DisturbanceBoundary.js';
import { Point } from '../geometry_msgs/pdu_jstype_Point.js';
import { binary_read_recursive_Point, binary_write_recursive_Point } from '../geometry_msgs/pdu_conv_Point.js';
import { Vector3 } from '../geometry_msgs/pdu_jstype_Vector3.js';
import { binary_read_recursive_Vector3, binary_write_recursive_Vector3 } from '../geometry_msgs/pdu_conv_Vector3.js';


/**
 * Deserializes a binary PDU into a DisturbanceBoundary object.
 * @param {ArrayBuffer} binary_data
 * @returns { DisturbanceBoundary }
 */
export function pduToJs_DisturbanceBoundary(binary_data) {
    const js_obj = new DisturbanceBoundary();
    const meta_parser = new PduUtils.PduMetaDataParser();
    const meta = meta_parser.load_pdu_meta(binary_data);
    if (meta === null) {
        throw new Error("Invalid PDU binary data: MetaData not found or corrupted");
    }
    binary_read_recursive_DisturbanceBoundary(meta, binary_data, js_obj, meta.base_off);
    return js_obj;
}

export function binary_read_recursive_DisturbanceBoundary(meta, binary_data, js_obj, base_off) {
    const view = new DataView(binary_data);
    const littleEndian = true;
    // member: boundary_point, type: geometry_msgs/Point (struct)

    {
        const tmp_obj = new Point();
        binary_read_recursive_Point(meta, binary_data, tmp_obj, base_off + 0);
        js_obj.boundary_point = tmp_obj;
    }
    
    // member: boundary_normal, type: geometry_msgs/Vector3 (struct)

    {
        const tmp_obj = new Vector3();
        binary_read_recursive_Vector3(meta, binary_data, tmp_obj, base_off + 24);
        js_obj.boundary_normal = tmp_obj;
    }
    
    return js_obj;
}

/**
 * Serializes a DisturbanceBoundary object into a binary PDU.
 * @param { DisturbanceBoundary } js_obj
 * @returns {ArrayBuffer}
 */
export function jsToPdu_DisturbanceBoundary(js_obj) {
    const base_allocator = new PduUtils.DynamicAllocator();
    const bw_container = new PduUtils.BinaryWriterContainer(new PduUtils.PduMetaData());

    binary_write_recursive_DisturbanceBoundary(0, bw_container, base_allocator, js_obj);

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

export function binary_write_recursive_DisturbanceBoundary(parent_off, bw_container, allocator, js_obj) {
    const littleEndian = true;
    // member: boundary_point, type: geometry_msgs/Point (struct)

    {
        binary_write_recursive_Point(parent_off + 0, bw_container, allocator, js_obj.boundary_point);
    }
    
    // member: boundary_normal, type: geometry_msgs/Vector3 (struct)

    {
        binary_write_recursive_Vector3(parent_off + 24, bw_container, allocator, js_obj.boundary_normal);
    }
    
}
