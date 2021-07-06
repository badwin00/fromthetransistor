module receiver(serial, trans);
//inputs
input serial;

//outputs
output trans;

//input ports
wire [0:0] serial; //since input comes in one bit at a time it can be a wire

//output ports
reg [0:0] trans;

//variables
reg [0:0] hold;
reg [0:0] receiving;

initial begin
  $display("receiver is online!");
  hold = 0;
  receiving = 0;
end

always @ (serial) // activate when receiving serial data
begin : RECEIVE
  $display("received data!");
  if(serial == 0 && receiving == 0) begin
    $display("received start bit!");
  end
  else begin
    hold = serial;
    $display("received data bit %b",hold);
  end  
end
endmodule
