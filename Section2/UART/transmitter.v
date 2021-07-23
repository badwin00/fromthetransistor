`define TX_ENABLE 1
`define TX_DISABLE 0
`define TX_FINISHED 2
`define TX_ERROR -1
module transmitter(clk,data,out,tx_enable);
//inputs
input data;
input clk;
input tx_enable;

//outputs
output out;

//input ports
reg [7:0] data;
wire clk;
reg [1:0] tx_enable;

//output port
wire out;
reg [3:0] data_count;

initial begin
  $display("transmitter is online!");
  data_count = 0;
end

always @ (posedge clk) begin
  if(tx_enable == `TX_ENABLE) begin
    $display("transmitter received: %b",data);
  end
  if(tx_enable == `TX_FINISHED) begin
    $display("transmitting data: %b",out);
  end

end
endmodule
