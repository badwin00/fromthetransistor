#include <verilated.h>
#include "Vtop.h"
#include <chrono>
#include <thread>

Vtop *top; //top level module

//vluint64_t main_time = 0; // current sim time

//double sc_time_stamp() { // Called by $time in Verilog
  //return main_time;
//}

int test(Vtop *top);

int main(int argc, char** argv){
  VerilatedContext* contextp = new VerilatedContext;
  contextp->commandArgs(argc, argv);

  Vtop *top = new Vtop {contextp}; //create instance

  //set inputs
  //top->clk = main_time;

  // trigger initial block of top.v
  //top->eval();
  while(1)
    top->eval();
  //top->clk++; 
  test(top);

  top->final(); //done
  delete top;
}

void eval_spin(Vtop *top)

int test(Vtop *top){
  // s = start/stop bits
  // d = data bits
  // p = parity bit
  //             s d d d d d d d d p s s 
  char bits[] = {1,0,1,0,1,0,0,0,1,1,1,1};
  int expected_data = 128;

 top->tx_in = 14;
 std::this_thread::sleep_for(std::chrono::seconds(3));
 top->tx_in = expected_data;
 std::this_thread::sleep_for(std::chrono::seconds(3));
 top->tx_in = 255;
 top->tx_in = 4;

  //check for expected values
  //assert(top->trans == expected_data);
  printf("Test 1 complete!\n");
  printf("Data: %u\n",top->tx_in);
  return 1;
}
