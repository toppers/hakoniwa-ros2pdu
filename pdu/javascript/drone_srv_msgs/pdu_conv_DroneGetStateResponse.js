import * as PduUtils from '../pdu_utils.js';
import { DroneGetStateResponse } from './pdu_jstype_DroneGetStateResponse.js';
import { Pose } from '../geometry_msgs/pdu_jstype_Pose.js';
import { binary_read_recursive_Pose, binary_write_recursive_Pose } from '../geometry_msgs/pdu_conv_Pose.js';
import { HakoBatteryStatus } from '../hako_msgs/pdu_jstype_HakoBatteryStatus.js';
import { binary_read_recursive_HakoBatteryStatus, binary_write_recursive_HakoBatteryStatus } from '../hako_msgs/pdu_conv_HakoBatteryStatus.js';


/**
 * Deserializes a binary PDU into a DroneGetStateResponse object.
 * @param {ArrayBuffer} binary_data
 * @returns { DroneGetStateResponse }
 */
export function pduToJs_DroneGetStateResponse(binary_data) {
    const js_obj = new DroneGetStateResponse();
    const meta_parser = new PduUtils.PduMetaDataParser();
    const meta = meta_parser.load_pdu_meta(binary_data);
    if (meta === null) {
        throw new Error("Invalid PDU binary data: MetaData not found or corrupted");
    }
    binary_read_recursive_DroneGetStateResponse(meta, binary_data, js_obj, meta.base_off);
    return js_obj;
}

export function binary_read_recursive_DroneGetStateResponse(meta, binary_data, js_obj, base_off) {
    const view = new DataView(binary_data);
    const littleEndian = true;
    // member: ok, type: bool (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 0, 4);
        js_obj.ok = PduUtils.binToValue("bool", bin);
    }
    
    // member: is_ready, type: bool (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 4, 4);
        js_obj.is_ready = PduUtils.binToValue("bool", bin);
    }
    
    // member: current_pose, type: geometry_msgs/Pose (struct)

    {
        const tmp_obj = new Pose();
        binary_read_recursive_Pose(meta, binary_data, tmp_obj, base_off + 8);
        js_obj.current_pose = tmp_obj;
    }
    
    // member: battery_status, type: hako_msgs/HakoBatteryStatus (struct)

    {
        const tmp_obj = new HakoBatteryStatus();
        binary_read_recursive_HakoBatteryStatus(meta, binary_data, tmp_obj, base_off + 64);
        js_obj.battery_status = tmp_obj;
    }
    
    // member: mode, type: string (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 96, 128);
        js_obj.mode = PduUtils.binToValue("string", bin);
    }
    
    // member: message, type: string (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 224, 128);
        js_obj.message = PduUtils.binToValue("string", bin);
    }
    
    return js_obj;
}

/**
 * Serializes a DroneGetStateResponse object into a binary PDU.
 * @param { DroneGetStateResponse } js_obj
 * @returns {ArrayBuffer}
 */
export function jsToPdu_DroneGetStateResponse(js_obj) {
    const base_allocator = new PduUtils.DynamicAllocator();
    const bw_container = new PduUtils.BinaryWriterContainer(new PduUtils.PduMetaData());

    binary_write_recursive_DroneGetStateResponse(0, bw_container, base_allocator, js_obj);

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

export function binary_write_recursive_DroneGetStateResponse(parent_off, bw_container, allocator, js_obj) {
    const littleEndian = true;
    // member: ok, type: bool (primitive)

    
    {
        const bin = PduUtils.typeToBin("bool", js_obj.ok, 4);
        allocator.add(bin, parent_off + 0);
    }
    
    // member: is_ready, type: bool (primitive)

    
    {
        const bin = PduUtils.typeToBin("bool", js_obj.is_ready, 4);
        allocator.add(bin, parent_off + 4);
    }
    
    // member: current_pose, type: geometry_msgs/Pose (struct)

    {
        binary_write_recursive_Pose(parent_off + 8, bw_container, allocator, js_obj.current_pose);
    }
    
    // member: battery_status, type: hako_msgs/HakoBatteryStatus (struct)

    {
        binary_write_recursive_HakoBatteryStatus(parent_off + 64, bw_container, allocator, js_obj.battery_status);
    }
    
    // member: mode, type: string (primitive)

    
    {
        const bin = PduUtils.typeToBin("string", js_obj.mode, 128);
        allocator.add(bin, parent_off + 96);
    }
    
    // member: message, type: string (primitive)

    
    {
        const bin = PduUtils.typeToBin("string", js_obj.message, 128);
        allocator.add(bin, parent_off + 224);
    }
    
}
