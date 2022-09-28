// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vfib__Syms.h"


void Vfib::traceChgTop0(void* userp, VerilatedVcd* tracep) {
    Vfib__Syms* __restrict vlSymsp = static_cast<Vfib__Syms*>(userp);
    Vfib* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        vlTOPp->traceChgSub0(userp, tracep);
    }
}

void Vfib::traceChgSub0(void* userp, VerilatedVcd* tracep) {
    Vfib__Syms* __restrict vlSymsp = static_cast<Vfib__Syms*>(userp);
    Vfib* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[1U])) {
            tracep->chgSData(oldp+0,((0x1ffU & ((IData)(vlTOPp->fib__DOT__step1_seq) 
                                                + (IData)(vlTOPp->fib__DOT__curr_seq)))),9);
            tracep->chgSData(oldp+1,(vlTOPp->fib__DOT__step1_seq),9);
            tracep->chgSData(oldp+2,(vlTOPp->fib__DOT__curr_seq),9);
        }
        tracep->chgBit(oldp+3,(vlTOPp->clk));
        tracep->chgBit(oldp+4,(vlTOPp->rst_n));
        tracep->chgSData(oldp+5,(vlTOPp->fib_seq),9);
    }
}

void Vfib::traceCleanup(void* userp, VerilatedVcd* /*unused*/) {
    Vfib__Syms* __restrict vlSymsp = static_cast<Vfib__Syms*>(userp);
    Vfib* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlTOPp->__Vm_traceActivity[0U] = 0U;
        vlTOPp->__Vm_traceActivity[1U] = 0U;
    }
}
