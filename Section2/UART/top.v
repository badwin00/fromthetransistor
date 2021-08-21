`include "receiver.v"
`include "transmitter.v"
module top(clk,tx_in,rx_in,tx_receiving,tx_transmitting,tx_out,rx_out);
//input
input tx_in;
input clk;
input tx_receiving;
input tx_transmitting;
input rx_in;

//output
output tx_out;
output rx_out;

//input port
reg [7:0] tx_in; // transmitter receives parallel data
reg clk;
wire tx_receiving;
wire tx_transmitting;

//output port
reg tx_out;// transmitter outputs 10 bit frame serially [start bit + data bits + stop bit]
reg [7:0] rx_out;

//variables
//reg clk;

transmitter t(clk,tx_in,tx_receiving,tx_transmitting,tx_out);
receiver rec(rx_in, clk, rx_out);

initial begin
  $display("Top initiated!");
end

endmodule
