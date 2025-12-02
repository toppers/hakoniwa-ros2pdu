/**
 * @file pdu_utils.js
 * @brief JavaScript PDU serialization/deserialization utilities.
 */

export const PDU_META_DATA_SIZE = 24;

/**
 * Manages a dynamically growing ArrayBuffer.
 */
export class DynamicAllocator {
    constructor() {
        this.buffer = new ArrayBuffer(1024); // Initial size
        this.length = 0;
    }

    _ensure_capacity(required) {
        while (this.buffer.byteLength < this.length + required) {
            const new_buffer = new ArrayBuffer(this.buffer.byteLength * 2);
            new Uint8Array(new_buffer).set(new Uint8Array(this.buffer));
            this.buffer = new_buffer;
        }
    }

    add(data_buffer, expected_offset = -1) {
        if (expected_offset !== -1 && this.length !== expected_offset) {
            if (this.length < expected_offset) {
                this._ensure_capacity(expected_offset - this.length);
                this.length = expected_offset;
            } else {
                // Overlapping write, should be handled carefully
            }
        }
        this._ensure_capacity(data_buffer.byteLength);
        new Uint8Array(this.buffer).set(new Uint8Array(data_buffer), this.length);
        this.length += data_buffer.byteLength;
        return this.length - data_buffer.byteLength; // Return start offset of added data
    }

    size() {
        return this.length;
    }

    toArray() {
        return this.buffer.slice(0, this.length);
    }
}

/**
 * Container for binary writers.
 */
export class BinaryWriterContainer {
    constructor(meta) {
        this.meta = meta;
        this.heap_allocator = new DynamicAllocator();
    }
}


/**
 * A class to represent and serialize PDU metadata.
 */
export class PduMetaData {
    constructor() {
        this.magic = 0x12345678;
        this.version = 1;
        this.base_off = PDU_META_DATA_SIZE;
        this.heap_off = 0;
        this.total_size = 0;
    }

    to_bytes() {
        const buffer = new ArrayBuffer(PDU_META_DATA_SIZE);
        const view = new DataView(buffer);
        view.setUint32(0, this.magic, true);
        view.setUint32(4, this.version, true);
        view.setUint32(8, this.base_off, true);
        view.setUint32(12, this.heap_off, true);
        view.setUint32(16, this.total_size, true);
        // Bytes 20-23 are reserved/unused
        return buffer;
    }
}

/**
 * A class to parse PDU metadata from a binary buffer.
 */
export class PduMetaDataParser {
    /**
     * @param {ArrayBuffer} binary_data
     * @returns {object|null} Parsed metadata or null if invalid.
     */
    load_pdu_meta(binary_data) {
        //console.log(`[DEBUG] load_pdu_meta: received ${binary_data.byteLength} bytes.`);
        if (binary_data.byteLength < PDU_META_DATA_SIZE) {
            console.error("[DEBUG] Data length is less than metadata size.");
            return null;
        }
        const view = new DataView(binary_data);
        const magic = view.getUint32(0, true);
        //console.log(`[DEBUG] Magic number read: 0x${magic.toString(16)}`);
        if (magic !== 0x12345678) {
            return null;
        }
        return {
            magic: magic,
            version: view.getUint32(4, true),
            base_off: view.getUint32(8, true),
            heap_off: view.getUint32(12, true),
            total_size: view.getUint32(16, true),
        };
    }
}

/**
 * Reads a slice of an ArrayBuffer.
 * @param {ArrayBuffer} buffer
 * @param {number} offset
 * @param {number} length
 * @returns {ArrayBuffer}
 */
export function readBinary(buffer, offset, length) {
    return buffer.slice(offset, offset + length);
}

/**
 * Writes data from a source buffer to a destination buffer.
 * @param {Uint8Array} dst - Note: Uint8Array for efficient set operation
 * @param {number} offset
 * @param {ArrayBuffer} src
 */
export function writeBinary(dst, offset, src) {
    dst.set(new Uint8Array(src), offset);
}

/**
 * Converts a binary buffer to a specific primitive value.
 * @param {string} type_name - ROS primitive type name.
 * @param {ArrayBuffer} bin - The binary buffer.
 * @returns {number|bigint|boolean|string}
 */
export function binToValue(type_name, bin) {
    const view = new DataView(bin);
    const littleEndian = true;
    switch (type_name) {
        case 'bool':
            return view.getUint8(0) !== 0;
        case 'byte':
        case 'uint8':
            return view.getUint8(0);
        case 'char': // Assuming char is treated as a single byte
            return String.fromCharCode(view.getUint8(0));
        case 'int8':
            return view.getInt8(0);
        case 'int16':
            return view.getInt16(0, littleEndian);
        case 'uint16':
            return view.getUint16(0, littleEndian);
        case 'int32':
            return view.getInt32(0, littleEndian);
        case 'uint32':
            return view.getUint32(0, littleEndian);
        case 'int64':
            return view.getBigInt64(0, littleEndian);
        case 'uint64':
            return view.getBigUint64(0, littleEndian);
        case 'float32':
            return view.getFloat32(0, littleEndian);
        case 'float64':
            return view.getFloat64(0, littleEndian);
        case 'string':
            // Find the null terminator
            const end = new Uint8Array(bin).indexOf(0);
            const buffer = end !== -1 ? bin.slice(0, end) : bin;
            return new TextDecoder().decode(buffer);
        default:
            throw new Error(`Unsupported primitive type for binToValue: ${type_name}`);
    }
}

/**
 * Converts a binary buffer to an array of primitive values.
 * @param {string} type_name - ROS primitive type name.
 * @param {ArrayBuffer} bin - The binary buffer containing the array data.
 * @param {number} count - The number of elements in the array.
 * @returns {Array<number|bigint|boolean>}
 */
export function binToArrayValues(type_name, bin, count) {
    const values = [];
    const view = new DataView(bin);
    const littleEndian = true;
    let offset = 0;
    let type_size = 0;

    for (let i = 0; i < count; i++) {
        switch (type_name) {
            case 'bool':
                values.push(view.getUint32(offset, littleEndian) !== 0);
                type_size = 4;
                break;
            case 'byte':
            case 'uint8':
                values.push(view.getUint8(offset));
                type_size = 1;
                break;
            case 'int8':
                values.push(view.getInt8(offset));
                type_size = 1;
                break;
            case 'int16':
                values.push(view.getInt16(offset, littleEndian));
                type_size = 2;
                break;
            case 'uint16':
                values.push(view.getUint16(offset, littleEndian));
                type_size = 2;
                break;
            case 'int32':
                values.push(view.getInt32(offset, littleEndian));
                type_size = 4;
                break;
            case 'uint32':
                values.push(view.getUint32(offset, littleEndian));
                type_size = 4;
                break;
            case 'int64':
                values.push(view.getBigInt64(offset, littleEndian));
                type_size = 8;
                break;
            case 'uint64':
                values.push(view.getBigUint64(offset, littleEndian));
                type_size = 8;
                break;
            case 'float32':
                values.push(view.getFloat32(offset, littleEndian));
                type_size = 4;
                break;
            case 'float64':
                values.push(view.getFloat64(offset, littleEndian));
                type_size = 8;
                break;
            default:
                throw new Error(`Unsupported primitive type for binToArrayValues: ${type_name}`);
        }
        offset += type_size;
    }
    return values;
}

/**
 * Converts a primitive JS value to a binary ArrayBuffer.
 * @param {string} type_name 
 * @param {any} value 
 * @param {number} size - The expected byte size.
 * @returns {ArrayBuffer}
 */
export function typeToBin(type_name, value, size) {
    const buffer = new ArrayBuffer(size);
    const view = new DataView(buffer);
    const littleEndian = true;

    switch (type_name) {
        case 'bool': view.setUint32(0, value ? 1 : 0, littleEndian); break;
        case 'byte':
        case 'uint8': view.setUint8(0, value); break;
        case 'int8': view.setInt8(0, value); break;
        case 'int16': view.setInt16(0, value, littleEndian); break;
        case 'uint16': view.setUint16(0, value, littleEndian); break;
        case 'int32': view.setInt32(0, value, littleEndian); break;
        case 'uint32': view.setUint32(0, value, littleEndian); break;
        case 'int64': view.setBigInt64(0, BigInt(value), littleEndian); break;
        case 'uint64': view.setBigUint64(0, BigInt(value), littleEndian); break;
        case 'float32': view.setFloat32(0, value, littleEndian); break;
        case 'float64': view.setFloat64(0, value, littleEndian); break;
        case 'string':
            const encoded = new TextEncoder().encode(value);
            writeBinary(new Uint8Array(buffer), 0, encoded.buffer);
            // Null terminator is implicitly added if buffer is larger, or handled by fixed size.
            break;
        default:
            throw new Error(`Unsupported primitive type for typeToBin: ${type_name}`);
    }
    return buffer;
}

/**
 * Converts an array of primitive JS values to a binary ArrayBuffer.
 * @param {string} type_name
 * @param {Array<any>} values
 * @returns {ArrayBuffer}
 */
export function typesToBin(type_name, values) {
    let type_size = 0;
    // Determine size of a single element
    switch (type_name) {
        case 'bool': case 'byte': case 'uint8': case 'int8': type_size = 1; break;
        case 'int16': case 'uint16': type_size = 2; break;
        case 'int32': case 'uint32': case 'float32': type_size = 4; break;
        case 'int64': case 'uint64': case 'float64': type_size = 8; break;
        default: throw new Error(`Unsupported primitive type for typesToBin: ${type_name}`);
    }

    const buffer = new ArrayBuffer(type_size * values.length);
    const view = new DataView(buffer);
    const littleEndian = true;
    let offset = 0;

    for (const value of values) {
        switch (type_name) {
            case 'bool': view.setUint8(offset, value ? 1 : 0); break;
            case 'byte':
            case 'uint8': view.setUint8(offset, value); break;
            case 'int8': view.setInt8(offset, value); break;
            case 'int16': view.setInt16(offset, value, littleEndian); break;
            case 'uint16': view.setUint16(offset, value, littleEndian); break;
            case 'int32': view.setInt32(offset, value, littleEndian); break;
            case 'uint32': view.setUint32(offset, value, littleEndian); break;
            case 'int64': view.setBigInt64(offset, BigInt(value), littleEndian); break;
            case 'uint64': view.setBigUint64(offset, BigInt(value), littleEndian); break;
            case 'float32': view.setFloat32(offset, value, littleEndian); break;
            case 'float64': view.setFloat64(offset, value, littleEndian); break;
        }
        offset += type_size;
    }
    return buffer;
}
