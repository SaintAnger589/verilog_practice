//this file is to simulate the instructions
//of riscv to understand various instrauctions

//integer register immediate instrauctions
#include <stdint.h>
#include <stdio.h>
#include <iostream>
#include "../instr_base.h"
//#include "../r_type_instr.h"
#include "../riscv_instr_helper.h"
#include "./ram.h"

using namespace std;
class r_type_instr;
class instr_base;


int main() {
  //r_type_instr r_type;
  //riscv_instr_helper helper;
  ram mem;
  int res;
  int32_t instruction;
  //int opcode;
  //unsigned int funct7;
  //checking sending of instructions
  instruction = 0x410433;

  instr_base base(instruction);

  mem.set_mem_val(4,5);
  mem.set_mem_val(2,8);
  res = mem.get_mem_val(8);


  //base.set_instr(instruction);
  base.check_r_type(mem);
  //opcode = base.get_opcode();
  //funct7 = in.get_funct7();
  //cout<<"opcode ="<<opcode<<"\n";
  //cout<<"funct7 = "<<funct7<<"\n";
  cout<<"res = "<<res<<"\n";
}
