module arbiter(
    input             clk,
    input             reset_n,
    input [3:0]       request,
    output reg [3:0]  grant,
    input [3:0]       end_tran
);

    reg [1:0] state;
    reg [1:0] next_state;
    reg [3:0] grant_next;

    parameter IDLE           = 2'b01;
    parameter END_ACCESS     = 2'b10;
    parameter IDLE_ID        = 0;
    parameter END_ACCESS_ID  = 1;

    assign any_request = (request != 4'b0);
    //state transition
    always @(*)
    begin
        next_state = state;
        case(state)
            IDLE:
            begin
                if (any_request) begin
                    next_state = END_ACCESS;
                end else begin
                    next_state = IDLE;
                end
            end
            END_ACCESS:
            begin
                 if (any_request) begin
                     next_state = END_ACCESS;
                 end else begin
                     next_state = IDLE;
                 end
            end
        endcase
    end
    always @(posedge clk or negedge reset_n) begin
      if (!reset_n) begin
         state <= IDLE;
      end else begin
         state <= next_state;
      end
    end

      //grant vector
      always @(*) begin
          grant_next = grant;
          if (any_request) begin
              if (request[0])
                  grant_next = 4'b0001;
              else if (request[1])
                  grant_next = 4'b0010;
              else if (request[2])
                  grant_next = 4'b0100;
              else if (request[3])
                  grant_next = 4'b1000;
          end else begin
              grant_next = 4'b0000;
          end
      end

      always @(posedge clk or negedge reset_n) begin
          if(!reset_n) begin
              grant <= 4'b0000;
          end else begin
              grant <= grant_next;
          end
      end
endmodule
