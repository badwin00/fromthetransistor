module receiver(rx_in,clk,rx_out);

//inputs
input rx_in;
input clk;

//outputs
output rx_out;

//input ports
reg rx_in;
wire clk;

//output ports
reg [7:0] rx_out;

//variables
reg [3:0] rx_count; //keep track of how many bits we've read so far

initial begin
  $display("Receiver online!"); 
  rx_count = 0;
end

always @ (posedge clk) begin
  //catch start bit
  if (rx_in == 1'b1 && rx_count == 0) begin 
    $display("Received start bit!"); 
    rx_count = 0;
  end

  //catch data bits
  else if ( rx_count >= 1 && rx_count < 9) begin
    $display("Received data bit %b",rx_in);
    rx_out [rx_count] = rx_in;
    rx_count += 1;
  end

  //catch end bit
  else if (rx_count == 9 && rx_in == 1) begin
    $display("received end bit! Finally received: %d",rx_out);
    rx_count = -1;
  end

  //error
  else begin
    if(rx_count > 0) begin
      $display("Error receiving data, rx_in: %b",rx_in);
    end
    rx_count = -1;
  end
end

endmodule
