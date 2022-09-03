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
        //sub instructions
        //rd_val  = helper.get_rs1_val(rd_loc);
        rd_val = rs1_val - rs2_val;
        //write the rd to memory
        helper.set_rd_val(rd_loc>>7, rd_val);
      }
      //SLL - shift left logical
      if (funct3 == 0x1 && funct7 == 0x0){
        //sll instructions
        //rd_val  = helper.get_rs1_val(rd_loc);
        //for a 32 bits rs2 the whole rs2 can be taken, however for 64 bit
        //lower 5 bits only
        rd_val = rs1_val << rs2_val;
        //write the rd to memory
        helper.set_rd_val(rd_loc>>7, rd_val);
      }

      //SLT - 1 if rs1 < rs2 else 0
      if (funct3 == 0x2 && funct7 == 0x0){
        //sll instructions
        //rd_val  = helper.get_rs1_val(rd_loc);
        //for a 32 bits rs2 the whole rs2 can be taken, however for 64 bit
        //lower 5 bits only
        rd_val = (rs1_val < rs2_val);
        //write the rd to memory
        helper.set_rd_val(rd_loc>>7, rd_val);
      }

      //SLTU - slt unsigned
      if (funct3 == 0x3 && funct7 == 0x0){
        //sll instructions
        //rd_val  = helper.get_rs1_val(rd_loc);
        //for a 32 bits rs2 the whole rs2 can be taken, however for 64 bit
        //lower 5 bits only
        unsigned int rs1_val_unsigned = rs1_val;
        unsigned int rs2_val_unsigned = rs2_val;
        rd_val = (rs1_val_unsigned < rs2_val_unsigned);
        //write the rd to memory
        helper.set_rd_val(rd_loc>>7, rd_val);
      }

      //XOR
      if (funct3 == 0x4 && funct7 == 0x0){
        //xor instructions
        //rd_val  = helper.get_rs1_val(rd_loc);
        //for a 32 bits rs2 the whole rs2 can be taken, however for 64 bit
        //lower 5 bits only
        //unsigned int rs1_val_unsigned = rs1_val;
        //unsigned int rs2_val_unsigned = rs2_val;
        rd_val = (rs1_val ^ rs2_val);
        //write the rd to memory
        helper.set_rd_val(rd_loc>>7, rd_val);
      }
      //SRL - shift right logical
      if (funct3 == 0x5 && funct7 == 0x0){
        int rd_val_int;
        //srl instructions
        //rd_val  = helper.get_rs1_val(rd_loc);
        //for a 32 bits rs2 the whole rs2 can be taken, however for 64 bit
        //lower 5 bits only
        //unsigned int rs1_val_unsigned = rs1_val;
        unsigned int rs2_val_unsigned = rs2_val;
        rd_val_int = (rs1_val >> rs2_val_unsigned);
        int signed_bit = (rs1_val & (1<<31)) >> 31;
        int signed_extension  = 0;
        for(int i=rs2_val_unsigned;i<32;i++){
          rd_val = rd_val_int | (signed_bit<<i);
        }
        //write the rd to memory
        helper.set_rd_val(rd_loc>>7, rd_val);
      }

      //SRA
      if (funct3 == 0x5 && funct7 == 0x0){
        //sra instructions
        //rd_val  = helper.get_rs1_val(rd_loc);
        //for a 32 bits rs2 the whole rs2 can be taken, however for 64 bit
        //lower 5 bits only
        //unsigned int rs1_val_unsigned = rs1_val;
        unsigned int rs2_val_unsigned = rs2_val;
        rd_val = (rs1_val >> rs2_val_unsigned);
        //write the rd to memory
        helper.set_rd_val(rd_loc>>7, rd_val);
      }

      //OR
      if (funct3 == 0x6 && funct7 == 0x0){
        //and instructions
        //rd_val  = helper.get_rs1_val(rd_loc);
        //for a 32 bits rs2 the whole rs2 can be taken, however for 64 bit
        //lower 5 bits only
        //unsigned int rs1_val_unsigned = rs1_val;
        //unsigned int rs2_val_unsigned = rs2_val;
        rd_val = (rs1_val | rs2_val);
        //write the rd to memory
        helper.set_rd_val(rd_loc>>7, rd_val);
      }

      //AND
      if (funct3 == 0x7 && funct7 == 0x0){
        //sra instructions
        //rd_val  = helper.get_rs1_val(rd_loc);
        //for a 32 bits rs2 the whole rs2 can be taken, however for 64 bit
        //lower 5 bits only
        //unsigned int rs1_val_unsigned = rs1_val;
        //unsigned int rs2_val_unsigned = rs2_val;
        rd_val = (rs1_val & rs2_val);
        //write the rd to memory
        helper.set_rd_val(rd_loc>>7, rd_val);
      }
  }
}

};
#endif
