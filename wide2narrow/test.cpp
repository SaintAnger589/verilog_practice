#include <stdio.h>
#include <stdlib.h>
#include <verilated_vcd_c.h>
#include "verilated.h"
#include "Vwide2narrow.h"
#include "testbench.h"

int main(int argc, char **argv) {
  Verilated::commandArgs(argc,argv);
  TESTBENCH<Vwide2narrow> *tb =new TESTBENCH<Vwide2narrow>();
  while(!tb->done()) {
    tb->opentrace("trace.vcd");
    tb->tick();
    tb->done();
  } exit(EXIT_SUCCESS);
}
