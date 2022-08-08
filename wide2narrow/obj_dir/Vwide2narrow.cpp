// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vwide2narrow.h for the primary calling header

#include "Vwide2narrow.h"
#include "Vwide2narrow__Syms.h"

//==========

void Vwide2narrow::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vwide2narrow::eval\n"); );
    Vwide2narrow__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vwide2narrow* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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
            VL_FATAL_MT("wide2narrow.sv", 1, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vwide2narrow::_eval_initial_loop(Vwide2narrow__Syms* __restrict vlSymsp) {
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
            VL_FATAL_MT("wide2narrow.sv", 1, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vwide2narrow::_sequent__TOP__1(Vwide2narrow__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vwide2narrow::_sequent__TOP__1\n"); );
    Vwide2narrow* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->data_narrow = ((IData)(vlTOPp->rst_narrow_n)
                            ? (0xffU & ((IData)(vlTOPp->clk_wide)
                                         ? (IData)(vlTOPp->data_wide)
                                         : ((IData)(vlTOPp->data_wide) 
                                            >> 8U)))
                            : 0U);
}

void Vwide2narrow::_eval(Vwide2narrow__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vwide2narrow::_eval\n"); );
    Vwide2narrow* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((((IData)(vlTOPp->clk_narrow) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk_narrow))) 
         | ((~ (IData)(vlTOPp->rst_narrow_n)) & (IData)(vlTOPp->__Vclklast__TOP__rst_narrow_n)))) {
        vlTOPp->_sequent__TOP__1(vlSymsp);
    }
    // Final
    vlTOPp->__Vclklast__TOP__clk_narrow = vlTOPp->clk_narrow;
    vlTOPp->__Vclklast__TOP__rst_narrow_n = vlTOPp->rst_narrow_n;
}

VL_INLINE_OPT QData Vwide2narrow::_change_request(Vwide2narrow__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vwide2narrow::_change_request\n"); );
    Vwide2narrow* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData Vwide2narrow::_change_request_1(Vwide2narrow__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vwide2narrow::_change_request_1\n"); );
    Vwide2narrow* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vwide2narrow::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vwide2narrow::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clk_wide & 0xfeU))) {
        Verilated::overWidthError("clk_wide");}
    if (VL_UNLIKELY((clk_narrow & 0xfeU))) {
        Verilated::overWidthError("clk_narrow");}
    if (VL_UNLIKELY((rst_narrow_n & 0xfeU))) {
        Verilated::overWidthError("rst_narrow_n");}
}
#endif  // VL_DEBUG
