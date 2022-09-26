#include <iostream>
#include <stdio.h>
#include "testbench.h"
#include "Vdivide_3.h"

using namespace std;

int main(int argc, char **argv) {
  Verilated::commandArgs(argc, argv);
  TESTBENCH<Vdivide_3> *tb =new TESTBENCH<Vdivide_3>();
  while(!tb->done()){
    tb->opentrace("trace.vcd");
    tb->reset();
    tb->done();
  } exit(EXIT_SUCCESS);
}
