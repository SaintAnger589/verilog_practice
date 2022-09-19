// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vbin2gray__Syms.h"


//======================

void Vbin2gray::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, __VlSymsp);
    traceRegister(tfp->spTrace());
}

void Vbin2gray::traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vbin2gray__Syms* __restrict vlSymsp = static_cast<Vbin2gray__Syms*>(userp);
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    Vbin2gray::traceInitTop(vlSymsp, tracep);
    tracep->scopeEscape('.');
}

//======================


void Vbin2gray::traceInitTop(void* userp, VerilatedVcd* tracep) {
    Vbin2gray__Syms* __restrict vlSymsp = static_cast<Vbin2gray__Syms*>(userp);
    Vbin2gray* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceInitSub0(userp, tracep);
    }
}

void Vbin2gray::traceInitSub0(void* userp, VerilatedVcd* tracep) {
    Vbin2gray__Syms* __restrict vlSymsp = static_cast<Vbin2gray__Syms*>(userp);
    Vbin2gray* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBus(c+1,"bin", false,-1, 3,0);
        tracep->declBit(c+2,"clk", false,-1);
        tracep->declBit(c+3,"rst", false,-1);
        tracep->declBit(c+4,"inc", false,-1);
        tracep->declBus(c+5,"gray", false,-1, 3,0);
        tracep->declBus(c+8,"bin2gray SIZE", false,-1, 31,0);
        tracep->declBus(c+1,"bin2gray bin", false,-1, 3,0);
        tracep->declBit(c+2,"bin2gray clk", false,-1);
        tracep->declBit(c+3,"bin2gray rst", false,-1);
        tracep->declBit(c+4,"bin2gray inc", false,-1);
        tracep->declBus(c+5,"bin2gray gray", false,-1, 3,0);
        tracep->declBus(c+6,"bin2gray gnext", false,-1, 3,0);
        tracep->declBus(c+7,"bin2gray bnext", false,-1, 3,0);
    }
}

void Vbin2gray::traceRegister(VerilatedVcd* tracep) {
    // Body
    {
        tracep->addFullCb(&traceFullTop0, __VlSymsp);
        tracep->addChgCb(&traceChgTop0, __VlSymsp);
        tracep->addCleanupCb(&traceCleanup, __VlSymsp);
    }
}

void Vbin2gray::traceFullTop0(void* userp, VerilatedVcd* tracep) {
    Vbin2gray__Syms* __restrict vlSymsp = static_cast<Vbin2gray__Syms*>(userp);
    Vbin2gray* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceFullSub0(userp, tracep);
    }
}

void Vbin2gray::traceFullSub0(void* userp, VerilatedVcd* tracep) {
    Vbin2gray__Syms* __restrict vlSymsp = static_cast<Vbin2gray__Syms*>(userp);
    Vbin2gray* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullCData(oldp+1,(vlTOPp->bin),4);
        tracep->fullBit(oldp+2,(vlTOPp->clk));
        tracep->fullBit(oldp+3,(vlTOPp->rst));
        tracep->fullBit(oldp+4,(vlTOPp->inc));
        tracep->fullCData(oldp+5,(vlTOPp->gray),4);
        tracep->fullCData(oldp+6,((0xfU & (((IData)(vlTOPp->bin2gray__DOT__bnext) 
                                            >> 1U) 
                                           ^ (IData)(vlTOPp->bin2gray__DOT__bnext)))),4);
        tracep->fullCData(oldp+7,(vlTOPp->bin2gray__DOT__bnext),4);
        tracep->fullIData(oldp+8,(4U),32);
    }
}
