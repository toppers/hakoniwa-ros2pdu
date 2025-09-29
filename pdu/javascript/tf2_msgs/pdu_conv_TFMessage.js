import * as PduUtils from '../pdu_utils.js';
import { TFMessage } from './pdu_jstype_TFMessage.js';
import { TransformStamped } from '../geometry_msgs/pdu_jstype_TransformStamped.js';
import { binary_read_recursive_TransformStamped, binary_write_recursive_TransformStamped } from '../geometry_msgs/pdu_conv_TransformStamped.js';


/**
 * Deserializes a binary PDU into a TFMessage object.
 * @param {ArrayBuffer} binary_data
 * @returns { TFMessage }
 */
export function pduToJs_TFMessage(binary_data) {
    const js_obj = new TFMessage();
    const meta_parser = new PduUtils.PduMetaDataParser();
    const meta = meta_parser.load_pdu_meta(binary_data);
    if (meta === null) {
        throw new Error("Invalid PDU binary data: MetaData not found or corrupted");
    }
    binary_read_recursive_TFMessage(meta, binary_data, js_obj, meta.base_off);
    return js_obj;
}

export function binary_read_recursive_TFMessage(meta, binary_data, js_obj, base_off) {
    const view = new DataView(binary_data);
    const littleEndian = true;
    // member: transforms, type: geometry_msgs/TransformStamped (struct)

    { // varray
        const array_size = view.getInt32(base_off + 0, littleEndian);
        const offset_from_heap = view.getInt32(base_off + 0 + 4, littleEndian);
        const one_elm_size = 320;
        const array_value = [];
        for (let i = 0; i < array_size; i++) {
            const tmp_obj = new TransformStamped();
            const item_offset = meta.heap_off + offset_from_heap + (i * one_elm_size);
            binary_read_recursive_TransformStamped(meta, binary_data, tmp_obj, item_offset);
            array_value.push(tmp_obj);
        }
        js_obj.transforms = array_value;
    }
    
    return js_obj;
}

/**
 * Serializes a TFMessage object into a binary PDU.
 * @param { TFMessage } js_obj
 * @returns {ArrayBuffer}
 */
export function jsToPdu_TFMessage(js_obj) {
    const base_allocator = new PduUtils.DynamicAllocator();
    const bw_container = new PduUtils.BinaryWriterContainer(new PduUtils.PduMetaData());

    binary_write_recursive_TFMessage(0, bw_container, base_allocator, js_obj);

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

export function binary_write_recursive_TFMessage(parent_off, bw_container, allocator, js_obj) {
    const littleEndian = true;
    // member: transforms, type: geometry_msgs/TransformStamped (struct)

    { // varray
        const offset_from_heap = bw_container.heap_allocator.size();
        const one_elm_size = 320;
        for (const elm of js_obj.transforms) {
            binary_write_recursive_TransformStamped(0, bw_container, bw_container.heap_allocator, elm);
        }

        const ref_buffer = new ArrayBuffer(8);
        const ref_view = new DataView(ref_buffer);
        ref_view.setInt32(0, js_obj.transforms.length, littleEndian); // array_size
        ref_view.setInt32(4, offset_from_heap, littleEndian);
        allocator.add(ref_buffer, parent_off + 0);
    }
    
}
