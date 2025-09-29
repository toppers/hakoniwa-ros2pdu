import * as PduUtils from '../pdu_utils.js';
import { HakoDroneCmdTakeoff } from './pdu_jstype_HakoDroneCmdTakeoff.js';
import { HakoDroneCmdHeader } from './pdu_jstype_HakoDroneCmdHeader.js';
import { binary_read_recursive_HakoDroneCmdHeader, binary_write_recursive_HakoDroneCmdHeader } from './pdu_conv_HakoDroneCmdHeader.js';


/**
 * Deserializes a binary PDU into a HakoDroneCmdTakeoff object.
 * @param {ArrayBuffer} binary_data
 * @returns { HakoDroneCmdTakeoff }
 */
export function pduToJs_HakoDroneCmdTakeoff(binary_data) {
    const js_obj = new HakoDroneCmdTakeoff();
    const meta_parser = new PduUtils.PduMetaDataParser();
    const meta = meta_parser.load_pdu_meta(binary_data);
    if (meta === null) {
        throw new Error("Invalid PDU binary data: MetaData not found or corrupted");
    }
    binary_read_recursive_HakoDroneCmdTakeoff(meta, binary_data, js_obj, meta.base_off);
    return js_obj;
}

export function binary_read_recursive_HakoDroneCmdTakeoff(meta, binary_data, js_obj, base_off) {
    const view = new DataView(binary_data);
    const littleEndian = true;
    // member: header, type: HakoDroneCmdHeader (struct)

    {
        const tmp_obj = new HakoDroneCmdHeader();
        binary_read_recursive_HakoDroneCmdHeader(meta, binary_data, tmp_obj, base_off + 0);
        js_obj.header = tmp_obj;
    }
    
    // member: height, type: float64 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 16, 8);
        js_obj.height = PduUtils.binToValue("float64", bin);
    }
    
    // member: speed, type: float64 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 24, 8);
        js_obj.speed = PduUtils.binToValue("float64", bin);
    }
    
    // member: yaw_deg, type: float64 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 32, 8);
        js_obj.yaw_deg = PduUtils.binToValue("float64", bin);
    }
    
    return js_obj;
}

/**
 * Serializes a HakoDroneCmdTakeoff object into a binary PDU.
 * @param { HakoDroneCmdTakeoff } js_obj
 * @returns {ArrayBuffer}
 */
export function jsToPdu_HakoDroneCmdTakeoff(js_obj) {
    const base_allocator = new PduUtils.DynamicAllocator();
    const bw_container = new PduUtils.BinaryWriterContainer(new PduUtils.PduMetaData());

    binary_write_recursive_HakoDroneCmdTakeoff(0, bw_container, base_allocator, js_obj);

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

export function binary_write_recursive_HakoDroneCmdTakeoff(parent_off, bw_container, allocator, js_obj) {
    const littleEndian = true;
    // member: header, type: HakoDroneCmdHeader (struct)

    {
        binary_write_recursive_HakoDroneCmdHeader(parent_off + 0, bw_container, allocator, js_obj.header);
    }
    
    // member: height, type: float64 (primitive)

    
    {
        const bin = PduUtils.typeToBin("float64", js_obj.height, 8);
        allocator.add(bin, parent_off + 16);
    }
    
    // member: speed, type: float64 (primitive)

    
    {
        const bin = PduUtils.typeToBin("float64", js_obj.speed, 8);
        allocator.add(bin, parent_off + 24);
    }
    
    // member: yaw_deg, type: float64 (primitive)

    
    {
        const bin = PduUtils.typeToBin("float64", js_obj.yaw_deg, 8);
        allocator.add(bin, parent_off + 32);
    }
    
}
