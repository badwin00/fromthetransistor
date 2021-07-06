// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VRECEIVER__SYMS_H_
#define VERILATED_VRECEIVER__SYMS_H_  // guard

#include "verilated_heavy.h"

// INCLUDE MODULE CLASSES
#include "Vreceiver.h"

// SYMS CLASS
class Vreceiver__Syms : public VerilatedSyms {
  public:

    // LOCAL STATE
    const char* const __Vm_namep;
    bool __Vm_didInit;

    // SUBCELL STATE
    Vreceiver*                     TOPp;

    // CREATORS
    Vreceiver__Syms(VerilatedContext* contextp, Vreceiver* topp, const char* namep);
    ~Vreceiver__Syms();

    // METHODS
    inline const char* name() { return __Vm_namep; }

} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
