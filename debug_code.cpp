#include <iostream>
#include <string>
#include <fstream>
#include "src/game/game.h"
#include "src/utils/read_rom.h"

using namespace std;

void print_registers(gameboy::Console game) {
  std::cout << "A: " << (unsigned int) game.cpu.reg.A << " F: " << (unsigned int) game.cpu.reg.F << std::endl; 
  std::cout << "B: " << (unsigned int) game.cpu.reg.B << " C: " << (unsigned int) game.cpu.reg.C << std::endl; 
  std::cout << "D: " << (unsigned int) game.cpu.reg.D << " E: " << (unsigned int) game.cpu.reg.E << std::endl; 
  std::cout << "H: " << (unsigned int) game.cpu.reg.H << " L: " << (unsigned int) game.cpu.reg.L << std::endl; 

  std::cout << "SP: " << (unsigned int) game.cpu.reg.SP << std::endl;
  std::cout << "PC: " << (unsigned int) game.cpu.reg.PC << std::endl;
}

int main(int argc, char *argv[])
{
  gameboy::Console game;
  Byte rom_data[32 * 1024];
  string file_path = "/home/raul/Programming/hello-world-asm/hello-world.gb";
  utils::read_rom_from_file(rom_data, file_path);
  game.initialize_registers();
  game.load_rom(rom_data);
  bool finding_breakpoint = false;
  bool finding_opcode = false;
  char user_digit;
  unsigned int user_addr;
  unsigned int user_value;
  while (true) {
    if (finding_breakpoint) {
      if (game.cpu.reg.PC != user_addr) {
        game.run_a_instruction_cycle();
        continue;
      }
      else {
        finding_breakpoint = false;
      }
    }
    if (finding_opcode) {
      if (game.mem.GetInAddr(game.cpu.reg.PC) != user_addr) {
        game.run_a_instruction_cycle();
        continue;
      }
      else {
        finding_opcode = false;
      }
    }
    print_registers(game);
    std::cout << "Input: ";
    std::cin >> user_digit;
    if (user_digit == 'q') {
      return 0;
    }
    if (user_digit == 'n') {
      game.run_a_instruction_cycle();
      continue;
    }
    if (user_digit == 'b') {
      std::cin >> user_addr;
      finding_breakpoint = true;
      continue;
    }
    if (user_digit == 'j') {
      std::cin >> user_value;
      for (int i = 0; i < user_value; i++) {
        game.run_a_instruction_cycle();
      }
      continue;
    }
    if (user_digit == 'o') {
      std::cin >> user_addr;
      finding_opcode = true;
      continue;
    }
    if (user_digit == 'g') {
      std::cin >> user_addr;
      std::cout << "Address (" << user_addr << "): " << (unsigned int) game.mem.GetInAddr(user_addr) << std::endl;
    }
    if (user_digit == 's') {
      std::cin >> user_addr;
      std::cin >> user_value;
      std::cout << "Set (" << user_addr << "): " << user_value << std::endl;
      game.mem.SetInAddr(user_addr, user_value);
    }
  }
}

