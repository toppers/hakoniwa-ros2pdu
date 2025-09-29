import * as PduUtils from '../pdu_utils.js';
import { DroneGoToRequest } from './pdu_jstype_DroneGoToRequest.js';
import { Vector3 } from '../geometry_msgs/pdu_jstype_Vector3.js';
import { binary_read_recursive_Vector3, binary_write_recursive_Vector3 } from '../geometry_msgs/pdu_conv_Vector3.js';


/**
 * Deserializes a binary PDU into a DroneGoToRequest object.
 * @param {ArrayBuffer} binary_data
 * @returns { DroneGoToRequest }
 */
export function pduToJs_DroneGoToRequest(binary_data) {
    const js_obj = new DroneGoToRequest();
    const meta_parser = new PduUtils.PduMetaDataParser();
    const meta = meta_parser.load_pdu_meta(binary_data);
    if (meta === null) {
        throw new Error("Invalid PDU binary data: MetaData not found or corrupted");
    }
    binary_read_recursive_DroneGoToRequest(meta, binary_data, js_obj, meta.base_off);
    return js_obj;
}

export function binary_read_recursive_DroneGoToRequest(meta, binary_data, js_obj, base_off) {
    const view = new DataView(binary_data);
    const littleEndian = true;
    // member: drone_name, type: string (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 0, 128);
        js_obj.drone_name = PduUtils.binToValue("string", bin);
    }
    
    // member: target_pose, type: geometry_msgs/Vector3 (struct)

    {
        const tmp_obj = new Vector3();
        binary_read_recursive_Vector3(meta, binary_data, tmp_obj, base_off + 128);
        js_obj.target_pose = tmp_obj;
    }
    
    // member: speed_m_s, type: float32 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 152, 4);
        js_obj.speed_m_s = PduUtils.binToValue("float32", bin);
    }
    
    // member: yaw_deg, type: float32 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 156, 4);
        js_obj.yaw_deg = PduUtils.binToValue("float32", bin);
    }
    
    // member: tolerance_m, type: float32 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 160, 4);
        js_obj.tolerance_m = PduUtils.binToValue("float32", bin);
    }
    
    // member: timeout_sec, type: float32 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 164, 4);
        js_obj.timeout_sec = PduUtils.binToValue("float32", bin);
    }
    
    return js_obj;
}

/**
 * Serializes a DroneGoToRequest object into a binary PDU.
 * @param { DroneGoToRequest } js_obj
 * @returns {ArrayBuffer}
 */
export function jsToPdu_DroneGoToRequest(js_obj) {
    const base_allocator = new PduUtils.DynamicAllocator();
    const bw_container = new PduUtils.BinaryWriterContainer(new PduUtils.PduMetaData());

    binary_write_recursive_DroneGoToRequest(0, bw_container, base_allocator, js_obj);

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

export function binary_write_recursive_DroneGoToRequest(parent_off, bw_container, allocator, js_obj) {
    const littleEndian = true;
    // member: drone_name, type: string (primitive)

    
    {
        const bin = PduUtils.typeToBin("string", js_obj.drone_name, 128);
        allocator.add(bin, parent_off + 0);
    }
    
    // member: target_pose, type: geometry_msgs/Vector3 (struct)

    {
        binary_write_recursive_Vector3(parent_off + 128, bw_container, allocator, js_obj.target_pose);
    }
    
    // member: speed_m_s, type: float32 (primitive)

    
    {
        const bin = PduUtils.typeToBin("float32", js_obj.speed_m_s, 4);
        allocator.add(bin, parent_off + 152);
    }
    
    // member: yaw_deg, type: float32 (primitive)

    
    {
        const bin = PduUtils.typeToBin("float32", js_obj.yaw_deg, 4);
        allocator.add(bin, parent_off + 156);
    }
    
    // member: tolerance_m, type: float32 (primitive)

    
    {
        const bin = PduUtils.typeToBin("float32", js_obj.tolerance_m, 4);
        allocator.add(bin, parent_off + 160);
    }
    
    // member: timeout_sec, type: float32 (primitive)

    
    {
        const bin = PduUtils.typeToBin("float32", js_obj.timeout_sec, 4);
        allocator.add(bin, parent_off + 164);
    }
    
}
