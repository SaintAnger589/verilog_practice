module afifo
       #(parameter data_width = 8
       	 , parameter address_width = 4
       	 , fifo_depth = (1<<address_width))
       (//reading data
       	output reg [data_width - 1:0] data_out,
       	output reg rempty_flag,
       	input rclk,
       	input read_enable
       	//write data
        input [data_width - 1:0] write_data,
        output reg wfull_flag,
        input write_enable,
        input wclk,

        input reset_in
       	);

    reg [data_width - 1:0] mem [fifo_depth - 1:0];
    wire [address_width - 1:0] pnextWordtoWrite, pnextWordtoRead;
    wire equalAddress;
    wire nextaddressReadEn, nextaddressWriteEn;
    wire set_status, rst_status;
    reg status;
    wire presetFull, presetEmpty;

    always @(posedge rclk) begin
    	if (read_enable && !rempty_flag) begin
    		data_out <= mem[pnextWordtoRead];
    	end
    end

    always @(posedge wclk) begin
    	if(write_enable && !wfull_flag) begin
    		mem[pnextWordtoWrite] <= write_data;
    	end
    end


endmodule