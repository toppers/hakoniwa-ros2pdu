import * as PduUtils from '../pdu_utils.js';
import { HakoATTITUDE } from './pdu_jstype_HakoATTITUDE.js';


/**
 * Deserializes a binary PDU into a HakoATTITUDE object.
 * @param {ArrayBuffer} binary_data
 * @returns { HakoATTITUDE }
 */
export function pduToJs_HakoATTITUDE(binary_data) {
    const js_obj = new HakoATTITUDE();
    const meta_parser = new PduUtils.PduMetaDataParser();
    const meta = meta_parser.load_pdu_meta(binary_data);
    if (meta === null) {
        throw new Error("Invalid PDU binary data: MetaData not found or corrupted");
    }
    binary_read_recursive_HakoATTITUDE(meta, binary_data, js_obj, meta.base_off);
    return js_obj;
}

export function binary_read_recursive_HakoATTITUDE(meta, binary_data, js_obj, base_off) {
    const view = new DataView(binary_data);
    const littleEndian = true;
    // member: time_boot_ms, type: uint32 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 0, 4);
        js_obj.time_boot_ms = PduUtils.binToValue("uint32", bin);
    }
    
    // member: roll, type: float32 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 4, 4);
        js_obj.roll = PduUtils.binToValue("float32", bin);
    }
    
    // member: pitch, type: float32 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 8, 4);
        js_obj.pitch = PduUtils.binToValue("float32", bin);
    }
    
    // member: yaw, type: float32 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 12, 4);
        js_obj.yaw = PduUtils.binToValue("float32", bin);
    }
    
    // member: rollspeed, type: float32 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 16, 4);
        js_obj.rollspeed = PduUtils.binToValue("float32", bin);
    }
    
    // member: pitchspeed, type: float32 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 20, 4);
        js_obj.pitchspeed = PduUtils.binToValue("float32", bin);
    }
    
    // member: yawspeed, type: float32 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 24, 4);
        js_obj.yawspeed = PduUtils.binToValue("float32", bin);
    }
    
    return js_obj;
}

/**
 * Serializes a HakoATTITUDE object into a binary PDU.
 * @param { HakoATTITUDE } js_obj
 * @returns {ArrayBuffer}
 */
export function jsToPdu_HakoATTITUDE(js_obj) {
    const base_allocator = new PduUtils.DynamicAllocator();
    const bw_container = new PduUtils.BinaryWriterContainer(new PduUtils.PduMetaData());

    binary_write_recursive_HakoATTITUDE(0, bw_container, base_allocator, js_obj);

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

export function binary_write_recursive_HakoATTITUDE(parent_off, bw_container, allocator, js_obj) {
    const littleEndian = true;
    // member: time_boot_ms, type: uint32 (primitive)

    
    {
        const bin = PduUtils.typeToBin("uint32", js_obj.time_boot_ms, 4);
        allocator.add(bin, parent_off + 0);
    }
    
    // member: roll, type: float32 (primitive)

    
    {
        const bin = PduUtils.typeToBin("float32", js_obj.roll, 4);
        allocator.add(bin, parent_off + 4);
    }
    
    // member: pitch, type: float32 (primitive)

    
    {
        const bin = PduUtils.typeToBin("float32", js_obj.pitch, 4);
        allocator.add(bin, parent_off + 8);
    }
    
    // member: yaw, type: float32 (primitive)

    
    {
        const bin = PduUtils.typeToBin("float32", js_obj.yaw, 4);
        allocator.add(bin, parent_off + 12);
    }
    
    // member: rollspeed, type: float32 (primitive)

    
    {
        const bin = PduUtils.typeToBin("float32", js_obj.rollspeed, 4);
        allocator.add(bin, parent_off + 16);
    }
    
    // member: pitchspeed, type: float32 (primitive)

    
    {
        const bin = PduUtils.typeToBin("float32", js_obj.pitchspeed, 4);
        allocator.add(bin, parent_off + 20);
    }
    
    // member: yawspeed, type: float32 (primitive)

    
    {
        const bin = PduUtils.typeToBin("float32", js_obj.yawspeed, 4);
        allocator.add(bin, parent_off + 24);
    }
    
}
