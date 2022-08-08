// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vwide2narrow.h for the primary calling header

#include "Vwide2narrow.h"
#include "Vwide2narrow__Syms.h"

//==========

VL_CTOR_IMP(Vwide2narrow) {
    Vwide2narrow__Syms* __restrict vlSymsp = __VlSymsp = new Vwide2narrow__Syms(this, name());
    Vwide2narrow* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vwide2narrow::__Vconfigure(Vwide2narrow__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

Vwide2narrow::~Vwide2narrow() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void Vwide2narrow::_eval_initial(Vwide2narrow__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vwide2narrow::_eval_initial\n"); );
    Vwide2narrow* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__clk_narrow = vlTOPp->clk_narrow;
    vlTOPp->__Vclklast__TOP__rst_narrow_n = vlTOPp->rst_narrow_n;
}

void Vwide2narrow::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vwide2narrow::final\n"); );
    // Variables
    Vwide2narrow__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vwide2narrow* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vwide2narrow::_eval_settle(Vwide2narrow__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vwide2narrow::_eval_settle\n"); );
    Vwide2narrow* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vwide2narrow::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vwide2narrow::_ctor_var_reset\n"); );
    // Body
    clk_wide = VL_RAND_RESET_I(1);
    clk_narrow = VL_RAND_RESET_I(1);
    rst_narrow_n = VL_RAND_RESET_I(1);
    data_wide = VL_RAND_RESET_I(16);
    data_narrow = VL_RAND_RESET_I(8);
    { int __Vi0=0; for (; __Vi0<1; ++__Vi0) {
            __Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }}
}
