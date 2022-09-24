// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdivide_5.h for the primary calling header

#include "Vdivide_5.h"
#include "Vdivide_5__Syms.h"

//==========

VL_CTOR_IMP(Vdivide_5) {
    Vdivide_5__Syms* __restrict vlSymsp = __VlSymsp = new Vdivide_5__Syms(this, name());
    Vdivide_5* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vdivide_5::__Vconfigure(Vdivide_5__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-9);
    Verilated::timeprecision(-9);
}

Vdivide_5::~Vdivide_5() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void Vdivide_5::_initial__TOP__3(Vdivide_5__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdivide_5::_initial__TOP__3\n"); );
    Vdivide_5* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->divide_5__DOT__q2 = 0U;
    vlTOPp->divide_5__DOT__q1 = 0U;
    vlTOPp->divide_5__DOT__q0 = 0U;
}

void Vdivide_5::_settle__TOP__5(Vdivide_5__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdivide_5::_settle__TOP__5\n"); );
    Vdivide_5* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->clk_out = ((IData)(vlTOPp->divide_5__DOT__q1) 
                       | (IData)(vlTOPp->divide_5__DOT__q2temp));
    vlTOPp->divide_5__DOT__d0 = (1U & ((~ (IData)(vlTOPp->divide_5__DOT__q2)) 
                                       & (~ (IData)(vlTOPp->divide_5__DOT__q0))));
    vlTOPp->divide_5__DOT__d1 = (((IData)(vlTOPp->divide_5__DOT__q1) 
                                  & (~ (IData)(vlTOPp->divide_5__DOT__q0))) 
                                 | ((~ (IData)(vlTOPp->divide_5__DOT__q1)) 
                                    & (IData)(vlTOPp->divide_5__DOT__q0)));
}

void Vdivide_5::_eval_initial(Vdivide_5__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdivide_5::_eval_initial\n"); );
    Vdivide_5* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->_initial__TOP__3(vlSymsp);
    vlTOPp->__Vm_traceActivity[1U] = 1U;
    vlTOPp->__Vm_traceActivity[0U] = 1U;
}

void Vdivide_5::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdivide_5::final\n"); );
    // Variables
    Vdivide_5__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vdivide_5* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vdivide_5::_eval_settle(Vdivide_5__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdivide_5::_eval_settle\n"); );
    Vdivide_5* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__5(vlSymsp);
}

void Vdivide_5::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdivide_5::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    clk_out = VL_RAND_RESET_I(1);
    divide_5__DOT__d1 = VL_RAND_RESET_I(1);
    divide_5__DOT__d0 = VL_RAND_RESET_I(1);
    divide_5__DOT__q2 = VL_RAND_RESET_I(1);
    divide_5__DOT__q1 = VL_RAND_RESET_I(1);
    divide_5__DOT__q0 = VL_RAND_RESET_I(1);
    divide_5__DOT__q2temp = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
            __Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }}
}
