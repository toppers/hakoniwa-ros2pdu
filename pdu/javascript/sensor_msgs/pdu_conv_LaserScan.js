import * as PduUtils from '../pdu_utils.js';
import { LaserScan } from './pdu_jstype_LaserScan.js';
import { Header } from '../std_msgs/pdu_jstype_Header.js';
import { binary_read_recursive_Header, binary_write_recursive_Header } from '../std_msgs/pdu_conv_Header.js';


/**
 * Deserializes a binary PDU into a LaserScan object.
 * @param {ArrayBuffer} binary_data
 * @returns { LaserScan }
 */
export function pduToJs_LaserScan(binary_data) {
    const js_obj = new LaserScan();
    const meta_parser = new PduUtils.PduMetaDataParser();
    const meta = meta_parser.load_pdu_meta(binary_data);
    if (meta === null) {
        throw new Error("Invalid PDU binary data: MetaData not found or corrupted");
    }
    binary_read_recursive_LaserScan(meta, binary_data, js_obj, meta.base_off);
    return js_obj;
}

export function binary_read_recursive_LaserScan(meta, binary_data, js_obj, base_off) {
    const view = new DataView(binary_data);
    const littleEndian = true;
    // member: header, type: std_msgs/Header (struct)

    {
        const tmp_obj = new Header();
        binary_read_recursive_Header(meta, binary_data, tmp_obj, base_off + 0);
        js_obj.header = tmp_obj;
    }
    
    // member: angle_min, type: float32 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 136, 4);
        js_obj.angle_min = PduUtils.binToValue("float32", bin);
    }
    
    // member: angle_max, type: float32 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 140, 4);
        js_obj.angle_max = PduUtils.binToValue("float32", bin);
    }
    
    // member: angle_increment, type: float32 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 144, 4);
        js_obj.angle_increment = PduUtils.binToValue("float32", bin);
    }
    
    // member: time_increment, type: float32 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 148, 4);
        js_obj.time_increment = PduUtils.binToValue("float32", bin);
    }
    
    // member: scan_time, type: float32 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 152, 4);
        js_obj.scan_time = PduUtils.binToValue("float32", bin);
    }
    
    // member: range_min, type: float32 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 156, 4);
        js_obj.range_min = PduUtils.binToValue("float32", bin);
    }
    
    // member: range_max, type: float32 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 160, 4);
        js_obj.range_max = PduUtils.binToValue("float32", bin);
    }
    
    // member: ranges, type: float32 (primitive)

    { // varray
        const array_size = view.getInt32(base_off + 164, littleEndian);
        const offset_from_heap = view.getInt32(base_off + 164 + 4, littleEndian);
        const one_elm_size = 4;
        const array_bin = PduUtils.readBinary(binary_data, meta.heap_off + offset_from_heap, one_elm_size * array_size);
        
        if ("float32" === 'string') {
            js_obj.ranges = PduUtils.binToValue("string", array_bin);
        } else {
            js_obj.ranges = PduUtils.binToArrayValues("float32", array_bin, array_size);
        }
    }
    
    // member: intensities, type: float32 (primitive)

    { // varray
        const array_size = view.getInt32(base_off + 172, littleEndian);
        const offset_from_heap = view.getInt32(base_off + 172 + 4, littleEndian);
        const one_elm_size = 4;
        const array_bin = PduUtils.readBinary(binary_data, meta.heap_off + offset_from_heap, one_elm_size * array_size);
        
        if ("float32" === 'string') {
            js_obj.intensities = PduUtils.binToValue("string", array_bin);
        } else {
            js_obj.intensities = PduUtils.binToArrayValues("float32", array_bin, array_size);
        }
    }
    
    return js_obj;
}

/**
 * Serializes a LaserScan object into a binary PDU.
 * @param { LaserScan } js_obj
 * @returns {ArrayBuffer}
 */
export function jsToPdu_LaserScan(js_obj) {
    const base_allocator = new PduUtils.DynamicAllocator();
    const bw_container = new PduUtils.BinaryWriterContainer(new PduUtils.PduMetaData());

    binary_write_recursive_LaserScan(0, bw_container, base_allocator, js_obj);

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

export function binary_write_recursive_LaserScan(parent_off, bw_container, allocator, js_obj) {
    const littleEndian = true;
    // member: header, type: std_msgs/Header (struct)

    {
        binary_write_recursive_Header(parent_off + 0, bw_container, allocator, js_obj.header);
    }
    
    // member: angle_min, type: float32 (primitive)

    
    {
        const bin = PduUtils.typeToBin("float32", js_obj.angle_min, 4);
        allocator.add(bin, parent_off + 136);
    }
    
    // member: angle_max, type: float32 (primitive)

    
    {
        const bin = PduUtils.typeToBin("float32", js_obj.angle_max, 4);
        allocator.add(bin, parent_off + 140);
    }
    
    // member: angle_increment, type: float32 (primitive)

    
    {
        const bin = PduUtils.typeToBin("float32", js_obj.angle_increment, 4);
        allocator.add(bin, parent_off + 144);
    }
    
    // member: time_increment, type: float32 (primitive)

    
    {
        const bin = PduUtils.typeToBin("float32", js_obj.time_increment, 4);
        allocator.add(bin, parent_off + 148);
    }
    
    // member: scan_time, type: float32 (primitive)

    
    {
        const bin = PduUtils.typeToBin("float32", js_obj.scan_time, 4);
        allocator.add(bin, parent_off + 152);
    }
    
    // member: range_min, type: float32 (primitive)

    
    {
        const bin = PduUtils.typeToBin("float32", js_obj.range_min, 4);
        allocator.add(bin, parent_off + 156);
    }
    
    // member: range_max, type: float32 (primitive)

    
    {
        const bin = PduUtils.typeToBin("float32", js_obj.range_max, 4);
        allocator.add(bin, parent_off + 160);
    }
    
    // member: ranges, type: float32 (primitive)

    { // varray
        const offset_from_heap = bw_container.heap_allocator.size();
        let data_buffer;
        let array_size;
        if ("float32" === 'string') {
            data_buffer = new TextEncoder().encode(js_obj.ranges);
            array_size = data_buffer.byteLength;
        } else {
            data_buffer = PduUtils.typesToBin("float32", js_obj.ranges);
            array_size = js_obj.ranges.length;
        }
        bw_container.heap_allocator.add(data_buffer);

        const ref_buffer = new ArrayBuffer(8);
        const ref_view = new DataView(ref_buffer);
        ref_view.setInt32(0, array_size, littleEndian);
        ref_view.setInt32(4, offset_from_heap, littleEndian);
        allocator.add(ref_buffer, parent_off + 164);
    }
    
    // member: intensities, type: float32 (primitive)

    { // varray
        const offset_from_heap = bw_container.heap_allocator.size();
        let data_buffer;
        let array_size;
        if ("float32" === 'string') {
            data_buffer = new TextEncoder().encode(js_obj.intensities);
            array_size = data_buffer.byteLength;
        } else {
            data_buffer = PduUtils.typesToBin("float32", js_obj.intensities);
            array_size = js_obj.intensities.length;
        }
        bw_container.heap_allocator.add(data_buffer);

        const ref_buffer = new ArrayBuffer(8);
        const ref_view = new DataView(ref_buffer);
        ref_view.setInt32(0, array_size, littleEndian);
        ref_view.setInt32(4, offset_from_heap, littleEndian);
        allocator.add(ref_buffer, parent_off + 172);
    }
    
}
