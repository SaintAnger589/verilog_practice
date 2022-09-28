// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vfib__Syms.h"


//======================

void Vfib::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, __VlSymsp);
    traceRegister(tfp->spTrace());
}

void Vfib::traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vfib__Syms* __restrict vlSymsp = static_cast<Vfib__Syms*>(userp);
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    Vfib::traceInitTop(vlSymsp, tracep);
    tracep->scopeEscape('.');
}

//======================


void Vfib::traceInitTop(void* userp, VerilatedVcd* tracep) {
    Vfib__Syms* __restrict vlSymsp = static_cast<Vfib__Syms*>(userp);
    Vfib* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceInitSub0(userp, tracep);
    }
}

void Vfib::traceInitSub0(void* userp, VerilatedVcd* tracep) {
    Vfib__Syms* __restrict vlSymsp = static_cast<Vfib__Syms*>(userp);
    Vfib* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBit(c+4,"clk", false,-1);
        tracep->declBit(c+5,"rst_n", false,-1);
        tracep->declBus(c+6,"fib_seq", false,-1, 8,0);
        tracep->declBit(c+4,"fib clk", false,-1);
        tracep->declBit(c+5,"fib rst_n", false,-1);
        tracep->declBus(c+6,"fib fib_seq", false,-1, 8,0);
        tracep->declBus(c+1,"fib step2_seq", false,-1, 8,0);
        tracep->declBus(c+2,"fib step1_seq", false,-1, 8,0);
        tracep->declBus(c+3,"fib curr_seq", false,-1, 8,0);
    }
}

void Vfib::traceRegister(VerilatedVcd* tracep) {
    // Body
    {
        tracep->addFullCb(&traceFullTop0, __VlSymsp);
        tracep->addChgCb(&traceChgTop0, __VlSymsp);
        tracep->addCleanupCb(&traceCleanup, __VlSymsp);
    }
}

void Vfib::traceFullTop0(void* userp, VerilatedVcd* tracep) {
    Vfib__Syms* __restrict vlSymsp = static_cast<Vfib__Syms*>(userp);
    Vfib* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceFullSub0(userp, tracep);
    }
}

void Vfib::traceFullSub0(void* userp, VerilatedVcd* tracep) {
    Vfib__Syms* __restrict vlSymsp = static_cast<Vfib__Syms*>(userp);
    Vfib* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullSData(oldp+1,((0x1ffU & ((IData)(vlTOPp->fib__DOT__step1_seq) 
                                             + (IData)(vlTOPp->fib__DOT__curr_seq)))),9);
        tracep->fullSData(oldp+2,(vlTOPp->fib__DOT__step1_seq),9);
        tracep->fullSData(oldp+3,(vlTOPp->fib__DOT__curr_seq),9);
        tracep->fullBit(oldp+4,(vlTOPp->clk));
        tracep->fullBit(oldp+5,(vlTOPp->rst_n));
        tracep->fullSData(oldp+6,(vlTOPp->fib_seq),9);
    }
}
