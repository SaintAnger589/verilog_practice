module narrow2wide (
    input clk_slow,
    input rst_slow,
    input clk_fast,
    input rst_fast,
    input [7:0] data_in,
    output reg [15:0] data_out
);

    reg [7:0] data_int;
    //delay the fast data by 1 clock cycle
    always @(posedge clk_fast or negedge rst_fast) begin
        if (!rst_fast) begin
            data_int <= 8'b0;
        end else begin
            data_int <= data_in;
        end
    end

    //register the slow data on the clock edge slow
    always @(posedge clk_slow or negedge rst_slow) begin
        if (!rst_slow) begin
            data_out <= 16'b0;
        end else begin
            data_out <= {data_in, data_int};
        end
    end


endmodule
