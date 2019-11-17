#include <stdint.h>

#define CREATE_J_INSTR(op_code, address) op_code << 26 | address

#define CREATE_I_INSTR(op_code, rs, rt,immediate) op_code << 26 | rs << 21 | rt << 16 | immediate


#define CREATE_R_INSTR(op_code, rs, rt, rd, shamt, funct) op_code << 26 | rs << 21 | rt << 16 | rd << 11 | shamt << 6 | funct