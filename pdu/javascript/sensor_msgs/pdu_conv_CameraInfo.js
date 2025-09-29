import * as PduUtils from '../pdu_utils.js';
import { CameraInfo } from './pdu_jstype_CameraInfo.js';
import { Header } from '../std_msgs/pdu_jstype_Header.js';
import { binary_read_recursive_Header, binary_write_recursive_Header } from '../std_msgs/pdu_conv_Header.js';
import { RegionOfInterest } from './pdu_jstype_RegionOfInterest.js';
import { binary_read_recursive_RegionOfInterest, binary_write_recursive_RegionOfInterest } from './pdu_conv_RegionOfInterest.js';


/**
 * Deserializes a binary PDU into a CameraInfo object.
 * @param {ArrayBuffer} binary_data
 * @returns { CameraInfo }
 */
export function pduToJs_CameraInfo(binary_data) {
    const js_obj = new CameraInfo();
    const meta_parser = new PduUtils.PduMetaDataParser();
    const meta = meta_parser.load_pdu_meta(binary_data);
    if (meta === null) {
        throw new Error("Invalid PDU binary data: MetaData not found or corrupted");
    }
    binary_read_recursive_CameraInfo(meta, binary_data, js_obj, meta.base_off);
    return js_obj;
}

export function binary_read_recursive_CameraInfo(meta, binary_data, js_obj, base_off) {
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
    
    // member: distortion_model, type: string (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 144, 128);
        js_obj.distortion_model = PduUtils.binToValue("string", bin);
    }
    
    // member: d, type: float64 (primitive)

    { // varray
        const array_size = view.getInt32(base_off + 272, littleEndian);
        const offset_from_heap = view.getInt32(base_off + 272 + 4, littleEndian);
        const one_elm_size = 8;
        const array_bin = PduUtils.readBinary(binary_data, meta.heap_off + offset_from_heap, one_elm_size * array_size);
        
        if ("float64" === 'string') {
            js_obj.d = PduUtils.binToValue("string", array_bin);
        } else {
            js_obj.d = PduUtils.binToArrayValues("float64", array_bin, array_size);
        }
    }
    
    // member: k, type: float64 (primitive)

    
    {
        const array_bin = PduUtils.readBinary(binary_data, base_off + 280, 72);
        js_obj.k = PduUtils.binToArrayValues("float64", array_bin, 9);
    }
    
    // member: r, type: float64 (primitive)

    
    {
        const array_bin = PduUtils.readBinary(binary_data, base_off + 352, 72);
        js_obj.r = PduUtils.binToArrayValues("float64", array_bin, 9);
    }
    
    // member: p, type: float64 (primitive)

    
    {
        const array_bin = PduUtils.readBinary(binary_data, base_off + 424, 96);
        js_obj.p = PduUtils.binToArrayValues("float64", array_bin, 12);
    }
    
    // member: binning_x, type: uint32 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 520, 4);
        js_obj.binning_x = PduUtils.binToValue("uint32", bin);
    }
    
    // member: binning_y, type: uint32 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 524, 4);
        js_obj.binning_y = PduUtils.binToValue("uint32", bin);
    }
    
    // member: roi, type: RegionOfInterest (struct)

    {
        const tmp_obj = new RegionOfInterest();
        binary_read_recursive_RegionOfInterest(meta, binary_data, tmp_obj, base_off + 528);
        js_obj.roi = tmp_obj;
    }
    
    return js_obj;
}

/**
 * Serializes a CameraInfo object into a binary PDU.
 * @param { CameraInfo } js_obj
 * @returns {ArrayBuffer}
 */
export function jsToPdu_CameraInfo(js_obj) {
    const base_allocator = new PduUtils.DynamicAllocator();
    const bw_container = new PduUtils.BinaryWriterContainer(new PduUtils.PduMetaData());

    binary_write_recursive_CameraInfo(0, bw_container, base_allocator, js_obj);

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

export function binary_write_recursive_CameraInfo(parent_off, bw_container, allocator, js_obj) {
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
    
    // member: distortion_model, type: string (primitive)

    
    {
        const bin = PduUtils.typeToBin("string", js_obj.distortion_model, 128);
        allocator.add(bin, parent_off + 144);
    }
    
    // member: d, type: float64 (primitive)

    { // varray
        const offset_from_heap = bw_container.heap_allocator.size();
        let data_buffer;
        let array_size;
        if ("float64" === 'string') {
            data_buffer = new TextEncoder().encode(js_obj.d);
            array_size = data_buffer.byteLength;
        } else {
            data_buffer = PduUtils.typesToBin("float64", js_obj.d);
            array_size = js_obj.d.length;
        }
        bw_container.heap_allocator.add(data_buffer);

        const ref_buffer = new ArrayBuffer(8);
        const ref_view = new DataView(ref_buffer);
        ref_view.setInt32(0, array_size, littleEndian);
        ref_view.setInt32(4, offset_from_heap, littleEndian);
        allocator.add(ref_buffer, parent_off + 272);
    }
    
    // member: k, type: float64 (primitive)

    
    {
        const buffer = PduUtils.typesToBin("float64", js_obj.k);
        allocator.add(buffer, parent_off + 280);
    }
    
    // member: r, type: float64 (primitive)

    
    {
        const buffer = PduUtils.typesToBin("float64", js_obj.r);
        allocator.add(buffer, parent_off + 352);
    }
    
    // member: p, type: float64 (primitive)

    
    {
        const buffer = PduUtils.typesToBin("float64", js_obj.p);
        allocator.add(buffer, parent_off + 424);
    }
    
    // member: binning_x, type: uint32 (primitive)

    
    {
        const bin = PduUtils.typeToBin("uint32", js_obj.binning_x, 4);
        allocator.add(bin, parent_off + 520);
    }
    
    // member: binning_y, type: uint32 (primitive)

    
    {
        const bin = PduUtils.typeToBin("uint32", js_obj.binning_y, 4);
        allocator.add(bin, parent_off + 524);
    }
    
    // member: roi, type: RegionOfInterest (struct)

    {
        binary_write_recursive_RegionOfInterest(parent_off + 528, bw_container, allocator, js_obj.roi);
    }
    
}
