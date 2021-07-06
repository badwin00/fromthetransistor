// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vreceiver.h for the primary calling header

#include "Vreceiver.h"
#include "Vreceiver__Syms.h"

//==========

VerilatedContext* Vreceiver::contextp() const {
    return vlSymsp->_vm_contextp__;
}

void Vreceiver___eval_initial(Vreceiver* vlSelf);
void Vreceiver___eval_settle(Vreceiver* vlSelf);
void Vreceiver___eval(Vreceiver* vlSelf);
QData Vreceiver___change_request(Vreceiver* vlSelf);
#ifdef VL_DEBUG
void Vreceiver___eval_debug_assertions(Vreceiver* vlSelf);
#endif  // VL_DEBUG
void Vreceiver___final(Vreceiver* vlSelf);

static void _eval_initial_loop(Vreceiver* vlSelf) {
    Vreceiver__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vlSymsp->__Vm_didInit = true;
    Vreceiver___eval_initial(vlSelf);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        Vreceiver___eval_settle(vlSelf);
        Vreceiver___eval(vlSelf);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = Vreceiver___change_request(vlSelf);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("receiver.v", 1, "",
                "Verilated model didn't DC converge\n"
                "- See https://verilator.org/warn/DIDNOTCONVERGE");
        } else {
            __Vchange = Vreceiver___change_request(vlSelf);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vreceiver::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vreceiver::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vreceiver___eval_debug_assertions(this);
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(this);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        Vreceiver___eval(this);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = Vreceiver___change_request(this);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("receiver.v", 1, "",
                "Verilated model didn't converge\n"
                "- See https://verilator.org/warn/DIDNOTCONVERGE");
        } else {
            __Vchange = Vreceiver___change_request(this);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vreceiver::final() {
    Vreceiver___final(this);
}

VL_INLINE_OPT void Vreceiver___combo__TOP__2(Vreceiver* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vreceiver__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vreceiver___combo__TOP__2\n"); );
    // Variables
    CData/*0:0*/ receiver__DOT__RECEIVE__DOT__hold;
    // Body
    VL_WRITEF("received start bit!\n");
    receiver__DOT__RECEIVE__DOT__hold = vlSelf->serial;
    VL_WRITEF("received data bit %b\n",1,receiver__DOT__RECEIVE__DOT__hold);
    vlSelf->trans = receiver__DOT__RECEIVE__DOT__hold;
}

void Vreceiver___eval(Vreceiver* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vreceiver__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vreceiver___eval\n"); );
    // Body
    Vreceiver___combo__TOP__2(vlSelf);
}

QData Vreceiver___change_request_1(Vreceiver* vlSelf);

VL_INLINE_OPT QData Vreceiver___change_request(Vreceiver* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vreceiver__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vreceiver___change_request\n"); );
    // Body
    return (Vreceiver___change_request_1(vlSelf));
}

VL_INLINE_OPT QData Vreceiver___change_request_1(Vreceiver* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vreceiver__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vreceiver___change_request_1\n"); );
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vreceiver___eval_debug_assertions(Vreceiver* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vreceiver__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vreceiver___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->serial & 0xfeU))) {
        Verilated::overWidthError("serial");}
}
#endif  // VL_DEBUG
