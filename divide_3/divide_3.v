module divide_3(
                input clk,
                output clk_out
                );
    wire d1, d0;
    reg q0, q1, q2;
    wire q0bar, q1bar;

    initial begin
        //clk_out = 0;
        q0 = 0;
        q1 = 0;
    end
    always @(posedge clk) begin
    	q0 <= d0;

    end

    assign d1 = q0;


    //not(q1bar, q1);
    assign q1bar = ~q1;
    //not(q0bar, q0);
    assign q0bar = ~q0;
    //and(d0,q1bar,q0bar);
    assign d0 = q1bar & q0bar;

    always @(posedge clk) begin
    	q1 <= d1;
    	//clk_out <= cout;
    end

    always @(negedge clk) begin
    	q2 <= q1;

    end
    assign clk_out = q2 | q1;
endmodule
