// Clock generator stolen from https://electronics.stackexchange.com/questions/13718/implement-serial-port-on-fpga-verilog
// Serial port clock generator
// Generate a 9600 baud clock signal for the serial port by dividing the
// 50Mhz clock by 5208

reg [14:0] clockdiv;

// Count from 0..5207 then reset back to zero
always @(posedge clk) 
begin
    if (clockdiv == 5207) 
        clockdiv <= 0;
    else
        clockdiv <= clockdiv + 1;
end

// The serclock is a short pulse each time we are reset
wire serclock = (clockdiv == 0);

/////////////////////////////////////////////////////////////////////////////
