// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vhello_world.h for the primary calling header

#ifndef VERILATED_VHELLO_WORLD___024UNIT_H_
#define VERILATED_VHELLO_WORLD___024UNIT_H_  // guard

#include "verilated_heavy.h"

//==========

class Vhello_world__Syms;

//----------

VL_MODULE(Vhello_world___024unit) {
  public:

    // LOCAL VARIABLES
    CData/*0:0*/ __VmonitorOff;
    QData/*63:0*/ __VmonitorNum;

    // INTERNAL VARIABLES
    Vhello_world__Syms* vlSymsp;  // Symbol table

    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vhello_world___024unit);  ///< Copying not allowed
  public:
    Vhello_world___024unit(const char* name = "TOP");
    ~Vhello_world___024unit();

    // INTERNAL METHODS
    void __Vconfigure(Vhello_world__Syms* symsp, bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
