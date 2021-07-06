// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop.h"
#include "Vtop__Syms.h"

//==========


void Vtop___ctor_var_reset(Vtop* vlSelf);

Vtop::Vtop(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModule{_vcname__}
 {
    // Create Sym instance
    Vtop__Syms* __restrict vlSymsp = new Vtop__Syms(_vcontextp__, this, name());
    // Reset structure values
    Vtop___ctor_var_reset(this);
}

void Vtop::__Vconfigure(Vtop__Syms* _vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->vlSymsp = _vlSymsp;
}

Vtop::~Vtop() {
    VL_DO_CLEAR(delete vlSymsp, vlSymsp = nullptr);
}

void Vtop___initial__TOP__1(Vtop* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___initial__TOP__1\n"); );
    // Body
    VL_WRITEF("initial serial: %b\npost serial: 1\npost serial: 1\npost serial: 1\n",
              1,vlSelf->top__DOT__serial);
    vlSelf->top__DOT__serial = 0U;
    VL_WRITEF("post serial: 0\nreceiver is online!\n");
    vlSelf->top__DOT__rec__DOT__hold = 0U;
    vlSelf->top__DOT__rec__DOT__receiving = 0U;
    VL_WRITEF("received data!\nreceived start bit!\n");
}

void Vtop___settle__TOP__2(Vtop* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___settle__TOP__2\n"); );
    // Body
    VL_WRITEF("received data!\n");
    if ((1U & ((~ (IData)(vlSelf->top__DOT__serial)) 
               & (~ (IData)(vlSelf->top__DOT__rec__DOT__receiving))))) {
        VL_WRITEF("received start bit!\n");
    } else {
        vlSelf->top__DOT__rec__DOT__hold = vlSelf->top__DOT__serial;
        VL_WRITEF("received data bit %b\n",1,vlSelf->top__DOT__rec__DOT__hold);
    }
}

void Vtop___eval_initial(Vtop* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___eval_initial\n"); );
    // Body
    Vtop___initial__TOP__1(vlSelf);
}

void Vtop___eval_settle(Vtop* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___eval_settle\n"); );
    // Body
    Vtop___settle__TOP__2(vlSelf);
}

void Vtop___final(Vtop* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___final\n"); );
}

void Vtop___ctor_var_reset(Vtop* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___ctor_var_reset\n"); );
    // Body
    vlSelf->top__DOT__serial = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__rec__DOT__hold = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__rec__DOT__receiving = VL_RAND_RESET_I(1);
}
