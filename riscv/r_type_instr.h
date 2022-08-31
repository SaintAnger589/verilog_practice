//R type instruction set
//determined by opcode = (33)base16 = (51)base10
//funct7 and funct3
//opcode/funct3/funct7
//add = 33/0/0 all base 16
//sub = 33/0/20 all base 16
#include <stdint.h>
#include <stdio.h>
#include <iostream>
#include "riscv_instr_helper.h"
#include "testbench/ram.h"


using namespace std;

#ifndef R_TYPE_INSTR
#define R_TYPE_INSTR
//class instr_base;
class r_type_instr {
    int32_t instruction;
public:
  int opcode, funct3, funct7;
  int rs1_loc, rs2_loc, rd_loc, rs1_val, rs2_val, rd_val;
  riscv_instr_helper helper;
  r_type_instr(){
    cout<<"Inside r type instruction\n";
    //this.instruction = instr;
  }

  void set_instr(int32_t instr){
    this->instruction = instr;
    helper.set_instr(instruction);
    //helper.set_mem_obj(mem);
  }

  void check_r_type_instr(ram mem){
    //set helper instructions
    //helper.set_instr(instrucion);
    helper.set_mem_obj(mem);
    opcode = helper.get_opcode();
    cout<<"r_instr_type::opcode = "<< opcode<<"\n";
    if (opcode == 0x33){
      cout<<"inside r_type_instruction opcode is of type r type\n";
      //R type instructions
      funct3 = helper.get_funct3();
      funct7 = helper.get_funct7();
      rs1_loc = helper.get_rs1_loc();
      rs2_loc = helper.get_rs2_loc();
      rd_loc = helper.get_rd_loc();

      rs1_val = helper.get_rs1_val(rs1_loc>>15);
      rs2_val = helper.get_rs2_val(rs2_loc>>20);

      cout<<"r_instr_type:: rs1_val = "<<rs1_val<<"\n";
      cout<<"r_instr_type:: rs2_val = "<<rs2_val<<"\n";
      //add
      if (funct3 == 0 && funct7 == 0){
        //add instructions
        //rd_val  = helper.get_rs1_val(rd_loc);
        rd_val = rs1_val + rs2_val;
        //write the rd to memory
        helper.set_rd_val(rd_loc>>7, rd_val);
      }
      //sub
      if (funct3 == 0 && funct7 == 0x20){
        //add instructions
        //rd_val  = helper.get_rs1_val(rd_loc);
        rd_val = rs1_val - rs2_val;
        //write the rd to memory
        helper.set_rd_val(rd_loc>>7, rd_val);
      }
  }
}

};
#endif
