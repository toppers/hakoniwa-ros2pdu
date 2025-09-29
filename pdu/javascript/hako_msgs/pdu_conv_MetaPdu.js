import * as PduUtils from '../pdu_utils.js';
import { MetaPdu } from './pdu_jstype_MetaPdu.js';


/**
 * Deserializes a binary PDU into a MetaPdu object.
 * @param {ArrayBuffer} binary_data
 * @returns { MetaPdu }
 */
export function pduToJs_MetaPdu(binary_data) {
    const js_obj = new MetaPdu();
    const meta_parser = new PduUtils.PduMetaDataParser();
    const meta = meta_parser.load_pdu_meta(binary_data);
    if (meta === null) {
        throw new Error("Invalid PDU binary data: MetaData not found or corrupted");
    }
    binary_read_recursive_MetaPdu(meta, binary_data, js_obj, meta.base_off);
    return js_obj;
}

export function binary_read_recursive_MetaPdu(meta, binary_data, js_obj, base_off) {
    const view = new DataView(binary_data);
    const littleEndian = true;
    // member: total_len, type: uint32 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 0, 4);
        js_obj.total_len = PduUtils.binToValue("uint32", bin);
    }
    
    // member: magicno, type: uint32 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 4, 4);
        js_obj.magicno = PduUtils.binToValue("uint32", bin);
    }
    
    // member: version, type: uint16 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 8, 2);
        js_obj.version = PduUtils.binToValue("uint16", bin);
    }
    
    // member: flags, type: uint16 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 10, 2);
        js_obj.flags = PduUtils.binToValue("uint16", bin);
    }
    
    // member: meta_request_type, type: uint32 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 12, 4);
        js_obj.meta_request_type = PduUtils.binToValue("uint32", bin);
    }
    
    // member: hako_time_us, type: uint64 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 16, 8);
        js_obj.hako_time_us = PduUtils.binToValue("uint64", bin);
    }
    
    // member: asset_time_us, type: uint64 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 24, 8);
        js_obj.asset_time_us = PduUtils.binToValue("uint64", bin);
    }
    
    // member: real_time_us, type: uint64 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 32, 8);
        js_obj.real_time_us = PduUtils.binToValue("uint64", bin);
    }
    
    // member: robot_name, type: string (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 40, 128);
        js_obj.robot_name = PduUtils.binToValue("string", bin);
    }
    
    // member: channel_id, type: int32 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 168, 4);
        js_obj.channel_id = PduUtils.binToValue("int32", bin);
    }
    
    // member: body_len, type: uint32 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 172, 4);
        js_obj.body_len = PduUtils.binToValue("uint32", bin);
    }
    
    return js_obj;
}

/**
 * Serializes a MetaPdu object into a binary PDU.
 * @param { MetaPdu } js_obj
 * @returns {ArrayBuffer}
 */
export function jsToPdu_MetaPdu(js_obj) {
    const base_allocator = new PduUtils.DynamicAllocator();
    const bw_container = new PduUtils.BinaryWriterContainer(new PduUtils.PduMetaData());

    binary_write_recursive_MetaPdu(0, bw_container, base_allocator, js_obj);

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

export function binary_write_recursive_MetaPdu(parent_off, bw_container, allocator, js_obj) {
    const littleEndian = true;
    // member: total_len, type: uint32 (primitive)

    
    {
        const bin = PduUtils.typeToBin("uint32", js_obj.total_len, 4);
        allocator.add(bin, parent_off + 0);
    }
    
    // member: magicno, type: uint32 (primitive)

    
    {
        const bin = PduUtils.typeToBin("uint32", js_obj.magicno, 4);
        allocator.add(bin, parent_off + 4);
    }
    
    // member: version, type: uint16 (primitive)

    
    {
        const bin = PduUtils.typeToBin("uint16", js_obj.version, 2);
        allocator.add(bin, parent_off + 8);
    }
    
    // member: flags, type: uint16 (primitive)

    
    {
        const bin = PduUtils.typeToBin("uint16", js_obj.flags, 2);
        allocator.add(bin, parent_off + 10);
    }
    
    // member: meta_request_type, type: uint32 (primitive)

    
    {
        const bin = PduUtils.typeToBin("uint32", js_obj.meta_request_type, 4);
        allocator.add(bin, parent_off + 12);
    }
    
    // member: hako_time_us, type: uint64 (primitive)

    
    {
        const bin = PduUtils.typeToBin("uint64", js_obj.hako_time_us, 8);
        allocator.add(bin, parent_off + 16);
    }
    
    // member: asset_time_us, type: uint64 (primitive)

    
    {
        const bin = PduUtils.typeToBin("uint64", js_obj.asset_time_us, 8);
        allocator.add(bin, parent_off + 24);
    }
    
    // member: real_time_us, type: uint64 (primitive)

    
    {
        const bin = PduUtils.typeToBin("uint64", js_obj.real_time_us, 8);
        allocator.add(bin, parent_off + 32);
    }
    
    // member: robot_name, type: string (primitive)

    
    {
        const bin = PduUtils.typeToBin("string", js_obj.robot_name, 128);
        allocator.add(bin, parent_off + 40);
    }
    
    // member: channel_id, type: int32 (primitive)

    
    {
        const bin = PduUtils.typeToBin("int32", js_obj.channel_id, 4);
        allocator.add(bin, parent_off + 168);
    }
    
    // member: body_len, type: uint32 (primitive)

    
    {
        const bin = PduUtils.typeToBin("uint32", js_obj.body_len, 4);
        allocator.add(bin, parent_off + 172);
    }
    
}
