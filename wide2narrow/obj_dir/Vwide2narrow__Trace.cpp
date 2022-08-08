// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vwide2narrow__Syms.h"


void Vwide2narrow::traceChgTop0(void* userp, VerilatedVcd* tracep) {
    Vwide2narrow__Syms* __restrict vlSymsp = static_cast<Vwide2narrow__Syms*>(userp);
    Vwide2narrow* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        vlTOPp->traceChgSub0(userp, tracep);
    }
}

void Vwide2narrow::traceChgSub0(void* userp, VerilatedVcd* tracep) {
    Vwide2narrow__Syms* __restrict vlSymsp = static_cast<Vwide2narrow__Syms*>(userp);
    Vwide2narrow* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->chgBit(oldp+0,(vlTOPp->clk_wide));
        tracep->chgBit(oldp+1,(vlTOPp->clk_narrow));
        tracep->chgBit(oldp+2,(vlTOPp->rst_narrow_n));
        tracep->chgSData(oldp+3,(vlTOPp->data_wide),16);
        tracep->chgCData(oldp+4,(vlTOPp->data_narrow),8);
    }
}

void Vwide2narrow::traceCleanup(void* userp, VerilatedVcd* /*unused*/) {
    Vwide2narrow__Syms* __restrict vlSymsp = static_cast<Vwide2narrow__Syms*>(userp);
    Vwide2narrow* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlTOPp->__Vm_traceActivity[0U] = 0U;
    }
}
