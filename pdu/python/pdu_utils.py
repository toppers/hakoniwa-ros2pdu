# pdu/python/pdu_utils.py

import struct

# PDU MetaData Constants and Layout
_MAGIC_NUMBER = 0x12345678
_PDU_VERSION = 1
_PDU_META_FORMAT = '<IIIII'  # Little-endian: magic, version, base_off, heap_off, total_size, reserved
_PDU_META_SIZE = struct.calcsize(_PDU_META_FORMAT)

# 8-byte alignment for meta data size
_ALIGNED_PDU_META_SIZE = (_PDU_META_SIZE + 7) & ~7

# Helper for variable-length array reference structure (length and offset)
_VARRAY_REF_FORMAT = '<ii' # Little-endian: length, offset
_VARRAY_REF_SIZE = struct.calcsize(_VARRAY_REF_FORMAT)

class PduDynamicMemoryPython:
    """
    A Python implementation of the C++ PduDynamicMemory class.
    Manages the heap area for PDU serialization.
    """
    def __init__(self):
        self.current_offset = 0
        self.allocations = []  # List of (offset, data_bytes)

    def allocate(self, data_bytes: bytes) -> int:
        """
        Allocates data to the heap, returning its offset within the heap.
        """
        if not isinstance(data_bytes, bytes):
            raise TypeError("data must be bytes")
        offset = self.current_offset
        self.allocations.append((offset, data_bytes))
        self.current_offset += len(data_bytes)
        return offset

    def get_total_size(self) -> int:
        """
        Returns the total size of the allocated heap data.
        """
        return self.current_offset

    def copy_to_pdu(self, heap_buffer: bytearray):
        """
        Copies all managed data blocks into the provided heap buffer.
        """
        for offset, data_bytes in self.allocations:
            heap_buffer[offset:offset + len(data_bytes)] = data_bytes

    def get_bytes(self) -> bytes:
        """Returns the entire heap as a single bytes object."""
        total_size = self.get_total_size()
        heap_buffer = bytearray(total_size)
        self.copy_to_pdu(heap_buffer)
        return bytes(heap_buffer)

def create_pdu(base_data: bytes, heap_data: bytes = b'') -> bytes:
    """
    Assembles the final PDU bytes from base_data and heap_data.
    """
    base_size = len(base_data)
    heap_size = len(heap_data)
    
    aligned_base_size = (base_size + 7) & ~7
    aligned_heap_size = (heap_size + 7) & ~7

    total_size = _ALIGNED_PDU_META_SIZE + aligned_base_size + aligned_heap_size
    base_offset = _ALIGNED_PDU_META_SIZE
    heap_offset = _ALIGNED_PDU_META_SIZE + aligned_base_size

    pdu_buffer = bytearray(total_size)

    # Pack MetaData
    struct.pack_into(_PDU_META_FORMAT, pdu_buffer, 0, 
                     _MAGIC_NUMBER, _PDU_VERSION, 
                     base_offset, heap_offset, total_size)

    # Copy BaseData
    pdu_buffer[base_offset : base_offset + base_size] = base_data

    # Copy HeapData
    if heap_size > 0:
        pdu_buffer[heap_offset : heap_offset + heap_size] = heap_data

    return bytes(pdu_buffer)

def unpack_pdu(pdu_bytes: bytes) -> (dict, bytes, bytes):
    """
    Disassembles PDU bytes into metadata, base_data, and heap_data.
    """
    if len(pdu_bytes) < _PDU_META_SIZE:
        raise ValueError("PDU is too small for metadata")

    magic, version, base_off, heap_off, total_size = struct.unpack_from(_PDU_META_FORMAT, pdu_bytes, 0)

    if magic != _MAGIC_NUMBER or version != _PDU_VERSION:
        raise ValueError(f"Invalid PDU MetaData: magic={hex(magic)}, version={version}")

    metadata = {
        'magic': magic,
        'version': version,
        'base_off': base_off,
        'heap_off': heap_off,
        'total_size': total_size
    }

    base_data = pdu_bytes[base_off:heap_off]
    heap_data = pdu_bytes[heap_off:total_size]

    return metadata, base_data, heap_data
