import * as PduUtils from '../pdu_utils.js';
import { TransformStamped } from './pdu_jstype_TransformStamped.js';
import { Header } from '../std_msgs/pdu_jstype_Header.js';
import { binary_read_recursive_Header, binary_write_recursive_Header } from '../std_msgs/pdu_conv_Header.js';
import { Transform } from './pdu_jstype_Transform.js';
import { binary_read_recursive_Transform, binary_write_recursive_Transform } from './pdu_conv_Transform.js';


/**
 * Deserializes a binary PDU into a TransformStamped object.
 * @param {ArrayBuffer} binary_data
 * @returns { TransformStamped }
 */
export function pduToJs_TransformStamped(binary_data) {
    const js_obj = new TransformStamped();
    const meta_parser = new PduUtils.PduMetaDataParser();
    const meta = meta_parser.load_pdu_meta(binary_data);
    if (meta === null) {
        throw new Error("Invalid PDU binary data: MetaData not found or corrupted");
    }
    binary_read_recursive_TransformStamped(meta, binary_data, js_obj, meta.base_off);
    return js_obj;
}

export function binary_read_recursive_TransformStamped(meta, binary_data, js_obj, base_off) {
    const view = new DataView(binary_data);
    const littleEndian = true;
    // member: header, type: std_msgs/Header (struct)

    {
        const tmp_obj = new Header();
        binary_read_recursive_Header(meta, binary_data, tmp_obj, base_off + 0);
        js_obj.header = tmp_obj;
    }
    
    // member: child_frame_id, type: string (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 136, 128);
        js_obj.child_frame_id = PduUtils.binToValue("string", bin);
    }
    
    // member: transform, type: Transform (struct)

    {
        const tmp_obj = new Transform();
        binary_read_recursive_Transform(meta, binary_data, tmp_obj, base_off + 264);
        js_obj.transform = tmp_obj;
    }
    
    return js_obj;
}

/**
 * Serializes a TransformStamped object into a binary PDU.
 * @param { TransformStamped } js_obj
 * @returns {ArrayBuffer}
 */
export function jsToPdu_TransformStamped(js_obj) {
    const base_allocator = new PduUtils.DynamicAllocator();
    const bw_container = new PduUtils.BinaryWriterContainer(new PduUtils.PduMetaData());

    binary_write_recursive_TransformStamped(0, bw_container, base_allocator, js_obj);

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

export function binary_write_recursive_TransformStamped(parent_off, bw_container, allocator, js_obj) {
    const littleEndian = true;
    // member: header, type: std_msgs/Header (struct)

    {
        binary_write_recursive_Header(parent_off + 0, bw_container, allocator, js_obj.header);
    }
    
    // member: child_frame_id, type: string (primitive)

    
    {
        const bin = PduUtils.typeToBin("string", js_obj.child_frame_id, 128);
        allocator.add(bin, parent_off + 136);
    }
    
    // member: transform, type: Transform (struct)

    {
        binary_write_recursive_Transform(parent_off + 264, bw_container, allocator, js_obj.transform);
    }
    
}
