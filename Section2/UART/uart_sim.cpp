#include <verilated.h>
#include "Vtop.h"

Vtop *top; //top level module

vluint64_t main_time = 0; // current sim time

double sc_time_stamp() { // Called by $time in Verilog
  return main_time;
}

void test(Vtop *top);

int main(int argc, char** argv){
  //Verilated::commandArgs(argc, argv); //remember args
  VerilatedContext* contextp = new VerilatedContext;
  contextp->commandArgs(argc, argv);

  Vtop *top = new Vtop {contextp}; //create instance

  //set inputs
  top->clk = main_time;
  //test(top);

/*
  while (!contextp->gotFinish()) {
    top->clk++;
    top->serial = 0;
    top->eval();
  }
*/
  //             s d d d d d d d d p s s 
  char bits[] = {1,0,0,1,0,0,1,0,0,0,1,1};

  // trigger initial block of top.v
  top->eval();
  top->clk++; 

  int x;
  for(x=0;x<12;x++){
    printf("x: %d given bit: %d\n",x,bits[x]);
    top->clk++;
    top->serial = bits[x];
    top->eval();
  }

  top->final(); //done
  delete top;
}

/*
void test(Vtop *top){
  vluint8_t test = 1;
  //top->serial = test;
  top->clk++;
  top->eval();
}
*/
