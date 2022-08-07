// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vnarrow2wide__Syms.h"


//======================

void Vnarrow2wide::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, __VlSymsp);
    traceRegister(tfp->spTrace());
}

void Vnarrow2wide::traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vnarrow2wide__Syms* __restrict vlSymsp = static_cast<Vnarrow2wide__Syms*>(userp);
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    Vnarrow2wide::traceInitTop(vlSymsp, tracep);
    tracep->scopeEscape('.');
}

//======================


void Vnarrow2wide::traceInitTop(void* userp, VerilatedVcd* tracep) {
    Vnarrow2wide__Syms* __restrict vlSymsp = static_cast<Vnarrow2wide__Syms*>(userp);
    Vnarrow2wide* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceInitSub0(userp, tracep);
    }
}

void Vnarrow2wide::traceInitSub0(void* userp, VerilatedVcd* tracep) {
    Vnarrow2wide__Syms* __restrict vlSymsp = static_cast<Vnarrow2wide__Syms*>(userp);
    Vnarrow2wide* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBit(c+1,"clk_slow", false,-1);
        tracep->declBit(c+2,"rst_slow", false,-1);
        tracep->declBit(c+3,"clk_fast", false,-1);
        tracep->declBit(c+4,"rst_fast", false,-1);
        tracep->declBus(c+5,"data_in", false,-1, 7,0);
        tracep->declBus(c+6,"data_out", false,-1, 15,0);
        tracep->declBit(c+1,"narrow2wide clk_slow", false,-1);
        tracep->declBit(c+2,"narrow2wide rst_slow", false,-1);
        tracep->declBit(c+3,"narrow2wide clk_fast", false,-1);
        tracep->declBit(c+4,"narrow2wide rst_fast", false,-1);
        tracep->declBus(c+5,"narrow2wide data_in", false,-1, 7,0);
        tracep->declBus(c+6,"narrow2wide data_out", false,-1, 15,0);
        tracep->declBus(c+7,"narrow2wide data_int", false,-1, 7,0);
    }
}

void Vnarrow2wide::traceRegister(VerilatedVcd* tracep) {
    // Body
    {
        tracep->addFullCb(&traceFullTop0, __VlSymsp);
        tracep->addChgCb(&traceChgTop0, __VlSymsp);
        tracep->addCleanupCb(&traceCleanup, __VlSymsp);
    }
}

void Vnarrow2wide::traceFullTop0(void* userp, VerilatedVcd* tracep) {
    Vnarrow2wide__Syms* __restrict vlSymsp = static_cast<Vnarrow2wide__Syms*>(userp);
    Vnarrow2wide* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceFullSub0(userp, tracep);
    }
}

void Vnarrow2wide::traceFullSub0(void* userp, VerilatedVcd* tracep) {
    Vnarrow2wide__Syms* __restrict vlSymsp = static_cast<Vnarrow2wide__Syms*>(userp);
    Vnarrow2wide* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullBit(oldp+1,(vlTOPp->clk_slow));
        tracep->fullBit(oldp+2,(vlTOPp->rst_slow));
        tracep->fullBit(oldp+3,(vlTOPp->clk_fast));
        tracep->fullBit(oldp+4,(vlTOPp->rst_fast));
        tracep->fullCData(oldp+5,(vlTOPp->data_in),8);
        tracep->fullSData(oldp+6,(vlTOPp->data_out),16);
        tracep->fullCData(oldp+7,(vlTOPp->narrow2wide__DOT__data_int),8);
    }
}
