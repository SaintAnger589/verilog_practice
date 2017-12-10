module test(output reg clk);
initial begin
	clk = 0;
	forever
		clk = ~clk;
end
endmodule