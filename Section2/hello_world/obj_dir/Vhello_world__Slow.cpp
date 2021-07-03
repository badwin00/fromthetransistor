// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vhello_world.h for the primary calling header

#include "Vhello_world.h"
#include "Vhello_world__Syms.h"

//==========


void Vhello_world___ctor_var_reset(Vhello_world* vlSelf);

Vhello_world::Vhello_world(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModule{_vcname__}
 {
    // Create Sym instance
    Vhello_world__Syms* __restrict vlSymsp = new Vhello_world__Syms(_vcontextp__, this, name());
    // Reset structure values
    Vhello_world___ctor_var_reset(this);
}

void Vhello_world::__Vconfigure(Vhello_world__Syms* _vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->vlSymsp = _vlSymsp;
}

Vhello_world::~Vhello_world() {
    VL_DO_CLEAR(delete vlSymsp, vlSymsp = nullptr);
}

void Vhello_world___eval_initial(Vhello_world* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vhello_world__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhello_world___eval_initial\n"); );
    // Body
    vlSelf->__Vclklast__TOP__clock = vlSelf->clock;
}

void Vhello_world___eval_settle(Vhello_world* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vhello_world__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhello_world___eval_settle\n"); );
}

void Vhello_world___final(Vhello_world* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vhello_world__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhello_world___final\n"); );
}

void Vhello_world___ctor_var_reset(Vhello_world* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vhello_world__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhello_world___ctor_var_reset\n"); );
    // Body
    vlSelf->clock = VL_RAND_RESET_I(1);
    vlSelf->reset = VL_RAND_RESET_I(1);
    vlSelf->enable = VL_RAND_RESET_I(1);
    vlSelf->counter_out = VL_RAND_RESET_I(4);
}
