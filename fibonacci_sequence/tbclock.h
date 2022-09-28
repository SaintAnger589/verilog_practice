#include <iostream>
#include "stdio.h"
#include <verilated_vcd_c.h>
#include "Vfib.h"

using namespace std;

template <class MODULE> class tbclock {
public:
  int last_edge, next_edge;
  int last_tick, next_tick;
  int width;

  tbclock(){
    //cout<<"inside tbclock constructor"<<"\n";
    last_edge = 0;
    next_edge = 0;
    width = 10;
    last_tick = 0;
    next_tick = 10;
  }
  tbclock(int wid) {
    last_edge = 0;
    next_edge = 0;
    width = wid;
    last_tick = 0;
    next_tick = wid;
  }
  virtual bool time_next_tick() {
    if (last_tick < next_tick){
      last_tick++;
      return false;
    } else {
      last_tick = 0;
      next_tick = width;
      return true;
    }
  }
  virtual int tick(){
    //cout<<"inside tbclock:: tick()"<<"\n";
    if (last_edge == 0){
      next_edge = 1;
      last_edge = next_edge;
    } else {
      next_edge = 0;
      last_edge = next_edge;
    }
    return next_edge;
  }
};
