// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vblink.h for the primary calling header

#include "Vblink.h"
#include "Vblink__Syms.h"

//==========

VerilatedContext* Vblink::contextp() const {
    return vlSymsp->_vm_contextp__;
}

void Vblink___eval_initial(Vblink* vlSelf);
void Vblink___eval_settle(Vblink* vlSelf);
void Vblink___eval(Vblink* vlSelf);
QData Vblink___change_request(Vblink* vlSelf);
#ifdef VL_DEBUG
void Vblink___eval_debug_assertions(Vblink* vlSelf);
#endif  // VL_DEBUG
void Vblink___final(Vblink* vlSelf);

static void _eval_initial_loop(Vblink* vlSelf) {
    Vblink__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vlSymsp->__Vm_didInit = true;
    Vblink___eval_initial(vlSelf);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        Vblink___eval_settle(vlSelf);
        Vblink___eval(vlSelf);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = Vblink___change_request(vlSelf);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("blink.v", 1, "",
                "Verilated model didn't DC converge\n"
                "- See https://verilator.org/warn/DIDNOTCONVERGE");
        } else {
            __Vchange = Vblink___change_request(vlSelf);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vblink::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vblink::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vblink___eval_debug_assertions(this);
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(this);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        Vblink___eval(this);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = Vblink___change_request(this);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("blink.v", 1, "",
                "Verilated model didn't converge\n"
                "- See https://verilator.org/warn/DIDNOTCONVERGE");
        } else {
            __Vchange = Vblink___change_request(this);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vblink::final() {
    Vblink___final(this);
}

VL_INLINE_OPT void Vblink___sequent__TOP__1(Vblink* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vblink__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vblink___sequent__TOP__1\n"); );
    // Body
    if (VL_UNLIKELY((0ULL == VL_MODDIV_QQQ(64, vlSelf->counter, 0x5f5e100ULL)))) {
        VL_WRITEF("Blink! Counter: %20#\n",64,vlSelf->counter);
    }
    vlSelf->counter = (1ULL + vlSelf->counter);
}

void Vblink___eval(Vblink* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vblink__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vblink___eval\n"); );
    // Body
    if (((IData)(vlSelf->clock) & (~ (IData)(vlSelf->__Vclklast__TOP__clock)))) {
        Vblink___sequent__TOP__1(vlSelf);
    }
    // Final
    vlSelf->__Vclklast__TOP__clock = vlSelf->clock;
}

QData Vblink___change_request_1(Vblink* vlSelf);

VL_INLINE_OPT QData Vblink___change_request(Vblink* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vblink__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vblink___change_request\n"); );
    // Body
    return (Vblink___change_request_1(vlSelf));
}

VL_INLINE_OPT QData Vblink___change_request_1(Vblink* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vblink__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vblink___change_request_1\n"); );
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vblink___eval_debug_assertions(Vblink* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vblink__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vblink___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clock & 0xfeU))) {
        Verilated::overWidthError("clock");}
}
#endif  // VL_DEBUG
