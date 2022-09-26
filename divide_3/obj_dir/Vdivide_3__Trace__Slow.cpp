// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vdivide_3__Syms.h"


//======================

void Vdivide_3::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, __VlSymsp);
    traceRegister(tfp->spTrace());
}

void Vdivide_3::traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vdivide_3__Syms* __restrict vlSymsp = static_cast<Vdivide_3__Syms*>(userp);
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    Vdivide_3::traceInitTop(vlSymsp, tracep);
    tracep->scopeEscape('.');
}

//======================


void Vdivide_3::traceInitTop(void* userp, VerilatedVcd* tracep) {
    Vdivide_3__Syms* __restrict vlSymsp = static_cast<Vdivide_3__Syms*>(userp);
    Vdivide_3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceInitSub0(userp, tracep);
    }
}

void Vdivide_3::traceInitSub0(void* userp, VerilatedVcd* tracep) {
    Vdivide_3__Syms* __restrict vlSymsp = static_cast<Vdivide_3__Syms*>(userp);
    Vdivide_3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBit(c+6,"clk", false,-1);
        tracep->declBit(c+7,"clk_out", false,-1);
        tracep->declBit(c+6,"divide_3 clk", false,-1);
        tracep->declBit(c+7,"divide_3 clk_out", false,-1);
        tracep->declBit(c+1,"divide_3 d1", false,-1);
        tracep->declBit(c+2,"divide_3 d0", false,-1);
        tracep->declBit(c+1,"divide_3 q0", false,-1);
        tracep->declBit(c+3,"divide_3 q1", false,-1);
        tracep->declBit(c+8,"divide_3 q2", false,-1);
        tracep->declBit(c+4,"divide_3 q0bar", false,-1);
        tracep->declBit(c+5,"divide_3 q1bar", false,-1);
    }
}

void Vdivide_3::traceRegister(VerilatedVcd* tracep) {
    // Body
    {
        tracep->addFullCb(&traceFullTop0, __VlSymsp);
        tracep->addChgCb(&traceChgTop0, __VlSymsp);
        tracep->addCleanupCb(&traceCleanup, __VlSymsp);
    }
}

void Vdivide_3::traceFullTop0(void* userp, VerilatedVcd* tracep) {
    Vdivide_3__Syms* __restrict vlSymsp = static_cast<Vdivide_3__Syms*>(userp);
    Vdivide_3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceFullSub0(userp, tracep);
    }
}

void Vdivide_3::traceFullSub0(void* userp, VerilatedVcd* tracep) {
    Vdivide_3__Syms* __restrict vlSymsp = static_cast<Vdivide_3__Syms*>(userp);
    Vdivide_3* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullBit(oldp+1,(vlTOPp->divide_3__DOT__q0));
        tracep->fullBit(oldp+2,((1U & ((~ (IData)(vlTOPp->divide_3__DOT__q1)) 
                                       & (~ (IData)(vlTOPp->divide_3__DOT__q0))))));
        tracep->fullBit(oldp+3,(vlTOPp->divide_3__DOT__q1));
        tracep->fullBit(oldp+4,((1U & (~ (IData)(vlTOPp->divide_3__DOT__q0)))));
        tracep->fullBit(oldp+5,((1U & (~ (IData)(vlTOPp->divide_3__DOT__q1)))));
        tracep->fullBit(oldp+6,(vlTOPp->clk));
        tracep->fullBit(oldp+7,(vlTOPp->clk_out));
        tracep->fullBit(oldp+8,(vlTOPp->divide_3__DOT__q2));
    }
}
