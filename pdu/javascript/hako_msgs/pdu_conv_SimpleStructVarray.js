import * as PduUtils from '../pdu_utils.js';
import { SimpleStructVarray } from './pdu_jstype_SimpleStructVarray.js';
import { SimpleVarray } from './pdu_jstype_SimpleVarray.js';
import { binary_read_recursive_SimpleVarray, binary_write_recursive_SimpleVarray } from './pdu_conv_SimpleVarray.js';


/**
 * Deserializes a binary PDU into a SimpleStructVarray object.
 * @param {ArrayBuffer} binary_data
 * @returns { SimpleStructVarray }
 */
export function pduToJs_SimpleStructVarray(binary_data) {
    const js_obj = new SimpleStructVarray();
    const meta_parser = new PduUtils.PduMetaDataParser();
    const meta = meta_parser.load_pdu_meta(binary_data);
    if (meta === null) {
        throw new Error("Invalid PDU binary data: MetaData not found or corrupted");
    }
    binary_read_recursive_SimpleStructVarray(meta, binary_data, js_obj, meta.base_off);
    return js_obj;
}

export function binary_read_recursive_SimpleStructVarray(meta, binary_data, js_obj, base_off) {
    const view = new DataView(binary_data);
    const littleEndian = true;
    // member: aaa, type: int32 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 0, 4);
        js_obj.aaa = PduUtils.binToValue("int32", bin);
    }
    
    // member: fixed_str, type: string (primitive)

    
    {
        const array_bin = PduUtils.readBinary(binary_data, base_off + 4, 256);
        js_obj.fixed_str = PduUtils.binToArrayValues("string", array_bin, 2);
    }
    
    // member: varray_str, type: string (primitive)

    { // varray
        const array_size = view.getInt32(base_off + 260, littleEndian);
        const offset_from_heap = view.getInt32(base_off + 260 + 4, littleEndian);
        const one_elm_size = 128;
        const array_bin = PduUtils.readBinary(binary_data, meta.heap_off + offset_from_heap, one_elm_size * array_size);
        
        if ("string" === 'string') {
            js_obj.varray_str = PduUtils.binToValue("string", array_bin);
        } else {
            js_obj.varray_str = PduUtils.binToArrayValues("string", array_bin, array_size);
        }
    }
    
    // member: fixed_array, type: SimpleVarray (struct)

    {
        const array_size = 5;
        const one_elm_size = 120 / array_size;
        const array_value = [];
        for (let i = 0; i < array_size; i++) {
            const tmp_obj = new SimpleVarray();
            const item_offset = base_off + 268 + (i * one_elm_size);
            binary_read_recursive_SimpleVarray(meta, binary_data, tmp_obj, item_offset);
            array_value.push(tmp_obj);
        }
        js_obj.fixed_array = array_value;
    }
    
    // member: data, type: SimpleVarray (struct)

    { // varray
        const array_size = view.getInt32(base_off + 388, littleEndian);
        const offset_from_heap = view.getInt32(base_off + 388 + 4, littleEndian);
        const one_elm_size = 24;
        const array_value = [];
        for (let i = 0; i < array_size; i++) {
            const tmp_obj = new SimpleVarray();
            const item_offset = meta.heap_off + offset_from_heap + (i * one_elm_size);
            binary_read_recursive_SimpleVarray(meta, binary_data, tmp_obj, item_offset);
            array_value.push(tmp_obj);
        }
        js_obj.data = array_value;
    }
    
    return js_obj;
}

/**
 * Serializes a SimpleStructVarray object into a binary PDU.
 * @param { SimpleStructVarray } js_obj
 * @returns {ArrayBuffer}
 */
export function jsToPdu_SimpleStructVarray(js_obj) {
    const base_allocator = new PduUtils.DynamicAllocator();
    const bw_container = new PduUtils.BinaryWriterContainer(new PduUtils.PduMetaData());

    binary_write_recursive_SimpleStructVarray(0, bw_container, base_allocator, js_obj);

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

export function binary_write_recursive_SimpleStructVarray(parent_off, bw_container, allocator, js_obj) {
    const littleEndian = true;
    // member: aaa, type: int32 (primitive)

    
    {
        const bin = PduUtils.typeToBin("int32", js_obj.aaa, 4);
        allocator.add(bin, parent_off + 0);
    }
    
    // member: fixed_str, type: string (primitive)

    
    {
        const buffer = PduUtils.typesToBin("string", js_obj.fixed_str);
        allocator.add(buffer, parent_off + 4);
    }
    
    // member: varray_str, type: string (primitive)

    { // varray
        const offset_from_heap = bw_container.heap_allocator.size();
        let data_buffer;
        let array_size;
        if ("string" === 'string') {
            data_buffer = new TextEncoder().encode(js_obj.varray_str);
            array_size = data_buffer.byteLength;
        } else {
            data_buffer = PduUtils.typesToBin("string", js_obj.varray_str);
            array_size = js_obj.varray_str.length;
        }
        bw_container.heap_allocator.add(data_buffer);

        const ref_buffer = new ArrayBuffer(8);
        const ref_view = new DataView(ref_buffer);
        ref_view.setInt32(0, array_size, littleEndian);
        ref_view.setInt32(4, offset_from_heap, littleEndian);
        allocator.add(ref_buffer, parent_off + 260);
    }
    
    // member: fixed_array, type: SimpleVarray (struct)

    {
        const one_elm_size = 120 / 5;
        for (let i = 0; i < 5; i++) {
            binary_write_recursive_SimpleVarray(parent_off + 268 + (i * one_elm_size), bw_container, allocator, js_obj.fixed_array[i]);
        }
    }
    
    // member: data, type: SimpleVarray (struct)

    { // varray
        const offset_from_heap = bw_container.heap_allocator.size();
        const one_elm_size = 24;
        for (const elm of js_obj.data) {
            binary_write_recursive_SimpleVarray(0, bw_container, bw_container.heap_allocator, elm);
        }

        const ref_buffer = new ArrayBuffer(8);
        const ref_view = new DataView(ref_buffer);
        ref_view.setInt32(0, js_obj.data.length, littleEndian); // array_size
        ref_view.setInt32(4, offset_from_heap, littleEndian);
        allocator.add(ref_buffer, parent_off + 388);
    }
    
}
