#include <iostream>
#include "stdio.h"
#include "verilated_vcd_c.h"
#include "Vdivide_5.h"
#include "tbclock.h"


using namespace std;

template <class MODULE> class TESTBENCH{
public:
  MODULE *m_core;
  int trace;
  VerilatedVcdC *m_trace;
  tbclock<MODULE> *tbclk;

  TESTBENCH(void){
    if (!m_core){
      m_core =  new MODULE;
      Verilated::traceEverOn(true);
    }
    if (!tbclk){
      tbclk = new tbclock<MODULE>();
    }
    trace = 1;
  }
  virtual ~TESTBENCH(void) {
    //delete m_core
    delete m_core;
    m_core = NULL;
  }
  virtual void opentrace(const char *vcdname){
    if (!m_trace){
      m_trace = new VerilatedVcdC;
    }
    m_core->trace(m_trace,99);
    m_trace->open(vcdname);

  }

  virtual void reset(void) {
    m_core->clk = 0;
    m_core->eval();
    this->tick();
  }

  virtual void tick(){
    int k;
    for(k=0;k<500;k++){
      m_core->clk = tbclk->ticktime();
      m_core->eval();
      if(trace){
        m_trace->dump(10*k);
        m_trace->flush();
      }
    }//k = 0 to 500
    exit(0);
  }//void tick
  virtual bool done(void) {
    return (Verilated::gotFinish());
    //return true;
  }
};
