#include <stdint.h>
#include <stdio.h>
#include <iostream.h>

class riscv_instr{
private:
  int32_t instr;
  int bits_instr[32];
public:
  riscv_instr(){
    instr = 0;
  }
  int get_opcode(){
    int i;
    int opcode;
    opcode = 0;
    for (i=0;i<7;i++){
      opcode = opcode + ((instr & (1<<i))<<i);
    }
    return opcode;
  }

  int get_rd(){
    int i;
    int rd;
    rd = 0;
    for (i=8;i<13;i++){
      rd = rd + ((instr & (1<<i))<<(i-8));
    }
    return rd;
  }

};
