import * as PduUtils from '../pdu_utils.js';
import { {{ container.class_name }} } from './pdu_jstype_{{ container.msg_type_name }}.js';
{% for imp in container.js_conv_imports -%}
{%- set import_path = './' -%}
{%- if imp.dep_pkg != container.pkg_name -%}
{%- set import_path = '../' + imp.dep_pkg + '/' -%}
{%- endif -%}
import { {{ imp.class_name }} } from '{{ import_path }}pdu_jstype_{{ imp.msg_type }}.js';
import { binary_read_recursive_{{ imp.class_name }}, binary_write_recursive_{{ imp.class_name }} } from '{{ import_path }}pdu_conv_{{ imp.msg_type }}.js';
{% endfor %}

/**
 * Deserializes a binary PDU into a {{ container.class_name }} object.
 * @param {ArrayBuffer} binary_data
 * @returns { {{ container.class_name }} }
 */
export function pduToJs_{{ container.msg_type_name }}(binary_data) {
    const js_obj = new {{ container.class_name }}();
    const meta_parser = new PduUtils.PduMetaDataParser();
    const meta = meta_parser.load_pdu_meta(binary_data);
    if (meta === null) {
        throw new Error("Invalid PDU binary data: MetaData not found or corrupted");
    }
    binary_read_recursive_{{ container.msg_type_name }}(meta, binary_data, js_obj, meta.base_off);
    return js_obj;
}

export function binary_read_recursive_{{ container.msg_type_name }}(meta, binary_data, js_obj, base_off) {
    const view = new DataView(binary_data);
    const littleEndian = true;
{%- for item in container.offset_data %}
    // member: {{ item.member_name }}, type: {{ item.type_name }} ({{ item.data_type }})
{% if item.data_type == 'primitive' or item.data_type == 'string' %}
    {% if item.array_type == 'single' %}
    {
        const bin = PduUtils.readBinary(binary_data, base_off + {{ item.offset }}, {{ item.size }});
        js_obj.{{ item.member_name }} = PduUtils.binToValue("{{ item.type_name }}", bin);
    }
    {% elif item.array_type == 'array' %}
    {
        const array_bin = PduUtils.readBinary(binary_data, base_off + {{ item.offset }}, {{ item.size }});
        js_obj.{{ item.member_name }} = PduUtils.binToArrayValues("{{ container.get_array_type(item.type_name) }}", array_bin, {{ item.array_len }});
    }
    {% else -%}
    { // varray
        const array_size = view.getInt32(base_off + {{ item.offset }}, littleEndian);
        const offset_from_heap = view.getInt32(base_off + {{ item.offset }} + 4, littleEndian);
        const one_elm_size = {{ item.size }};
        const array_bin = PduUtils.readBinary(binary_data, meta.heap_off + offset_from_heap, one_elm_size * array_size);
        
        if ("{{ item.type_name }}" === 'string') {
            js_obj.{{ item.member_name }} = PduUtils.binToValue("string", array_bin);
        } else {
            js_obj.{{ item.member_name }} = PduUtils.binToArrayValues("{{ item.type_name }}", array_bin, array_size);
        }
    }
    {% endif -%}
{% else -%}
    {% if item.array_type == 'single' %}
    {
        const tmp_obj = new {{ container.get_js_class_name(item.type_name) }}();
        binary_read_recursive_{{ container.get_js_class_name(item.type_name) }}(meta, binary_data, tmp_obj, base_off + {{ item.offset }});
        js_obj.{{ item.member_name }} = tmp_obj;
    }
    {% elif item.array_type == 'array' %}
    {
        const array_size = {{ item.array_len }};
        const one_elm_size = {{ item.size }} / array_size;
        const array_value = [];
        for (let i = 0; i < array_size; i++) {
            const tmp_obj = new {{ container.get_js_class_name(item.type_name) }}();
            const item_offset = base_off + {{ item.offset }} + (i * one_elm_size);
            binary_read_recursive_{{ container.get_js_class_name(item.type_name) }}(meta, binary_data, tmp_obj, item_offset);
            array_value.push(tmp_obj);
        }
        js_obj.{{ item.member_name }} = array_value;
    }
    {% else %}
    { // varray
        const array_size = view.getInt32(base_off + {{ item.offset }}, littleEndian);
        const offset_from_heap = view.getInt32(base_off + {{ item.offset }} + 4, littleEndian);
        const one_elm_size = {{ item.size }};
        const array_value = [];
        for (let i = 0; i < array_size; i++) {
            const tmp_obj = new {{ container.get_js_class_name(item.type_name) }}();
            const item_offset = meta.heap_off + offset_from_heap + (i * one_elm_size);
            binary_read_recursive_{{ container.get_js_class_name(item.type_name) }}(meta, binary_data, tmp_obj, item_offset);
            array_value.push(tmp_obj);
        }
        js_obj.{{ item.member_name }} = array_value;
    }
    {% endif -%}
{% endif -%}
{% endfor %}
    return js_obj;
}

/**
 * Serializes a {{ container.class_name }} object into a binary PDU.
 * @param { {{ container.class_name }} } js_obj
 * @returns {ArrayBuffer}
 */
export function jsToPdu_{{ container.msg_type_name }}(js_obj) {
    const base_allocator = new PduUtils.DynamicAllocator();
    const bw_container = new PduUtils.BinaryWriterContainer(new PduUtils.PduMetaData());

    binary_write_recursive_{{ container.msg_type_name }}(0, bw_container, base_allocator, js_obj);

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

export function binary_write_recursive_{{ container.msg_type_name }}(parent_off, bw_container, allocator, js_obj) {
    const littleEndian = true;
{%- for item in container.offset_data %}
    // member: {{ item.member_name }}, type: {{ item.type_name }} ({{ item.data_type }})
{% if item.data_type == 'primitive' or item.data_type == 'string' %}
    {% if item.array_type == 'single' %}
    {
        const bin = PduUtils.typeToBin("{{ item.type_name }}", js_obj.{{ item.member_name }}, {{ item.size }});
        allocator.add(bin, parent_off + {{ item.offset }});
    }
    {% elif item.array_type == 'array' %}
    {
        const buffer = PduUtils.typesToBin("{{ container.get_array_type(item.type_name) }}", js_obj.{{ item.member_name }});
        allocator.add(buffer, parent_off + {{ item.offset }});
    }
    {% else -%}
    { // varray
        const offset_from_heap = bw_container.heap_allocator.size();
        let data_buffer;
        let array_size;
        if ("{{ item.type_name }}" === 'string') {
            data_buffer = new TextEncoder().encode(js_obj.{{ item.member_name }});
            array_size = data_buffer.byteLength;
        } else {
            data_buffer = PduUtils.typesToBin("{{ item.type_name }}", js_obj.{{ item.member_name }});
            array_size = js_obj.{{ item.member_name }}.length;
        }
        bw_container.heap_allocator.add(data_buffer);

        const ref_buffer = new ArrayBuffer(8);
        const ref_view = new DataView(ref_buffer);
        ref_view.setInt32(0, array_size, littleEndian);
        ref_view.setInt32(4, offset_from_heap, littleEndian);
        allocator.add(ref_buffer, parent_off + {{ item.offset }});
    }
    {% endif -%}
{% else -%}
    {% if item.array_type == 'single' %}
    {
        binary_write_recursive_{{ container.get_js_class_name(item.type_name) }}(parent_off + {{ item.offset }}, bw_container, allocator, js_obj.{{ item.member_name }});
    }
    {% elif item.array_type == 'array' %}
    {
        const one_elm_size = {{ item.size }} / {{ item.array_len }};
        for (let i = 0; i < {{ item.array_len }}; i++) {
            binary_write_recursive_{{ container.get_js_class_name(item.type_name) }}(parent_off + {{ item.offset }} + (i * one_elm_size), bw_container, allocator, js_obj.{{ item.member_name }}[i]);
        }
    }
    {% else %}
    { // varray
        const offset_from_heap = bw_container.heap_allocator.size();
        const one_elm_size = {{ item.size }};
        for (const elm of js_obj.{{ item.member_name }}) {
            binary_write_recursive_{{ container.get_js_class_name(item.type_name) }}(0, bw_container, bw_container.heap_allocator, elm);
        }

        const ref_buffer = new ArrayBuffer(8);
        const ref_view = new DataView(ref_buffer);
        ref_view.setInt32(0, js_obj.{{ item.member_name }}.length, littleEndian); // array_size
        ref_view.setInt32(4, offset_from_heap, littleEndian);
        allocator.add(ref_buffer, parent_off + {{ item.offset }});
    }
    {% endif -%}
{% endif -%}
{% endfor %}
}
