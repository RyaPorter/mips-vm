#include "../include/memory.hh"
#include <stdint.h>

hardware::memory::~memory() { delete hardware::memory::mem; }

uint32_t hardware::memory::read(uint32_t addr) {
    return hardware::memory::mem[addr];
}

void hardware::memory::write(uint32_t addr, uint32_t val) {
    hardware::memory::mem[addr] = val;
}