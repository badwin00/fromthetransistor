`include "receiver.v"
module top(serial,clk,trans);
//input
input serial;
input clk;

//output
output trans;

//input port
wire clk;
reg serial; //pretty sure this is 1 bit wide?

//output port
reg [7:0] trans;

receiver rec(serial, clk, trans);

initial begin
  $display("Top initiated!");
  //serial = 1;
end

/*
always @ (posedge clk) begin
  $display("serial flip!");
  serial = ~serial;
end
*/
endmodule
