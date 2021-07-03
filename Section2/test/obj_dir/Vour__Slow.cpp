// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vour.h for the primary calling header

#include "Vour.h"
#include "Vour__Syms.h"

//==========


void Vour___ctor_var_reset(Vour* vlSelf);

Vour::Vour(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModule{_vcname__}
 {
    // Create Sym instance
    Vour__Syms* __restrict vlSymsp = new Vour__Syms(_vcontextp__, this, name());
    // Reset structure values
    Vour___ctor_var_reset(this);
}

void Vour::__Vconfigure(Vour__Syms* _vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->vlSymsp = _vlSymsp;
}

Vour::~Vour() {
    VL_DO_CLEAR(delete vlSymsp, vlSymsp = nullptr);
}

void Vour___initial__TOP__1(Vour* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vour__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vour___initial__TOP__1\n"); );
    // Body
    VL_WRITEF("Hello World\n");
    VL_FINISH_MT("our.v", 2, "");
}

void Vour___eval_initial(Vour* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vour__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vour___eval_initial\n"); );
    // Body
    Vour___initial__TOP__1(vlSelf);
}

void Vour___eval_settle(Vour* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vour__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vour___eval_settle\n"); );
}

void Vour___final(Vour* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vour__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vour___final\n"); );
}

void Vour___ctor_var_reset(Vour* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vour__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vour___ctor_var_reset\n"); );
}
