`include "receiver.v"
module top;

reg [0:0] serial;
reg [0:0] trans;

receiver rec(serial,trans);

initial begin
  $display("initial serial: %b",rec.serial);
  serial = 1;
  $display("post serial: %b",rec.serial);
  serial = 1;
  $display("post serial: %b",rec.serial);
  serial = 1;
  $display("post serial: %b",rec.serial);
  serial = 0;
  $display("post serial: %b",rec.serial);
end
endmodule
