import * as PduUtils from '../pdu_utils.js';
import { MultiArrayLayout } from './pdu_jstype_MultiArrayLayout.js';
import { MultiArrayDimension } from './pdu_jstype_MultiArrayDimension.js';
import { binary_read_recursive_MultiArrayDimension, binary_write_recursive_MultiArrayDimension } from './pdu_conv_MultiArrayDimension.js';


/**
 * Deserializes a binary PDU into a MultiArrayLayout object.
 * @param {ArrayBuffer} binary_data
 * @returns { MultiArrayLayout }
 */
export function pduToJs_MultiArrayLayout(binary_data) {
    const js_obj = new MultiArrayLayout();
    const meta_parser = new PduUtils.PduMetaDataParser();
    const meta = meta_parser.load_pdu_meta(binary_data);
    if (meta === null) {
        throw new Error("Invalid PDU binary data: MetaData not found or corrupted");
    }
    binary_read_recursive_MultiArrayLayout(meta, binary_data, js_obj, meta.base_off);
    return js_obj;
}

export function binary_read_recursive_MultiArrayLayout(meta, binary_data, js_obj, base_off) {
    const view = new DataView(binary_data);
    const littleEndian = true;
    // member: dim, type: MultiArrayDimension (struct)

    { // varray
        const array_size = view.getInt32(base_off + 0, littleEndian);
        const offset_from_heap = view.getInt32(base_off + 0 + 4, littleEndian);
        const one_elm_size = 136;
        const array_value = [];
        for (let i = 0; i < array_size; i++) {
            const tmp_obj = new MultiArrayDimension();
            const item_offset = meta.heap_off + offset_from_heap + (i * one_elm_size);
            binary_read_recursive_MultiArrayDimension(meta, binary_data, tmp_obj, item_offset);
            array_value.push(tmp_obj);
        }
        js_obj.dim = array_value;
    }
    
    // member: data_offset, type: uint32 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 8, 4);
        js_obj.data_offset = PduUtils.binToValue("uint32", bin);
    }
    
    return js_obj;
}

/**
 * Serializes a MultiArrayLayout object into a binary PDU.
 * @param { MultiArrayLayout } js_obj
 * @returns {ArrayBuffer}
 */
export function jsToPdu_MultiArrayLayout(js_obj) {
    const base_allocator = new PduUtils.DynamicAllocator();
    const bw_container = new PduUtils.BinaryWriterContainer(new PduUtils.PduMetaData());

    binary_write_recursive_MultiArrayLayout(0, bw_container, base_allocator, js_obj);

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

export function binary_write_recursive_MultiArrayLayout(parent_off, bw_container, allocator, js_obj) {
    const littleEndian = true;
    // member: dim, type: MultiArrayDimension (struct)

    { // varray
        const offset_from_heap = bw_container.heap_allocator.size();
        const one_elm_size = 136;
        for (const elm of js_obj.dim) {
            binary_write_recursive_MultiArrayDimension(0, bw_container, bw_container.heap_allocator, elm);
        }

        const ref_buffer = new ArrayBuffer(8);
        const ref_view = new DataView(ref_buffer);
        ref_view.setInt32(0, js_obj.dim.length, littleEndian); // array_size
        ref_view.setInt32(4, offset_from_heap, littleEndian);
        allocator.add(ref_buffer, parent_off + 0);
    }
    
    // member: data_offset, type: uint32 (primitive)

    
    {
        const bin = PduUtils.typeToBin("uint32", js_obj.data_offset, 4);
        allocator.add(bin, parent_off + 8);
    }
    
}
