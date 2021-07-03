// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vhello_world.h for the primary calling header

#include "Vhello_world.h"
#include "Vhello_world__Syms.h"

//==========

VerilatedContext* Vhello_world::contextp() const {
    return vlSymsp->_vm_contextp__;
}

void Vhello_world___eval_initial(Vhello_world* vlSelf);
void Vhello_world___eval_settle(Vhello_world* vlSelf);
void Vhello_world___eval(Vhello_world* vlSelf);
QData Vhello_world___change_request(Vhello_world* vlSelf);
#ifdef VL_DEBUG
void Vhello_world___eval_debug_assertions(Vhello_world* vlSelf);
#endif  // VL_DEBUG
void Vhello_world___final(Vhello_world* vlSelf);

static void _eval_initial_loop(Vhello_world* vlSelf) {
    Vhello_world__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vlSymsp->__Vm_didInit = true;
    Vhello_world___eval_initial(vlSelf);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        Vhello_world___eval_settle(vlSelf);
        Vhello_world___eval(vlSelf);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = Vhello_world___change_request(vlSelf);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("hello_world.v", 1, "",
                "Verilated model didn't DC converge\n"
                "- See https://verilator.org/warn/DIDNOTCONVERGE");
        } else {
            __Vchange = Vhello_world___change_request(vlSelf);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vhello_world::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vhello_world::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vhello_world___eval_debug_assertions(this);
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(this);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        Vhello_world___eval(this);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = Vhello_world___change_request(this);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("hello_world.v", 1, "",
                "Verilated model didn't converge\n"
                "- See https://verilator.org/warn/DIDNOTCONVERGE");
        } else {
            __Vchange = Vhello_world___change_request(this);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vhello_world::final() {
    Vhello_world___final(this);
}

VL_INLINE_OPT void Vhello_world___sequent__TOP__1(Vhello_world* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vhello_world__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhello_world___sequent__TOP__1\n"); );
    // Variables
    CData/*3:0*/ __Vdly__counter_out;
    // Body
    __Vdly__counter_out = vlSelf->counter_out;
    if (vlSelf->reset) {
        __Vdly__counter_out = 0U;
    } else if (vlSelf->enable) {
        __Vdly__counter_out = (0xfU & ((IData)(1U) 
                                       + (IData)(vlSelf->counter_out)));
    }
    vlSelf->counter_out = __Vdly__counter_out;
}

void Vhello_world___eval(Vhello_world* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vhello_world__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhello_world___eval\n"); );
    // Body
    if (((IData)(vlSelf->clock) & (~ (IData)(vlSelf->__Vclklast__TOP__clock)))) {
        Vhello_world___sequent__TOP__1(vlSelf);
    }
    // Final
    vlSelf->__Vclklast__TOP__clock = vlSelf->clock;
}

QData Vhello_world___change_request_1(Vhello_world* vlSelf);

VL_INLINE_OPT QData Vhello_world___change_request(Vhello_world* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vhello_world__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhello_world___change_request\n"); );
    // Body
    return (Vhello_world___change_request_1(vlSelf));
}

VL_INLINE_OPT QData Vhello_world___change_request_1(Vhello_world* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vhello_world__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhello_world___change_request_1\n"); );
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vhello_world___eval_debug_assertions(Vhello_world* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vhello_world__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhello_world___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clock & 0xfeU))) {
        Verilated::overWidthError("clock");}
    if (VL_UNLIKELY((vlSelf->reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
    if (VL_UNLIKELY((vlSelf->enable & 0xfeU))) {
        Verilated::overWidthError("enable");}
}
#endif  // VL_DEBUG
