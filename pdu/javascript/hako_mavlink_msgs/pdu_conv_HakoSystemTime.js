import * as PduUtils from '../pdu_utils.js';
import { HakoSystemTime } from './pdu_jstype_HakoSystemTime.js';


/**
 * Deserializes a binary PDU into a HakoSystemTime object.
 * @param {ArrayBuffer} binary_data
 * @returns { HakoSystemTime }
 */
export function pduToJs_HakoSystemTime(binary_data) {
    const js_obj = new HakoSystemTime();
    const meta_parser = new PduUtils.PduMetaDataParser();
    const meta = meta_parser.load_pdu_meta(binary_data);
    if (meta === null) {
        throw new Error("Invalid PDU binary data: MetaData not found or corrupted");
    }
    binary_read_recursive_HakoSystemTime(meta, binary_data, js_obj, meta.base_off);
    return js_obj;
}

export function binary_read_recursive_HakoSystemTime(meta, binary_data, js_obj, base_off) {
    const view = new DataView(binary_data);
    const littleEndian = true;
    // member: time_unix_usec, type: uint64 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 0, 8);
        js_obj.time_unix_usec = PduUtils.binToValue("uint64", bin);
    }
    
    // member: time_boot_ms, type: uint64 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 8, 8);
        js_obj.time_boot_ms = PduUtils.binToValue("uint64", bin);
    }
    
    return js_obj;
}

/**
 * Serializes a HakoSystemTime object into a binary PDU.
 * @param { HakoSystemTime } js_obj
 * @returns {ArrayBuffer}
 */
export function jsToPdu_HakoSystemTime(js_obj) {
    const base_allocator = new PduUtils.DynamicAllocator();
    const bw_container = new PduUtils.BinaryWriterContainer(new PduUtils.PduMetaData());

    binary_write_recursive_HakoSystemTime(0, bw_container, base_allocator, js_obj);

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

export function binary_write_recursive_HakoSystemTime(parent_off, bw_container, allocator, js_obj) {
    const littleEndian = true;
    // member: time_unix_usec, type: uint64 (primitive)

    
    {
        const bin = PduUtils.typeToBin("uint64", js_obj.time_unix_usec, 8);
        allocator.add(bin, parent_off + 0);
    }
    
    // member: time_boot_ms, type: uint64 (primitive)

    
    {
        const bin = PduUtils.typeToBin("uint64", js_obj.time_boot_ms, 8);
        allocator.add(bin, parent_off + 8);
    }
    
}
