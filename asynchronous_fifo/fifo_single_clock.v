`define BUF_WIDTH 3
`define BUF_SIZE (1<<`BUF_WIDTH)

module fifo_single_clock(
    clk,
    rst, 
    wr_en,
    rd_en,
    buf_out,
    buf_in,
    buf_full,
    buf_empty,
    fifo_counter
	);

	input clk;
	input rst;
	input wr_en;
	input rd_en;
	output reg [`BUF_SIZE-1:0] buf_out;
	input  [`BUF_SIZE-1:0] buf_in;
	output reg buf_full;
	output reg buf_empty;
	output reg [`BUF_WIDTH:0] fifo_counter;

	reg [7:0] mem [`BUF_SIZE-1:0];
	//internal signals
	reg [`BUF_WIDTH-1:0] wr_ptr;
	reg [`BUF_WIDTH-1:0] rd_ptr;

always @(fifo_counter) begin
	//buf_full and buf_empty
	buf_full  = (fifo_counter == `BUF_SIZE);
	buf_empty = (fifo_counter == 0);
end
	

	//fifo_counter
	always @(posedge clk or posedge rst) begin
		if (rst) begin
		    fifo_counter <= 0;	
		end else begin
			if ((wr_en && !buf_full) & (rd_en && !buf_empty)) begin
				fifo_counter <= fifo_counter;
			end else if (wr_en && !buf_full) begin
				fifo_counter <= fifo_counter + 1;
			end else if (rd_en && !buf_empty) begin
				fifo_counter <= fifo_counter - 1;
			end else begin
				fifo_counter <= fifo_counter;
			end
		end

	//
		

	end
	//write operation
	always @(posedge clk) begin
		begin
		    if (!buf_full && wr_en) begin
		    	mem[wr_ptr] <= buf_in;
		    end		        
		    else begin
		    	mem[wr_ptr] <= mem[wr_ptr];	
		    	end	
		end
	end

	//read operation
	always @(posedge clk or posedge rst) begin
	    if (rst) begin
	    	buf_out <= 0;
	    end
		if (!buf_empty && rd_en) begin
			buf_out <= mem[rd_ptr];
		end else begin
			buf_out <= buf_out;
		end
	end

	//write pointer 
	always @(posedge clk or posedge rst) begin
		if (rst) begin
			wr_ptr <= 0;
			rd_ptr <= 0;
		end else begin
		    if (wr_en && !buf_full) begin
		    	wr_ptr <= wr_ptr + 1;
		    end else begin
		    	wr_ptr <= wr_ptr;
		    end
			if (rd_en && !buf_empty) begin
				rd_ptr <= rd_ptr + 1;
			end else begin
				rd_ptr <= rd_ptr;
			end
		end
	end
endmodule
