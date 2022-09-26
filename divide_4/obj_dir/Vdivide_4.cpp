// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdivide_4.h for the primary calling header

#include "Vdivide_4.h"
#include "Vdivide_4__Syms.h"

//==========

void Vdivide_4::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vdivide_4::eval\n"); );
    Vdivide_4__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vdivide_4* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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
            VL_FATAL_MT("divide_4.v", 1, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vdivide_4::_eval_initial_loop(Vdivide_4__Syms* __restrict vlSymsp) {
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
            VL_FATAL_MT("divide_4.v", 1, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vdivide_4::_sequent__TOP__1(Vdivide_4__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdivide_4::_sequent__TOP__1\n"); );
    Vdivide_4* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->divide_4__DOT__clk_2 = (1U & (~ (IData)(vlTOPp->divide_4__DOT__clk_2)));
}

VL_INLINE_OPT void Vdivide_4::_sequent__TOP__3(Vdivide_4__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdivide_4::_sequent__TOP__3\n"); );
    Vdivide_4* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->clk_out = (1U & (~ (IData)(vlTOPp->clk_out)));
}

void Vdivide_4::_eval(Vdivide_4__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdivide_4::_eval\n"); );
    Vdivide_4* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk)))) {
        vlTOPp->_sequent__TOP__1(vlSymsp);
    }
    if (((IData)(vlTOPp->__VinpClk__TOP__divide_4__DOT__clk_2) 
         & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__divide_4__DOT__clk_2)))) {
        vlTOPp->_sequent__TOP__3(vlSymsp);
    }
    // Final
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__divide_4__DOT__clk_2 
        = vlTOPp->__VinpClk__TOP__divide_4__DOT__clk_2;
    vlTOPp->__VinpClk__TOP__divide_4__DOT__clk_2 = vlTOPp->divide_4__DOT__clk_2;
}

VL_INLINE_OPT QData Vdivide_4::_change_request(Vdivide_4__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdivide_4::_change_request\n"); );
    Vdivide_4* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData Vdivide_4::_change_request_1(Vdivide_4__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdivide_4::_change_request_1\n"); );
    Vdivide_4* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    __req |= ((vlTOPp->divide_4__DOT__clk_2 ^ vlTOPp->__Vchglast__TOP__divide_4__DOT__clk_2));
    VL_DEBUG_IF( if(__req && ((vlTOPp->divide_4__DOT__clk_2 ^ vlTOPp->__Vchglast__TOP__divide_4__DOT__clk_2))) VL_DBG_MSGF("        CHANGE: divide_4.v:4: divide_4.clk_2\n"); );
    // Final
    vlTOPp->__Vchglast__TOP__divide_4__DOT__clk_2 = vlTOPp->divide_4__DOT__clk_2;
    return __req;
}

#ifdef VL_DEBUG
void Vdivide_4::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdivide_4::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
}
#endif  // VL_DEBUG
