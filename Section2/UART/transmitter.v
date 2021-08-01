module transmitter(clk,tx_in,tx_out);
//inputs
input tx_in;
input clk;

//outputs
output tx_out;

//input ports
reg [7:0] tx_in;
reg clk;

//output port
wire tx_out;
reg [9:0] tx_out_frame;

assign tx_out = 1;
initial begin
  $display("transmitter is online!");
end

//always @ (posedge clk) begin
  //tx_out <= 1; // hold high signal when idling
//end

always @ tx_in begin
  $display("tx_in change! %b", tx_in);
  tx_out_frame [8:1] = tx_in;
  $display("transmitting %b",tx_out_frame);
end

endmodule
