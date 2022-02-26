
#ifndef GAME_CPU_H_
#define GAME_CPU_H_

#include "../primitives.h"
#include "../memory.h"

namespace gameboy {

struct Registers {
  Byte A, F;
  Byte B, C;
  Byte D, E;
  Byte H, L;
  Address SP;
  Address PC;
};

class CPU {
 private:
  void JP_a16_Instruction(Memory* mem);
  void LD_d8_Instruction(Memory* mem);
  void LD_B_d8_Instruction(Memory* mem);
  void LD_C_d8_Instruction(Memory* mem);
  void LD_a8_A_Instruction(Memory* mem);
  void LD_a16_A_Instruction(Memory* mem);
  void LD_A_a16_Instruction(Memory* mem);
  void CP_d8_Instruction(Memory* mem);
  void PUSH_BC_Instruction(Memory* mem);
  void JP_C_a16_Instruction(Memory* mem);
  void LD_DE_d16_Instruction(Memory* mem);
  void LD_HL_d16_Instruction(Memory* mem);
  void LD_BC_d16_Instruction(Memory* mem);
  void LD_A_aDE_Instruction(Memory* mem);
  void LD_aC_A_Instruction(Memory* mem);
  void LD_aHLI_A_Instruction(Memory* mem);
  void LD_aHL_A_Instruction(Memory* mem);
  void INC_DE_Instruction(Memory* mem);
  void DEC_BC_Instruction(Memory* mem);
  void LD_A_B_Instruction(Memory* mem);
  void LD_A_C_Instruction(Memory* mem);
  void OR_A_C_Instruction(Memory* mem);
  void XOR_A_A_Instruction(Memory* mem);
  void JR_NZ_s8_Instruction(Memory* mem);
  void JP_NZ_a16_Instruction(Memory* mem);
  void JP_Z_a16_Instruction(Memory* mem);
  void CALL_a16_Instruction(Memory* mem);
  void RET_Instruction(Memory* mem);
  void JR_s8_Instruction(Memory* mem);
  

  void execute_prefixed_instruction(Memory* mem);


  void RES_7_aHL_Instruction(Memory* mem);
  void RES_1_aHL_Instruction(Memory* mem);
  void SET_7_aHL_Instruction(Memory* mem);
  void SET_4_aHL_Instruction(Memory* mem);
  void SET_1_aHL_Instruction(Memory* mem);
  void SET_0_aHL_Instruction(Memory* mem);

 public:
  struct Registers reg;

  void execute_intruction(Memory* mem);
};

}

#endif  // GAME_CPU_H_
