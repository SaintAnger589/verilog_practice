#include <iostream>
#include <stdio.h>
#include "verilated_vcd_c.h"
#include "Vbin2gray.h"
#include "tbclock.h"

using namespace std;

template <class MODULE> class TESTBENCH {
public:
  VerilatedVcdC *m_trace;
  unsigned long m_tickcount;
  MODULE *m_core;
  int NUM_TESTS;
  int trace;
  //tbclock *tbclock;
  //TESTBENCH<Vbin2gray> *tb = new TESTBENCH<Vbin2gray>();
  tbclock<MODULE> *tbclk;

  TESTBENCH(void){
    m_core = new MODULE;
    tbclk = new tbclock<MODULE>();
    m_tickcount = 0;
    Verilated::traceEverOn(true);
    NUM_TESTS = 1;
    trace = 1;
  }

  virtual void opentrace(const char *vcdname){
    if (!m_trace){
      m_trace = new VerilatedVcdC;
      m_core->trace(m_trace,99);
      m_trace->open(vcdname);
    }
  }

    //close the trace file
    virtual void close(void){
      if (m_trace){
        m_trace->close();
        m_trace = NULL;
      }
    }
      virtual ~TESTBENCH(void) {
        delete m_core;
        m_core = NULL;
      }
      virtual void reset(void){
        m_core->rst = 1;
        m_core->clk =0;
        m_core->eval();
        this->tick();
        m_core->rst = 0;
      }
      virtual void tick(void) {
        int k;
        int test_binary =0b0000;
        int expected_gray = 0b0000;
        int expected_gray_and = 0b0000;

        for(k=0;k<500;k = k + 3){
            m_core->eval();
            //test_binary =0b0000;
            //clock event
            m_core->clk = tbclk->ticktime();
            m_core->eval();
            if (trace){
             m_trace->dump(10*(k));
             //m_trace->flush();
            }
            //if (k % 8 == 0) {
              //m_core->eval();
              //if (trace){
              //  m_trace->dump(10*k);
              //}
              //binary encoding
              //for (int i =0;i<8;i++){
                test_binary = test_binary & 0b1111;
                m_core->bin = test_binary;
                m_core->inc = 0b0;
                //m_core->eval();

                expected_gray = (test_binary>>1) ^ test_binary;
                //cout<<"expected_gray before bitwise AND= "<<expected_gray<<"\n";
                //expected_gray_and = expected_gray & 15;

                //expected_gray = expected_gray & 0b1111;
                m_core->eval();
                //clock event
                m_core->clk = tbclk->ticktime();
                m_core->eval();
                m_core->clk = tbclk->ticktime();
                m_core->eval();
                if (trace){
                 m_trace->dump(10*(k+1));
                 //m_trace->flush();
                }
              //}//for i 0 to 8
            //} //if (k%8==0)
            if (m_core->gray != expected_gray){
              //cout<<"Error: test_binary = "<<test_binary<<" expected_gray = "<<expected_gray<<", result = "<< m_core->gray<<"\n";
              printf("Error: bin_input =%d test_binary = %d expected_gray = %d, result = %d \n", m_core->bin, test_binary, expected_gray, m_core->gray);
            } else {
              cout<<"Success: expected_gray = "<<expected_gray<<", result = "<< (int)(m_core->gray)<<"\n";
            }
            //m_core->eval();
            test_binary = test_binary+0b1;
            if (trace){
              m_trace->dump(10*(k+2));
              m_trace->flush();
            }
        }//for k loop
        exit(0);
      }
      virtual bool done(void) {
        return (Verilated::gotFinish());
        //return true;
      }
};
