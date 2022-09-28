// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vfib.h for the primary calling header

#include "Vfib.h"
#include "Vfib__Syms.h"

//==========

VL_CTOR_IMP(Vfib) {
    Vfib__Syms* __restrict vlSymsp = __VlSymsp = new Vfib__Syms(this, name());
    Vfib* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vfib::__Vconfigure(Vfib__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-9);
    Verilated::timeprecision(-9);
}

Vfib::~Vfib() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void Vfib::_settle__TOP__2(Vfib__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfib::_settle__TOP__2\n"); );
    Vfib* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->fib_seq = vlTOPp->fib__DOT__curr_seq;
    vlTOPp->fib__DOT__step2_seq = (0x1ffU & ((IData)(vlTOPp->fib__DOT__step1_seq) 
                                             + (IData)(vlTOPp->fib__DOT__curr_seq)));
}

void Vfib::_eval_initial(Vfib__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfib::_eval_initial\n"); );
    Vfib* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->__Vclklast__TOP__rst_n = vlTOPp->rst_n;
}

void Vfib::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfib::final\n"); );
    // Variables
    Vfib__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vfib* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vfib::_eval_settle(Vfib__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfib::_eval_settle\n"); );
    Vfib* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__2(vlSymsp);
}

void Vfib::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfib::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    rst_n = VL_RAND_RESET_I(1);
    fib_seq = VL_RAND_RESET_I(9);
    fib__DOT__step2_seq = VL_RAND_RESET_I(9);
    fib__DOT__step1_seq = VL_RAND_RESET_I(9);
    fib__DOT__curr_seq = VL_RAND_RESET_I(9);
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
            __Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }}
}
