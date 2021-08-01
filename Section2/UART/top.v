//`include "receiver.v"
`include "transmitter.v"
module top(tx_in,tx_out);
//input
input tx_in;

//output
output tx_out;

//input port
reg [7:0] tx_in; // transmitter receives parallel data

//output port
wire tx_out;// transmitter outputs 10 bit frame serially [start bit + data bits + stop bit]


//variables
reg clk;

//receiver rec(rx_in, clk, tx_in, parity, tx_enable);
transmitter t(clk,tx_in,tx_out);

initial begin
  $display("Top initiated!");
end

always @ * begin
  clk = ~clk;
end
endmodule
