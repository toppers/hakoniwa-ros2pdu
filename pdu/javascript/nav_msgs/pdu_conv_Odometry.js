import * as PduUtils from '../pdu_utils.js';
import { Odometry } from './pdu_jstype_Odometry.js';
import { Header } from '../std_msgs/pdu_jstype_Header.js';
import { binary_read_recursive_Header, binary_write_recursive_Header } from '../std_msgs/pdu_conv_Header.js';
import { PoseWithCovariance } from '../geometry_msgs/pdu_jstype_PoseWithCovariance.js';
import { binary_read_recursive_PoseWithCovariance, binary_write_recursive_PoseWithCovariance } from '../geometry_msgs/pdu_conv_PoseWithCovariance.js';
import { TwistWithCovariance } from '../geometry_msgs/pdu_jstype_TwistWithCovariance.js';
import { binary_read_recursive_TwistWithCovariance, binary_write_recursive_TwistWithCovariance } from '../geometry_msgs/pdu_conv_TwistWithCovariance.js';


/**
 * Deserializes a binary PDU into a Odometry object.
 * @param {ArrayBuffer} binary_data
 * @returns { Odometry }
 */
export function pduToJs_Odometry(binary_data) {
    const js_obj = new Odometry();
    const meta_parser = new PduUtils.PduMetaDataParser();
    const meta = meta_parser.load_pdu_meta(binary_data);
    if (meta === null) {
        throw new Error("Invalid PDU binary data: MetaData not found or corrupted");
    }
    binary_read_recursive_Odometry(meta, binary_data, js_obj, meta.base_off);
    return js_obj;
}

export function binary_read_recursive_Odometry(meta, binary_data, js_obj, base_off) {
    const view = new DataView(binary_data);
    const littleEndian = true;
    // member: header, type: std_msgs/Header (struct)

    {
        const tmp_obj = new Header();
        binary_read_recursive_Header(meta, binary_data, tmp_obj, base_off + 0);
        js_obj.header = tmp_obj;
    }
    
    // member: child_frame_id, type: string (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 136, 128);
        js_obj.child_frame_id = PduUtils.binToValue("string", bin);
    }
    
    // member: pose, type: geometry_msgs/PoseWithCovariance (struct)

    {
        const tmp_obj = new PoseWithCovariance();
        binary_read_recursive_PoseWithCovariance(meta, binary_data, tmp_obj, base_off + 264);
        js_obj.pose = tmp_obj;
    }
    
    // member: twist, type: geometry_msgs/TwistWithCovariance (struct)

    {
        const tmp_obj = new TwistWithCovariance();
        binary_read_recursive_TwistWithCovariance(meta, binary_data, tmp_obj, base_off + 608);
        js_obj.twist = tmp_obj;
    }
    
    return js_obj;
}

/**
 * Serializes a Odometry object into a binary PDU.
 * @param { Odometry } js_obj
 * @returns {ArrayBuffer}
 */
export function jsToPdu_Odometry(js_obj) {
    const base_allocator = new PduUtils.DynamicAllocator();
    const bw_container = new PduUtils.BinaryWriterContainer(new PduUtils.PduMetaData());

    binary_write_recursive_Odometry(0, bw_container, base_allocator, js_obj);

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

export function binary_write_recursive_Odometry(parent_off, bw_container, allocator, js_obj) {
    const littleEndian = true;
    // member: header, type: std_msgs/Header (struct)

    {
        binary_write_recursive_Header(parent_off + 0, bw_container, allocator, js_obj.header);
    }
    
    // member: child_frame_id, type: string (primitive)

    
    {
        const bin = PduUtils.typeToBin("string", js_obj.child_frame_id, 128);
        allocator.add(bin, parent_off + 136);
    }
    
    // member: pose, type: geometry_msgs/PoseWithCovariance (struct)

    {
        binary_write_recursive_PoseWithCovariance(parent_off + 264, bw_container, allocator, js_obj.pose);
    }
    
    // member: twist, type: geometry_msgs/TwistWithCovariance (struct)

    {
        binary_write_recursive_TwistWithCovariance(parent_off + 608, bw_container, allocator, js_obj.twist);
    }
    
}
