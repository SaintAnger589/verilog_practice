// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vnarrow2wide__Syms.h"


void Vnarrow2wide::traceChgTop0(void* userp, VerilatedVcd* tracep) {
    Vnarrow2wide__Syms* __restrict vlSymsp = static_cast<Vnarrow2wide__Syms*>(userp);
    Vnarrow2wide* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        vlTOPp->traceChgSub0(userp, tracep);
    }
}

void Vnarrow2wide::traceChgSub0(void* userp, VerilatedVcd* tracep) {
    Vnarrow2wide__Syms* __restrict vlSymsp = static_cast<Vnarrow2wide__Syms*>(userp);
    Vnarrow2wide* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->chgBit(oldp+0,(vlTOPp->clk_slow));
        tracep->chgBit(oldp+1,(vlTOPp->rst_slow));
        tracep->chgBit(oldp+2,(vlTOPp->clk_fast));
        tracep->chgBit(oldp+3,(vlTOPp->rst_fast));
        tracep->chgCData(oldp+4,(vlTOPp->data_in),8);
        tracep->chgSData(oldp+5,(vlTOPp->data_out),16);
        tracep->chgCData(oldp+6,(vlTOPp->narrow2wide__DOT__data_int),8);
    }
}

void Vnarrow2wide::traceCleanup(void* userp, VerilatedVcd* /*unused*/) {
    Vnarrow2wide__Syms* __restrict vlSymsp = static_cast<Vnarrow2wide__Syms*>(userp);
    Vnarrow2wide* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlTOPp->__Vm_traceActivity[0U] = 0U;
    }
}
