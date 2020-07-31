#!/usr/bin python3

import crccheck
import os
import sys
from mmap import ACCESS_READ, mmap
from crccheck.crc import Crc64We

def create_block(path, data_pattern, size_mb=1):
    """
    data_pattern: hex pattern must be 64 bits
    """
    assert(len(data_pattern) == 8*2)
    with open(path, "wb") as block:
        br = bytearray.fromhex(data_pattern)
        count = (size_mb * 1024 * 1024) / 8
        while count > 0:
            block.write(br)
            count -=1

def crc_test(pth):
    #OK with 10'000
    with open("/tmp/test_block", "wb") as blk:
        for _ in range(34300):
            blk.write(bytearray(b"1234567890"))

    with open("/tmp/test_block", 'rb') as fh, mmap(fh.fileno(), 0, access=ACCESS_READ) as mm: 
        crc = Crc64We.calc((b[0] for b in mm))
        print(f"GOLD: TEST /tmp/test_block crc: {hex(crc)}")


def print_crc64(path):
    cr64 = crccheck.crc.Crc64We()
    with open(path, "rb") as blk:
        data = blk.read(128*1024)
        if data:
            cr64.process(data)
    print("___")
    print(cr64.finalhex())

if __name__ == "__main__":
    block_path = "/tmp/crc_block"
    create_block(block_path, "DEADBEEFDEADBEEF")
    b = bytearray.fromhex("313233343536373839");
    cr64 = crccheck.crc.Crc64We()
    cr64.process(b)
    print(f"Test value {hex(cr64._check_result)} Calculated {cr64.finalhex()}")

    # create_block(block_path, "BADC00FEBADC00FE")
    print_crc64("/tmp/test_block") 
    crc_test(block_path)
    # DEADBEEFDEADBEEF => 0x29d8e96fd64c2e72
    # BADC00FEBADC00FE => 0x1d8cae34ea398460
