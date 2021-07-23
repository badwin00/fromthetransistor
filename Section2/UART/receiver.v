`define TX_ENABLE 1
`define TX_DISABLE 0
`define TX_FINISHED 2
`define TX_ERROR -1
module receiver(serial, clk, trans, parity, tx_enable);
//inputs
input serial;
input clk;

//outputs
output trans;
output parity;
output tx_enable;

//input ports
wire serial; 
wire clk;

//output ports
reg [7:0] trans; //8 bit wide output
reg [0:0] parity;
reg [1:0] tx_enable;

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
  parity = 0;
  tx_enable = `TX_DISABLE;
end

always @ (posedge clk) 
begin : RECEIVE
  if(receiving) begin
    //tell the transmitter we're getting data
    tx_enable <= `TX_ENABLE;
    // read all 8 data bits
    if(read_count < 8) begin
      $display("received data bit %b",serial);
      read_count <= read_count + 1;
      trans[write_count] <= serial; // write to output little-endian
      write_count <= write_count + 1;

      //toggle parity bit every time a '1' is received
      if(serial == 1) begin
        parity <= ~parity;
      end
    end

    // after receiving 8 bits, check for valid parity bit
    else if (read_count == 8) begin 
      $display("parity received: %b",serial);
      if(serial != parity) begin
        $display("Incorrect parity bit received! Received: %b | Expected: %b",serial,parity);
        receiving <= 0;
      end
      read_count <= read_count + 1;
    end

    //check for both positive end bits
    else if (read_count == 9 || read_count == 10) begin 
      if (serial == 1) begin
        stopped <= stopped + 1;
        $display("received stop %b",serial);
        if(stopped == 2) begin
          receiving <= 0;
          //tell the transmitter we're done getting data
          tx_enable <= `TX_FINISHED;
          $display("all data successfully read, stopped.");
        end
      end
      //stop signal came back negative
      else begin
        receiving <= 0;
        tx_enable <= `TX_ERROR;
        $display("received incorrect stop signal");
      end
    end
  end

  //check for start bit
  else if(serial == 1) begin
    $display("received start bit!");
    receiving <= 1;
  end
  //something has gone wrong
  else begin
    receiving <= 0;
    tx_enable <= `TX_ERROR;
    $display("Unable to handle signal"); //something has gone horribly wrong
  end
end
endmodule
