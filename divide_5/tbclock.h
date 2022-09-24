#include <iostream>
#include <stdio.h>
#include "verilated_vcd_c.h"
#include "Vdivide_5.h"

using namespace std;

template <class MODULE> class tbclock{
public:
  int width;
  int last_edge, current_edge, next_edge;
  tbclock(){
    last_edge = 0;
    current_edge = 0;
    next_edge = 0;
    width = 10;
  }
  tbclock(int wid) {
    last_edge = 0;
    current_edge = 0;
    width = wid;
  }

  virtual int ticktime() {
    int k = 1;
    while (k % width != 0) {
      k++;
    }
    if (last_edge == 0) {
      current_edge = 1;
      last_edge = current_edge;
    } else {
      current_edge = 0;
      last_edge = current_edge;
    }
    return current_edge;
  }
};
