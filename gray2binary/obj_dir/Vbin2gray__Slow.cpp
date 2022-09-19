// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vbin2gray.h for the primary calling header

#include "Vbin2gray.h"
#include "Vbin2gray__Syms.h"

//==========

VL_CTOR_IMP(Vbin2gray) {
    Vbin2gray__Syms* __restrict vlSymsp = __VlSymsp = new Vbin2gray__Syms(this, name());
    Vbin2gray* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vbin2gray::__Vconfigure(Vbin2gray__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-9);
    Verilated::timeprecision(-9);
}

Vbin2gray::~Vbin2gray() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void Vbin2gray::_eval_initial(Vbin2gray__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbin2gray::_eval_initial\n"); );
    Vbin2gray* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->__Vclklast__TOP__rst = vlTOPp->rst;
}

void Vbin2gray::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbin2gray::final\n"); );
    // Variables
    Vbin2gray__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vbin2gray* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vbin2gray::_eval_settle(Vbin2gray__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbin2gray::_eval_settle\n"); );
    Vbin2gray* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__2(vlSymsp);
}

void Vbin2gray::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbin2gray::_ctor_var_reset\n"); );
    // Body
    bin = VL_RAND_RESET_I(4);
    clk = VL_RAND_RESET_I(1);
    rst = VL_RAND_RESET_I(1);
    inc = VL_RAND_RESET_I(1);
    gray = VL_RAND_RESET_I(4);
    bin2gray__DOT__bnext = VL_RAND_RESET_I(4);
    { int __Vi0=0; for (; __Vi0<1; ++__Vi0) {
            __Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }}
}
