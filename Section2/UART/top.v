`include "receiver.v"
`include "transmitter.v"
module top(serial,clk,trans,parity,tx_out);
//input
input serial;
input clk;

//output
output trans;
output parity;
output tx_out;

//input port
wire clk;
wire serial; //pretty sure this is 1 bit wide?

//output port
reg [7:0] trans;
reg [0:0] parity;
wire tx_out;

wire tx_final;

receiver rec(serial, clk, trans, parity);
transmitter t(clk,trans,tx_out);

initial begin
  $display("Top initiated!");
end

endmodule
