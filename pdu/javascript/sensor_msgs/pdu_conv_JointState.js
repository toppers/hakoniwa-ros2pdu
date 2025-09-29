import * as PduUtils from '../pdu_utils.js';
import { JointState } from './pdu_jstype_JointState.js';
import { Header } from '../std_msgs/pdu_jstype_Header.js';
import { binary_read_recursive_Header, binary_write_recursive_Header } from '../std_msgs/pdu_conv_Header.js';


/**
 * Deserializes a binary PDU into a JointState object.
 * @param {ArrayBuffer} binary_data
 * @returns { JointState }
 */
export function pduToJs_JointState(binary_data) {
    const js_obj = new JointState();
    const meta_parser = new PduUtils.PduMetaDataParser();
    const meta = meta_parser.load_pdu_meta(binary_data);
    if (meta === null) {
        throw new Error("Invalid PDU binary data: MetaData not found or corrupted");
    }
    binary_read_recursive_JointState(meta, binary_data, js_obj, meta.base_off);
    return js_obj;
}

export function binary_read_recursive_JointState(meta, binary_data, js_obj, base_off) {
    const view = new DataView(binary_data);
    const littleEndian = true;
    // member: header, type: std_msgs/Header (struct)

    {
        const tmp_obj = new Header();
        binary_read_recursive_Header(meta, binary_data, tmp_obj, base_off + 0);
        js_obj.header = tmp_obj;
    }
    
    // member: name, type: string (primitive)

    { // varray
        const array_size = view.getInt32(base_off + 136, littleEndian);
        const offset_from_heap = view.getInt32(base_off + 136 + 4, littleEndian);
        const one_elm_size = 128;
        const array_bin = PduUtils.readBinary(binary_data, meta.heap_off + offset_from_heap, one_elm_size * array_size);
        
        if ("string" === 'string') {
            js_obj.name = PduUtils.binToValue("string", array_bin);
        } else {
            js_obj.name = PduUtils.binToArrayValues("string", array_bin, array_size);
        }
    }
    
    // member: position, type: float64 (primitive)

    { // varray
        const array_size = view.getInt32(base_off + 144, littleEndian);
        const offset_from_heap = view.getInt32(base_off + 144 + 4, littleEndian);
        const one_elm_size = 8;
        const array_bin = PduUtils.readBinary(binary_data, meta.heap_off + offset_from_heap, one_elm_size * array_size);
        
        if ("float64" === 'string') {
            js_obj.position = PduUtils.binToValue("string", array_bin);
        } else {
            js_obj.position = PduUtils.binToArrayValues("float64", array_bin, array_size);
        }
    }
    
    // member: velocity, type: float64 (primitive)

    { // varray
        const array_size = view.getInt32(base_off + 152, littleEndian);
        const offset_from_heap = view.getInt32(base_off + 152 + 4, littleEndian);
        const one_elm_size = 8;
        const array_bin = PduUtils.readBinary(binary_data, meta.heap_off + offset_from_heap, one_elm_size * array_size);
        
        if ("float64" === 'string') {
            js_obj.velocity = PduUtils.binToValue("string", array_bin);
        } else {
            js_obj.velocity = PduUtils.binToArrayValues("float64", array_bin, array_size);
        }
    }
    
    // member: effort, type: float64 (primitive)

    { // varray
        const array_size = view.getInt32(base_off + 160, littleEndian);
        const offset_from_heap = view.getInt32(base_off + 160 + 4, littleEndian);
        const one_elm_size = 8;
        const array_bin = PduUtils.readBinary(binary_data, meta.heap_off + offset_from_heap, one_elm_size * array_size);
        
        if ("float64" === 'string') {
            js_obj.effort = PduUtils.binToValue("string", array_bin);
        } else {
            js_obj.effort = PduUtils.binToArrayValues("float64", array_bin, array_size);
        }
    }
    
    return js_obj;
}

/**
 * Serializes a JointState object into a binary PDU.
 * @param { JointState } js_obj
 * @returns {ArrayBuffer}
 */
export function jsToPdu_JointState(js_obj) {
    const base_allocator = new PduUtils.DynamicAllocator();
    const bw_container = new PduUtils.BinaryWriterContainer(new PduUtils.PduMetaData());

    binary_write_recursive_JointState(0, bw_container, base_allocator, js_obj);

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

export function binary_write_recursive_JointState(parent_off, bw_container, allocator, js_obj) {
    const littleEndian = true;
    // member: header, type: std_msgs/Header (struct)

    {
        binary_write_recursive_Header(parent_off + 0, bw_container, allocator, js_obj.header);
    }
    
    // member: name, type: string (primitive)

    { // varray
        const offset_from_heap = bw_container.heap_allocator.size();
        let data_buffer;
        let array_size;
        if ("string" === 'string') {
            data_buffer = new TextEncoder().encode(js_obj.name);
            array_size = data_buffer.byteLength;
        } else {
            data_buffer = PduUtils.typesToBin("string", js_obj.name);
            array_size = js_obj.name.length;
        }
        bw_container.heap_allocator.add(data_buffer);

        const ref_buffer = new ArrayBuffer(8);
        const ref_view = new DataView(ref_buffer);
        ref_view.setInt32(0, array_size, littleEndian);
        ref_view.setInt32(4, offset_from_heap, littleEndian);
        allocator.add(ref_buffer, parent_off + 136);
    }
    
    // member: position, type: float64 (primitive)

    { // varray
        const offset_from_heap = bw_container.heap_allocator.size();
        let data_buffer;
        let array_size;
        if ("float64" === 'string') {
            data_buffer = new TextEncoder().encode(js_obj.position);
            array_size = data_buffer.byteLength;
        } else {
            data_buffer = PduUtils.typesToBin("float64", js_obj.position);
            array_size = js_obj.position.length;
        }
        bw_container.heap_allocator.add(data_buffer);

        const ref_buffer = new ArrayBuffer(8);
        const ref_view = new DataView(ref_buffer);
        ref_view.setInt32(0, array_size, littleEndian);
        ref_view.setInt32(4, offset_from_heap, littleEndian);
        allocator.add(ref_buffer, parent_off + 144);
    }
    
    // member: velocity, type: float64 (primitive)

    { // varray
        const offset_from_heap = bw_container.heap_allocator.size();
        let data_buffer;
        let array_size;
        if ("float64" === 'string') {
            data_buffer = new TextEncoder().encode(js_obj.velocity);
            array_size = data_buffer.byteLength;
        } else {
            data_buffer = PduUtils.typesToBin("float64", js_obj.velocity);
            array_size = js_obj.velocity.length;
        }
        bw_container.heap_allocator.add(data_buffer);

        const ref_buffer = new ArrayBuffer(8);
        const ref_view = new DataView(ref_buffer);
        ref_view.setInt32(0, array_size, littleEndian);
        ref_view.setInt32(4, offset_from_heap, littleEndian);
        allocator.add(ref_buffer, parent_off + 152);
    }
    
    // member: effort, type: float64 (primitive)

    { // varray
        const offset_from_heap = bw_container.heap_allocator.size();
        let data_buffer;
        let array_size;
        if ("float64" === 'string') {
            data_buffer = new TextEncoder().encode(js_obj.effort);
            array_size = data_buffer.byteLength;
        } else {
            data_buffer = PduUtils.typesToBin("float64", js_obj.effort);
            array_size = js_obj.effort.length;
        }
        bw_container.heap_allocator.add(data_buffer);

        const ref_buffer = new ArrayBuffer(8);
        const ref_view = new DataView(ref_buffer);
        ref_view.setInt32(0, array_size, littleEndian);
        ref_view.setInt32(4, offset_from_heap, littleEndian);
        allocator.add(ref_buffer, parent_off + 160);
    }
    
}
