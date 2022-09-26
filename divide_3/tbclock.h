#include <iostream>
#include "stdio.h"
#include <verilated_vcd_c.h>
#include "Vdivide_3.h"

using namespace std;

template <class MODULE> class tbclock{
public:
  int last_edge, current_edge,next_edge;
  int last_tick, current_tick;
  int width;

  tbclock() {
    last_edge = 0;
    current_edge = 0;
    last_tick = 0;
    width = 10;
    current_tick = width;
  }
  tbclock(int wid){
    last_edge = 0;
    current_edge = 0;
    last_tick = 0;
    current_tick = wid;
    width = wid;
  }
  virtual bool time_next_tick(){
    if (last_tick < current_tick){
      last_tick++;
      return false;
    } else {
      last_tick = 0;
      current_tick = width;
      return true;
    }
  }

  virtual int tick(){
    if (last_edge == 0){
      current_edge = 1;
      last_edge = current_edge;
    } else {
      current_edge = 0;
      last_edge = current_edge;
    }
    return current_edge;
  }
};
