#include <verilated.h>
#include <iostream>
#include "Vhello.h"

Vhello *top; //top level module

vluint64_t main_time = 0; // current sim time

double sc_time_stamp() { // Called by $time in Verilog
  return main_time;
}

int main(int argc, char** argv){
  //Verilated::commandArgs(argc, argv); //remember args
  VerilatedContext* contextp = new VerilatedContext;
  contextp->commandArgs(argc, argv);

  Vhello* top = new Vhello{contextp}; //create instance

  //set inputs

  while (!contextp->gotFinish()) {
    main_time++;
    top->eval();
  }

  //top->final(); //done
  delete top;
}
