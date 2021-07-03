// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vhello.h for the primary calling header

#include "Vhello.h"
#include "Vhello__Syms.h"

//==========

VerilatedContext* Vhello::contextp() const {
    return vlSymsp->_vm_contextp__;
}

void Vhello___eval_initial(Vhello* vlSelf);
void Vhello___eval_settle(Vhello* vlSelf);
void Vhello___eval(Vhello* vlSelf);
QData Vhello___change_request(Vhello* vlSelf);
#ifdef VL_DEBUG
void Vhello___eval_debug_assertions(Vhello* vlSelf);
#endif  // VL_DEBUG
void Vhello___final(Vhello* vlSelf);

static void _eval_initial_loop(Vhello* vlSelf) {
    Vhello__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vlSymsp->__Vm_didInit = true;
    Vhello___eval_initial(vlSelf);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        Vhello___eval_settle(vlSelf);
        Vhello___eval(vlSelf);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = Vhello___change_request(vlSelf);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("hello.v", 1, "",
                "Verilated model didn't DC converge\n"
                "- See https://verilator.org/warn/DIDNOTCONVERGE");
        } else {
            __Vchange = Vhello___change_request(vlSelf);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vhello::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vhello::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vhello___eval_debug_assertions(this);
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(this);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        Vhello___eval(this);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = Vhello___change_request(this);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("hello.v", 1, "",
                "Verilated model didn't converge\n"
                "- See https://verilator.org/warn/DIDNOTCONVERGE");
        } else {
            __Vchange = Vhello___change_request(this);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vhello::final() {
    Vhello___final(this);
}

void Vhello___eval(Vhello* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vhello__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhello___eval\n"); );
}

QData Vhello___change_request_1(Vhello* vlSelf);

VL_INLINE_OPT QData Vhello___change_request(Vhello* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vhello__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhello___change_request\n"); );
    // Body
    return (Vhello___change_request_1(vlSelf));
}

VL_INLINE_OPT QData Vhello___change_request_1(Vhello* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vhello__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhello___change_request_1\n"); );
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vhello___eval_debug_assertions(Vhello* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vhello__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhello___eval_debug_assertions\n"); );
}
#endif  // VL_DEBUG
