#include "../include/architecture.hh"
#include "../include/cpu.hh"
#include "../include/instr_utils.hh"
#include "../include/memory.hh"

int main(int argc, char const *argv[]) {
    hardware::memory *ram = new hardware::memory();

    uint32_t prog[] = {
        CREATE_I_INSTR(architecture::op_code::LUI, 0, 3, 0x8000),
        CREATE_I_INSTR(architecture::op_code::ORI, 0, 3, 0x1),
        CREATE_R_INSTR(0, 2, 3, 4, 0, 0x20)
        //(0 << 26 | 2 << 21 | 3 << 16 | 4 << 11 | 0 << 6 | 0x20 )
    };

    ram->write(TEXT_BASE, prog[0]);

    hardware::cpu *cpu_1 = new hardware::cpu(ram);

    cpu_1->run();

    return 0;
}
