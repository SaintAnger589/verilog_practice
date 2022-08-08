// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vwide2narrow__Syms.h"


//======================

void Vwide2narrow::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, __VlSymsp);
    traceRegister(tfp->spTrace());
}

void Vwide2narrow::traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vwide2narrow__Syms* __restrict vlSymsp = static_cast<Vwide2narrow__Syms*>(userp);
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    Vwide2narrow::traceInitTop(vlSymsp, tracep);
    tracep->scopeEscape('.');
}

//======================


void Vwide2narrow::traceInitTop(void* userp, VerilatedVcd* tracep) {
    Vwide2narrow__Syms* __restrict vlSymsp = static_cast<Vwide2narrow__Syms*>(userp);
    Vwide2narrow* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceInitSub0(userp, tracep);
    }
}

void Vwide2narrow::traceInitSub0(void* userp, VerilatedVcd* tracep) {
    Vwide2narrow__Syms* __restrict vlSymsp = static_cast<Vwide2narrow__Syms*>(userp);
    Vwide2narrow* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBit(c+1,"clk_wide", false,-1);
        tracep->declBit(c+2,"clk_narrow", false,-1);
        tracep->declBit(c+3,"rst_narrow_n", false,-1);
        tracep->declBus(c+4,"data_wide", false,-1, 15,0);
        tracep->declBus(c+5,"data_narrow", false,-1, 7,0);
        tracep->declBit(c+1,"wide2narrow clk_wide", false,-1);
        tracep->declBit(c+2,"wide2narrow clk_narrow", false,-1);
        tracep->declBit(c+3,"wide2narrow rst_narrow_n", false,-1);
        tracep->declBus(c+4,"wide2narrow data_wide", false,-1, 15,0);
        tracep->declBus(c+5,"wide2narrow data_narrow", false,-1, 7,0);
    }
}

void Vwide2narrow::traceRegister(VerilatedVcd* tracep) {
    // Body
    {
        tracep->addFullCb(&traceFullTop0, __VlSymsp);
        tracep->addChgCb(&traceChgTop0, __VlSymsp);
        tracep->addCleanupCb(&traceCleanup, __VlSymsp);
    }
}

void Vwide2narrow::traceFullTop0(void* userp, VerilatedVcd* tracep) {
    Vwide2narrow__Syms* __restrict vlSymsp = static_cast<Vwide2narrow__Syms*>(userp);
    Vwide2narrow* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceFullSub0(userp, tracep);
    }
}

void Vwide2narrow::traceFullSub0(void* userp, VerilatedVcd* tracep) {
    Vwide2narrow__Syms* __restrict vlSymsp = static_cast<Vwide2narrow__Syms*>(userp);
    Vwide2narrow* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullBit(oldp+1,(vlTOPp->clk_wide));
        tracep->fullBit(oldp+2,(vlTOPp->clk_narrow));
        tracep->fullBit(oldp+3,(vlTOPp->rst_narrow_n));
        tracep->fullSData(oldp+4,(vlTOPp->data_wide),16);
        tracep->fullCData(oldp+5,(vlTOPp->data_narrow),8);
    }
}
