#pragma once
#include "architecture.hh"
#include "memory.hh"
#include <stdint.h>

#define REG_COUNT (32 + 3) // 32 GPR, 1 PC, 1 HI, 1 LO

namespace hardware {
class cpu {
  private:
    uint32_t regs[REG_COUNT];
    hardware::memory *cpu_mem;
    bool running = false;
    uint32_t nPC = TEXT_BASE + 4; // we will execute first instruction at pc,
                                  // then advance pc with nPC...

    architecture::instr curr_instr;

    uint32_t fetch() {
        uint32_t val = cpu_mem->read(regs[architecture::regs::PC]);
        return val;
    }

    void decode(uint32_t instr) {
        // Treat instruction as all type (I,J,R)
        // We're only interested in the op_code
        // The different cases will use the correct bits.
        curr_instr.op_code = (instr >> 26) & 0x3F;
        curr_instr.rd = (instr >> 11) & 0x1F;
        curr_instr.rt = (instr >> 16) & 0x1F;
        curr_instr.rs = (instr >> 21) & 0x1F;
        curr_instr.shamt = (instr >> 6) & 0x1F;
        curr_instr.funct = instr & 0x3F;
        curr_instr.imm = instr & 0xFFFF;
        curr_instr.addr = instr & 0x3FFFFFF;
    }

    void execute() {
        switch (curr_instr.op_code) {
        case architecture::op_code::logic: {
            handle_logic_code();
            advance_pc(4);
        } break;
        case architecture::op_code::LW: {
            uint16_t offset = curr_instr.imm;
            uint16_t rs = curr_instr.rs;
            uint32_t val = hardware::cpu::cpu_mem->read(offset + rs);
            hardware::cpu::regs[curr_instr.rt] = val;
            advance_pc(4);
        } break;
        case architecture::op_code::ORI: {
            hardware::cpu::regs[curr_instr.rt] =
                hardware::cpu::regs[curr_instr.rs] | curr_instr.imm;
            advance_pc(4);
        } break;
        case architecture::op_code::LUI: {
            hardware::cpu::regs[curr_instr.rt] = (curr_instr.imm << 16);
            advance_pc(4);
        } break;
        case architecture::op_code::ADDI: {

            uint32_t sei = (curr_instr.imm & 0x1FF) |
                           ((curr_instr.imm & 0x100) ? 0xFE00 : 0);

            hardware::cpu::regs[curr_instr.rt] =
                hardware::cpu::regs[curr_instr.rs] + sei;

            advance_pc(4);
        } break;
        case architecture::op_code::ADDIU: {

            uint32_t sei = (curr_instr.imm & 0x1FF) |
                           ((curr_instr.imm & 0x100) ? 0xFE00 : 0);

            hardware::cpu::regs[curr_instr.rt] =
                hardware::cpu::regs[curr_instr.rs] + sei;

            advance_pc(4);
        } break;
        }
    }

    void advance_pc(uint32_t offset) {

        regs[architecture::regs::PC] = nPC;

        nPC += offset;
    }

    void handle_logic_code() {
        switch (curr_instr.funct) {
        case architecture::funct_code::ADD: {
            uint32_t f = hardware::cpu::regs[curr_instr.rs];
            uint32_t s = hardware::cpu::regs[curr_instr.rt];
            hardware::cpu::regs[curr_instr.rd] = f + s;
        } break;
        }
    }

  public:
    cpu(hardware::memory *mem);
    ~cpu();

    void run();
};

}; // namespace hardware