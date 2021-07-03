// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vhello.h for the primary calling header

#include "Vhello.h"
#include "Vhello__Syms.h"

//==========


void Vhello___ctor_var_reset(Vhello* vlSelf);

Vhello::Vhello(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModule{_vcname__}
 {
    // Create Sym instance
    Vhello__Syms* __restrict vlSymsp = new Vhello__Syms(_vcontextp__, this, name());
    // Reset structure values
    Vhello___ctor_var_reset(this);
}

void Vhello::__Vconfigure(Vhello__Syms* _vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->vlSymsp = _vlSymsp;
}

Vhello::~Vhello() {
    VL_DO_CLEAR(delete vlSymsp, vlSymsp = nullptr);
}

void Vhello___initial__TOP__1(Vhello* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vhello__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhello___initial__TOP__1\n"); );
    // Body
    VL_WRITEF("Hello World by Sam\n");
    VL_FINISH_MT("hello.v", 5, "");
}

void Vhello___eval_initial(Vhello* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vhello__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhello___eval_initial\n"); );
    // Body
    Vhello___initial__TOP__1(vlSelf);
}

void Vhello___eval_settle(Vhello* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vhello__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhello___eval_settle\n"); );
}

void Vhello___final(Vhello* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vhello__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhello___final\n"); );
}

void Vhello___ctor_var_reset(Vhello* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vhello__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhello___ctor_var_reset\n"); );
}
