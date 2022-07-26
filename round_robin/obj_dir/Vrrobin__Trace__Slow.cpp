// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vrrobin__Syms.h"


//======================

void Vrrobin::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, __VlSymsp);
    traceRegister(tfp->spTrace());
}

void Vrrobin::traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vrrobin__Syms* __restrict vlSymsp = static_cast<Vrrobin__Syms*>(userp);
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    Vrrobin::traceInitTop(vlSymsp, tracep);
    tracep->scopeEscape('.');
}

//======================


void Vrrobin::traceInitTop(void* userp, VerilatedVcd* tracep) {
    Vrrobin__Syms* __restrict vlSymsp = static_cast<Vrrobin__Syms*>(userp);
    Vrrobin* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceInitSub0(userp, tracep);
    }
}

void Vrrobin::traceInitSub0(void* userp, VerilatedVcd* tracep) {
    Vrrobin__Syms* __restrict vlSymsp = static_cast<Vrrobin__Syms*>(userp);
    Vrrobin* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBit(c+1,"clk", false,-1);
        tracep->declBit(c+2,"rst_n", false,-1);
        tracep->declBit(c+3,"req0", false,-1);
        tracep->declBit(c+4,"req1", false,-1);
        tracep->declBit(c+5,"req2", false,-1);
        tracep->declBit(c+6,"req3", false,-1);
        tracep->declBit(c+7,"ack", false,-1);
        tracep->declBus(c+8,"gnt", false,-1, 1,0);
        tracep->declBit(c+1,"rrobin clk", false,-1);
        tracep->declBit(c+2,"rrobin rst_n", false,-1);
        tracep->declBit(c+3,"rrobin req0", false,-1);
        tracep->declBit(c+4,"rrobin req1", false,-1);
        tracep->declBit(c+5,"rrobin req2", false,-1);
        tracep->declBit(c+6,"rrobin req3", false,-1);
        tracep->declBit(c+7,"rrobin ack", false,-1);
        tracep->declBus(c+8,"rrobin gnt", false,-1, 1,0);
        tracep->declBus(c+9,"rrobin last_grant", false,-1, 1,0);
        tracep->declBit(c+10,"rrobin change_state", false,-1);
        tracep->declBus(c+11,"rrobin state", false,-1, 1,0);
        tracep->declBus(c+12,"rrobin next_state", false,-1, 1,0);
    }
}

void Vrrobin::traceRegister(VerilatedVcd* tracep) {
    // Body
    {
        tracep->addFullCb(&traceFullTop0, __VlSymsp);
        tracep->addChgCb(&traceChgTop0, __VlSymsp);
        tracep->addCleanupCb(&traceCleanup, __VlSymsp);
    }
}

void Vrrobin::traceFullTop0(void* userp, VerilatedVcd* tracep) {
    Vrrobin__Syms* __restrict vlSymsp = static_cast<Vrrobin__Syms*>(userp);
    Vrrobin* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceFullSub0(userp, tracep);
    }
}

void Vrrobin::traceFullSub0(void* userp, VerilatedVcd* tracep) {
    Vrrobin__Syms* __restrict vlSymsp = static_cast<Vrrobin__Syms*>(userp);
    Vrrobin* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullBit(oldp+1,(vlTOPp->clk));
        tracep->fullBit(oldp+2,(vlTOPp->rst_n));
        tracep->fullBit(oldp+3,(vlTOPp->req0));
        tracep->fullBit(oldp+4,(vlTOPp->req1));
        tracep->fullBit(oldp+5,(vlTOPp->req2));
        tracep->fullBit(oldp+6,(vlTOPp->req3));
        tracep->fullBit(oldp+7,(vlTOPp->ack));
        tracep->fullCData(oldp+8,(vlTOPp->gnt),2);
        tracep->fullCData(oldp+9,(vlTOPp->rrobin__DOT__last_grant),2);
        tracep->fullBit(oldp+10,(((IData)(vlTOPp->req0) 
                                  | ((IData)(vlTOPp->req1) 
                                     | ((IData)(vlTOPp->req2) 
                                        | (IData)(vlTOPp->req3))))));
        tracep->fullCData(oldp+11,(vlTOPp->rrobin__DOT__state),2);
        tracep->fullCData(oldp+12,(((0U == (IData)(vlTOPp->rrobin__DOT__state))
                                     ? (((IData)(vlTOPp->req0) 
                                         | ((IData)(vlTOPp->req1) 
                                            | ((IData)(vlTOPp->req2) 
                                               | (IData)(vlTOPp->req3))))
                                         ? 1U : 0U)
                                     : ((1U == (IData)(vlTOPp->rrobin__DOT__state))
                                         ? 2U : ((2U 
                                                  == (IData)(vlTOPp->rrobin__DOT__state))
                                                  ? 
                                                 ((IData)(vlTOPp->ack)
                                                   ? 0U
                                                   : 2U)
                                                  : 0U)))),2);
    }
}
