import * as PduUtils from '../pdu_utils.js';
import { HakoCan } from './pdu_jstype_HakoCan.js';
import { HakoCanHead } from './pdu_jstype_HakoCanHead.js';
import { binary_read_recursive_HakoCanHead, binary_write_recursive_HakoCanHead } from './pdu_conv_HakoCanHead.js';
import { HakoCanBody } from './pdu_jstype_HakoCanBody.js';
import { binary_read_recursive_HakoCanBody, binary_write_recursive_HakoCanBody } from './pdu_conv_HakoCanBody.js';


/**
 * Deserializes a binary PDU into a HakoCan object.
 * @param {ArrayBuffer} binary_data
 * @returns { HakoCan }
 */
export function pduToJs_HakoCan(binary_data) {
    const js_obj = new HakoCan();
    const meta_parser = new PduUtils.PduMetaDataParser();
    const meta = meta_parser.load_pdu_meta(binary_data);
    if (meta === null) {
        throw new Error("Invalid PDU binary data: MetaData not found or corrupted");
    }
    binary_read_recursive_HakoCan(meta, binary_data, js_obj, meta.base_off);
    return js_obj;
}

export function binary_read_recursive_HakoCan(meta, binary_data, js_obj, base_off) {
    const view = new DataView(binary_data);
    const littleEndian = true;
    // member: head, type: HakoCanHead (struct)

    {
        const tmp_obj = new HakoCanHead();
        binary_read_recursive_HakoCanHead(meta, binary_data, tmp_obj, base_off + 0);
        js_obj.head = tmp_obj;
    }
    
    // member: body, type: HakoCanBody (struct)

    {
        const tmp_obj = new HakoCanBody();
        binary_read_recursive_HakoCanBody(meta, binary_data, tmp_obj, base_off + 20);
        js_obj.body = tmp_obj;
    }
    
    return js_obj;
}

/**
 * Serializes a HakoCan object into a binary PDU.
 * @param { HakoCan } js_obj
 * @returns {ArrayBuffer}
 */
export function jsToPdu_HakoCan(js_obj) {
    const base_allocator = new PduUtils.DynamicAllocator();
    const bw_container = new PduUtils.BinaryWriterContainer(new PduUtils.PduMetaData());

    binary_write_recursive_HakoCan(0, bw_container, base_allocator, js_obj);

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

export function binary_write_recursive_HakoCan(parent_off, bw_container, allocator, js_obj) {
    const littleEndian = true;
    // member: head, type: HakoCanHead (struct)

    {
        binary_write_recursive_HakoCanHead(parent_off + 0, bw_container, allocator, js_obj.head);
    }
    
    // member: body, type: HakoCanBody (struct)

    {
        binary_write_recursive_HakoCanBody(parent_off + 20, bw_container, allocator, js_obj.body);
    }
    
}
