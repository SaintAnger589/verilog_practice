// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdivide_3.h for the primary calling header

#include "Vdivide_3.h"
#include "Vdivide_3__Syms.h"

//==========

VL_CTOR_IMP(Vdivide_3) {
    Vdivide_3__Syms* __restrict vlSymsp = __VlSymsp = new Vdivide_3__Syms(this, name());
    Vdivide_3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vdivide_3::__Vconfigure(Vdivide_3__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-9);
    Verilated::timeprecision(-9);
}

Vdivide_3::~Vdivide_3() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void Vdivide_3::_initial__TOP__3(Vdivide_3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdivide_3::_initial__TOP__3\n"); );
    Vdivide_3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->divide_3__DOT__q0 = 0U;
    vlTOPp->divide_3__DOT__q1 = 0U;
}

void Vdivide_3::_settle__TOP__5(Vdivide_3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdivide_3::_settle__TOP__5\n"); );
    Vdivide_3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->clk_out = ((IData)(vlTOPp->divide_3__DOT__q2) 
                       | (IData)(vlTOPp->divide_3__DOT__q1));
    vlTOPp->divide_3__DOT__d0 = (1U & ((~ (IData)(vlTOPp->divide_3__DOT__q1)) 
                                       & (~ (IData)(vlTOPp->divide_3__DOT__q0))));
}

void Vdivide_3::_eval_initial(Vdivide_3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdivide_3::_eval_initial\n"); );
    Vdivide_3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->_initial__TOP__3(vlSymsp);
    vlTOPp->__Vm_traceActivity[1U] = 1U;
    vlTOPp->__Vm_traceActivity[0U] = 1U;
}

void Vdivide_3::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdivide_3::final\n"); );
    // Variables
    Vdivide_3__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vdivide_3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vdivide_3::_eval_settle(Vdivide_3__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdivide_3::_eval_settle\n"); );
    Vdivide_3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__5(vlSymsp);
}

void Vdivide_3::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdivide_3::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    clk_out = VL_RAND_RESET_I(1);
    divide_3__DOT__d0 = VL_RAND_RESET_I(1);
    divide_3__DOT__q0 = VL_RAND_RESET_I(1);
    divide_3__DOT__q1 = VL_RAND_RESET_I(1);
    divide_3__DOT__q2 = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
            __Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }}
}
