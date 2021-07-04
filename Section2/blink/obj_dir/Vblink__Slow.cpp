// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vblink.h for the primary calling header

#include "Vblink.h"
#include "Vblink__Syms.h"

//==========


void Vblink___ctor_var_reset(Vblink* vlSelf);

Vblink::Vblink(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModule{_vcname__}
 {
    // Create Sym instance
    Vblink__Syms* __restrict vlSymsp = new Vblink__Syms(_vcontextp__, this, name());
    // Reset structure values
    Vblink___ctor_var_reset(this);
}

void Vblink::__Vconfigure(Vblink__Syms* _vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->vlSymsp = _vlSymsp;
}

Vblink::~Vblink() {
    VL_DO_CLEAR(delete vlSymsp, vlSymsp = nullptr);
}

void Vblink___eval_initial(Vblink* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vblink__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vblink___eval_initial\n"); );
    // Body
    vlSelf->__Vclklast__TOP__clock = vlSelf->clock;
}

void Vblink___eval_settle(Vblink* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vblink__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vblink___eval_settle\n"); );
}

void Vblink___final(Vblink* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vblink__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vblink___final\n"); );
}

void Vblink___ctor_var_reset(Vblink* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vblink__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vblink___ctor_var_reset\n"); );
    // Body
    vlSelf->clock = VL_RAND_RESET_I(1);
    vlSelf->counter = VL_RAND_RESET_Q(64);
}
