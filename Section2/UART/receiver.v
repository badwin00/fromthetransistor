module receiver(serial, clk, trans);
//inputs
input serial;
input clk;

//outputs
output trans;

//input ports
wire serial; 
wire clk;

//output ports
reg [7:0] trans; //8 bit wide output

//variables
reg hold;
reg [3:0] read_count; //4 bit register to count the 8 data bits
reg receiving;
reg [1:0] stopped; // count stop bits received
reg parity;

initial begin
  $display("receiver is online!");
  hold = 0;
  receiving = 0;
end

always @ (posedge clk) 
begin : RECEIVE
  if(serial == 1 && receiving == 0) begin // check for start bit
    $display("received start bit!");
    receiving <= 1;
  end
  else if (read_count < 8 && receiving == 1) begin // pull data bits
    $display("received data bit %b",serial);
    read_count <= read_count + 1;
  end
  else if (read_count == 8) begin // stop when received 8 data bits
    $display("parity received: %b",serial);
    parity <= serial;
    read_count <= read_count + 1;
  end
  else if (read_count == 9 || read_count == 10) begin
    if (serial == 1) begin
      stopped <= stopped + 1;
      $display("received stop %b",serial);
      if(stopped == 2) begin
        $display("all data successfully read, stopped.");
      end
    end
    else begin
      $display("received incorrect stop signal");
    end
  end
  else begin
    $display("Unable to handle signal");
  end
end
endmodule
