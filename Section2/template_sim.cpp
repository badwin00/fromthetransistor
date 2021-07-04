#include <verilated.h>
#include "V<name>.h"

V<name> *top; //top level module

vluint64_t main_time = 0; // current sim time

double sc_time_stamp() { // Called by $time in Verilog
  return main_time;
}

int main(int argc, char** argv){
  //Verilated::commandArgs(argc, argv); //remember args
  VerilatedContext* contextp = new VerilatedContext;
  contextp->commandArgs(argc, argv);

  V<name>* top = new V<name>{contextp}; //create instance

  //set inputs
  top->clock = main_time;

  while (!contextp->gotFinish()) {
    top->eval();
  }

  //top->final(); //done
  delete top;
}
