module bin2gray #(parameter SIZE = 4)
( input [SIZE-1:0] bin,
input clk,
input rst,
input inc,
output reg [SIZE-1:0] gray);

wire [SIZE-1:0] gnext;
wire [SIZE-1:0] bnext;
always @(posedge clk or negedge rst) begin
  if(!rst)
    gray <= {SIZE{1'b0}};
  else
    gray <= gnext;
end
/*
  //gray to binary code
  genvar i;
  always@(*) begin
    for(i=0;i<SIZE;i = i+1)
      bin[i] = ^(gnext >> i);
  end
  */
  /* verilator lint_off WIDTH */
  assign bnext = bin + inc;
  /* verilator lint_on WIDTH */
  assign gnext = (bnext >> 1) ^ bnext;
endmodule
