import * as PduUtils from '../pdu_utils.js';
import { DisturbanceWind } from './pdu_jstype_DisturbanceWind.js';
import { Vector3 } from '../geometry_msgs/pdu_jstype_Vector3.js';
import { binary_read_recursive_Vector3, binary_write_recursive_Vector3 } from '../geometry_msgs/pdu_conv_Vector3.js';


/**
 * Deserializes a binary PDU into a DisturbanceWind object.
 * @param {ArrayBuffer} binary_data
 * @returns { DisturbanceWind }
 */
export function pduToJs_DisturbanceWind(binary_data) {
    const js_obj = new DisturbanceWind();
    const meta_parser = new PduUtils.PduMetaDataParser();
    const meta = meta_parser.load_pdu_meta(binary_data);
    if (meta === null) {
        throw new Error("Invalid PDU binary data: MetaData not found or corrupted");
    }
    binary_read_recursive_DisturbanceWind(meta, binary_data, js_obj, meta.base_off);
    return js_obj;
}

export function binary_read_recursive_DisturbanceWind(meta, binary_data, js_obj, base_off) {
    const view = new DataView(binary_data);
    const littleEndian = true;
    // member: value, type: geometry_msgs/Vector3 (struct)

    {
        const tmp_obj = new Vector3();
        binary_read_recursive_Vector3(meta, binary_data, tmp_obj, base_off + 0);
        js_obj.value = tmp_obj;
    }
    
    return js_obj;
}

/**
 * Serializes a DisturbanceWind object into a binary PDU.
 * @param { DisturbanceWind } js_obj
 * @returns {ArrayBuffer}
 */
export function jsToPdu_DisturbanceWind(js_obj) {
    const base_allocator = new PduUtils.DynamicAllocator();
    const bw_container = new PduUtils.BinaryWriterContainer(new PduUtils.PduMetaData());

    binary_write_recursive_DisturbanceWind(0, bw_container, base_allocator, js_obj);

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

export function binary_write_recursive_DisturbanceWind(parent_off, bw_container, allocator, js_obj) {
    const littleEndian = true;
    // member: value, type: geometry_msgs/Vector3 (struct)

    {
        binary_write_recursive_Vector3(parent_off + 0, bw_container, allocator, js_obj.value);
    }
    
}
