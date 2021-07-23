#include <verilated.h>
#include "Vtop.h"

Vtop *top; //top level module

vluint64_t main_time = 0; // current sim time

double sc_time_stamp() { // Called by $time in Verilog
  return main_time;
}

int test(Vtop *top);

int main(int argc, char** argv){
  VerilatedContext* contextp = new VerilatedContext;
  contextp->commandArgs(argc, argv);

  Vtop *top = new Vtop {contextp}; //create instance

  //set inputs
  top->clk = main_time;

  // trigger initial block of top.v
  top->eval();
  top->clk++; 
  test(top);

  top->final(); //done
  delete top;
}

int test(Vtop *top){
  // s = start/stop bits
  // d = data bits
  // p = parity bit
  //             s d d d d d d d d p s s 
  char bits[] = {1,0,1,0,1,0,0,0,1,1,1,1};
  int expected_data = 128;

  int x;
  for(x=0;x<12;x++){
    printf("x: %d given bit: %d\n",x,bits[x]);
    top->clk++;
    top->serial = bits[x];
    top->eval();
  }

  //check for expected values
  //assert(top->trans == expected_data);
  printf("Test 1 complete!\n");
  printf("Data: %u\n",top->trans);
  return 1;
}
