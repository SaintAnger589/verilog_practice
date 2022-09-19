// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vbin2gray__Syms.h"


void Vbin2gray::traceChgTop0(void* userp, VerilatedVcd* tracep) {
    Vbin2gray__Syms* __restrict vlSymsp = static_cast<Vbin2gray__Syms*>(userp);
    Vbin2gray* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        vlTOPp->traceChgSub0(userp, tracep);
    }
}

void Vbin2gray::traceChgSub0(void* userp, VerilatedVcd* tracep) {
    Vbin2gray__Syms* __restrict vlSymsp = static_cast<Vbin2gray__Syms*>(userp);
    Vbin2gray* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->chgCData(oldp+0,(vlTOPp->bin),4);
        tracep->chgBit(oldp+1,(vlTOPp->clk));
        tracep->chgBit(oldp+2,(vlTOPp->rst));
        tracep->chgBit(oldp+3,(vlTOPp->inc));
        tracep->chgCData(oldp+4,(vlTOPp->gray),4);
        tracep->chgCData(oldp+5,((0xfU & (((IData)(vlTOPp->bin2gray__DOT__bnext) 
                                           >> 1U) ^ (IData)(vlTOPp->bin2gray__DOT__bnext)))),4);
        tracep->chgCData(oldp+6,(vlTOPp->bin2gray__DOT__bnext),4);
    }
}

void Vbin2gray::traceCleanup(void* userp, VerilatedVcd* /*unused*/) {
    Vbin2gray__Syms* __restrict vlSymsp = static_cast<Vbin2gray__Syms*>(userp);
    Vbin2gray* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlTOPp->__Vm_traceActivity[0U] = 0U;
    }
}
