// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vhello_world.h for the primary calling header

#include "Vhello_world___024unit.h"
#include "Vhello_world__Syms.h"

//==========


void Vhello_world___024unit___ctor_var_reset(Vhello_world___024unit* vlSelf);

Vhello_world___024unit::Vhello_world___024unit(const char* _vcname__)
    : VerilatedModule(_vcname__)
 {
    // Reset structure values
    Vhello_world___024unit___ctor_var_reset(this);
}

void Vhello_world___024unit::__Vconfigure(Vhello_world__Syms* _vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->vlSymsp = _vlSymsp;
}

Vhello_world___024unit::~Vhello_world___024unit() {
}

void Vhello_world___024unit___ctor_var_reset(Vhello_world___024unit* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vhello_world__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+  Vhello_world___024unit___ctor_var_reset\n"); );
    // Body
    vlSelf->__VmonitorNum = VL_RAND_RESET_Q(64);
    vlSelf->__VmonitorOff = VL_RAND_RESET_I(1);
}
