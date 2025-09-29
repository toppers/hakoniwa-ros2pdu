import * as PduUtils from '../pdu_utils.js';
import { DroneStatus } from './pdu_jstype_DroneStatus.js';
import { Vector3 } from '../geometry_msgs/pdu_jstype_Vector3.js';
import { binary_read_recursive_Vector3, binary_write_recursive_Vector3 } from '../geometry_msgs/pdu_conv_Vector3.js';


/**
 * Deserializes a binary PDU into a DroneStatus object.
 * @param {ArrayBuffer} binary_data
 * @returns { DroneStatus }
 */
export function pduToJs_DroneStatus(binary_data) {
    const js_obj = new DroneStatus();
    const meta_parser = new PduUtils.PduMetaDataParser();
    const meta = meta_parser.load_pdu_meta(binary_data);
    if (meta === null) {
        throw new Error("Invalid PDU binary data: MetaData not found or corrupted");
    }
    binary_read_recursive_DroneStatus(meta, binary_data, js_obj, meta.base_off);
    return js_obj;
}

export function binary_read_recursive_DroneStatus(meta, binary_data, js_obj, base_off) {
    const view = new DataView(binary_data);
    const littleEndian = true;
    // member: flight_mode, type: int32 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 0, 4);
        js_obj.flight_mode = PduUtils.binToValue("int32", bin);
    }
    
    // member: internal_state, type: int32 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 4, 4);
        js_obj.internal_state = PduUtils.binToValue("int32", bin);
    }
    
    // member: propeller_wind, type: geometry_msgs/Vector3 (struct)

    {
        const tmp_obj = new Vector3();
        binary_read_recursive_Vector3(meta, binary_data, tmp_obj, base_off + 8);
        js_obj.propeller_wind = tmp_obj;
    }
    
    return js_obj;
}

/**
 * Serializes a DroneStatus object into a binary PDU.
 * @param { DroneStatus } js_obj
 * @returns {ArrayBuffer}
 */
export function jsToPdu_DroneStatus(js_obj) {
    const base_allocator = new PduUtils.DynamicAllocator();
    const bw_container = new PduUtils.BinaryWriterContainer(new PduUtils.PduMetaData());

    binary_write_recursive_DroneStatus(0, bw_container, base_allocator, js_obj);

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

export function binary_write_recursive_DroneStatus(parent_off, bw_container, allocator, js_obj) {
    const littleEndian = true;
    // member: flight_mode, type: int32 (primitive)

    
    {
        const bin = PduUtils.typeToBin("int32", js_obj.flight_mode, 4);
        allocator.add(bin, parent_off + 0);
    }
    
    // member: internal_state, type: int32 (primitive)

    
    {
        const bin = PduUtils.typeToBin("int32", js_obj.internal_state, 4);
        allocator.add(bin, parent_off + 4);
    }
    
    // member: propeller_wind, type: geometry_msgs/Vector3 (struct)

    {
        binary_write_recursive_Vector3(parent_off + 8, bw_container, allocator, js_obj.propeller_wind);
    }
    
}
