#include <iostream>
#include "stdio.h"
#include <Vfib.h>
#include "verilated_vcd_c.h"
#include "testbench.h"

using namespace std;

int main(int argc, char **argv) {
  Verilated::commandArgs(argc, argv);
  //cout<<"in main"<<"\n";
  TESTBENCH<Vfib> *tb = new TESTBENCH<Vfib>();
  while(!tb->done()){
    tb->opentrace("trace.vcd");
    tb->reset();
    tb->done();
  } exit(EXIT_SUCCESS);
}
