import * as PduUtils from '../pdu_utils.js';
import { HakoHilGps } from './pdu_jstype_HakoHilGps.js';


/**
 * Deserializes a binary PDU into a HakoHilGps object.
 * @param {ArrayBuffer} binary_data
 * @returns { HakoHilGps }
 */
export function pduToJs_HakoHilGps(binary_data) {
    const js_obj = new HakoHilGps();
    const meta_parser = new PduUtils.PduMetaDataParser();
    const meta = meta_parser.load_pdu_meta(binary_data);
    if (meta === null) {
        throw new Error("Invalid PDU binary data: MetaData not found or corrupted");
    }
    binary_read_recursive_HakoHilGps(meta, binary_data, js_obj, meta.base_off);
    return js_obj;
}

export function binary_read_recursive_HakoHilGps(meta, binary_data, js_obj, base_off) {
    const view = new DataView(binary_data);
    const littleEndian = true;
    // member: time_usec, type: uint64 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 0, 8);
        js_obj.time_usec = PduUtils.binToValue("uint64", bin);
    }
    
    // member: lat, type: int32 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 8, 4);
        js_obj.lat = PduUtils.binToValue("int32", bin);
    }
    
    // member: lon, type: int32 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 12, 4);
        js_obj.lon = PduUtils.binToValue("int32", bin);
    }
    
    // member: alt, type: int32 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 16, 4);
        js_obj.alt = PduUtils.binToValue("int32", bin);
    }
    
    // member: eph, type: uint16 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 20, 2);
        js_obj.eph = PduUtils.binToValue("uint16", bin);
    }
    
    // member: epv, type: uint16 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 22, 2);
        js_obj.epv = PduUtils.binToValue("uint16", bin);
    }
    
    // member: vel, type: uint16 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 24, 2);
        js_obj.vel = PduUtils.binToValue("uint16", bin);
    }
    
    // member: vn, type: int16 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 26, 2);
        js_obj.vn = PduUtils.binToValue("int16", bin);
    }
    
    // member: ve, type: int16 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 28, 2);
        js_obj.ve = PduUtils.binToValue("int16", bin);
    }
    
    // member: vd, type: int16 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 30, 2);
        js_obj.vd = PduUtils.binToValue("int16", bin);
    }
    
    // member: cog, type: uint16 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 32, 2);
        js_obj.cog = PduUtils.binToValue("uint16", bin);
    }
    
    // member: satellites_visible, type: uint8 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 34, 1);
        js_obj.satellites_visible = PduUtils.binToValue("uint8", bin);
    }
    
    // member: id, type: uint8 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 35, 1);
        js_obj.id = PduUtils.binToValue("uint8", bin);
    }
    
    // member: yaw, type: uint8 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 36, 1);
        js_obj.yaw = PduUtils.binToValue("uint8", bin);
    }
    
    // member: fix_type, type: uint8 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 37, 1);
        js_obj.fix_type = PduUtils.binToValue("uint8", bin);
    }
    
    return js_obj;
}

/**
 * Serializes a HakoHilGps object into a binary PDU.
 * @param { HakoHilGps } js_obj
 * @returns {ArrayBuffer}
 */
export function jsToPdu_HakoHilGps(js_obj) {
    const base_allocator = new PduUtils.DynamicAllocator();
    const bw_container = new PduUtils.BinaryWriterContainer(new PduUtils.PduMetaData());

    binary_write_recursive_HakoHilGps(0, bw_container, base_allocator, js_obj);

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

export function binary_write_recursive_HakoHilGps(parent_off, bw_container, allocator, js_obj) {
    const littleEndian = true;
    // member: time_usec, type: uint64 (primitive)

    
    {
        const bin = PduUtils.typeToBin("uint64", js_obj.time_usec, 8);
        allocator.add(bin, parent_off + 0);
    }
    
    // member: lat, type: int32 (primitive)

    
    {
        const bin = PduUtils.typeToBin("int32", js_obj.lat, 4);
        allocator.add(bin, parent_off + 8);
    }
    
    // member: lon, type: int32 (primitive)

    
    {
        const bin = PduUtils.typeToBin("int32", js_obj.lon, 4);
        allocator.add(bin, parent_off + 12);
    }
    
    // member: alt, type: int32 (primitive)

    
    {
        const bin = PduUtils.typeToBin("int32", js_obj.alt, 4);
        allocator.add(bin, parent_off + 16);
    }
    
    // member: eph, type: uint16 (primitive)

    
    {
        const bin = PduUtils.typeToBin("uint16", js_obj.eph, 2);
        allocator.add(bin, parent_off + 20);
    }
    
    // member: epv, type: uint16 (primitive)

    
    {
        const bin = PduUtils.typeToBin("uint16", js_obj.epv, 2);
        allocator.add(bin, parent_off + 22);
    }
    
    // member: vel, type: uint16 (primitive)

    
    {
        const bin = PduUtils.typeToBin("uint16", js_obj.vel, 2);
        allocator.add(bin, parent_off + 24);
    }
    
    // member: vn, type: int16 (primitive)

    
    {
        const bin = PduUtils.typeToBin("int16", js_obj.vn, 2);
        allocator.add(bin, parent_off + 26);
    }
    
    // member: ve, type: int16 (primitive)

    
    {
        const bin = PduUtils.typeToBin("int16", js_obj.ve, 2);
        allocator.add(bin, parent_off + 28);
    }
    
    // member: vd, type: int16 (primitive)

    
    {
        const bin = PduUtils.typeToBin("int16", js_obj.vd, 2);
        allocator.add(bin, parent_off + 30);
    }
    
    // member: cog, type: uint16 (primitive)

    
    {
        const bin = PduUtils.typeToBin("uint16", js_obj.cog, 2);
        allocator.add(bin, parent_off + 32);
    }
    
    // member: satellites_visible, type: uint8 (primitive)

    
    {
        const bin = PduUtils.typeToBin("uint8", js_obj.satellites_visible, 1);
        allocator.add(bin, parent_off + 34);
    }
    
    // member: id, type: uint8 (primitive)

    
    {
        const bin = PduUtils.typeToBin("uint8", js_obj.id, 1);
        allocator.add(bin, parent_off + 35);
    }
    
    // member: yaw, type: uint8 (primitive)

    
    {
        const bin = PduUtils.typeToBin("uint8", js_obj.yaw, 1);
        allocator.add(bin, parent_off + 36);
    }
    
    // member: fix_type, type: uint8 (primitive)

    
    {
        const bin = PduUtils.typeToBin("uint8", js_obj.fix_type, 1);
        allocator.add(bin, parent_off + 37);
    }
    
}
