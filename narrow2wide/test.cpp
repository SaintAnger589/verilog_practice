#include <stdio.h>
#include <stdlib.h>
#include "verilated.h"
#include <verilated_vcd_c.h>
#include "Vnarrow2wide.h"
#include "testbench.h"

int main(int argc, char **argv) {
  Verilated::commandArgs(argc, argv);
  TESTBENCH<Vnarrow2wide> *tb = new TESTBENCH<Vnarrow2wide>();
  while (!tb->done()){
    tb->opentrace("trace.vcd");
    tb->tick();
    tb->done();
  } exit(EXIT_SUCCESS);
}
