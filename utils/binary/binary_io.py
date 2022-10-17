#!/usr/bin/python
# -*- coding: utf-8 -*-

import glob
import re
import os
from sys import byteorder
import struct

def binToint8(binary):
    return struct.unpack('b', binary)[0]

def binToint16(binary):
    return struct.unpack('h', binary)[0]

def binToint32(binary):
    return struct.unpack('i', binary)[0]

def binToint64(binary):
    return struct.unpack('q', binary)[0]

def binTouint8(binary):
    return struct.unpack('B', binary)[0]

def binTouint16(binary):
    return struct.unpack('H', binary)[0]

def binTouint32(binary):
    return struct.unpack('I', binary)[0]

def binTouint64(binary):
    return struct.unpack('Q', binary)[0]

def binTofloat32(binary):
    return struct.unpack('f', binary)[0]

def binTofloat64(binary):
    return struct.unpack('d', binary)[0]


def int8Tobin(arg):
    return struct.pack('b', arg)

def int16Tobin(arg):
    return struct.pack('h', arg)

def int32Tobin(arg):
    return struct.pack('i', arg)

def int64Tobin(arg):
    return struct.pack('q', arg)

def uint8Tobin(arg):
    return struct.pack('B', arg)

def uint16Tobin(arg):
    return struct.pack('H', arg)

def uint32Tobin(arg):
    return struct.pack('I', arg)

def uint64Tobin(arg):
    return struct.pack('Q', arg)

def float32Tobin(arg):
    return struct.pack('f', arg)

def float64Tobin(arg):
    return struct.pack('d', arg)

def writeBinary(filepath, off, bin):
    f = open(filepath, 'r+b')
    f.seek(off, os.SEEK_SET)
    f.write(bin)
    f.close()

def readBinary(filepath, off, size):
    f = open(filepath, 'rb')
    f.seek(off, os.SEEK_SET)
    bin = f.read(size)
    f.close()
    return bin

def find_filepath(path, filename):
    tmp = glob.glob(path + filename, recursive=True)
    if (len(tmp) == 0):
        return None
    return tmp[0]

