#include <iostream>
#include <stdio.h>
#include "Vdivide_5.h"
#include "testbench.h"

using namespace std;

int main(int argc, char **argv){
  Verilated::commandArgs(argc, argv);
  TESTBENCH<Vdivide_5> *tb = new TESTBENCH<Vdivide_5>();
  while(!tb->done()){
    tb->opentrace("trace.vcd");
    tb->reset();
    tb->done();

  } exit(EXIT_SUCCESS);
}
