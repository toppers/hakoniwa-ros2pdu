import * as PduUtils from '../pdu_utils.js';
import { HakoBatteryStatus } from './pdu_jstype_HakoBatteryStatus.js';


/**
 * Deserializes a binary PDU into a HakoBatteryStatus object.
 * @param {ArrayBuffer} binary_data
 * @returns { HakoBatteryStatus }
 */
export function pduToJs_HakoBatteryStatus(binary_data) {
    const js_obj = new HakoBatteryStatus();
    const meta_parser = new PduUtils.PduMetaDataParser();
    const meta = meta_parser.load_pdu_meta(binary_data);
    if (meta === null) {
        throw new Error("Invalid PDU binary data: MetaData not found or corrupted");
    }
    binary_read_recursive_HakoBatteryStatus(meta, binary_data, js_obj, meta.base_off);
    return js_obj;
}

export function binary_read_recursive_HakoBatteryStatus(meta, binary_data, js_obj, base_off) {
    const view = new DataView(binary_data);
    const littleEndian = true;
    // member: full_voltage, type: float64 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 0, 8);
        js_obj.full_voltage = PduUtils.binToValue("float64", bin);
    }
    
    // member: curr_voltage, type: float64 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 8, 8);
        js_obj.curr_voltage = PduUtils.binToValue("float64", bin);
    }
    
    // member: curr_temp, type: float64 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 16, 8);
        js_obj.curr_temp = PduUtils.binToValue("float64", bin);
    }
    
    // member: status, type: uint32 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 24, 4);
        js_obj.status = PduUtils.binToValue("uint32", bin);
    }
    
    // member: cycles, type: uint32 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 28, 4);
        js_obj.cycles = PduUtils.binToValue("uint32", bin);
    }
    
    return js_obj;
}

/**
 * Serializes a HakoBatteryStatus object into a binary PDU.
 * @param { HakoBatteryStatus } js_obj
 * @returns {ArrayBuffer}
 */
export function jsToPdu_HakoBatteryStatus(js_obj) {
    const base_allocator = new PduUtils.DynamicAllocator();
    const bw_container = new PduUtils.BinaryWriterContainer(new PduUtils.PduMetaData());

    binary_write_recursive_HakoBatteryStatus(0, bw_container, base_allocator, js_obj);

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

export function binary_write_recursive_HakoBatteryStatus(parent_off, bw_container, allocator, js_obj) {
    const littleEndian = true;
    // member: full_voltage, type: float64 (primitive)

    
    {
        const bin = PduUtils.typeToBin("float64", js_obj.full_voltage, 8);
        allocator.add(bin, parent_off + 0);
    }
    
    // member: curr_voltage, type: float64 (primitive)

    
    {
        const bin = PduUtils.typeToBin("float64", js_obj.curr_voltage, 8);
        allocator.add(bin, parent_off + 8);
    }
    
    // member: curr_temp, type: float64 (primitive)

    
    {
        const bin = PduUtils.typeToBin("float64", js_obj.curr_temp, 8);
        allocator.add(bin, parent_off + 16);
    }
    
    // member: status, type: uint32 (primitive)

    
    {
        const bin = PduUtils.typeToBin("uint32", js_obj.status, 4);
        allocator.add(bin, parent_off + 24);
    }
    
    // member: cycles, type: uint32 (primitive)

    
    {
        const bin = PduUtils.typeToBin("uint32", js_obj.cycles, 4);
        allocator.add(bin, parent_off + 28);
    }
    
}
