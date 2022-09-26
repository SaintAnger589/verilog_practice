// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdivide_4.h for the primary calling header

#include "Vdivide_4.h"
#include "Vdivide_4__Syms.h"

//==========

VL_CTOR_IMP(Vdivide_4) {
    Vdivide_4__Syms* __restrict vlSymsp = __VlSymsp = new Vdivide_4__Syms(this, name());
    Vdivide_4* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vdivide_4::__Vconfigure(Vdivide_4__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-9);
    Verilated::timeprecision(-9);
}

Vdivide_4::~Vdivide_4() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void Vdivide_4::_initial__TOP__2(Vdivide_4__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdivide_4::_initial__TOP__2\n"); );
    Vdivide_4* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->divide_4__DOT__clk_2 = 0U;
    vlTOPp->clk_out = 0U;
}

void Vdivide_4::_eval_initial(Vdivide_4__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdivide_4::_eval_initial\n"); );
    Vdivide_4* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->_initial__TOP__2(vlSymsp);
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__divide_4__DOT__clk_2 
        = vlTOPp->__VinpClk__TOP__divide_4__DOT__clk_2;
}

void Vdivide_4::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdivide_4::final\n"); );
    // Variables
    Vdivide_4__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vdivide_4* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vdivide_4::_eval_settle(Vdivide_4__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdivide_4::_eval_settle\n"); );
    Vdivide_4* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vdivide_4::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdivide_4::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    clk_out = VL_RAND_RESET_I(1);
    divide_4__DOT__clk_2 = VL_RAND_RESET_I(1);
    __VinpClk__TOP__divide_4__DOT__clk_2 = VL_RAND_RESET_I(1);
    __Vchglast__TOP__divide_4__DOT__clk_2 = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<1; ++__Vi0) {
            __Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }}
}
