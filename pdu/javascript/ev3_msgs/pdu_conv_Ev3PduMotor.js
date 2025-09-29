import * as PduUtils from '../pdu_utils.js';
import { Ev3PduMotor } from './pdu_jstype_Ev3PduMotor.js';


/**
 * Deserializes a binary PDU into a Ev3PduMotor object.
 * @param {ArrayBuffer} binary_data
 * @returns { Ev3PduMotor }
 */
export function pduToJs_Ev3PduMotor(binary_data) {
    const js_obj = new Ev3PduMotor();
    const meta_parser = new PduUtils.PduMetaDataParser();
    const meta = meta_parser.load_pdu_meta(binary_data);
    if (meta === null) {
        throw new Error("Invalid PDU binary data: MetaData not found or corrupted");
    }
    binary_read_recursive_Ev3PduMotor(meta, binary_data, js_obj, meta.base_off);
    return js_obj;
}

export function binary_read_recursive_Ev3PduMotor(meta, binary_data, js_obj, base_off) {
    const view = new DataView(binary_data);
    const littleEndian = true;
    // member: power, type: int32 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 0, 4);
        js_obj.power = PduUtils.binToValue("int32", bin);
    }
    
    // member: stop, type: uint32 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 4, 4);
        js_obj.stop = PduUtils.binToValue("uint32", bin);
    }
    
    // member: reset_angle, type: uint32 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 8, 4);
        js_obj.reset_angle = PduUtils.binToValue("uint32", bin);
    }
    
    return js_obj;
}

/**
 * Serializes a Ev3PduMotor object into a binary PDU.
 * @param { Ev3PduMotor } js_obj
 * @returns {ArrayBuffer}
 */
export function jsToPdu_Ev3PduMotor(js_obj) {
    const base_allocator = new PduUtils.DynamicAllocator();
    const bw_container = new PduUtils.BinaryWriterContainer(new PduUtils.PduMetaData());

    binary_write_recursive_Ev3PduMotor(0, bw_container, base_allocator, js_obj);

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

export function binary_write_recursive_Ev3PduMotor(parent_off, bw_container, allocator, js_obj) {
    const littleEndian = true;
    // member: power, type: int32 (primitive)

    
    {
        const bin = PduUtils.typeToBin("int32", js_obj.power, 4);
        allocator.add(bin, parent_off + 0);
    }
    
    // member: stop, type: uint32 (primitive)

    
    {
        const bin = PduUtils.typeToBin("uint32", js_obj.stop, 4);
        allocator.add(bin, parent_off + 4);
    }
    
    // member: reset_angle, type: uint32 (primitive)

    
    {
        const bin = PduUtils.typeToBin("uint32", js_obj.reset_angle, 4);
        allocator.add(bin, parent_off + 8);
    }
    
}
