// this class accepts instruction from the simulator
// and pass it on to the type of class
#include <iostream>
#include <stdint.h>
#include <stdio.h>
#include "./r_type_instr.h"
#include "riscv_instr_helper.h"
#include "testbench/ram.h"


#ifndef INSTR_BASE
#define INSTR_BASE
//class r_type_instr;
//class instr_base;
class instr_base{
      int32_t instruction;
public:

  r_type_instr rtype1;
  //riscv_instr_helper helper;

  instr_base(int32_t instr) {
    set_instr(instr);
    rtype1.set_instr(instruction);
    //helper.set_instr(instr);
  }

  void set_instr(int instr){
    this->instruction = instr;
    cout<<"base::instr = "<<instr<<"\n";
  }
  //calling to see if it is R type instruction

  //rtype.set_instr(instruction);
  //check_r_type_instr()

  void check_r_type( ram mem) {
    rtype1.check_r_type_instr(mem);
  }
};

#endif
