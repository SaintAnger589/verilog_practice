//I type instruction set
//determined by opcode = (33)base16 = (51)base10
//funct7 and funct3
//opcode/funct3
//addi = 13/0 all base 16
//slti = 13/2 all base 16
#include <stdint.h>
#include <stdio.h>
#include <iostream>
#include "riscv_instr_helper.h"
#include "testbench/ram.h"

using namespace std;

#ifndef I_TYPE_INSTR
#define I_TYPE_INSTR
//class instr_base;
class i_type_instr {
  int32_t instruction;
public:
int opcode, funct3, funct7;
int rs1_loc, rd_loc, rs1_val, rd_val;
int imm, imm_27_32,imm_20_24, imm_20_26;
riscv_instr_helper helper;
i_type_instr(){
  cout<<"Inside I type instruction\n";
  imm = 0;
  //this.instruction = instr;
}

void set_instr(int32_t instr){
  this->instruction = instr;
  helper.set_instr(instruction);
  //helper.set_mem_obj(mem);
}

void check_i_type_instr(ram mem){

  helper.set_mem_obj(mem);
  opcode = helper.get_opcode();
  cout<<"i_instr_type::opcode = "<< opcode<<"\n";
  if (opcode == 0x13) {
    funct3 = helper.get_funct3();
    rs1_loc = helper.get_rs1_loc();
    rd_loc = helper.get_rd_loc();
    rs1_val = helper.get_rs1_val(rs1_loc>>15);
    //getting 12 bits of immediate
    for(int i=20;i<32;i++){
      imm = imm + (instruction & (1<<i));
    }
    //addi
    if (funct3 == 0x0){
      rd_val = rs1_val + imm;
      helper.set_rd_val(rd_loc>>7, rd_val);
    }

    //slti
    if (funct3 == 0x2){
      rd_val = (rs1_val < imm);
      helper.set_rd_val(rd_loc>>7, rd_val);
    }

    //sltiu
    if (funct3 == 0x3){
      unsigned int rs1_val_unsigned = rs1_val;
      unsigned int imm_unsigned = imm;
      rd_val = (rs1_val_unsigned < imm_unsigned);
      helper.set_rd_val(rd_loc>>7, rd_val);
    }

    //xori
    if (funct3 == 0x4){
      rd_val = rs1_val ^ imm;
      helper.set_rd_val(rd_loc>>7, rd_val);
    }

    //ori
    if (funct3 == 0x6){
      rd_val = rs1_val | imm;
      helper.set_rd_val(rd_loc>>7, rd_val);
    }

    //andi
    if (funct3 == 0x7){
      rd_val = rs1_val & imm;
      helper.set_rd_val(rd_loc>>7, rd_val);
    }


    //slli
    if (funct3 == 0x1){
      rd_val = rs1_val + imm;
      helper.set_rd_val(rd_loc>>7, rd_val);
    }


    //srli - shift right logical
    if (funct3 == 0x5){
      for(int i=27;i<32;i++){
        imm_27_32 = imm_27_32 + (instruction & (1<<i));
      }
      for(int i=20;i<25;i++){
        imm_20_24 = imm_20_24 + (instruction & (1<<i));
      }
      unsigned int imm_20_24_unsigned = imm_20_24;
      if (imm_27_32 = 0x0){
          rd_val = rs1_val >> imm_20_24_unsigned;
      } else if (imm_27_32 == 0x8) { //srai
        rd_val = rs1_val >> imm_20_24;
      }
      helper.set_rd_val(rd_loc>>7, rd_val);
  }

    }

    //load instructions
    if (opcode == 0x3) {
      int i, rd_val_int;
      funct3 = helper.get_funct3();
      rs1_loc = helper.get_rs1_loc();
      rd_loc = helper.get_rd_loc();
      rs1_val = helper.get_rs1_val(rs1_loc>>15);
      //LB
      if (funct3 == 0x0){
        //load the 8 bit value from the memory and sign extends
        for(i=20;i<32;i++){
          imm = imm + (instruction & (1<<i));
        }
        int addr = rd1 + imm;
        //load the mem value
        rd_val_int = mem[addr];
        std::bitset<32> rd_bits(rd_val);
        //sign extends
        for(i=8;i<32;i++){
          rd_bits[i] = rd_bits[i] | rd_bits[31];
        }
        //convert to int
        rd_val =  (int)(rd_bits.to_ulong());
        helper.set_rd_val(rd_loc>>7, rd_val);
      }
      //LH
      if (funct3 == 0x1){
        //load the 8 bit value from the memory and sign extends
        for(i=20;i<32;i++){
          imm = imm + (instruction & (1<<i));
        }
        int addr = rd1 + imm;
        //load the mem value
        rd_val_int = mem[addr];
        std::bitset<32> rd_bits(rd_val);
        //sign extends
        for(i=16;i<32;i++){
          rd_bits[i] = rd_bits[i] | rd_bits[31];
        }
        //convert to int
        rd_val =  (int)(rd_bits.to_ulong());
        helper.set_rd_val(rd_loc>>7, rd_val);
      }

      //LW
      if (funct3 == 0x2){
        //load the 8 bit value from the memory and sign extends
        for(i=20;i<32;i++){
          imm = imm + (instruction & (1<<i));
        }
        int addr = rd1 + imm;
        //load the mem value
        rd_val = mem[addr];
        helper.set_rd_val(rd_loc>>7, rd_val);
        //convert to int
        //rd_val =  (int)(rd_bits.to_ulong());
      }

      //LBU
      //load 8 bit values and zero extends this to XLEN
      if (funct3 == 0x4){
        //load the 8 bit value from the memory and sign extends
        for(i=20;i<32;i++){
          imm = imm + (instruction & (1<<i));
        }
        int addr = rd1 + imm;
        //load the mem value
        rd_val_int = mem[addr];
        //take out 8 bits
        int zero_extend = 8b1111_1111;
        rd_val = rd_val_int & zero_extend;

        helper.set_rd_val(rd_loc>>7, rd_val);
        //convert to int
        //rd_val =  (int)(rd_bits.to_ulong());
      }

      //LHU
      if (funct3 == 0x5){
        //load the 8 bit value from the memory and sign extends
        for(i=20;i<32;i++){
          imm = imm + (instruction & (1<<i));
        }
        int addr = rd1 + imm;
        //load the mem value
        rd_val_int = mem[addr];
        //take out 8 bits
        int zero_extend = 16b1111_1111_1111_1111;
        rd_val = rd_val_int & zero_extend;

        helper.set_rd_val(rd_loc>>7, rd_val);
        //convert to int
        //rd_val =  (int)(rd_bits.to_ulong());
      }
    }
  }//check_i_type_instr


};
