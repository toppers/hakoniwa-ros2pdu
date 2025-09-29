import * as PduUtils from '../pdu_utils.js';
import { TwistWithCovariance } from './pdu_jstype_TwistWithCovariance.js';
import { Twist } from './pdu_jstype_Twist.js';
import { binary_read_recursive_Twist, binary_write_recursive_Twist } from './pdu_conv_Twist.js';


/**
 * Deserializes a binary PDU into a TwistWithCovariance object.
 * @param {ArrayBuffer} binary_data
 * @returns { TwistWithCovariance }
 */
export function pduToJs_TwistWithCovariance(binary_data) {
    const js_obj = new TwistWithCovariance();
    const meta_parser = new PduUtils.PduMetaDataParser();
    const meta = meta_parser.load_pdu_meta(binary_data);
    if (meta === null) {
        throw new Error("Invalid PDU binary data: MetaData not found or corrupted");
    }
    binary_read_recursive_TwistWithCovariance(meta, binary_data, js_obj, meta.base_off);
    return js_obj;
}

export function binary_read_recursive_TwistWithCovariance(meta, binary_data, js_obj, base_off) {
    const view = new DataView(binary_data);
    const littleEndian = true;
    // member: twist, type: Twist (struct)

    {
        const tmp_obj = new Twist();
        binary_read_recursive_Twist(meta, binary_data, tmp_obj, base_off + 0);
        js_obj.twist = tmp_obj;
    }
    
    // member: covariance, type: float64 (primitive)

    
    {
        const array_bin = PduUtils.readBinary(binary_data, base_off + 48, 288);
        js_obj.covariance = PduUtils.binToArrayValues("float64", array_bin, 36);
    }
    
    return js_obj;
}

/**
 * Serializes a TwistWithCovariance object into a binary PDU.
 * @param { TwistWithCovariance } js_obj
 * @returns {ArrayBuffer}
 */
export function jsToPdu_TwistWithCovariance(js_obj) {
    const base_allocator = new PduUtils.DynamicAllocator();
    const bw_container = new PduUtils.BinaryWriterContainer(new PduUtils.PduMetaData());

    binary_write_recursive_TwistWithCovariance(0, bw_container, base_allocator, js_obj);

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

export function binary_write_recursive_TwistWithCovariance(parent_off, bw_container, allocator, js_obj) {
    const littleEndian = true;
    // member: twist, type: Twist (struct)

    {
        binary_write_recursive_Twist(parent_off + 0, bw_container, allocator, js_obj.twist);
    }
    
    // member: covariance, type: float64 (primitive)

    
    {
        const buffer = PduUtils.typesToBin("float64", js_obj.covariance);
        allocator.add(buffer, parent_off + 48);
    }
    
}
