import * as PduUtils from '../pdu_utils.js';
import { UInt32MultiArray } from './pdu_jstype_UInt32MultiArray.js';
import { MultiArrayLayout } from './pdu_jstype_MultiArrayLayout.js';
import { binary_read_recursive_MultiArrayLayout, binary_write_recursive_MultiArrayLayout } from './pdu_conv_MultiArrayLayout.js';


/**
 * Deserializes a binary PDU into a UInt32MultiArray object.
 * @param {ArrayBuffer} binary_data
 * @returns { UInt32MultiArray }
 */
export function pduToJs_UInt32MultiArray(binary_data) {
    const js_obj = new UInt32MultiArray();
    const meta_parser = new PduUtils.PduMetaDataParser();
    const meta = meta_parser.load_pdu_meta(binary_data);
    if (meta === null) {
        throw new Error("Invalid PDU binary data: MetaData not found or corrupted");
    }
    binary_read_recursive_UInt32MultiArray(meta, binary_data, js_obj, meta.base_off);
    return js_obj;
}

export function binary_read_recursive_UInt32MultiArray(meta, binary_data, js_obj, base_off) {
    const view = new DataView(binary_data);
    const littleEndian = true;
    // member: layout, type: MultiArrayLayout (struct)

    {
        const tmp_obj = new MultiArrayLayout();
        binary_read_recursive_MultiArrayLayout(meta, binary_data, tmp_obj, base_off + 0);
        js_obj.layout = tmp_obj;
    }
    
    // member: data, type: uint32 (primitive)

    { // varray
        const array_size = view.getInt32(base_off + 12, littleEndian);
        const offset_from_heap = view.getInt32(base_off + 12 + 4, littleEndian);
        const one_elm_size = 4;
        const array_bin = PduUtils.readBinary(binary_data, meta.heap_off + offset_from_heap, one_elm_size * array_size);
        
        if ("uint32" === 'string') {
            js_obj.data = PduUtils.binToValue("string", array_bin);
        } else {
            js_obj.data = PduUtils.binToArrayValues("uint32", array_bin, array_size);
        }
    }
    
    return js_obj;
}

/**
 * Serializes a UInt32MultiArray object into a binary PDU.
 * @param { UInt32MultiArray } js_obj
 * @returns {ArrayBuffer}
 */
export function jsToPdu_UInt32MultiArray(js_obj) {
    const base_allocator = new PduUtils.DynamicAllocator();
    const bw_container = new PduUtils.BinaryWriterContainer(new PduUtils.PduMetaData());

    binary_write_recursive_UInt32MultiArray(0, bw_container, base_allocator, js_obj);

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

export function binary_write_recursive_UInt32MultiArray(parent_off, bw_container, allocator, js_obj) {
    const littleEndian = true;
    // member: layout, type: MultiArrayLayout (struct)

    {
        binary_write_recursive_MultiArrayLayout(parent_off + 0, bw_container, allocator, js_obj.layout);
    }
    
    // member: data, type: uint32 (primitive)

    { // varray
        const offset_from_heap = bw_container.heap_allocator.size();
        let data_buffer;
        let array_size;
        if ("uint32" === 'string') {
            data_buffer = new TextEncoder().encode(js_obj.data);
            array_size = data_buffer.byteLength;
        } else {
            data_buffer = PduUtils.typesToBin("uint32", js_obj.data);
            array_size = js_obj.data.length;
        }
        bw_container.heap_allocator.add(data_buffer);

        const ref_buffer = new ArrayBuffer(8);
        const ref_view = new DataView(ref_buffer);
        ref_view.setInt32(0, array_size, littleEndian);
        ref_view.setInt32(4, offset_from_heap, littleEndian);
        allocator.add(ref_buffer, parent_off + 12);
    }
    
}
