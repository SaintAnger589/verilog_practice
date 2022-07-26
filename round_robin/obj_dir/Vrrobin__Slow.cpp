// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vrrobin.h for the primary calling header

#include "Vrrobin.h"
#include "Vrrobin__Syms.h"

//==========

VL_CTOR_IMP(Vrrobin) {
    Vrrobin__Syms* __restrict vlSymsp = __VlSymsp = new Vrrobin__Syms(this, name());
    Vrrobin* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vrrobin::__Vconfigure(Vrrobin__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

Vrrobin::~Vrrobin() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void Vrrobin::_eval_initial(Vrrobin__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrrobin::_eval_initial\n"); );
    Vrrobin* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->__Vclklast__TOP__rst_n = vlTOPp->rst_n;
}

void Vrrobin::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrrobin::final\n"); );
    // Variables
    Vrrobin__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vrrobin* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vrrobin::_eval_settle(Vrrobin__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrrobin::_eval_settle\n"); );
    Vrrobin* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__2(vlSymsp);
}

void Vrrobin::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrrobin::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    rst_n = VL_RAND_RESET_I(1);
    req0 = VL_RAND_RESET_I(1);
    req1 = VL_RAND_RESET_I(1);
    req2 = VL_RAND_RESET_I(1);
    req3 = VL_RAND_RESET_I(1);
    ack = VL_RAND_RESET_I(1);
    gnt = VL_RAND_RESET_I(2);
    rrobin__DOT__last_grant = VL_RAND_RESET_I(2);
    rrobin__DOT__state = VL_RAND_RESET_I(2);
    rrobin__DOT__next_state = VL_RAND_RESET_I(2);
    { int __Vi0=0; for (; __Vi0<1; ++__Vi0) {
            __Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }}
}
