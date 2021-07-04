#include <verilated.h>
#include "Vblink.h"

Vblink *top; //top level module

vluint8_t main_time = 0; // current sim time

double sc_time_stamp() { // Called by $time in Verilog
  return main_time;
}


int main(int argc, char** argv){
  //Verilated::commandArgs(argc, argv); //remember args
  VerilatedContext* contextp = new VerilatedContext;
  contextp->commandArgs(argc, argv);

  Vblink *top = new Vblink{contextp}; //create instance

  //set inputs
  top->clock = main_time;

  while (!contextp->gotFinish()) {
    top->clock++;
    top->eval();
  }

  //top->final(); //done
  delete top;
}
