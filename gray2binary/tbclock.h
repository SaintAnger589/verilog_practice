#include <iostream>
#include <stdio.h>
#include "verilated_vcd_c.h"
#include "Vbin2gray.h"

using namespace std;

template <class MODULE> class tbclock{
public:
  int width;
  int last_edge, current_edge, next_edge;
  //MODULE *m_core;
  tbclock(){
    //MODULE *m_core = new MODULE;
    last_edge = 0;
    current_edge = 0;
    width = 10;
  }
  tbclock(int wid){
    //MODULE *m_core = new MODULE;
    last_edge = 0;
    current_edge = 0;
    width = wid;
  }
  //timescale 1ns/1ns - given at the time of verilator command

  virtual int ticktime(){
    int k = 1;
    //for (k=0;k<500;k++){
      while (k % width != 0){
        k++;
        //cout<<"tbclock k = "<<k<<"\n";
      } //while k % width == 0
      if (last_edge == 0){
        current_edge = 1;
        last_edge = current_edge;
      } else {
        current_edge = 0;
        last_edge = current_edge;
      }
      //cout<<"current_edge = "<<current_edge<<"\n";
    //} //for k 1 to 500
    return current_edge;
  }

};
