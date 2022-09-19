#include <stdio.h>
#include <stdlib.h>
#include "verilated.h"
#include "verilated_vcd_c.h"
#include "Vbin2gray.h"
#include "testbench.h"

using namespace std;
int main(int argc, char **argv) {
  Verilated::commandArgs(argc,argv);
  TESTBENCH<Vbin2gray> *tb = new TESTBENCH<Vbin2gray>();
  while(!tb->done()){
    tb->opentrace("trace.vcd");
    tb->reset();
    tb->done();
  } exit(EXIT_SUCCESS);
}
