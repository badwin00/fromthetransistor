module transmitter(clk,data,out);
//inputs
input data;
input clk;

//outputs
output out;

//input ports
reg [7:0] data;
wire clk;

//output port
wire out;

initial begin
  $display("transmitter is online!");
end
always @ (posedge clk) begin
  if(data != 0) begin
    $display("data to transmit: %b",data);
  end
end
endmodule
