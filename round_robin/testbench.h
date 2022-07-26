#include "verilated.h"
#include <verilated_vcd_c.h>
#include "Vrrobin.h"

template<class MODULE> class TESTBENCH {
public:
  VerilatedVcdC *m_trace;
  unsigned long m_tickcount;
  MODULE *m_core;

  TESTBENCH(void) {
    m_core = new MODULE;
    m_tickcount = 0;
    Verilated::traceEverOn(true);
  }

  //open/create a trace file
  virtual void opentrace(const char *vcdname){
    if(!m_trace) {
      m_trace = new VerilatedVcdC;
      m_core->trace(m_trace,99);
      m_trace->open(vcdname);
    }
  }

  //close the trace file
  virtual void close(void) {
    if(m_trace) {
      m_trace->close();
      m_trace = NULL;
    }
  }
  virtual ~TESTBENCH(void) {
    delete m_core;
    m_core =NULL;
  }

  virtual void reset(void) {
    m_core->rst_n = 1;
    //make sure inheritence gets applied
    this->tick();
    m_core->rst_n = 0;
    this->tick();
    m_core->rst_n = 1;
  }

  virtual void tick(void) {
    //increment our own internal timer for reference
    m_tickcount++;
    //makes sure any combinatorial logic depending upon
    //inputs that may have changed before we called tick()
    //has settled before the rising edge of the clock
    m_core->clk = 0;
    m_core->rst_n = 1;
    m_core->eval();
    int trace =1;
    int last_i,last_i1,last_i2,last_i3,last_i4;

    //dump the waves in the trace file
    //if (trace) m_trace->dump(10*m_tickcount -2);
    //repeat for the positive edge of the clock
    //m_core->clk = 1;
    //m_core->eval();
    //if(trace) m_trace->dump(10*m_tickcount);

    //now the negative negedge
    m_core->clk = 0;
    m_core->eval();
    //if(trace) {
    //  m_trace->dump(10*m_tickcount+5);
      //m_trace->flush();
    //}
    //now the specific testcase
    //for(int i =0;i<500;i++){
      //m_core->clk = k % 4;
      //m_core->clk = k % 2;
      //raise req0
      m_core->req0 = 1;
      //raise for 4 clk cycle
      last_i = this->counter(4,11);
      m_core->req0 = 0;
      //raise the ack signal
      m_core->ack=1;
      //wait for a clock and lower ack
      last_i1 = this->counter(1,last_i+1);
      m_core->ack = 0;
      m_core->eval();
      //now raise req 2
      m_core->req2 = 1;
      last_i2 = this->counter(4,last_i1+1);
      m_core->req2 = 0;
      m_core->ack = 1;
      //wait for a clock and lower ack
      last_i3 = this->counter(1,last_i2+1);
      m_core->ack = 0;
      m_core->eval();
      last_i4 = this->counter(50,last_i3+1);
      exit(0);
    //}
  }
  virtual int counter(int num,int prev){
    int i;
    for(i=0;i<num*2;i++){
      m_core->clk =i % 2;
      //if (i == 0) {
        m_trace->dump(10*i+5+prev);
        m_trace->flush();
      //}
      m_core->eval();
    }
    return (10*i+5+prev);
  }

  virtual bool done(void) {return (Verilated::gotFinish());}
};
