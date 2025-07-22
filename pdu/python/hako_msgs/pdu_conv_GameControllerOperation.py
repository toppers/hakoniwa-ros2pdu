
import struct
from .pdu_pytype_GameControllerOperation import GameControllerOperation
from ..pdu_utils import *
from .. import binary_io

# dependencies for the generated Python class



def pdu_to_py_GameControllerOperation(binary_data: bytes) -> GameControllerOperation:
    py_obj = GameControllerOperation()
    meta_parser = binary_io.PduMetaDataParser()
    meta = meta_parser.load_pdu_meta(binary_data)
    if meta is None:
        raise ValueError("Invalid PDU binary data: MetaData not found or corrupted")
    binary_read_recursive_GameControllerOperation(meta, binary_data, py_obj, binary_io.PduMetaData.PDU_META_DATA_SIZE)
    return py_obj


def binary_read_recursive_GameControllerOperation(meta: binary_io.PduMetaData, binary_data: bytes, py_obj: GameControllerOperation, base_off: int):
    # array_type: array 
    # data_type: primitive 
    # member_name: axis 
    # type_name: float64 
    # offset: 0 size: 48 
    # array_len: 6

    
    array_value = binary_io.readBinary(binary_data, base_off + 0, 48)
    py_obj.axis = binary_io.binToArrayValues("float64", array_value)
    
    # array_type: array 
    # data_type: primitive 
    # member_name: button 
    # type_name: bool 
    # offset: 48 size: 60 
    # array_len: 15

    
    array_value = binary_io.readBinary(binary_data, base_off + 48, 60)
    py_obj.button = binary_io.binToArrayValues("bool", array_value)
    
    return py_obj
