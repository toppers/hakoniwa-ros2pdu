import * as PduUtils from '../pdu_utils.js';
import { HakoHilActuatorControls } from './pdu_jstype_HakoHilActuatorControls.js';


/**
 * Deserializes a binary PDU into a HakoHilActuatorControls object.
 * @param {ArrayBuffer} binary_data
 * @returns { HakoHilActuatorControls }
 */
export function pduToJs_HakoHilActuatorControls(binary_data) {
    const js_obj = new HakoHilActuatorControls();
    const meta_parser = new PduUtils.PduMetaDataParser();
    const meta = meta_parser.load_pdu_meta(binary_data);
    if (meta === null) {
        throw new Error("Invalid PDU binary data: MetaData not found or corrupted");
    }
    binary_read_recursive_HakoHilActuatorControls(meta, binary_data, js_obj, meta.base_off);
    return js_obj;
}

export function binary_read_recursive_HakoHilActuatorControls(meta, binary_data, js_obj, base_off) {
    const view = new DataView(binary_data);
    const littleEndian = true;
    // member: time_usec, type: uint64 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 0, 8);
        js_obj.time_usec = PduUtils.binToValue("uint64", bin);
    }
    
    // member: controls, type: float32 (primitive)

    
    {
        const array_bin = PduUtils.readBinary(binary_data, base_off + 8, 64);
        js_obj.controls = PduUtils.binToArrayValues("float32", array_bin, 16);
    }
    
    // member: mode, type: uint8 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 72, 1);
        js_obj.mode = PduUtils.binToValue("uint8", bin);
    }
    
    // member: flags, type: uint64 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 80, 8);
        js_obj.flags = PduUtils.binToValue("uint64", bin);
    }
    
    return js_obj;
}

/**
 * Serializes a HakoHilActuatorControls object into a binary PDU.
 * @param { HakoHilActuatorControls } js_obj
 * @returns {ArrayBuffer}
 */
export function jsToPdu_HakoHilActuatorControls(js_obj) {
    const base_allocator = new PduUtils.DynamicAllocator();
    const bw_container = new PduUtils.BinaryWriterContainer(new PduUtils.PduMetaData());

    binary_write_recursive_HakoHilActuatorControls(0, bw_container, base_allocator, js_obj);

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

export function binary_write_recursive_HakoHilActuatorControls(parent_off, bw_container, allocator, js_obj) {
    const littleEndian = true;
    // member: time_usec, type: uint64 (primitive)

    
    {
        const bin = PduUtils.typeToBin("uint64", js_obj.time_usec, 8);
        allocator.add(bin, parent_off + 0);
    }
    
    // member: controls, type: float32 (primitive)

    
    {
        const buffer = PduUtils.typesToBin("float32", js_obj.controls);
        allocator.add(buffer, parent_off + 8);
    }
    
    // member: mode, type: uint8 (primitive)

    
    {
        const bin = PduUtils.typeToBin("uint8", js_obj.mode, 1);
        allocator.add(bin, parent_off + 72);
    }
    
    // member: flags, type: uint64 (primitive)

    
    {
        const bin = PduUtils.typeToBin("uint64", js_obj.flags, 8);
        allocator.add(bin, parent_off + 80);
    }
    
}
