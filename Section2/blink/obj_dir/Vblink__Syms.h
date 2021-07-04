// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VBLINK__SYMS_H_
#define VERILATED_VBLINK__SYMS_H_  // guard

#include "verilated_heavy.h"

// INCLUDE MODULE CLASSES
#include "Vblink.h"

// SYMS CLASS
class Vblink__Syms : public VerilatedSyms {
  public:

    // LOCAL STATE
    const char* const __Vm_namep;
    bool __Vm_didInit;

    // SUBCELL STATE
    Vblink*                        TOPp;

    // CREATORS
    Vblink__Syms(VerilatedContext* contextp, Vblink* topp, const char* namep);
    ~Vblink__Syms();

    // METHODS
    inline const char* name() { return __Vm_namep; }

} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
