import * as PduUtils from '../pdu_utils.js';
import { Ev3PduSensor } from './pdu_jstype_Ev3PduSensor.js';
import { Ev3PduSensorHeader } from './pdu_jstype_Ev3PduSensorHeader.js';
import { binary_read_recursive_Ev3PduSensorHeader, binary_write_recursive_Ev3PduSensorHeader } from './pdu_conv_Ev3PduSensorHeader.js';
import { Ev3PduColorSensor } from './pdu_jstype_Ev3PduColorSensor.js';
import { binary_read_recursive_Ev3PduColorSensor, binary_write_recursive_Ev3PduColorSensor } from './pdu_conv_Ev3PduColorSensor.js';
import { Ev3PduTouchSensor } from './pdu_jstype_Ev3PduTouchSensor.js';
import { binary_read_recursive_Ev3PduTouchSensor, binary_write_recursive_Ev3PduTouchSensor } from './pdu_conv_Ev3PduTouchSensor.js';


/**
 * Deserializes a binary PDU into a Ev3PduSensor object.
 * @param {ArrayBuffer} binary_data
 * @returns { Ev3PduSensor }
 */
export function pduToJs_Ev3PduSensor(binary_data) {
    const js_obj = new Ev3PduSensor();
    const meta_parser = new PduUtils.PduMetaDataParser();
    const meta = meta_parser.load_pdu_meta(binary_data);
    if (meta === null) {
        throw new Error("Invalid PDU binary data: MetaData not found or corrupted");
    }
    binary_read_recursive_Ev3PduSensor(meta, binary_data, js_obj, meta.base_off);
    return js_obj;
}

export function binary_read_recursive_Ev3PduSensor(meta, binary_data, js_obj, base_off) {
    const view = new DataView(binary_data);
    const littleEndian = true;
    // member: head, type: Ev3PduSensorHeader (struct)

    {
        const tmp_obj = new Ev3PduSensorHeader();
        binary_read_recursive_Ev3PduSensorHeader(meta, binary_data, tmp_obj, base_off + 0);
        js_obj.head = tmp_obj;
    }
    
    // member: buttons, type: uint8 (primitive)

    
    {
        const array_bin = PduUtils.readBinary(binary_data, base_off + 152, 1);
        js_obj.buttons = PduUtils.binToArrayValues("uint8", array_bin, 1);
    }
    
    // member: color_sensors, type: Ev3PduColorSensor (struct)

    {
        const array_size = 2;
        const one_elm_size = 40 / array_size;
        const array_value = [];
        for (let i = 0; i < array_size; i++) {
            const tmp_obj = new Ev3PduColorSensor();
            const item_offset = base_off + 156 + (i * one_elm_size);
            binary_read_recursive_Ev3PduColorSensor(meta, binary_data, tmp_obj, item_offset);
            array_value.push(tmp_obj);
        }
        js_obj.color_sensors = array_value;
    }
    
    // member: touch_sensors, type: Ev3PduTouchSensor (struct)

    {
        const array_size = 2;
        const one_elm_size = 8 / array_size;
        const array_value = [];
        for (let i = 0; i < array_size; i++) {
            const tmp_obj = new Ev3PduTouchSensor();
            const item_offset = base_off + 196 + (i * one_elm_size);
            binary_read_recursive_Ev3PduTouchSensor(meta, binary_data, tmp_obj, item_offset);
            array_value.push(tmp_obj);
        }
        js_obj.touch_sensors = array_value;
    }
    
    // member: motor_angle, type: uint32 (primitive)

    
    {
        const array_bin = PduUtils.readBinary(binary_data, base_off + 204, 12);
        js_obj.motor_angle = PduUtils.binToArrayValues("uint32", array_bin, 3);
    }
    
    // member: gyro_degree, type: int32 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 216, 4);
        js_obj.gyro_degree = PduUtils.binToValue("int32", bin);
    }
    
    // member: gyro_degree_rate, type: int32 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 220, 4);
        js_obj.gyro_degree_rate = PduUtils.binToValue("int32", bin);
    }
    
    // member: sensor_ultrasonic, type: uint32 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 224, 4);
        js_obj.sensor_ultrasonic = PduUtils.binToValue("uint32", bin);
    }
    
    // member: gps_lat, type: float64 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 232, 8);
        js_obj.gps_lat = PduUtils.binToValue("float64", bin);
    }
    
    // member: gps_lon, type: float64 (primitive)

    
    {
        const bin = PduUtils.readBinary(binary_data, base_off + 240, 8);
        js_obj.gps_lon = PduUtils.binToValue("float64", bin);
    }
    
    return js_obj;
}

/**
 * Serializes a Ev3PduSensor object into a binary PDU.
 * @param { Ev3PduSensor } js_obj
 * @returns {ArrayBuffer}
 */
export function jsToPdu_Ev3PduSensor(js_obj) {
    const base_allocator = new PduUtils.DynamicAllocator();
    const bw_container = new PduUtils.BinaryWriterContainer(new PduUtils.PduMetaData());

    binary_write_recursive_Ev3PduSensor(0, bw_container, base_allocator, js_obj);

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

export function binary_write_recursive_Ev3PduSensor(parent_off, bw_container, allocator, js_obj) {
    const littleEndian = true;
    // member: head, type: Ev3PduSensorHeader (struct)

    {
        binary_write_recursive_Ev3PduSensorHeader(parent_off + 0, bw_container, allocator, js_obj.head);
    }
    
    // member: buttons, type: uint8 (primitive)

    
    {
        const buffer = PduUtils.typesToBin("uint8", js_obj.buttons);
        allocator.add(buffer, parent_off + 152);
    }
    
    // member: color_sensors, type: Ev3PduColorSensor (struct)

    {
        const one_elm_size = 40 / 2;
        for (let i = 0; i < 2; i++) {
            binary_write_recursive_Ev3PduColorSensor(parent_off + 156 + (i * one_elm_size), bw_container, allocator, js_obj.color_sensors[i]);
        }
    }
    
    // member: touch_sensors, type: Ev3PduTouchSensor (struct)

    {
        const one_elm_size = 8 / 2;
        for (let i = 0; i < 2; i++) {
            binary_write_recursive_Ev3PduTouchSensor(parent_off + 196 + (i * one_elm_size), bw_container, allocator, js_obj.touch_sensors[i]);
        }
    }
    
    // member: motor_angle, type: uint32 (primitive)

    
    {
        const buffer = PduUtils.typesToBin("uint32", js_obj.motor_angle);
        allocator.add(buffer, parent_off + 204);
    }
    
    // member: gyro_degree, type: int32 (primitive)

    
    {
        const bin = PduUtils.typeToBin("int32", js_obj.gyro_degree, 4);
        allocator.add(bin, parent_off + 216);
    }
    
    // member: gyro_degree_rate, type: int32 (primitive)

    
    {
        const bin = PduUtils.typeToBin("int32", js_obj.gyro_degree_rate, 4);
        allocator.add(bin, parent_off + 220);
    }
    
    // member: sensor_ultrasonic, type: uint32 (primitive)

    
    {
        const bin = PduUtils.typeToBin("uint32", js_obj.sensor_ultrasonic, 4);
        allocator.add(bin, parent_off + 224);
    }
    
    // member: gps_lat, type: float64 (primitive)

    
    {
        const bin = PduUtils.typeToBin("float64", js_obj.gps_lat, 8);
        allocator.add(bin, parent_off + 232);
    }
    
    // member: gps_lon, type: float64 (primitive)

    
    {
        const bin = PduUtils.typeToBin("float64", js_obj.gps_lon, 8);
        allocator.add(bin, parent_off + 240);
    }
    
}
