// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vdivide_5__Syms.h"


void Vdivide_5::traceChgTop0(void* userp, VerilatedVcd* tracep) {
    Vdivide_5__Syms* __restrict vlSymsp = static_cast<Vdivide_5__Syms*>(userp);
    Vdivide_5* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        vlTOPp->traceChgSub0(userp, tracep);
    }
}

void Vdivide_5::traceChgSub0(void* userp, VerilatedVcd* tracep) {
    Vdivide_5__Syms* __restrict vlSymsp = static_cast<Vdivide_5__Syms*>(userp);
    Vdivide_5* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[1U])) {
            tracep->chgBit(oldp+0,(((IData)(vlTOPp->divide_5__DOT__q1) 
                                    & (IData)(vlTOPp->divide_5__DOT__q0))));
            tracep->chgBit(oldp+1,((((IData)(vlTOPp->divide_5__DOT__q1) 
                                     & (~ (IData)(vlTOPp->divide_5__DOT__q0))) 
                                    | ((~ (IData)(vlTOPp->divide_5__DOT__q1)) 
                                       & (IData)(vlTOPp->divide_5__DOT__q0)))));
            tracep->chgBit(oldp+2,((1U & ((~ (IData)(vlTOPp->divide_5__DOT__q2)) 
                                          & (~ (IData)(vlTOPp->divide_5__DOT__q0))))));
            tracep->chgBit(oldp+3,(vlTOPp->divide_5__DOT__q2));
            tracep->chgBit(oldp+4,(vlTOPp->divide_5__DOT__q1));
            tracep->chgBit(oldp+5,(vlTOPp->divide_5__DOT__q0));
            tracep->chgBit(oldp+6,((1U & (~ (IData)(vlTOPp->divide_5__DOT__q2)))));
            tracep->chgBit(oldp+7,((1U & (~ (IData)(vlTOPp->divide_5__DOT__q1)))));
            tracep->chgBit(oldp+8,((1U & (~ (IData)(vlTOPp->divide_5__DOT__q0)))));
        }
        tracep->chgBit(oldp+9,(vlTOPp->clk));
        tracep->chgBit(oldp+10,(vlTOPp->clk_out));
        tracep->chgBit(oldp+11,(vlTOPp->divide_5__DOT__q2temp));
    }
}

void Vdivide_5::traceCleanup(void* userp, VerilatedVcd* /*unused*/) {
    Vdivide_5__Syms* __restrict vlSymsp = static_cast<Vdivide_5__Syms*>(userp);
    Vdivide_5* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlTOPp->__Vm_traceActivity[0U] = 0U;
        vlTOPp->__Vm_traceActivity[1U] = 0U;
    }
}
