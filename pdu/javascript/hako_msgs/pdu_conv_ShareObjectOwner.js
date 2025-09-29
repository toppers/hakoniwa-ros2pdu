import * as PduUtils from '../pdu_utils.js';
import { ShareObjectOwner } from './pdu_jstype_ShareObjectOwner.js';
import { Twist } from '../geometry_msgs/pdu_jstype_Twist.js';
import { binary_read_recursive_Twist, binary_write_recursive_Twist } from '../geometry_msgs/pdu_conv_Twist.js';


/**
 * Deserializes a binary PDU into a ShareObjectOwner object.
 * @param {ArrayBuffer} binary_data
 * @returns { ShareObjectOwner }
 */
export function pduToJs_ShareObjectOwner(binary_data) {
    const js_obj = new ShareObjectOwner();
    const meta_parser = new PduUtils.PduMetaDataParser();
    const meta = meta_parser.load_pdu_meta(binary_data);
    if (meta === null) {
        throw new Error("Invalid PDU binary data: MetaData not found or corrupted");
    }
    binary_read_recursive_ShareObjectOwner(meta, binary_data, js_obj, meta.base_off);
    return js_obj;
}

export function binary_read_recursive_ShareObjectOwner(meta, binary_data, js_obj, base_off) {
    const view = new DataView(binary_data);
    const littleEndian = true;
    // member: object_name, type: string (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 0, 128);
        js_obj.object_name = PduUtils.binToValue("string", bin);
    }
    
    // member: owner_id, type: uint32 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 128, 4);
        js_obj.owner_id = PduUtils.binToValue("uint32", bin);
    }
    
    // member: last_update, type: uint64 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 136, 8);
        js_obj.last_update = PduUtils.binToValue("uint64", bin);
    }
    
    // member: pos, type: geometry_msgs/Twist (struct)

    {
        const tmp_obj = new Twist();
        binary_read_recursive_Twist(meta, binary_data, tmp_obj, base_off + 144);
        js_obj.pos = tmp_obj;
    }
    
    return js_obj;
}

/**
 * Serializes a ShareObjectOwner object into a binary PDU.
 * @param { ShareObjectOwner } js_obj
 * @returns {ArrayBuffer}
 */
export function jsToPdu_ShareObjectOwner(js_obj) {
    const base_allocator = new PduUtils.DynamicAllocator();
    const bw_container = new PduUtils.BinaryWriterContainer(new PduUtils.PduMetaData());

    binary_write_recursive_ShareObjectOwner(0, bw_container, base_allocator, js_obj);

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

export function binary_write_recursive_ShareObjectOwner(parent_off, bw_container, allocator, js_obj) {
    const littleEndian = true;
    // member: object_name, type: string (primitive)

    
    {
        const bin = PduUtils.typeToBin("string", js_obj.object_name, 128);
        allocator.add(bin, parent_off + 0);
    }
    
    // member: owner_id, type: uint32 (primitive)

    
    {
        const bin = PduUtils.typeToBin("uint32", js_obj.owner_id, 4);
        allocator.add(bin, parent_off + 128);
    }
    
    // member: last_update, type: uint64 (primitive)

    
    {
        const bin = PduUtils.typeToBin("uint64", js_obj.last_update, 8);
        allocator.add(bin, parent_off + 136);
    }
    
    // member: pos, type: geometry_msgs/Twist (struct)

    {
        binary_write_recursive_Twist(parent_off + 144, bw_container, allocator, js_obj.pos);
    }
    
}
