// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vnarrow2wide.h for the primary calling header

#include "Vnarrow2wide.h"
#include "Vnarrow2wide__Syms.h"

//==========

void Vnarrow2wide::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vnarrow2wide::eval\n"); );
    Vnarrow2wide__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vnarrow2wide* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        vlSymsp->__Vm_activity = true;
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("narrow2wide.sv", 1, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vnarrow2wide::_eval_initial_loop(Vnarrow2wide__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("narrow2wide.sv", 1, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vnarrow2wide::_sequent__TOP__2(Vnarrow2wide__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnarrow2wide::_sequent__TOP__2\n"); );
    Vnarrow2wide* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->data_out = ((IData)(vlTOPp->rst_slow) ? 
                        (((IData)(vlTOPp->data_in) 
                          << 8U) | (IData)(vlTOPp->narrow2wide__DOT__data_int))
                         : 0U);
}

VL_INLINE_OPT void Vnarrow2wide::_sequent__TOP__3(Vnarrow2wide__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnarrow2wide::_sequent__TOP__3\n"); );
    Vnarrow2wide* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->narrow2wide__DOT__data_int = ((IData)(vlTOPp->rst_fast)
                                           ? (IData)(vlTOPp->data_in)
                                           : 0U);
}

void Vnarrow2wide::_eval(Vnarrow2wide__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnarrow2wide::_eval\n"); );
    Vnarrow2wide* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((((IData)(vlTOPp->clk_slow) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk_slow))) 
         | ((~ (IData)(vlTOPp->rst_slow)) & (IData)(vlTOPp->__Vclklast__TOP__rst_slow)))) {
        vlTOPp->_sequent__TOP__2(vlSymsp);
    }
    if ((((IData)(vlTOPp->clk_fast) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk_fast))) 
         | ((~ (IData)(vlTOPp->rst_fast)) & (IData)(vlTOPp->__Vclklast__TOP__rst_fast)))) {
        vlTOPp->_sequent__TOP__3(vlSymsp);
    }
    // Final
    vlTOPp->__Vclklast__TOP__clk_fast = vlTOPp->clk_fast;
    vlTOPp->__Vclklast__TOP__rst_fast = vlTOPp->rst_fast;
    vlTOPp->__Vclklast__TOP__clk_slow = vlTOPp->clk_slow;
    vlTOPp->__Vclklast__TOP__rst_slow = vlTOPp->rst_slow;
}

VL_INLINE_OPT QData Vnarrow2wide::_change_request(Vnarrow2wide__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnarrow2wide::_change_request\n"); );
    Vnarrow2wide* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData Vnarrow2wide::_change_request_1(Vnarrow2wide__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnarrow2wide::_change_request_1\n"); );
    Vnarrow2wide* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vnarrow2wide::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnarrow2wide::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clk_slow & 0xfeU))) {
        Verilated::overWidthError("clk_slow");}
    if (VL_UNLIKELY((rst_slow & 0xfeU))) {
        Verilated::overWidthError("rst_slow");}
    if (VL_UNLIKELY((clk_fast & 0xfeU))) {
        Verilated::overWidthError("clk_fast");}
    if (VL_UNLIKELY((rst_fast & 0xfeU))) {
        Verilated::overWidthError("rst_fast");}
}
#endif  // VL_DEBUG
