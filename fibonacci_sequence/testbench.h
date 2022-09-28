#include <iostream>
#include "stdio.h"
#include <verilated_vcd_c.h>
#include "tbclock.h"

using namespace std;

template <class MODULE> class TESTBENCH {
public:
  MODULE *m_core;
  tbclock <MODULE> *tbclk;
  int trace;
  VerilatedVcdC *m_trace;

  TESTBENCH(){
    if (!m_core){
      m_core = new MODULE;
      Verilated::traceEverOn(true);
    }
    if (!tbclk){
      tbclk = new tbclock<MODULE>();
    }
    trace = 1;
    //cout<<"outside the constructor"<<"\n";
  }

  virtual ~TESTBENCH(){
    delete m_core;
    m_core = NULL;
  }
  virtual void opentrace(const char *vcdname){
    if (!m_trace){
      m_trace = new VerilatedVcdC;
      m_core->trace(m_trace, 99);
      m_trace->open(vcdname);
      //cout<<"openetrace end"<<"\n";
    }
  }
    virtual void reset(){
      m_core->rst_n = 1;
      m_core->eval();
      m_core->rst_n = 0;
      m_core->eval();
      m_core->rst_n = 1;
      m_core->eval();
      if(trace){
        m_trace->dump(1);
      }
      //cout<<"going to tick function in testbench"<<"\n";
      tick();
    }
    virtual void tick(){
      int k;
      for(k=0;k<200;k++){
        if (tbclk->time_next_tick()){
          //cout<<"inside time next tick"<<"\n";
          m_core->clk = tbclk->tick();
          m_core->eval();
          //cout<<"dumping the value in wave"<<"\n";
          if (trace){
            m_trace->dump(10*k);
            m_trace->flush();
          }
        }
      } //for k 0 to 500
      exit(0);
    } //tick
    virtual bool done(){return (Verilated::gotFinish());}
};
