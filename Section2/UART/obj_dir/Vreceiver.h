// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef VERILATED_VRECEIVER_H_
#define VERILATED_VRECEIVER_H_  // guard

#include "verilated_heavy.h"

//==========

class Vreceiver__Syms;

//----------

VL_MODULE(Vreceiver) {
  public:

    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(serial,0,0);
    VL_OUT8(trans,0,0);

    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vreceiver__Syms* vlSymsp;  // Symbol table

    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vreceiver);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// If contextp is null, then the model will use the default global context
    /// If name is "", then makes a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vreceiver(VerilatedContext* contextp, const char* name = "TOP");
    Vreceiver(const char* name = "TOP")
      : Vreceiver(nullptr, name) {}
    /// Destroy the model; called (often implicitly) by application code
    ~Vreceiver();

    // API METHODS
    /// Return current simulation context for this model.
    /// Used to get to e.g. simulation time via contextp()->time()
    VerilatedContext* contextp() const;
    /// Evaluate the model.  Application must call when inputs change.
    void eval() { eval_step(); }
    /// Evaluate when calling multiple units/models per time step.
    void eval_step();
    /// Evaluate at end of a timestep for tracing, when using eval_step().
    /// Application must call after all eval() and before time changes.
    void eval_end_step() {}
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();

    // INTERNAL METHODS
    void __Vconfigure(Vreceiver__Syms* symsp, bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
