// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VHELLO_WORLD__SYMS_H_
#define VERILATED_VHELLO_WORLD__SYMS_H_  // guard

#include "verilated_heavy.h"

// INCLUDE MODULE CLASSES
#include "Vhello_world.h"

// SYMS CLASS
class Vhello_world__Syms : public VerilatedSyms {
  public:

    // LOCAL STATE
    const char* const __Vm_namep;
    bool __Vm_didInit;

    // SUBCELL STATE
    Vhello_world*                  TOPp;

    // CREATORS
    Vhello_world__Syms(VerilatedContext* contextp, Vhello_world* topp, const char* namep);
    ~Vhello_world__Syms();

    // METHODS
    inline const char* name() { return __Vm_namep; }

} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
