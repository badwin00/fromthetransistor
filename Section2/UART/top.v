`include "receiver.v"
module top(serial,clk,trans,parity);
//input
input serial;
input clk;

//output
output trans;
output parity;

//input port
wire clk;
wire serial; //pretty sure this is 1 bit wide?

//output port
reg [7:0] trans;
reg [0:0] parity;

receiver rec(serial, clk, trans, parity);

initial begin
  $display("Top initiated!");
end

endmodule
