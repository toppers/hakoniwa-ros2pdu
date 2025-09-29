import * as PduUtils from '../pdu_utils.js';
import { GameControllerOperation } from './pdu_jstype_GameControllerOperation.js';


/**
 * Deserializes a binary PDU into a GameControllerOperation object.
 * @param {ArrayBuffer} binary_data
 * @returns { GameControllerOperation }
 */
export function pduToJs_GameControllerOperation(binary_data) {
    const js_obj = new GameControllerOperation();
    const meta_parser = new PduUtils.PduMetaDataParser();
    const meta = meta_parser.load_pdu_meta(binary_data);
    if (meta === null) {
        throw new Error("Invalid PDU binary data: MetaData not found or corrupted");
    }
    binary_read_recursive_GameControllerOperation(meta, binary_data, js_obj, meta.base_off);
    return js_obj;
}

export function binary_read_recursive_GameControllerOperation(meta, binary_data, js_obj, base_off) {
    const view = new DataView(binary_data);
    const littleEndian = true;
    // member: axis, type: float64 (primitive)

    
    {
        const array_bin = PduUtils.readBinary(binary_data, base_off + 0, 48);
        js_obj.axis = PduUtils.binToArrayValues("float64", array_bin, 6);
    }
    
    // member: button, type: bool (primitive)

    
    {
        const array_bin = PduUtils.readBinary(binary_data, base_off + 48, 60);
        js_obj.button = PduUtils.binToArrayValues("bool", array_bin, 15);
    }
    
    return js_obj;
}

/**
 * Serializes a GameControllerOperation object into a binary PDU.
 * @param { GameControllerOperation } js_obj
 * @returns {ArrayBuffer}
 */
export function jsToPdu_GameControllerOperation(js_obj) {
    const base_allocator = new PduUtils.DynamicAllocator();
    const bw_container = new PduUtils.BinaryWriterContainer(new PduUtils.PduMetaData());

    binary_write_recursive_GameControllerOperation(0, bw_container, base_allocator, js_obj);

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

export function binary_write_recursive_GameControllerOperation(parent_off, bw_container, allocator, js_obj) {
    const littleEndian = true;
    // member: axis, type: float64 (primitive)

    
    {
        const buffer = PduUtils.typesToBin("float64", js_obj.axis);
        allocator.add(buffer, parent_off + 0);
    }
    
    // member: button, type: bool (primitive)

    
    {
        const buffer = PduUtils.typesToBin("bool", js_obj.button);
        allocator.add(buffer, parent_off + 48);
    }
    
}
