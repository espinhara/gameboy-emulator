
#include <gtest/gtest.h>

#include "../src/game/game.h"
#include "../src/game/primitives.h"
#include "../src/game/cpu/cb_prefixed_opcodes.h"

TEST(PrefixedInstructions, RES_7_aHL_instruction) {
  gameboy::Console game;
  game.initialize_registers();
  game.mem.SetInAddr(0x100, OPCODE_PREFIX);
  game.mem.SetInAddr(0x101, RES_7_aHL);
  game.mem.SetInAddr(0x150, 0b11111111);
  game.cpu.reg.H = 0x01;
  game.cpu.reg.L = 0x50;

  game.cpu.execute_intruction(&game.mem);

  EXPECT_EQ(game.cpu.reg.PC, 0x102);
  EXPECT_EQ(game.mem.GetInAddr(0x150), 0b01111111);
}

TEST(PrefixedInstructions, SET_7_aHL_instruction) {
  gameboy::Console game;
  game.initialize_registers();
  game.mem.SetInAddr(0x100, OPCODE_PREFIX);
  game.mem.SetInAddr(0x101, SET_7_aHL);
  game.mem.SetInAddr(0x150, 0b01111111);
  game.cpu.reg.H = 0x01;
  game.cpu.reg.L = 0x50;

  game.cpu.execute_intruction(&game.mem);

  EXPECT_EQ(game.cpu.reg.PC, 0x102);
  EXPECT_EQ(game.mem.GetInAddr(0x150), 0b11111111);
}

TEST(PrefixedInstructions, SET_4_aHL_instruction) {
  gameboy::Console game;
  game.initialize_registers();
  game.mem.SetInAddr(0x100, OPCODE_PREFIX);
  game.mem.SetInAddr(0x101, SET_4_aHL);
  game.mem.SetInAddr(0x150, 0b00100000);
  game.cpu.reg.H = 0x01;
  game.cpu.reg.L = 0x50;

  game.cpu.execute_intruction(&game.mem);

  EXPECT_EQ(game.cpu.reg.PC, 0x102);
  EXPECT_EQ(game.mem.GetInAddr(0x150), 0b00110000);
}

TEST(PrefixedInstructions, SET_1_aHL_instruction) {
  gameboy::Console game;
  game.initialize_registers();
  game.mem.SetInAddr(0x100, OPCODE_PREFIX);
  game.mem.SetInAddr(0x101, SET_1_aHL);
  game.mem.SetInAddr(0x150, 0b11111000);
  game.cpu.reg.H = 0x01;
  game.cpu.reg.L = 0x50;

  game.cpu.execute_intruction(&game.mem);

  EXPECT_EQ(game.cpu.reg.PC, 0x102);
  EXPECT_EQ(game.mem.GetInAddr(0x150), 0b11111010);
}

TEST(PrefixedInstructions, SET_0_aHL_instruction) {
  gameboy::Console game;
  game.initialize_registers();
  game.mem.SetInAddr(0x100, OPCODE_PREFIX);
  game.mem.SetInAddr(0x101, SET_0_aHL);
  game.mem.SetInAddr(0x150, 0b11111000);
  game.cpu.reg.H = 0x01;
  game.cpu.reg.L = 0x50;

  game.cpu.execute_intruction(&game.mem);

  EXPECT_EQ(game.cpu.reg.PC, 0x102);
  EXPECT_EQ(game.mem.GetInAddr(0x150), 0b11111001);
}
