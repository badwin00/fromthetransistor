#include <verilated.h>
#include "Vhello_world.h"

Vhello_world *top; //top level module

vluint64_t main_time = 0; // current sim time

double sc_time_stamp() { // Called by $time in Verilog
  return main_time;
}

int main(int argc, char** argv){
  //Verilated::commandArgs(argc, argv); //remember args
  VerilatedContext* contextp = new VerilatedContext;
  contextp->commandArgs(argc, argv);

  Vhello_world* top = new Vhello_world{contextp}; //create instance

  //set inputs
  top->reset = 0; 
  top->enable = 0;
  top->clock = main_time;

  while (!contextp->gotFinish()) {
    printf("time: %u\n",top->clock);
    top->clock++;
    top->eval();
  }

  //top->final(); //done
  delete top;
}
