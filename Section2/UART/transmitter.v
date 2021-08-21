module transmitter(clk,tx_in,tx_receiving,tx_transmitting,tx_out);
//inputs
input tx_in;
input clk;
input tx_receiving;
input tx_transmitting;

//outputs
output tx_out;

//input ports
reg [7:0] tx_in;
reg clk;
wire tx_receiving;
wire tx_transmitting;

//output port
reg tx_out;
reg [9:0] tx_out_frame;

//variables
reg [3:0] tx_count; //track how many bits we've transmitted

initial begin
  $display("transmitter is online!");
  tx_out = 0;
end

always @ (posedge clk) begin
  if (tx_receiving == 1) begin
    $display("transmitter received %d",tx_in);
    tx_out_frame [8:1] = tx_in;
    tx_out_frame [0] = 'b1; // set start bit
    tx_out_frame [9] = 'b1; // set end bit
    $display("transmitting %b",tx_out_frame);
  end

  //this controls endianness of sent data
  if(tx_transmitting == 1 && tx_count < 10) begin
    tx_out = tx_out_frame[tx_count];
    tx_count = tx_count + 1;
    $display("transmitting: %b!",tx_out);
  end
end

endmodule
