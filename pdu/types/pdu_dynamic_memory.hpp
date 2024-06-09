#ifndef _PDU_DYNAMIC_MEMORY_HPP_
#define _PDU_DYNAMIC_MEMORY_HPP_

#include <vector>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <stdexcept>

// Class to manage dynamic memory for PDU
class PduDynamicMemory {
public:
    struct Allocation {
        int length;
        int offset;
        void* data;

        Allocation(int len, int off, void* ptr) : length(len), offset(off), data(ptr) {}
    };

    PduDynamicMemory() : current_offset(0) {}

    ~PduDynamicMemory() {
        for (auto& alloc : allocations) {
            free(alloc.data);
        }
    }

    // Allocate memory and store the allocation info
    void* allocate(int length, size_t elem_size) {
        void* ptr = malloc(length * elem_size);
        if (ptr == nullptr) {
            throw std::runtime_error("Memory allocation failed");
        }
        allocations.emplace_back(length * elem_size, current_offset, ptr);
        current_offset += length * elem_size;
        return ptr;
    }

    // Get total size of all allocations
    int get_total_size() const {
        return current_offset;
    }

    // Copy data to a destination buffer and set offsets
    void copy_to_pdu(char* dest) const {
        //std::cout << "dest addr: " << (long long)dest << std::endl;
        for (const auto& alloc : allocations) {
            //std::cout << "dest addr + off: " << (long long)(dest + alloc.offset) << std::endl;
            //std::cout << "length: " << alloc.length << std::endl;
            memcpy(dest + alloc.offset, alloc.data, alloc.length);
        }
    }

    // Get the offset of a specific allocation
    int get_offset(void* data_ptr) const {
        for (const auto& alloc : allocations) {
            if (alloc.data == data_ptr) {
                return alloc.offset;
            }
        }
        return -1; // Not found
    }

private:
    std::vector<Allocation> allocations;
    int current_offset;
};

#endif /* _PDU_DYNAMIC_MEMORY_HPP_ */
