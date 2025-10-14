import * as PduUtils from '../pdu_utils.js';
import { Disturbance } from './pdu_jstype_Disturbance.js';
import { DisturbanceTemperature } from './pdu_jstype_DisturbanceTemperature.js';
import { binary_read_recursive_DisturbanceTemperature, binary_write_recursive_DisturbanceTemperature } from './pdu_conv_DisturbanceTemperature.js';
import { DisturbanceWind } from './pdu_jstype_DisturbanceWind.js';
import { binary_read_recursive_DisturbanceWind, binary_write_recursive_DisturbanceWind } from './pdu_conv_DisturbanceWind.js';
import { DisturbanceAtm } from './pdu_jstype_DisturbanceAtm.js';
import { binary_read_recursive_DisturbanceAtm, binary_write_recursive_DisturbanceAtm } from './pdu_conv_DisturbanceAtm.js';
import { DisturbanceBoundary } from './pdu_jstype_DisturbanceBoundary.js';
import { binary_read_recursive_DisturbanceBoundary, binary_write_recursive_DisturbanceBoundary } from './pdu_conv_DisturbanceBoundary.js';
import { DisturbanceUserCustom } from './pdu_jstype_DisturbanceUserCustom.js';
import { binary_read_recursive_DisturbanceUserCustom, binary_write_recursive_DisturbanceUserCustom } from './pdu_conv_DisturbanceUserCustom.js';


/**
 * Deserializes a binary PDU into a Disturbance object.
 * @param {ArrayBuffer} binary_data
 * @returns { Disturbance }
 */
export function pduToJs_Disturbance(binary_data) {
    const js_obj = new Disturbance();
    const meta_parser = new PduUtils.PduMetaDataParser();
    const meta = meta_parser.load_pdu_meta(binary_data);
    if (meta === null) {
        throw new Error("Invalid PDU binary data: MetaData not found or corrupted");
    }
    binary_read_recursive_Disturbance(meta, binary_data, js_obj, meta.base_off);
    return js_obj;
}

export function binary_read_recursive_Disturbance(meta, binary_data, js_obj, base_off) {
    const view = new DataView(binary_data);
    const littleEndian = true;
    // member: d_temp, type: hako_msgs/DisturbanceTemperature (struct)

    {
        const tmp_obj = new DisturbanceTemperature();
        binary_read_recursive_DisturbanceTemperature(meta, binary_data, tmp_obj, base_off + 0);
        js_obj.d_temp = tmp_obj;
    }
    
    // member: d_wind, type: hako_msgs/DisturbanceWind (struct)

    {
        const tmp_obj = new DisturbanceWind();
        binary_read_recursive_DisturbanceWind(meta, binary_data, tmp_obj, base_off + 8);
        js_obj.d_wind = tmp_obj;
    }
    
    // member: d_atm, type: hako_msgs/DisturbanceAtm (struct)

    {
        const tmp_obj = new DisturbanceAtm();
        binary_read_recursive_DisturbanceAtm(meta, binary_data, tmp_obj, base_off + 32);
        js_obj.d_atm = tmp_obj;
    }
    
    // member: d_boundary, type: hako_msgs/DisturbanceBoundary (struct)

    {
        const tmp_obj = new DisturbanceBoundary();
        binary_read_recursive_DisturbanceBoundary(meta, binary_data, tmp_obj, base_off + 40);
        js_obj.d_boundary = tmp_obj;
    }
    
    // member: d_user_custom, type: hako_msgs/DisturbanceUserCustom (struct)

    { // varray
        const array_size = view.getInt32(base_off + 88, littleEndian);
        const offset_from_heap = view.getInt32(base_off + 88 + 4, littleEndian);
        const one_elm_size = 8;
        const array_value = [];
        for (let i = 0; i < array_size; i++) {
            const tmp_obj = new DisturbanceUserCustom();
            const item_offset = meta.heap_off + offset_from_heap + (i * one_elm_size);
            binary_read_recursive_DisturbanceUserCustom(meta, binary_data, tmp_obj, item_offset);
            array_value.push(tmp_obj);
        }
        js_obj.d_user_custom = array_value;
    }
    
    return js_obj;
}

/**
 * Serializes a Disturbance object into a binary PDU.
 * @param { Disturbance } js_obj
 * @returns {ArrayBuffer}
 */
export function jsToPdu_Disturbance(js_obj) {
    const base_allocator = new PduUtils.DynamicAllocator();
    const bw_container = new PduUtils.BinaryWriterContainer(new PduUtils.PduMetaData());

    binary_write_recursive_Disturbance(0, bw_container, base_allocator, js_obj);

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

export function binary_write_recursive_Disturbance(parent_off, bw_container, allocator, js_obj) {
    const littleEndian = true;
    // member: d_temp, type: hako_msgs/DisturbanceTemperature (struct)

    {
        binary_write_recursive_DisturbanceTemperature(parent_off + 0, bw_container, allocator, js_obj.d_temp);
    }
    
    // member: d_wind, type: hako_msgs/DisturbanceWind (struct)

    {
        binary_write_recursive_DisturbanceWind(parent_off + 8, bw_container, allocator, js_obj.d_wind);
    }
    
    // member: d_atm, type: hako_msgs/DisturbanceAtm (struct)

    {
        binary_write_recursive_DisturbanceAtm(parent_off + 32, bw_container, allocator, js_obj.d_atm);
    }
    
    // member: d_boundary, type: hako_msgs/DisturbanceBoundary (struct)

    {
        binary_write_recursive_DisturbanceBoundary(parent_off + 40, bw_container, allocator, js_obj.d_boundary);
    }
    
    // member: d_user_custom, type: hako_msgs/DisturbanceUserCustom (struct)

    { // varray
        const offset_from_heap = bw_container.heap_allocator.size();
        const one_elm_size = 8;
        for (const elm of js_obj.d_user_custom) {
            binary_write_recursive_DisturbanceUserCustom(0, bw_container, bw_container.heap_allocator, elm);
        }

        const ref_buffer = new ArrayBuffer(8);
        const ref_view = new DataView(ref_buffer);
        ref_view.setInt32(0, js_obj.d_user_custom.length, littleEndian); // array_size
        ref_view.setInt32(4, offset_from_heap, littleEndian);
        allocator.add(ref_buffer, parent_off + 88);
    }
    
}
