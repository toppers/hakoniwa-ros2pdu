import * as PduUtils from '../pdu_utils.js';
import { Ev3PduActuator } from './pdu_jstype_Ev3PduActuator.js';
import { Ev3PduActuatorHeader } from './pdu_jstype_Ev3PduActuatorHeader.js';
import { binary_read_recursive_Ev3PduActuatorHeader, binary_write_recursive_Ev3PduActuatorHeader } from './pdu_conv_Ev3PduActuatorHeader.js';
import { Ev3PduMotor } from './pdu_jstype_Ev3PduMotor.js';
import { binary_read_recursive_Ev3PduMotor, binary_write_recursive_Ev3PduMotor } from './pdu_conv_Ev3PduMotor.js';


/**
 * Deserializes a binary PDU into a Ev3PduActuator object.
 * @param {ArrayBuffer} binary_data
 * @returns { Ev3PduActuator }
 */
export function pduToJs_Ev3PduActuator(binary_data) {
    const js_obj = new Ev3PduActuator();
    const meta_parser = new PduUtils.PduMetaDataParser();
    const meta = meta_parser.load_pdu_meta(binary_data);
    if (meta === null) {
        throw new Error("Invalid PDU binary data: MetaData not found or corrupted");
    }
    binary_read_recursive_Ev3PduActuator(meta, binary_data, js_obj, meta.base_off);
    return js_obj;
}

export function binary_read_recursive_Ev3PduActuator(meta, binary_data, js_obj, base_off) {
    const view = new DataView(binary_data);
    const littleEndian = true;
    // member: head, type: Ev3PduActuatorHeader (struct)

    {
        const tmp_obj = new Ev3PduActuatorHeader();
        binary_read_recursive_Ev3PduActuatorHeader(meta, binary_data, tmp_obj, base_off + 0);
        js_obj.head = tmp_obj;
    }
    
    // member: leds, type: uint8 (primitive)

    
    {
        const array_bin = PduUtils.readBinary(binary_data, base_off + 152, 1);
        js_obj.leds = PduUtils.binToArrayValues("uint8", array_bin, 1);
    }
    
    // member: motors, type: Ev3PduMotor (struct)

    {
        const array_size = 3;
        const one_elm_size = 36 / array_size;
        const array_value = [];
        for (let i = 0; i < array_size; i++) {
            const tmp_obj = new Ev3PduMotor();
            const item_offset = base_off + 156 + (i * one_elm_size);
            binary_read_recursive_Ev3PduMotor(meta, binary_data, tmp_obj, item_offset);
            array_value.push(tmp_obj);
        }
        js_obj.motors = array_value;
    }
    
    // member: gyro_reset, type: uint32 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 192, 4);
        js_obj.gyro_reset = PduUtils.binToValue("uint32", bin);
    }
    
    return js_obj;
}

/**
 * Serializes a Ev3PduActuator object into a binary PDU.
 * @param { Ev3PduActuator } js_obj
 * @returns {ArrayBuffer}
 */
export function jsToPdu_Ev3PduActuator(js_obj) {
    const base_allocator = new PduUtils.DynamicAllocator();
    const bw_container = new PduUtils.BinaryWriterContainer(new PduUtils.PduMetaData());

    binary_write_recursive_Ev3PduActuator(0, bw_container, base_allocator, js_obj);

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

export function binary_write_recursive_Ev3PduActuator(parent_off, bw_container, allocator, js_obj) {
    const littleEndian = true;
    // member: head, type: Ev3PduActuatorHeader (struct)

    {
        binary_write_recursive_Ev3PduActuatorHeader(parent_off + 0, bw_container, allocator, js_obj.head);
    }
    
    // member: leds, type: uint8 (primitive)

    
    {
        const buffer = PduUtils.typesToBin("uint8", js_obj.leds);
        allocator.add(buffer, parent_off + 152);
    }
    
    // member: motors, type: Ev3PduMotor (struct)

    {
        const one_elm_size = 36 / 3;
        for (let i = 0; i < 3; i++) {
            binary_write_recursive_Ev3PduMotor(parent_off + 156 + (i * one_elm_size), bw_container, allocator, js_obj.motors[i]);
        }
    }
    
    // member: gyro_reset, type: uint32 (primitive)

    
    {
        const bin = PduUtils.typeToBin("uint32", js_obj.gyro_reset, 4);
        allocator.add(bin, parent_off + 192);
    }
    
}
