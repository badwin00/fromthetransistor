module blink(clock,counter);
//inputs
input clock;

//outputs
output counter;

//input ports
wire clock;

//output ports
reg [63:0] counter;

//actual code
always @ (posedge clock) // activate on positive edge of clock
begin : BLINKER
  // if enable is active then we increment the counter
  if(counter % 100000000 == 0) begin
    $display("Blink!"); 
  end
  counter <= counter + 1;
end

endmodule
