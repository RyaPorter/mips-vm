#pragma once
#include <stdint.h>

#define TEXT_BASE 0x00400000

namespace architecture {

/**
 * Represents all instruction encodings (I, J, R)
 */
struct instr {
    uint8_t op_code : 6;
    uint8_t rs : 5;
    uint8_t rt : 5;
    uint8_t rd : 5;
    uint8_t shamt : 5;
    uint8_t funct : 6;
    uint16_t imm : 16;
    uint32_t addr : 26;
};

enum regs {
    r1 = 1,
    r2,
    r3,
    r4,
    r5,
    r6,
    r7,
    r9,
    r10,
    r11,
    r12,
    r13,
    r14,
    r15,
    r16,
    r17,
    r18,
    r19,
    r20,
    r21,
    r22,
    r23,
    r24,
    r25,
    r26,
    r27,
    r28,
    r29,
    r30,
    r31,
    PC,
    HI,
    LO
};

enum funct_code {
    SLL = 0,

    SRL = 2,
    SRA = 3,
    SLLv = 4,
    SRLV = 5,
    SRAV = 6,
    JR = 7,
    JALR = 8,

    MFHI = 16,
    MTHI = 17,
    MFLO = 18,
    MTLO = 19,

    MULT = 24,
    MULTU = 25,
    DIV = 26,
    DIVU = 27,

    ADD = 32,
    ADDU = 33,
    SUB = 34,
    SUBU = 35,
    AND = 36,
    OR = 37,
    XOR = 38,
    NOR = 39,
    SLT = 42,
    SLTU = 43
};

enum op_code {
    logic = 0,
    BGEZAL = 1,
    J = 2,
    JAL = 3,
    BEQ = 4,
    BNE = 5,
    BLEZ = 6,
    BGTZ = 7,
    ADDI = 8,
    ADDIU = 9,
    SLTI = 10,
    SLTIU = 11,
    ANDI = 12,
    ORI = 13,
    XORI = 14,
    LUI = 15,
    FPU = 17,

    LB = 32,
    LH = 33,
    LWL = 34,
    LW = 35,
    LBU = 36,
    LHU = 37,
    LWR = 38,
    SB = 39,
    SH = 40,
    SWL = 41,
    SW = 42,
    SWR = 43
};

}; // namespace architecture