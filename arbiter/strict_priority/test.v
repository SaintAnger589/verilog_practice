module test;
    reg          clk;
    reg          reset_n;
    reg [3:0]    request;
    wire [3:0]   grant;
    reg [3:0]    end_tran;

  initial begin
    clk = 0;
    forever begin
      #10 clk = ~clk;
    end
  end

  initial begin
    $dumpfile("test.vcd");
    $dumpvars(0,test);
    reset_n = 0;
    #10;
    reset_n = 1;
    #10;
    request = 4'b0011;
    #120;
    request = 4'b0010;
    #30;
    request = 4'b0000;
    #513 $finish;
  end

  arbiter arbiter(
    .clk(clk)
    , .reset_n(reset_n)
    , .request(request)
    , .grant(grant)
    , .end_tran(end_tran)
  );

endmodule
