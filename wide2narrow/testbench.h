#include "verilated.h"
#include <verilated_vcd_c.h>
#include "Vwide2narrow.h"
template<class MODULE> class TESTBENCH {
public:
  VerilatedVcdC *m_trace;
  unsigned long m_tickcount;
  MODULE *m_core;

  TESTBENCH(void) {
    m_core = new MODULE;
    m_tickcount= 0;
    Verilated::traceEverOn(true);
  }

  virtual void opentrace(const char *vcdname) {
    if(!m_trace){
      m_trace = new VerilatedVcdC;
      m_core->trace(m_trace,99);
      m_trace->open(vcdname);
    }
  }

  //close the trace file
  virtual void close(void){
    if(m_trace){
      m_trace->close();
      m_trace = NULL;
    }
  }
  virtual ~TESTBENCH(void) {
    delete m_core;
    m_core = NULL;
  }
  virtual void reset(void){
    //m_core->rst_wide_n = 1;
    m_core->rst_narrow_n = 1;
    //make sure inheritence gets applied
    this->tick();
    //m_core->rst_wide_n = 0;
    m_core->rst_narrow_n = 0;
  }

  virtual void tick(void) {
    m_tickcount++;
    //make sure the combinational logic depending upon
    //inputs that may have changed before we called tick
    //has settled before the rising edge of the clock
    m_core->clk_wide = 0;
    m_core->clk_narrow = 0;
    //m_core->rst_wide_n = 1;
    m_core->rst_narrow_n = 1;
    m_core->data_wide = 0xAA;
    m_core->eval();
    int trace = 1;

    for(int k =0;k<500;k++){
      if (k % 4 == 0){
        m_core->clk_narrow = !m_core->clk_narrow;
      }
      if(k % 8 == 0){
        m_core->clk_wide = !m_core->clk_wide;
        m_core->data_wide = m_core->data_wide + 3;
      }
      m_core->eval();
      if(trace){
        m_trace->dump(10*k+5);
        m_trace->flush();
      }
    }
    exit(0);
  }
  virtual bool done(void) {return Verilated::gotFinish();}
};
