#include<stdio.h>
#include<stdlib.h>
#include "verilated.h"
#include <verilated_vcd_c.h>
#include "Vrrobin.h"
#include "testbench.h"

int main(int argc, char **argv){
  Verilated::commandArgs(argc, argv);
  TESTBENCH<Vrrobin> *tb = new TESTBENCH<Vrrobin>();
  while (!tb->done()) {
    tb->opentrace("trace.vcd");
    tb->tick();
    tb->done();
  } exit(EXIT_SUCCESS);
}
