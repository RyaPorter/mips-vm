#include "../include/cpu.hh"
#include "../include/architecture.hh"

hardware::cpu::cpu(hardware::memory *mem) {
    hardware::cpu::cpu_mem = mem;
    running = true;
    hardware::cpu::regs[architecture::regs::PC] = TEXT_BASE;
}

hardware::cpu::~cpu() { running = false; }

void hardware::cpu::run() {
    while (running) {
        uint32_t intr = fetch();
        decode(intr);
        execute();
    }
}