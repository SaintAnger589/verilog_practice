module divide_4(input clk
                ,output reg clk_out);
    
    reg clk_2 = 0;

    initial begin
        clk_out = 0;
    end
    always @(posedge clk) begin
        clk_2 <= ~clk_2;
    end

    always @(posedge clk_2) begin
        clk_out <= ~clk_out;
    end

endmodule