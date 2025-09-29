import * as PduUtils from '../pdu_utils.js';
import { HakoGLOBAL_POSITION_INT } from './pdu_jstype_HakoGLOBAL_POSITION_INT.js';


/**
 * Deserializes a binary PDU into a HakoGLOBAL_POSITION_INT object.
 * @param {ArrayBuffer} binary_data
 * @returns { HakoGLOBAL_POSITION_INT }
 */
export function pduToJs_HakoGLOBAL_POSITION_INT(binary_data) {
    const js_obj = new HakoGLOBAL_POSITION_INT();
    const meta_parser = new PduUtils.PduMetaDataParser();
    const meta = meta_parser.load_pdu_meta(binary_data);
    if (meta === null) {
        throw new Error("Invalid PDU binary data: MetaData not found or corrupted");
    }
    binary_read_recursive_HakoGLOBAL_POSITION_INT(meta, binary_data, js_obj, meta.base_off);
    return js_obj;
}

export function binary_read_recursive_HakoGLOBAL_POSITION_INT(meta, binary_data, js_obj, base_off) {
    const view = new DataView(binary_data);
    const littleEndian = true;
    // member: time_boot_ms, type: uint32 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 0, 4);
        js_obj.time_boot_ms = PduUtils.binToValue("uint32", bin);
    }
    
    // member: lat, type: int32 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 4, 4);
        js_obj.lat = PduUtils.binToValue("int32", bin);
    }
    
    // member: lon, type: int32 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 8, 4);
        js_obj.lon = PduUtils.binToValue("int32", bin);
    }
    
    // member: alt, type: int32 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 12, 4);
        js_obj.alt = PduUtils.binToValue("int32", bin);
    }
    
    // member: relative_alt, type: int32 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 16, 4);
        js_obj.relative_alt = PduUtils.binToValue("int32", bin);
    }
    
    // member: vx, type: int16 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 20, 2);
        js_obj.vx = PduUtils.binToValue("int16", bin);
    }
    
    // member: vy, type: int16 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 22, 2);
        js_obj.vy = PduUtils.binToValue("int16", bin);
    }
    
    // member: vz, type: int16 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 24, 2);
        js_obj.vz = PduUtils.binToValue("int16", bin);
    }
    
    // member: hdg, type: uint16 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 26, 2);
        js_obj.hdg = PduUtils.binToValue("uint16", bin);
    }
    
    return js_obj;
}

/**
 * Serializes a HakoGLOBAL_POSITION_INT object into a binary PDU.
 * @param { HakoGLOBAL_POSITION_INT } js_obj
 * @returns {ArrayBuffer}
 */
export function jsToPdu_HakoGLOBAL_POSITION_INT(js_obj) {
    const base_allocator = new PduUtils.DynamicAllocator();
    const bw_container = new PduUtils.BinaryWriterContainer(new PduUtils.PduMetaData());

    binary_write_recursive_HakoGLOBAL_POSITION_INT(0, bw_container, base_allocator, js_obj);

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

export function binary_write_recursive_HakoGLOBAL_POSITION_INT(parent_off, bw_container, allocator, js_obj) {
    const littleEndian = true;
    // member: time_boot_ms, type: uint32 (primitive)

    
    {
        const bin = PduUtils.typeToBin("uint32", js_obj.time_boot_ms, 4);
        allocator.add(bin, parent_off + 0);
    }
    
    // member: lat, type: int32 (primitive)

    
    {
        const bin = PduUtils.typeToBin("int32", js_obj.lat, 4);
        allocator.add(bin, parent_off + 4);
    }
    
    // member: lon, type: int32 (primitive)

    
    {
        const bin = PduUtils.typeToBin("int32", js_obj.lon, 4);
        allocator.add(bin, parent_off + 8);
    }
    
    // member: alt, type: int32 (primitive)

    
    {
        const bin = PduUtils.typeToBin("int32", js_obj.alt, 4);
        allocator.add(bin, parent_off + 12);
    }
    
    // member: relative_alt, type: int32 (primitive)

    
    {
        const bin = PduUtils.typeToBin("int32", js_obj.relative_alt, 4);
        allocator.add(bin, parent_off + 16);
    }
    
    // member: vx, type: int16 (primitive)

    
    {
        const bin = PduUtils.typeToBin("int16", js_obj.vx, 2);
        allocator.add(bin, parent_off + 20);
    }
    
    // member: vy, type: int16 (primitive)

    
    {
        const bin = PduUtils.typeToBin("int16", js_obj.vy, 2);
        allocator.add(bin, parent_off + 22);
    }
    
    // member: vz, type: int16 (primitive)

    
    {
        const bin = PduUtils.typeToBin("int16", js_obj.vz, 2);
        allocator.add(bin, parent_off + 24);
    }
    
    // member: hdg, type: uint16 (primitive)

    
    {
        const bin = PduUtils.typeToBin("uint16", js_obj.hdg, 2);
        allocator.add(bin, parent_off + 26);
    }
    
}
