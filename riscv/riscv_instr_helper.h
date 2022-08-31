#include <stdint.h>
#include <stdio.h>
#include <bitset>
#include <iostream>
#include "testbench/ram.h"

using namespace std;

#ifndef RISCV_HELPER
#define RISCV_HELPER
class riscv_instr_helper {
private:
  int32_t instr;
  int bits_instr[32];
  int trace;
public:
  ram mem;
  riscv_instr_helper(){
    set_instr(0);
    debug_on(true);
  }

  void set_mem_obj(ram mem){
    this->mem = mem;
  }

  void debug_on(bool trace) {
    this->trace = trace;
  }

  void set_instr(int32_t instruction){
    instr = instruction;
  }

  int get_funct7(){
    int i;
    int funct7;
    funct7 = 0;
    for (i=25;i<32;i++){
      funct7 = funct7 + (instr & (1<<i));
    }
    if (trace){
      std::bitset<32> y(funct7);
      cout<<"funct7 = "<<y<<"\n";
    }
    return funct7;
  }

  int get_rs2_loc(){
    int i;
    int rs2;
    rs2 = 0;
    for (i=20;i<25;i++){
      rs2 = rs2 + (instr & (1<<i));
    }
    if (trace){
      std::bitset<32> y(rs2);
      cout<<"rs2 = "<<y<<"\n";
    }
    return rs2;
  }

  int get_rs1_loc(){
    int i;
    int rs1;
    rs1 = 0;
    for (i=15;i<20;i++){
      rs1 = rs1 + (instr & (1<<i));
    }
    if (trace){
      std::bitset<32> y(rs1);
      cout<<"rs1 = "<<y<<"\n";
    }
    return rs1;
  }

  int get_funct3(){
    int i;
    int funct3;
    funct3 = 0;
    for (i=12;i<15;i++){
      funct3 = funct3 + (instr & (1<<i));
    }
    if (trace){
      std::bitset<32> y(funct3);
      cout<<"funct3 = "<<y<<"\n";
    }
    return funct3;
  }


  int get_rd_loc(){
    int i;
    int rd;
    rd = 0;
    for (i=8;i<13;i++){
      rd = rd + (instr & (1<<i));
    }
    if (trace){
      std::bitset<32> y(rd);
      cout<<"rd = "<<y<<"\n";
    }
    return rd;
  }

  int get_opcode(){
    cout<<"helper::instr = "<<instr<<"\n";

    int i;
    int opcode;
    opcode = 0;
    for (i=0;i<7;i++){
      opcode = opcode + (instr & (1<<i));
    }
    if (trace){
      std::bitset<32> y(opcode);
      cout<<"opcode = "<<y<<"\n";
    }
    return opcode;
  }

  int get_rs1_val(int rs1_loc) {
    int res;
    cout<<"helper::get_rs1_val: rs1_loc = "<<rs1_loc<<"\n";
    res = mem.get_mem_val(rs1_loc);
    return res;
  }


  int get_rs2_val(int rs2_loc) {
    int res;
    cout<<"helper::get_rs2_val: rs1_loc = "<<rs2_loc<<"\n";
    res = mem.get_mem_val(rs2_loc);
    cout<<"helper::get_rs2_val rs2_val = "<<res<<"\n";
    return res;
  }

  int get_rd_val(int rd_loc) {
    int res;
    res = mem.get_mem_val(rd_loc);
    return res;
  }

  void set_rd_val(int rd_loc, int val){
    cout<<"helper::rd_loc = "<<rd_loc<<"\n";
    cout<<"helper::rd_val = "<<val<<"\n";
    mem.set_mem_val(rd_loc, val);
  }

};
#endif
