// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vrrobin.h for the primary calling header

#include "Vrrobin.h"
#include "Vrrobin__Syms.h"

//==========

void Vrrobin::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vrrobin::eval\n"); );
    Vrrobin__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vrrobin* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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
            VL_FATAL_MT("rrobin.sv", 1, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vrrobin::_eval_initial_loop(Vrrobin__Syms* __restrict vlSymsp) {
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
            VL_FATAL_MT("rrobin.sv", 1, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vrrobin::_sequent__TOP__1(Vrrobin__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrrobin::_sequent__TOP__1\n"); );
    Vrrobin* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (vlTOPp->rst_n) {
        vlTOPp->rrobin__DOT__last_grant = vlTOPp->gnt;
        vlTOPp->rrobin__DOT__state = vlTOPp->rrobin__DOT__next_state;
    } else {
        vlTOPp->rrobin__DOT__last_grant = 0U;
        vlTOPp->rrobin__DOT__state = 0U;
    }
}

VL_INLINE_OPT void Vrrobin::_settle__TOP__2(Vrrobin__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrrobin::_settle__TOP__2\n"); );
    Vrrobin* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((0U != (IData)(vlTOPp->rrobin__DOT__state))) {
        if ((1U == (IData)(vlTOPp->rrobin__DOT__state))) {
            if ((0U == (IData)(vlTOPp->rrobin__DOT__last_grant))) {
                if (vlTOPp->req1) {
                    vlTOPp->gnt = 1U;
                } else {
                    if (vlTOPp->req2) {
                        vlTOPp->gnt = 2U;
                    } else {
                        if (vlTOPp->req3) {
                            vlTOPp->gnt = 3U;
                        } else {
                            if (vlTOPp->req0) {
                                vlTOPp->gnt = 0U;
                            }
                        }
                    }
                }
            } else {
                if ((1U == (IData)(vlTOPp->rrobin__DOT__last_grant))) {
                    if (vlTOPp->req2) {
                        vlTOPp->gnt = 2U;
                    } else {
                        if (vlTOPp->req3) {
                            vlTOPp->gnt = 3U;
                        } else {
                            if (vlTOPp->req0) {
                                vlTOPp->gnt = 0U;
                            } else {
                                if (vlTOPp->req1) {
                                    vlTOPp->gnt = 1U;
                                }
                            }
                        }
                    }
                } else {
                    if ((2U == (IData)(vlTOPp->rrobin__DOT__last_grant))) {
                        if (vlTOPp->req3) {
                            vlTOPp->gnt = 3U;
                        } else {
                            if (vlTOPp->req0) {
                                vlTOPp->gnt = 0U;
                            } else {
                                if (vlTOPp->req1) {
                                    vlTOPp->gnt = 1U;
                                } else {
                                    if (vlTOPp->req2) {
                                        vlTOPp->gnt = 2U;
                                    }
                                }
                            }
                        }
                    } else {
                        if ((3U == (IData)(vlTOPp->rrobin__DOT__last_grant))) {
                            if (vlTOPp->req0) {
                                vlTOPp->gnt = 0U;
                            } else {
                                if (vlTOPp->req1) {
                                    vlTOPp->gnt = 1U;
                                } else {
                                    if (vlTOPp->req2) {
                                        vlTOPp->gnt = 2U;
                                    } else {
                                        if (vlTOPp->req3) {
                                            vlTOPp->gnt = 3U;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    vlTOPp->rrobin__DOT__next_state = ((0U == (IData)(vlTOPp->rrobin__DOT__state))
                                        ? (((IData)(vlTOPp->req0) 
                                            | ((IData)(vlTOPp->req1) 
                                               | ((IData)(vlTOPp->req2) 
                                                  | (IData)(vlTOPp->req3))))
                                            ? 1U : 0U)
                                        : ((1U == (IData)(vlTOPp->rrobin__DOT__state))
                                            ? 2U : 
                                           ((2U == (IData)(vlTOPp->rrobin__DOT__state))
                                             ? ((IData)(vlTOPp->ack)
                                                 ? 0U
                                                 : 2U)
                                             : 0U)));
}

void Vrrobin::_eval(Vrrobin__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrrobin::_eval\n"); );
    Vrrobin* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
         | ((~ (IData)(vlTOPp->rst_n)) & (IData)(vlTOPp->__Vclklast__TOP__rst_n)))) {
        vlTOPp->_sequent__TOP__1(vlSymsp);
    }
    vlTOPp->_settle__TOP__2(vlSymsp);
    // Final
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->__Vclklast__TOP__rst_n = vlTOPp->rst_n;
}

VL_INLINE_OPT QData Vrrobin::_change_request(Vrrobin__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrrobin::_change_request\n"); );
    Vrrobin* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData Vrrobin::_change_request_1(Vrrobin__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrrobin::_change_request_1\n"); );
    Vrrobin* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vrrobin::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrrobin::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((rst_n & 0xfeU))) {
        Verilated::overWidthError("rst_n");}
    if (VL_UNLIKELY((req0 & 0xfeU))) {
        Verilated::overWidthError("req0");}
    if (VL_UNLIKELY((req1 & 0xfeU))) {
        Verilated::overWidthError("req1");}
    if (VL_UNLIKELY((req2 & 0xfeU))) {
        Verilated::overWidthError("req2");}
    if (VL_UNLIKELY((req3 & 0xfeU))) {
        Verilated::overWidthError("req3");}
    if (VL_UNLIKELY((ack & 0xfeU))) {
        Verilated::overWidthError("ack");}
}
#endif  // VL_DEBUG
