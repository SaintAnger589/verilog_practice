#include <iostream>
#include "stdio.h"
#include <verilated_vcd_c.h>
#include "Vdivide_2.h"
#include "testbench.h"

using namespace std;

int main(int argc, char **argv){
  Verilated::commandArgs(argc,argv);
  TESTBENCH<Vdivide_2> *tb = new TESTBENCH<Vdivide_2>();
  while(!tb->done()){
    tb->opentrace("trace.vcd");
    tb->reset();
    tb->done();
  } exit(EXIT_SUCCESS);
}
