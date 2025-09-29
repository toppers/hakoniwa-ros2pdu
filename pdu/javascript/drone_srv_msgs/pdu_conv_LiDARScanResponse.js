import * as PduUtils from '../pdu_utils.js';
import { LiDARScanResponse } from './pdu_jstype_LiDARScanResponse.js';
import { PointCloud2 } from '../sensor_msgs/pdu_jstype_PointCloud2.js';
import { binary_read_recursive_PointCloud2, binary_write_recursive_PointCloud2 } from '../sensor_msgs/pdu_conv_PointCloud2.js';
import { Pose } from '../geometry_msgs/pdu_jstype_Pose.js';
import { binary_read_recursive_Pose, binary_write_recursive_Pose } from '../geometry_msgs/pdu_conv_Pose.js';


/**
 * Deserializes a binary PDU into a LiDARScanResponse object.
 * @param {ArrayBuffer} binary_data
 * @returns { LiDARScanResponse }
 */
export function pduToJs_LiDARScanResponse(binary_data) {
    const js_obj = new LiDARScanResponse();
    const meta_parser = new PduUtils.PduMetaDataParser();
    const meta = meta_parser.load_pdu_meta(binary_data);
    if (meta === null) {
        throw new Error("Invalid PDU binary data: MetaData not found or corrupted");
    }
    binary_read_recursive_LiDARScanResponse(meta, binary_data, js_obj, meta.base_off);
    return js_obj;
}

export function binary_read_recursive_LiDARScanResponse(meta, binary_data, js_obj, base_off) {
    const view = new DataView(binary_data);
    const littleEndian = true;
    // member: ok, type: bool (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 0, 4);
        js_obj.ok = PduUtils.binToValue("bool", bin);
    }
    
    // member: point_cloud, type: sensor_msgs/PointCloud2 (struct)

    {
        const tmp_obj = new PointCloud2();
        binary_read_recursive_PointCloud2(meta, binary_data, tmp_obj, base_off + 4);
        js_obj.point_cloud = tmp_obj;
    }
    
    // member: lidar_pose, type: geometry_msgs/Pose (struct)

    {
        const tmp_obj = new Pose();
        binary_read_recursive_Pose(meta, binary_data, tmp_obj, base_off + 184);
        js_obj.lidar_pose = tmp_obj;
    }
    
    // member: message, type: string (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 240, 128);
        js_obj.message = PduUtils.binToValue("string", bin);
    }
    
    return js_obj;
}

/**
 * Serializes a LiDARScanResponse object into a binary PDU.
 * @param { LiDARScanResponse } js_obj
 * @returns {ArrayBuffer}
 */
export function jsToPdu_LiDARScanResponse(js_obj) {
    const base_allocator = new PduUtils.DynamicAllocator();
    const bw_container = new PduUtils.BinaryWriterContainer(new PduUtils.PduMetaData());

    binary_write_recursive_LiDARScanResponse(0, bw_container, base_allocator, js_obj);

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

export function binary_write_recursive_LiDARScanResponse(parent_off, bw_container, allocator, js_obj) {
    const littleEndian = true;
    // member: ok, type: bool (primitive)

    
    {
        const bin = PduUtils.typeToBin("bool", js_obj.ok, 4);
        allocator.add(bin, parent_off + 0);
    }
    
    // member: point_cloud, type: sensor_msgs/PointCloud2 (struct)

    {
        binary_write_recursive_PointCloud2(parent_off + 4, bw_container, allocator, js_obj.point_cloud);
    }
    
    // member: lidar_pose, type: geometry_msgs/Pose (struct)

    {
        binary_write_recursive_Pose(parent_off + 184, bw_container, allocator, js_obj.lidar_pose);
    }
    
    // member: message, type: string (primitive)

    
    {
        const bin = PduUtils.typeToBin("string", js_obj.message, 128);
        allocator.add(bin, parent_off + 240);
    }
    
}
