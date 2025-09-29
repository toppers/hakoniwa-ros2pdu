import * as PduUtils from '../pdu_utils.js';
import { ManualPosAttControl } from './pdu_jstype_ManualPosAttControl.js';
import { Twist } from '../geometry_msgs/pdu_jstype_Twist.js';
import { binary_read_recursive_Twist, binary_write_recursive_Twist } from '../geometry_msgs/pdu_conv_Twist.js';


/**
 * Deserializes a binary PDU into a ManualPosAttControl object.
 * @param {ArrayBuffer} binary_data
 * @returns { ManualPosAttControl }
 */
export function pduToJs_ManualPosAttControl(binary_data) {
    const js_obj = new ManualPosAttControl();
    const meta_parser = new PduUtils.PduMetaDataParser();
    const meta = meta_parser.load_pdu_meta(binary_data);
    if (meta === null) {
        throw new Error("Invalid PDU binary data: MetaData not found or corrupted");
    }
    binary_read_recursive_ManualPosAttControl(meta, binary_data, js_obj, meta.base_off);
    return js_obj;
}

export function binary_read_recursive_ManualPosAttControl(meta, binary_data, js_obj, base_off) {
    const view = new DataView(binary_data);
    const littleEndian = true;
    // member: do_operation, type: bool (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 0, 4);
        js_obj.do_operation = PduUtils.binToValue("bool", bin);
    }
    
    // member: posatt, type: geometry_msgs/Twist (struct)

    {
        const tmp_obj = new Twist();
        binary_read_recursive_Twist(meta, binary_data, tmp_obj, base_off + 8);
        js_obj.posatt = tmp_obj;
    }
    
    return js_obj;
}

/**
 * Serializes a ManualPosAttControl object into a binary PDU.
 * @param { ManualPosAttControl } js_obj
 * @returns {ArrayBuffer}
 */
export function jsToPdu_ManualPosAttControl(js_obj) {
    const base_allocator = new PduUtils.DynamicAllocator();
    const bw_container = new PduUtils.BinaryWriterContainer(new PduUtils.PduMetaData());

    binary_write_recursive_ManualPosAttControl(0, bw_container, base_allocator, js_obj);

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

export function binary_write_recursive_ManualPosAttControl(parent_off, bw_container, allocator, js_obj) {
    const littleEndian = true;
    // member: do_operation, type: bool (primitive)

    
    {
        const bin = PduUtils.typeToBin("bool", js_obj.do_operation, 4);
        allocator.add(bin, parent_off + 0);
    }
    
    // member: posatt, type: geometry_msgs/Twist (struct)

    {
        binary_write_recursive_Twist(parent_off + 8, bw_container, allocator, js_obj.posatt);
    }
    
}
