module rrobin(
        input clk,
        input rst_n,
        input req0,
        input req1,
        input req2,
        input req3,
        input ack,
        output logic [1:0] gnt
  );

    logic [1:0] last_grant;
    logic change_state;
    enum logic [1:0] {
        IDLE=2'b00,
        GNTSTATE = 2'b01,
        WAIT = 2'b10
    } state, next_state;

    assign change_state = |{req0, req1, req2, req3};
    always_comb begin
        case(state)
          IDLE: begin
            //gnt = 2'b00;
            //gnt = 2'b00;
            if (change_state) begin
              next_state = GNTSTATE;
            end else begin
              next_state = IDLE;
            end //else
          end //IDLE
          GNTSTATE: begin
              if(last_grant == 2'b00) begin
                if (req1) begin
                  gnt = 2'b01;
                end else if(req2) begin
                  gnt = 2'b10;
                end else if(req3) begin
                  gnt = 2'b11;
                end else if(req0) begin
                  gnt = 2'b00;
                end
              end //last_grant
              else if(last_grant == 2'b01) begin
                if (req2) begin
                  gnt = 2'b10;
                end else if(req3) begin
                  gnt = 2'b11;
                end else if(req0) begin
                  gnt = 2'b00;
                end else if (req1) begin
                  gnt = 2'b01;
                end
              end //last_grant
              else if(last_grant == 2'b10) begin
                if (req3) begin
                  gnt = 2'b11;
                end else if(req0) begin
                  gnt = 2'b00;
                end else if(req1) begin
                  gnt = 2'b01;
                end else if (req2) begin
                  gnt = 2'b10;
                end
              end //last_grant
              else if(last_grant == 2'b11) begin
                if (req0) begin
                  gnt = 2'b00;
                end else if(req1) begin
                  gnt = 2'b01;
                end else if(req2) begin
                  gnt = 2'b10;
                end else if (req3) begin
                  gnt = 2'b11;
                end
              end //last_grant
              next_state = WAIT;
          end //STATE1
          WAIT: begin
            //wait for ack signal and then go to IDLE
            if (ack) begin
              next_state =IDLE;
            end else begin
              next_state = WAIT;
            end
          end
          default: begin
            next_state = IDLE;
          end
      endcase
    end //always_comb
    always_ff @(posedge clk or negedge rst_n) begin
      if(!rst_n) begin
        last_grant <= 2'b00;
        state <= IDLE;
      end else begin
        state <= next_state;
        last_grant <= gnt;;
      end
    end
endmodule
