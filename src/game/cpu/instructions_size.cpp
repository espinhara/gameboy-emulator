
#include <iostream>

#include "instructions_size.h"

namespace gameboy {

InstructionsSize::InstructionsSize() : instructions{0} {
  instructions[LD_d8] = 2;
  instructions[LD_B_d8] = 2;
  instructions[LD_C_d8] = 2;
  instructions[LD_D_d8] = 2;
  instructions[LD_E_d8] = 2;
  instructions[RLCA] = 1;
  instructions[SBC_A_C] = 1;
  instructions[SBC_A_d8] = 2;
  instructions[DEC_A] = 1;
  instructions[DEC_B] = 1;
  instructions[DEC_C] = 1;
  instructions[DEC_E] = 1;
  instructions[DEC_L] = 1;
}

unsigned int InstructionsSize::GetSize(int opcode, bool CBPrefix) {
  if (CBPrefix) {
    return 2;
  } else {
    return instructions[opcode];
  }
}

}