#include <iostream>
#include "stdio.h"
#include <verilated_vcd_c.h>
#include "Vdivide_3.h"
#include "tbclock.h"


using namespace std;

template <class MODULE> class TESTBENCH {
public:
  MODULE *m_core;
  VerilatedVcdC *m_trace;
  tbclock<MODULE> *tbclk;
  int trace;

  TESTBENCH(){
    if (!m_core){
      m_core = new MODULE;
      Verilated::traceEverOn(true);
    }
    if (!tbclk){
      tbclk = new tbclock<MODULE>();
    }
    trace = 1;
  }
    virtual ~TESTBENCH(){
      //destroy m_core
      delete m_core;
      m_core = NULL;
    }
    virtual void opentrace(const char *vcdname){
      if (!m_trace){
        m_trace = new VerilatedVcdC;
        m_core->trace(m_trace,99);
        m_trace->open(vcdname);
      }
    }
    virtual void reset(){
      m_core->clk = 0;
      m_core->eval();
      tick();
    }

    virtual void tick(){
      int k;
      for(k = 0;k < 500;k++) {
        if (tbclk->time_next_tick()){
          m_core->clk = tbclk->tick();
          m_core->eval();
          if (trace){
            m_trace->dump(10*k);
            m_trace->flush();
          }
        }
      } //for k 0 to 500
      exit(0);
    }
    virtual bool done(void) {
      return (Verilated::gotFinish());
    }
  };
