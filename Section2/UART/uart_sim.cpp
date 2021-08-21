#include <verilated.h>
#include "Vtop.h"
#include <chrono>
#include <thread>

Vtop *top; //top level module

vluint64_t main_time = 0; // current sim time

//double sc_time_stamp() { // Called by $time in Verilog
  //return main_time;
//}

void send(int message, Vtop *sender, Vtop *dest);

void clock(Vtop *top);

int main(int argc, char** argv){
  VerilatedContext* contextp = new VerilatedContext;
  contextp->commandArgs(argc, argv);

  Vtop *top = new Vtop {contextp}; //create instance
  Vtop *top2 = new Vtop {contextp}; //create instance
  top->clk = main_time;
  top2->clk = main_time;
  top->tx_receiving = 0;
  top2->tx_receiving = 0;
  top->tx_transmitting = 0;
  top2->tx_transmitting = 0;

  int x = 0;
  /*for(;x<10;x++){
    top->clk++;
    top2->clk++;
    top->eval();
    top2->eval();
  }
  */

  clock(top);
  clock(top2);
  clock(top);
  clock(top2);
  clock(top);
  clock(top2);
  clock(top);
  clock(top2);
  
  x = 0;
  send(15,top,top2);

  top->final(); //done
  delete top;
}

void send(int message, Vtop *sender, Vtop *dest){
  //load the transmitter with the message
  sender->tx_receiving = 1;
  sender->tx_in = message;
  clock(sender);
  clock(dest);
  sender->tx_in = 0;
  sender->tx_receiving = 0;
  clock(sender);
  clock(dest);

  //actually send data
  sender->tx_transmitting = 1;
  int i = 0;
  for(;i<10;i++){ //send the whole packet serially
    dest->rx_in = sender->tx_out;
    clock(sender);
    clock(dest);
  }
  sender->tx_transmitting = 0;
}

void clock(Vtop *top){
  top->clk++;
  top->eval();
}
