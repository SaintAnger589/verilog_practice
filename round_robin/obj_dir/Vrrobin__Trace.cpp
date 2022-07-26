// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vrrobin__Syms.h"


void Vrrobin::traceChgTop0(void* userp, VerilatedVcd* tracep) {
    Vrrobin__Syms* __restrict vlSymsp = static_cast<Vrrobin__Syms*>(userp);
    Vrrobin* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        vlTOPp->traceChgSub0(userp, tracep);
    }
}

void Vrrobin::traceChgSub0(void* userp, VerilatedVcd* tracep) {
    Vrrobin__Syms* __restrict vlSymsp = static_cast<Vrrobin__Syms*>(userp);
    Vrrobin* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->chgBit(oldp+0,(vlTOPp->clk));
        tracep->chgBit(oldp+1,(vlTOPp->rst_n));
        tracep->chgBit(oldp+2,(vlTOPp->req0));
        tracep->chgBit(oldp+3,(vlTOPp->req1));
        tracep->chgBit(oldp+4,(vlTOPp->req2));
        tracep->chgBit(oldp+5,(vlTOPp->req3));
        tracep->chgBit(oldp+6,(vlTOPp->ack));
        tracep->chgCData(oldp+7,(vlTOPp->gnt),2);
        tracep->chgCData(oldp+8,(vlTOPp->rrobin__DOT__last_grant),2);
        tracep->chgBit(oldp+9,(((IData)(vlTOPp->req0) 
                                | ((IData)(vlTOPp->req1) 
                                   | ((IData)(vlTOPp->req2) 
                                      | (IData)(vlTOPp->req3))))));
        tracep->chgCData(oldp+10,(vlTOPp->rrobin__DOT__state),2);
        tracep->chgCData(oldp+11,(((0U == (IData)(vlTOPp->rrobin__DOT__state))
                                    ? (((IData)(vlTOPp->req0) 
                                        | ((IData)(vlTOPp->req1) 
                                           | ((IData)(vlTOPp->req2) 
                                              | (IData)(vlTOPp->req3))))
                                        ? 1U : 0U) : 
                                   ((1U == (IData)(vlTOPp->rrobin__DOT__state))
                                     ? 2U : ((2U == (IData)(vlTOPp->rrobin__DOT__state))
                                              ? ((IData)(vlTOPp->ack)
                                                  ? 0U
                                                  : 2U)
                                              : 0U)))),2);
    }
}

void Vrrobin::traceCleanup(void* userp, VerilatedVcd* /*unused*/) {
    Vrrobin__Syms* __restrict vlSymsp = static_cast<Vrrobin__Syms*>(userp);
    Vrrobin* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlTOPp->__Vm_traceActivity[0U] = 0U;
    }
}
