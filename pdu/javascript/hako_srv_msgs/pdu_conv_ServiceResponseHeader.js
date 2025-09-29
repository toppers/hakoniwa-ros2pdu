import * as PduUtils from '../pdu_utils.js';
import { ServiceResponseHeader } from './pdu_jstype_ServiceResponseHeader.js';


/**
 * Deserializes a binary PDU into a ServiceResponseHeader object.
 * @param {ArrayBuffer} binary_data
 * @returns { ServiceResponseHeader }
 */
export function pduToJs_ServiceResponseHeader(binary_data) {
    const js_obj = new ServiceResponseHeader();
    const meta_parser = new PduUtils.PduMetaDataParser();
    const meta = meta_parser.load_pdu_meta(binary_data);
    if (meta === null) {
        throw new Error("Invalid PDU binary data: MetaData not found or corrupted");
    }
    binary_read_recursive_ServiceResponseHeader(meta, binary_data, js_obj, meta.base_off);
    return js_obj;
}

export function binary_read_recursive_ServiceResponseHeader(meta, binary_data, js_obj, base_off) {
    const view = new DataView(binary_data);
    const littleEndian = true;
    // member: request_id, type: uint32 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 0, 4);
        js_obj.request_id = PduUtils.binToValue("uint32", bin);
    }
    
    // member: service_name, type: string (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 4, 128);
        js_obj.service_name = PduUtils.binToValue("string", bin);
    }
    
    // member: client_name, type: string (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 132, 128);
        js_obj.client_name = PduUtils.binToValue("string", bin);
    }
    
    // member: status, type: uint8 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 260, 1);
        js_obj.status = PduUtils.binToValue("uint8", bin);
    }
    
    // member: processing_percentage, type: uint8 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 261, 1);
        js_obj.processing_percentage = PduUtils.binToValue("uint8", bin);
    }
    
    // member: result_code, type: int32 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 264, 4);
        js_obj.result_code = PduUtils.binToValue("int32", bin);
    }
    
    return js_obj;
}

/**
 * Serializes a ServiceResponseHeader object into a binary PDU.
 * @param { ServiceResponseHeader } js_obj
 * @returns {ArrayBuffer}
 */
export function jsToPdu_ServiceResponseHeader(js_obj) {
    const base_allocator = new PduUtils.DynamicAllocator();
    const bw_container = new PduUtils.BinaryWriterContainer(new PduUtils.PduMetaData());

    binary_write_recursive_ServiceResponseHeader(0, bw_container, base_allocator, js_obj);

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

export function binary_write_recursive_ServiceResponseHeader(parent_off, bw_container, allocator, js_obj) {
    const littleEndian = true;
    // member: request_id, type: uint32 (primitive)

    
    {
        const bin = PduUtils.typeToBin("uint32", js_obj.request_id, 4);
        allocator.add(bin, parent_off + 0);
    }
    
    // member: service_name, type: string (primitive)

    
    {
        const bin = PduUtils.typeToBin("string", js_obj.service_name, 128);
        allocator.add(bin, parent_off + 4);
    }
    
    // member: client_name, type: string (primitive)

    
    {
        const bin = PduUtils.typeToBin("string", js_obj.client_name, 128);
        allocator.add(bin, parent_off + 132);
    }
    
    // member: status, type: uint8 (primitive)

    
    {
        const bin = PduUtils.typeToBin("uint8", js_obj.status, 1);
        allocator.add(bin, parent_off + 260);
    }
    
    // member: processing_percentage, type: uint8 (primitive)

    
    {
        const bin = PduUtils.typeToBin("uint8", js_obj.processing_percentage, 1);
        allocator.add(bin, parent_off + 261);
    }
    
    // member: result_code, type: int32 (primitive)

    
    {
        const bin = PduUtils.typeToBin("int32", js_obj.result_code, 4);
        allocator.add(bin, parent_off + 264);
    }
    
}
