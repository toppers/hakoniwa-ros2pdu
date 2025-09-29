import * as PduUtils from '../pdu_utils.js';
import { Image } from './pdu_jstype_Image.js';
import { Header } from '../std_msgs/pdu_jstype_Header.js';
import { binary_read_recursive_Header, binary_write_recursive_Header } from '../std_msgs/pdu_conv_Header.js';


/**
 * Deserializes a binary PDU into a Image object.
 * @param {ArrayBuffer} binary_data
 * @returns { Image }
 */
export function pduToJs_Image(binary_data) {
    const js_obj = new Image();
    const meta_parser = new PduUtils.PduMetaDataParser();
    const meta = meta_parser.load_pdu_meta(binary_data);
    if (meta === null) {
        throw new Error("Invalid PDU binary data: MetaData not found or corrupted");
    }
    binary_read_recursive_Image(meta, binary_data, js_obj, meta.base_off);
    return js_obj;
}

export function binary_read_recursive_Image(meta, binary_data, js_obj, base_off) {
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
    
    // member: encoding, type: string (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 144, 128);
        js_obj.encoding = PduUtils.binToValue("string", bin);
    }
    
    // member: is_bigendian, type: uint8 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 272, 1);
        js_obj.is_bigendian = PduUtils.binToValue("uint8", bin);
    }
    
    // member: step, type: uint32 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 276, 4);
        js_obj.step = PduUtils.binToValue("uint32", bin);
    }
    
    // member: data, type: uint8 (primitive)

    { // varray
        const array_size = view.getInt32(base_off + 280, littleEndian);
        const offset_from_heap = view.getInt32(base_off + 280 + 4, littleEndian);
        const one_elm_size = 1;
        const array_bin = PduUtils.readBinary(binary_data, meta.heap_off + offset_from_heap, one_elm_size * array_size);
        
        if ("uint8" === 'string') {
            js_obj.data = PduUtils.binToValue("string", array_bin);
        } else {
            js_obj.data = PduUtils.binToArrayValues("uint8", array_bin, array_size);
        }
    }
    
    return js_obj;
}

/**
 * Serializes a Image object into a binary PDU.
 * @param { Image } js_obj
 * @returns {ArrayBuffer}
 */
export function jsToPdu_Image(js_obj) {
    const base_allocator = new PduUtils.DynamicAllocator();
    const bw_container = new PduUtils.BinaryWriterContainer(new PduUtils.PduMetaData());

    binary_write_recursive_Image(0, bw_container, base_allocator, js_obj);

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

export function binary_write_recursive_Image(parent_off, bw_container, allocator, js_obj) {
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
    
    // member: encoding, type: string (primitive)

    
    {
        const bin = PduUtils.typeToBin("string", js_obj.encoding, 128);
        allocator.add(bin, parent_off + 144);
    }
    
    // member: is_bigendian, type: uint8 (primitive)

    
    {
        const bin = PduUtils.typeToBin("uint8", js_obj.is_bigendian, 1);
        allocator.add(bin, parent_off + 272);
    }
    
    // member: step, type: uint32 (primitive)

    
    {
        const bin = PduUtils.typeToBin("uint32", js_obj.step, 4);
        allocator.add(bin, parent_off + 276);
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
        allocator.add(ref_buffer, parent_off + 280);
    }
    
}
