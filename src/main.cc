#include "../include/architecture.hh"
#include "../include/cpu.hh"
#include "../include/instr_utils.hh"
#include "../include/memory.hh"

int main(int argc, char const *argv[]) {
    hardware::memory *ram = new hardware::memory();

    uint32_t prog[] = {CREATE_I_INSTR(architecture::op_code::ADDI, 0, 3, 0x1E),
                       CREATE_I_INSTR(architecture::op_code::ADDI, 0, 2, 0x2E),
                       CREATE_R_INSTR(0, 2, 3, 4, 0, 0x20)};

    ram->write(TEXT_BASE, prog[0]);
    ram->write(TEXT_BASE + 4, prog[1]);
    ram->write(TEXT_BASE + 8, prog[2]);

    hardware::cpu *cpu_1 = new hardware::cpu(ram);

    cpu_1->run();

    return 0;
}
