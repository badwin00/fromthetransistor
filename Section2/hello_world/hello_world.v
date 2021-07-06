module hello_world(clock, reset, enable, counter_out);
//inputs
input clock;
input reset;
input enable;
//outputs
output[3:0] counter_out; // 4 bit wide bitvector
//input ports
wire clock;
wire reset;
wire enable;
//output ports
reg[3:0] counter_out;

//actual code
always @ (posedge clock) // activate on positive edge of clock
begin : COUNTER
  //check if reset is active
  if(reset == 1'b1) begin
    counter_out <= 4'b0000;
  end
  // if enable is active then we increment the counter
  else if(enable == 1'b1) begin
    counter_out <= counter_out + 1;
  end
end
endmodule
