module receiver(serial, clk, trans, parity);
//inputs
input serial;
input clk;

//outputs
output trans;
output parity;


//input ports
wire serial; 
wire clk;

//output ports
reg [7:0] trans; //8 bit wide output
reg [0:0] parity;

//variables
reg hold;
reg [3:0] read_count; //4 bit register to count the 8 data bits
reg receiving;
reg [1:0] stopped; // count stop bits received
reg [2:0] write_count; // number of data bits received and saved

initial begin
  $display("receiver is online!");
  hold = 0;
  receiving = 0;
  write_count = 0;
  parity = 0; // 0 is even 1 is odd
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
    trans[write_count] <= serial;
    write_count <= write_count + 1;

    //toggle parity bit every time a '1' is received
    if(serial == 1) begin
      parity <= ~parity;
    end
  end
  else if (read_count == 8) begin // stop when received 8 data bits
    $display("parity received: %b",serial);
    parity <= serial;
    read_count <= read_count + 1;
  end
  else if (read_count == 9 || read_count == 10) begin //receive both positive start bits
    if (serial == 1) begin
      stopped <= stopped + 1;
      $display("received stop %b",serial);
      if(stopped == 2) begin
        receiving <= 0;
        $display("all data successfully read, stopped.");
      end
    end
    else begin
      receiving <= 0;
      $display("received incorrect stop signal"); //stop signal came back negative
    end
  end
  else begin
    receiving <= 0;
    $display("Unable to handle signal"); //something has gone horribly wrong
  end
end
endmodule
