//this is the class for the memory
#include <stdint.h>
#include <stdio.h>
#include <iostream>

using namespace std;
#ifndef RAM_INST
#define RAM_INST
class ram{
public:
    int mem[100];
    //FIRST 32 bits
    //rs1 -  0 - 31 rows
    //rs2 - 32 - 63 rows
    //rd - 64 - 95 rows
    ram() {
      for(int i = 0;i<100;i++){
        mem[i] = 0;
      }
    }
    void set_mem_val(int loc, int val) {
      cout<<"ram:: mem_val = "<<val<<"\n";
      cout<<"ram:: loc = "<<loc<<"\n";
      mem[loc] = val;
      cout<<"ram: mem written ="<<mem[loc]<<"\n";
    }

    int get_mem_val(int loc){
      cout<<"ram:: get_loc = "<<loc<<"\n";
      return mem[loc];
    }
};
#endif
