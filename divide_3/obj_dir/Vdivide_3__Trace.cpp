// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vdivide_3__Syms.h"


void Vdivide_3::traceChgTop0(void* userp, VerilatedVcd* tracep) {
    Vdivide_3__Syms* __restrict vlSymsp = static_cast<Vdivide_3__Syms*>(userp);
    Vdivide_3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        vlTOPp->traceChgSub0(userp, tracep);
    }
}

void Vdivide_3::traceChgSub0(void* userp, VerilatedVcd* tracep) {
    Vdivide_3__Syms* __restrict vlSymsp = static_cast<Vdivide_3__Syms*>(userp);
    Vdivide_3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[1U])) {
            tracep->chgBit(oldp+0,(vlTOPp->divide_3__DOT__q0));
            tracep->chgBit(oldp+1,((1U & ((~ (IData)(vlTOPp->divide_3__DOT__q1)) 
                                          & (~ (IData)(vlTOPp->divide_3__DOT__q0))))));
            tracep->chgBit(oldp+2,(vlTOPp->divide_3__DOT__q1));
            tracep->chgBit(oldp+3,((1U & (~ (IData)(vlTOPp->divide_3__DOT__q0)))));
            tracep->chgBit(oldp+4,((1U & (~ (IData)(vlTOPp->divide_3__DOT__q1)))));
        }
        tracep->chgBit(oldp+5,(vlTOPp->clk));
        tracep->chgBit(oldp+6,(vlTOPp->clk_out));
        tracep->chgBit(oldp+7,(vlTOPp->divide_3__DOT__q2));
    }
}

void Vdivide_3::traceCleanup(void* userp, VerilatedVcd* /*unused*/) {
    Vdivide_3__Syms* __restrict vlSymsp = static_cast<Vdivide_3__Syms*>(userp);
    Vdivide_3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlTOPp->__Vm_traceActivity[0U] = 0U;
        vlTOPp->__Vm_traceActivity[1U] = 0U;
    }
}
