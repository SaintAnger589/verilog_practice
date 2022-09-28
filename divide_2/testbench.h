#include <iostream>
#include "stdio.h"
#include <Vdivide_2.h>
#include "tbclock.h"
#include "verilated_vcd_c.h"

using namespace std;

template <class MODULE> class TESTBENCH {
public:
MODULE *m_core;
tbclock <MODULE> *tbclk;
VerilatedVcdC *m_trace;
int trace;

TESTBENCH() {
  if(!m_core) {
    m_core = new MODULE;
    Verilated::traceEverOn(true);
  }
  if (!tbclk){
    tbclk = new tbclock<MODULE>();
  }
  trace = 1;
}
virtual ~TESTBENCH() {
  delete m_core;
  m_core = NULL;
}

virtual void opentrace(const char *vcdname){
  if (!m_trace){
    m_trace = new VerilatedVcdC;
    m_core->trace(m_trace, 99);
    m_trace->open(vcdname);
  }
}
virtual void reset(void){
  m_core->clk = 0;
  m_core->eval();
  tick();
}
virtual void tick(){
  int k;
  for(k=0;k<500;k++){
    if(tbclk->time_next_tick()){
      m_core->clk = tbclk->tick();
      m_core->eval();
      if (trace){
        m_trace->dump(10*k);
        m_trace->flush();
      }
    }
  }
  exit(0);
}

virtual bool done(){ return (Verilated::gotFinish());}
};
