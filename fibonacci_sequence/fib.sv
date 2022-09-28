module fib(
  input clk,
  input rst_n,
  output [8:0] fib_seq
  );

  wire [8:0] step2_seq;
  reg [8:0] step1_seq;
  reg [8:0] curr_seq;

  always_ff @ (posedge clk or negedge rst_n) begin
    if (!rst_n) begin
      step1_seq <= 9'b1;
      //step2_seq <= 7'b1;
      curr_seq <= 9'b0;
    end else begin
      //state <= next_state;
      step1_seq <= curr_seq;
      //step2_seq <= step1_seq + curr_seq;
      curr_seq <= step2_seq;
    end
  end
  assign fib_seq = curr_seq;
  assign step2_seq = step1_seq + curr_seq;
endmodule
