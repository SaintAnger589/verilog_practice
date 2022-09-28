// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vdivide_2__Syms.h"


void Vdivide_2::traceChgTop0(void* userp, VerilatedVcd* tracep) {
    Vdivide_2__Syms* __restrict vlSymsp = static_cast<Vdivide_2__Syms*>(userp);
    Vdivide_2* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        vlTOPp->traceChgSub0(userp, tracep);
    }
}

void Vdivide_2::traceChgSub0(void* userp, VerilatedVcd* tracep) {
    Vdivide_2__Syms* __restrict vlSymsp = static_cast<Vdivide_2__Syms*>(userp);
    Vdivide_2* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->chgBit(oldp+0,(vlTOPp->clk));
        tracep->chgBit(oldp+1,(vlTOPp->clk_out));
    }
}

void Vdivide_2::traceCleanup(void* userp, VerilatedVcd* /*unused*/) {
    Vdivide_2__Syms* __restrict vlSymsp = static_cast<Vdivide_2__Syms*>(userp);
    Vdivide_2* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlTOPp->__Vm_traceActivity[0U] = 0U;
    }
}
