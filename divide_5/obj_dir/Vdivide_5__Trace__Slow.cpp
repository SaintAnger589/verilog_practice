// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vdivide_5__Syms.h"


//======================

void Vdivide_5::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, __VlSymsp);
    traceRegister(tfp->spTrace());
}

void Vdivide_5::traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vdivide_5__Syms* __restrict vlSymsp = static_cast<Vdivide_5__Syms*>(userp);
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    Vdivide_5::traceInitTop(vlSymsp, tracep);
    tracep->scopeEscape('.');
}

//======================


void Vdivide_5::traceInitTop(void* userp, VerilatedVcd* tracep) {
    Vdivide_5__Syms* __restrict vlSymsp = static_cast<Vdivide_5__Syms*>(userp);
    Vdivide_5* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceInitSub0(userp, tracep);
    }
}

void Vdivide_5::traceInitSub0(void* userp, VerilatedVcd* tracep) {
    Vdivide_5__Syms* __restrict vlSymsp = static_cast<Vdivide_5__Syms*>(userp);
    Vdivide_5* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBit(c+10,"clk", false,-1);
        tracep->declBit(c+11,"clk_out", false,-1);
        tracep->declBit(c+10,"divide_5 clk", false,-1);
        tracep->declBit(c+11,"divide_5 clk_out", false,-1);
        tracep->declBit(c+1,"divide_5 d2", false,-1);
        tracep->declBit(c+2,"divide_5 d1", false,-1);
        tracep->declBit(c+3,"divide_5 d0", false,-1);
        tracep->declBit(c+4,"divide_5 q2", false,-1);
        tracep->declBit(c+5,"divide_5 q1", false,-1);
        tracep->declBit(c+6,"divide_5 q0", false,-1);
        tracep->declBit(c+12,"divide_5 q2temp", false,-1);
        tracep->declBit(c+7,"divide_5 q2bar", false,-1);
        tracep->declBit(c+8,"divide_5 q1bar", false,-1);
        tracep->declBit(c+9,"divide_5 q0bar", false,-1);
    }
}

void Vdivide_5::traceRegister(VerilatedVcd* tracep) {
    // Body
    {
        tracep->addFullCb(&traceFullTop0, __VlSymsp);
        tracep->addChgCb(&traceChgTop0, __VlSymsp);
        tracep->addCleanupCb(&traceCleanup, __VlSymsp);
    }
}

void Vdivide_5::traceFullTop0(void* userp, VerilatedVcd* tracep) {
    Vdivide_5__Syms* __restrict vlSymsp = static_cast<Vdivide_5__Syms*>(userp);
    Vdivide_5* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceFullSub0(userp, tracep);
    }
}

void Vdivide_5::traceFullSub0(void* userp, VerilatedVcd* tracep) {
    Vdivide_5__Syms* __restrict vlSymsp = static_cast<Vdivide_5__Syms*>(userp);
    Vdivide_5* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullBit(oldp+1,(((IData)(vlTOPp->divide_5__DOT__q1) 
                                 & (IData)(vlTOPp->divide_5__DOT__q0))));
        tracep->fullBit(oldp+2,((((IData)(vlTOPp->divide_5__DOT__q1) 
                                  & (~ (IData)(vlTOPp->divide_5__DOT__q0))) 
                                 | ((~ (IData)(vlTOPp->divide_5__DOT__q1)) 
                                    & (IData)(vlTOPp->divide_5__DOT__q0)))));
        tracep->fullBit(oldp+3,((1U & ((~ (IData)(vlTOPp->divide_5__DOT__q2)) 
                                       & (~ (IData)(vlTOPp->divide_5__DOT__q0))))));
        tracep->fullBit(oldp+4,(vlTOPp->divide_5__DOT__q2));
        tracep->fullBit(oldp+5,(vlTOPp->divide_5__DOT__q1));
        tracep->fullBit(oldp+6,(vlTOPp->divide_5__DOT__q0));
        tracep->fullBit(oldp+7,((1U & (~ (IData)(vlTOPp->divide_5__DOT__q2)))));
        tracep->fullBit(oldp+8,((1U & (~ (IData)(vlTOPp->divide_5__DOT__q1)))));
        tracep->fullBit(oldp+9,((1U & (~ (IData)(vlTOPp->divide_5__DOT__q0)))));
        tracep->fullBit(oldp+10,(vlTOPp->clk));
        tracep->fullBit(oldp+11,(vlTOPp->clk_out));
        tracep->fullBit(oldp+12,(vlTOPp->divide_5__DOT__q2temp));
    }
}
