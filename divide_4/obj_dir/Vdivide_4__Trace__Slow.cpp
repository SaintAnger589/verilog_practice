// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vdivide_4__Syms.h"


//======================

void Vdivide_4::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, __VlSymsp);
    traceRegister(tfp->spTrace());
}

void Vdivide_4::traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vdivide_4__Syms* __restrict vlSymsp = static_cast<Vdivide_4__Syms*>(userp);
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    Vdivide_4::traceInitTop(vlSymsp, tracep);
    tracep->scopeEscape('.');
}

//======================


void Vdivide_4::traceInitTop(void* userp, VerilatedVcd* tracep) {
    Vdivide_4__Syms* __restrict vlSymsp = static_cast<Vdivide_4__Syms*>(userp);
    Vdivide_4* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceInitSub0(userp, tracep);
    }
}

void Vdivide_4::traceInitSub0(void* userp, VerilatedVcd* tracep) {
    Vdivide_4__Syms* __restrict vlSymsp = static_cast<Vdivide_4__Syms*>(userp);
    Vdivide_4* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBit(c+1,"clk", false,-1);
        tracep->declBit(c+2,"clk_out", false,-1);
        tracep->declBit(c+1,"divide_4 clk", false,-1);
        tracep->declBit(c+2,"divide_4 clk_out", false,-1);
        tracep->declBit(c+3,"divide_4 clk_2", false,-1);
    }
}

void Vdivide_4::traceRegister(VerilatedVcd* tracep) {
    // Body
    {
        tracep->addFullCb(&traceFullTop0, __VlSymsp);
        tracep->addChgCb(&traceChgTop0, __VlSymsp);
        tracep->addCleanupCb(&traceCleanup, __VlSymsp);
    }
}

void Vdivide_4::traceFullTop0(void* userp, VerilatedVcd* tracep) {
    Vdivide_4__Syms* __restrict vlSymsp = static_cast<Vdivide_4__Syms*>(userp);
    Vdivide_4* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceFullSub0(userp, tracep);
    }
}

void Vdivide_4::traceFullSub0(void* userp, VerilatedVcd* tracep) {
    Vdivide_4__Syms* __restrict vlSymsp = static_cast<Vdivide_4__Syms*>(userp);
    Vdivide_4* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullBit(oldp+1,(vlTOPp->clk));
        tracep->fullBit(oldp+2,(vlTOPp->clk_out));
        tracep->fullBit(oldp+3,(vlTOPp->divide_4__DOT__clk_2));
    }
}
