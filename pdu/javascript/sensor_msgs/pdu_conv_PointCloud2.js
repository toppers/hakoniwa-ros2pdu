import * as PduUtils from '../pdu_utils.js';
import { PointCloud2 } from './pdu_jstype_PointCloud2.js';
import { Header } from '../std_msgs/pdu_jstype_Header.js';
import { binary_read_recursive_Header, binary_write_recursive_Header } from '../std_msgs/pdu_conv_Header.js';
import { PointField } from './pdu_jstype_PointField.js';
import { binary_read_recursive_PointField, binary_write_recursive_PointField } from './pdu_conv_PointField.js';


/**
 * Deserializes a binary PDU into a PointCloud2 object.
 * @param {ArrayBuffer} binary_data
 * @returns { PointCloud2 }
 */
export function pduToJs_PointCloud2(binary_data) {
    const js_obj = new PointCloud2();
    const meta_parser = new PduUtils.PduMetaDataParser();
    const meta = meta_parser.load_pdu_meta(binary_data);
    if (meta === null) {
        throw new Error("Invalid PDU binary data: MetaData not found or corrupted");
    }
    binary_read_recursive_PointCloud2(meta, binary_data, js_obj, meta.base_off);
    return js_obj;
}

export function binary_read_recursive_PointCloud2(meta, binary_data, js_obj, base_off) {
    const view = new DataView(binary_data);
    const littleEndian = true;
    // member: header, type: std_msgs/Header (struct)

    {
        const tmp_obj = new Header();
        binary_read_recursive_Header(meta, binary_data, tmp_obj, base_off + 0);
        js_obj.header = tmp_obj;
    }
    
    // member: height, type: uint32 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 136, 4);
        js_obj.height = PduUtils.binToValue("uint32", bin);
    }
    
    // member: width, type: uint32 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 140, 4);
        js_obj.width = PduUtils.binToValue("uint32", bin);
    }
    
    // member: fields, type: PointField (struct)

    { // varray
        const array_size = view.getInt32(base_off + 144, littleEndian);
        const offset_from_heap = view.getInt32(base_off + 144 + 4, littleEndian);
        const one_elm_size = 140;
        const array_value = [];
        for (let i = 0; i < array_size; i++) {
            const tmp_obj = new PointField();
            const item_offset = meta.heap_off + offset_from_heap + (i * one_elm_size);
            binary_read_recursive_PointField(meta, binary_data, tmp_obj, item_offset);
            array_value.push(tmp_obj);
        }
        js_obj.fields = array_value;
    }
    
    // member: is_bigendian, type: bool (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 152, 4);
        js_obj.is_bigendian = PduUtils.binToValue("bool", bin);
    }
    
    // member: point_step, type: uint32 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 156, 4);
        js_obj.point_step = PduUtils.binToValue("uint32", bin);
    }
    
    // member: row_step, type: uint32 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 160, 4);
        js_obj.row_step = PduUtils.binToValue("uint32", bin);
    }
    
    // member: data, type: uint8 (primitive)

    { // varray
        const array_size = view.getInt32(base_off + 164, littleEndian);
        const offset_from_heap = view.getInt32(base_off + 164 + 4, littleEndian);
        const one_elm_size = 1;
        const array_bin = PduUtils.readBinary(binary_data, meta.heap_off + offset_from_heap, one_elm_size * array_size);
        
        if ("uint8" === 'string') {
            js_obj.data = PduUtils.binToValue("string", array_bin);
        } else {
            js_obj.data = PduUtils.binToArrayValues("uint8", array_bin, array_size);
        }
    }
    
    // member: is_dense, type: bool (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 172, 4);
        js_obj.is_dense = PduUtils.binToValue("bool", bin);
    }
    
    return js_obj;
}

/**
 * Serializes a PointCloud2 object into a binary PDU.
 * @param { PointCloud2 } js_obj
 * @returns {ArrayBuffer}
 */
export function jsToPdu_PointCloud2(js_obj) {
    const base_allocator = new PduUtils.DynamicAllocator();
    const bw_container = new PduUtils.BinaryWriterContainer(new PduUtils.PduMetaData());

    binary_write_recursive_PointCloud2(0, bw_container, base_allocator, js_obj);

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

export function binary_write_recursive_PointCloud2(parent_off, bw_container, allocator, js_obj) {
    const littleEndian = true;
    // member: header, type: std_msgs/Header (struct)

    {
        binary_write_recursive_Header(parent_off + 0, bw_container, allocator, js_obj.header);
    }
    
    // member: height, type: uint32 (primitive)

    
    {
        const bin = PduUtils.typeToBin("uint32", js_obj.height, 4);
        allocator.add(bin, parent_off + 136);
    }
    
    // member: width, type: uint32 (primitive)

    
    {
        const bin = PduUtils.typeToBin("uint32", js_obj.width, 4);
        allocator.add(bin, parent_off + 140);
    }
    
    // member: fields, type: PointField (struct)

    { // varray
        const offset_from_heap = bw_container.heap_allocator.size();
        const one_elm_size = 140;
        for (const elm of js_obj.fields) {
            binary_write_recursive_PointField(0, bw_container, bw_container.heap_allocator, elm);
        }

        const ref_buffer = new ArrayBuffer(8);
        const ref_view = new DataView(ref_buffer);
        ref_view.setInt32(0, js_obj.fields.length, littleEndian); // array_size
        ref_view.setInt32(4, offset_from_heap, littleEndian);
        allocator.add(ref_buffer, parent_off + 144);
    }
    
    // member: is_bigendian, type: bool (primitive)

    
    {
        const bin = PduUtils.typeToBin("bool", js_obj.is_bigendian, 4);
        allocator.add(bin, parent_off + 152);
    }
    
    // member: point_step, type: uint32 (primitive)

    
    {
        const bin = PduUtils.typeToBin("uint32", js_obj.point_step, 4);
        allocator.add(bin, parent_off + 156);
    }
    
    // member: row_step, type: uint32 (primitive)

    
    {
        const bin = PduUtils.typeToBin("uint32", js_obj.row_step, 4);
        allocator.add(bin, parent_off + 160);
    }
    
    // member: data, type: uint8 (primitive)

    { // varray
        const offset_from_heap = bw_container.heap_allocator.size();
        let data_buffer;
        let array_size;
        if ("uint8" === 'string') {
            data_buffer = new TextEncoder().encode(js_obj.data);
            array_size = data_buffer.byteLength;
        } else {
            data_buffer = PduUtils.typesToBin("uint8", js_obj.data);
            array_size = js_obj.data.length;
        }
        bw_container.heap_allocator.add(data_buffer);

        const ref_buffer = new ArrayBuffer(8);
        const ref_view = new DataView(ref_buffer);
        ref_view.setInt32(0, array_size, littleEndian);
        ref_view.setInt32(4, offset_from_heap, littleEndian);
        allocator.add(ref_buffer, parent_off + 164);
    }
    
    // member: is_dense, type: bool (primitive)

    
    {
        const bin = PduUtils.typeToBin("bool", js_obj.is_dense, 4);
        allocator.add(bin, parent_off + 172);
    }
    
}
