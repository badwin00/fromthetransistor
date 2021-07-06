// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vreceiver.h for the primary calling header

#include "Vreceiver.h"
#include "Vreceiver__Syms.h"

//==========


void Vreceiver___ctor_var_reset(Vreceiver* vlSelf);

Vreceiver::Vreceiver(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModule{_vcname__}
 {
    // Create Sym instance
    Vreceiver__Syms* __restrict vlSymsp = new Vreceiver__Syms(_vcontextp__, this, name());
    // Reset structure values
    Vreceiver___ctor_var_reset(this);
}

void Vreceiver::__Vconfigure(Vreceiver__Syms* _vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->vlSymsp = _vlSymsp;
}

Vreceiver::~Vreceiver() {
    VL_DO_CLEAR(delete vlSymsp, vlSymsp = nullptr);
}

void Vreceiver___initial__TOP__1(Vreceiver* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vreceiver__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vreceiver___initial__TOP__1\n"); );
    // Body
    VL_WRITEF("receiver is online!\n");
}

void Vreceiver___eval_initial(Vreceiver* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vreceiver__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vreceiver___eval_initial\n"); );
    // Body
    Vreceiver___initial__TOP__1(vlSelf);
}

void Vreceiver___combo__TOP__2(Vreceiver* vlSelf);

void Vreceiver___eval_settle(Vreceiver* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vreceiver__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vreceiver___eval_settle\n"); );
    // Body
    Vreceiver___combo__TOP__2(vlSelf);
}

void Vreceiver___final(Vreceiver* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vreceiver__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vreceiver___final\n"); );
}

void Vreceiver___ctor_var_reset(Vreceiver* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vreceiver__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vreceiver___ctor_var_reset\n"); );
    // Body
    vlSelf->serial = VL_RAND_RESET_I(1);
    vlSelf->trans = VL_RAND_RESET_I(1);
}
