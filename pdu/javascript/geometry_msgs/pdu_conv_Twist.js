import * as PduUtils from '../pdu_utils.js';
import { Twist } from './pdu_jstype_Twist.js';
import { Vector3 } from './pdu_jstype_Vector3.js';
import { binary_read_recursive_Vector3, binary_write_recursive_Vector3 } from './pdu_conv_Vector3.js';


/**
 * Deserializes a binary PDU into a Twist object.
 * @param {ArrayBuffer} binary_data
 * @returns { Twist }
 */
export function pduToJs_Twist(binary_data) {
    const js_obj = new Twist();
    const meta_parser = new PduUtils.PduMetaDataParser();
    const meta = meta_parser.load_pdu_meta(binary_data);
    if (meta === null) {
        throw new Error("Invalid PDU binary data: MetaData not found or corrupted");
    }
    binary_read_recursive_Twist(meta, binary_data, js_obj, meta.base_off);
    return js_obj;
}

export function binary_read_recursive_Twist(meta, binary_data, js_obj, base_off) {
    const view = new DataView(binary_data);
    const littleEndian = true;
    // member: linear, type: Vector3 (struct)

    {
        const tmp_obj = new Vector3();
        binary_read_recursive_Vector3(meta, binary_data, tmp_obj, base_off + 0);
        js_obj.linear = tmp_obj;
    }
    
    // member: angular, type: Vector3 (struct)

    {
        const tmp_obj = new Vector3();
        binary_read_recursive_Vector3(meta, binary_data, tmp_obj, base_off + 24);
        js_obj.angular = tmp_obj;
    }
    
    return js_obj;
}

/**
 * Serializes a Twist object into a binary PDU.
 * @param { Twist } js_obj
 * @returns {ArrayBuffer}
 */
export function jsToPdu_Twist(js_obj) {
    const base_allocator = new PduUtils.DynamicAllocator();
    const bw_container = new PduUtils.BinaryWriterContainer(new PduUtils.PduMetaData());

    binary_write_recursive_Twist(0, bw_container, base_allocator, js_obj);

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

export function binary_write_recursive_Twist(parent_off, bw_container, allocator, js_obj) {
    const littleEndian = true;
    // member: linear, type: Vector3 (struct)

    {
        binary_write_recursive_Vector3(parent_off + 0, bw_container, allocator, js_obj.linear);
    }
    
    // member: angular, type: Vector3 (struct)

    {
        binary_write_recursive_Vector3(parent_off + 24, bw_container, allocator, js_obj.angular);
    }
    
}
