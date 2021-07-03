// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vour.h for the primary calling header

#include "Vour.h"
#include "Vour__Syms.h"

//==========

VerilatedContext* Vour::contextp() const {
    return vlSymsp->_vm_contextp__;
}

void Vour___eval_initial(Vour* vlSelf);
void Vour___eval_settle(Vour* vlSelf);
void Vour___eval(Vour* vlSelf);
QData Vour___change_request(Vour* vlSelf);
#ifdef VL_DEBUG
void Vour___eval_debug_assertions(Vour* vlSelf);
#endif  // VL_DEBUG
void Vour___final(Vour* vlSelf);

static void _eval_initial_loop(Vour* vlSelf) {
    Vour__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vlSymsp->__Vm_didInit = true;
    Vour___eval_initial(vlSelf);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        Vour___eval_settle(vlSelf);
        Vour___eval(vlSelf);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = Vour___change_request(vlSelf);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("our.v", 1, "",
                "Verilated model didn't DC converge\n"
                "- See https://verilator.org/warn/DIDNOTCONVERGE");
        } else {
            __Vchange = Vour___change_request(vlSelf);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vour::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vour::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vour___eval_debug_assertions(this);
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(this);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        Vour___eval(this);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = Vour___change_request(this);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("our.v", 1, "",
                "Verilated model didn't converge\n"
                "- See https://verilator.org/warn/DIDNOTCONVERGE");
        } else {
            __Vchange = Vour___change_request(this);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vour::final() {
    Vour___final(this);
}

void Vour___eval(Vour* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vour__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vour___eval\n"); );
}

QData Vour___change_request_1(Vour* vlSelf);

VL_INLINE_OPT QData Vour___change_request(Vour* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vour__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vour___change_request\n"); );
    // Body
    return (Vour___change_request_1(vlSelf));
}

VL_INLINE_OPT QData Vour___change_request_1(Vour* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vour__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vour___change_request_1\n"); );
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vour___eval_debug_assertions(Vour* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vour__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vour___eval_debug_assertions\n"); );
}
#endif  // VL_DEBUG
