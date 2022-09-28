// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdivide_2.h for the primary calling header

#include "Vdivide_2.h"
#include "Vdivide_2__Syms.h"

//==========

VL_CTOR_IMP(Vdivide_2) {
    Vdivide_2__Syms* __restrict vlSymsp = __VlSymsp = new Vdivide_2__Syms(this, name());
    Vdivide_2* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vdivide_2::__Vconfigure(Vdivide_2__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-9);
    Verilated::timeprecision(-9);
}

Vdivide_2::~Vdivide_2() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void Vdivide_2::_initial__TOP__2(Vdivide_2__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdivide_2::_initial__TOP__2\n"); );
    Vdivide_2* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->clk_out = 0U;
}

void Vdivide_2::_eval_initial(Vdivide_2__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdivide_2::_eval_initial\n"); );
    Vdivide_2* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->_initial__TOP__2(vlSymsp);
}

void Vdivide_2::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdivide_2::final\n"); );
    // Variables
    Vdivide_2__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vdivide_2* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vdivide_2::_eval_settle(Vdivide_2__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdivide_2::_eval_settle\n"); );
    Vdivide_2* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vdivide_2::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdivide_2::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    clk_out = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<1; ++__Vi0) {
            __Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }}
}
