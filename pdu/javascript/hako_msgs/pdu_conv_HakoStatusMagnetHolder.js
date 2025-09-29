import * as PduUtils from '../pdu_utils.js';
import { HakoStatusMagnetHolder } from './pdu_jstype_HakoStatusMagnetHolder.js';


/**
 * Deserializes a binary PDU into a HakoStatusMagnetHolder object.
 * @param {ArrayBuffer} binary_data
 * @returns { HakoStatusMagnetHolder }
 */
export function pduToJs_HakoStatusMagnetHolder(binary_data) {
    const js_obj = new HakoStatusMagnetHolder();
    const meta_parser = new PduUtils.PduMetaDataParser();
    const meta = meta_parser.load_pdu_meta(binary_data);
    if (meta === null) {
        throw new Error("Invalid PDU binary data: MetaData not found or corrupted");
    }
    binary_read_recursive_HakoStatusMagnetHolder(meta, binary_data, js_obj, meta.base_off);
    return js_obj;
}

export function binary_read_recursive_HakoStatusMagnetHolder(meta, binary_data, js_obj, base_off) {
    const view = new DataView(binary_data);
    const littleEndian = true;
    // member: magnet_on, type: bool (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 0, 4);
        js_obj.magnet_on = PduUtils.binToValue("bool", bin);
    }
    
    // member: contact_on, type: bool (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 4, 4);
        js_obj.contact_on = PduUtils.binToValue("bool", bin);
    }
    
    return js_obj;
}

/**
 * Serializes a HakoStatusMagnetHolder object into a binary PDU.
 * @param { HakoStatusMagnetHolder } js_obj
 * @returns {ArrayBuffer}
 */
export function jsToPdu_HakoStatusMagnetHolder(js_obj) {
    const base_allocator = new PduUtils.DynamicAllocator();
    const bw_container = new PduUtils.BinaryWriterContainer(new PduUtils.PduMetaData());

    binary_write_recursive_HakoStatusMagnetHolder(0, bw_container, base_allocator, js_obj);

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

export function binary_write_recursive_HakoStatusMagnetHolder(parent_off, bw_container, allocator, js_obj) {
    const littleEndian = true;
    // member: magnet_on, type: bool (primitive)

    
    {
        const bin = PduUtils.typeToBin("bool", js_obj.magnet_on, 4);
        allocator.add(bin, parent_off + 0);
    }
    
    // member: contact_on, type: bool (primitive)

    
    {
        const bin = PduUtils.typeToBin("bool", js_obj.contact_on, 4);
        allocator.add(bin, parent_off + 4);
    }
    
}
