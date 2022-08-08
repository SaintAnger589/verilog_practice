module wide2narrow(
    input clk_wide,
    input clk_narrow,
    //input rst_wide_n,
    input rst_narrow_n,
    input [15:0] data_wide,
    output reg [7:0] data_narrow
);

      always @(posedge clk_narrow or negedge rst_narrow_n)
      begin
          if (!rst_narrow_n) begin
              data_narrow <= 8'b0;
          end else begin
              if (clk_wide) begin
                  data_narrow <= data_wide[7:0];
              end else begin
                  data_narrow <= data_wide[15:8];
              end
          end
      end
endmodule
