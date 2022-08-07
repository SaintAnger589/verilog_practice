// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vnarrow2wide.h for the primary calling header

#include "Vnarrow2wide.h"
#include "Vnarrow2wide__Syms.h"

//==========

VL_CTOR_IMP(Vnarrow2wide) {
    Vnarrow2wide__Syms* __restrict vlSymsp = __VlSymsp = new Vnarrow2wide__Syms(this, name());
    Vnarrow2wide* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vnarrow2wide::__Vconfigure(Vnarrow2wide__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

Vnarrow2wide::~Vnarrow2wide() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void Vnarrow2wide::_eval_initial(Vnarrow2wide__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnarrow2wide::_eval_initial\n"); );
    Vnarrow2wide* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__clk_fast = vlTOPp->clk_fast;
    vlTOPp->__Vclklast__TOP__rst_fast = vlTOPp->rst_fast;
    vlTOPp->__Vclklast__TOP__clk_slow = vlTOPp->clk_slow;
    vlTOPp->__Vclklast__TOP__rst_slow = vlTOPp->rst_slow;
}

void Vnarrow2wide::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnarrow2wide::final\n"); );
    // Variables
    Vnarrow2wide__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vnarrow2wide* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vnarrow2wide::_eval_settle(Vnarrow2wide__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnarrow2wide::_eval_settle\n"); );
    Vnarrow2wide* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vnarrow2wide::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnarrow2wide::_ctor_var_reset\n"); );
    // Body
    clk_slow = VL_RAND_RESET_I(1);
    rst_slow = VL_RAND_RESET_I(1);
    clk_fast = VL_RAND_RESET_I(1);
    rst_fast = VL_RAND_RESET_I(1);
    data_in = VL_RAND_RESET_I(8);
    data_out = VL_RAND_RESET_I(16);
    narrow2wide__DOT__data_int = VL_RAND_RESET_I(8);
    { int __Vi0=0; for (; __Vi0<1; ++__Vi0) {
            __Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }}
}
