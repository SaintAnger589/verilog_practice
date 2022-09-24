
module half_handshake(
        input clk_trasnmit,
        input clk_receive,
        input reset,
        input [31:0] data_trndom,
        input tready,
        output rack_trndom,
        output [31:0] data_revdom
);

transmit_domain trndom(
    .clk_trasnmit ( ),
    .rst_transmit ( ),
    .data_trndom  ( ),
    .tready       ( ),
    .rack_trndom  ( )
);

receive_domain revdom(
    .clk_receive    ( ),
    .rst_receive    ( ),
    .data_revdom    ( ),
    .tready_trndom  ( ),
    .rack           ( )
);

endmodule
