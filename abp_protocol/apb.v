module apb #(datawidth = 32,
addresswidth = 8) (
input clk,
input rst_n,
input [addrwidth-1:0]paddr,
input [datawidth-1:0] pwdata,
input pwrite,
input psel,
input penable,
input pready,
output reg [datawitdth-1:0]prdata
);

reg [datawidth-1:0] mem[256];

reg [1:0] state;
reg [1:0] IDLE   = 0;
reg [1:0] SETUP  = 1;
reg [1:0] WRITE = 2;
reg [1:0] READ = 3;

always @(posedge clk or negedge rst_n) begin
	if(!rst_n) begin
		prdata <= 0;
		state  <= IDLE; 
	end else begin
		case(state)
		  SETUP : begin
		  	if (psel & !penable) begin
		  		if  (pwrite) begin
		  			state <= WRITE;
		  		end else begin
		  			state <= READ;
		  		end
		  	end
		  end
		  WRITE: begin
		  	if (psel & penable & pwrite) begin
		  		mem[paddr] <= pwdata;	
		  	end
		  	if (!pready & psel) begin
		  		state <= SETUP;
		  	end else begin
		  		state <= IDLE;
		  	end
		  	  
		  end
		  READ : begin
		    if (psel & penable & !pwrite) begin
		  		prdata <= mem[paddr];	
		  	end
		  	if (!pready & psel) begin
		  		state <= SETUP;
		  	end else begin
		  		state <= IDLE;
		  	end
		  end
	end

end

endmodule