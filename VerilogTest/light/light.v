module light(
  input clk,
  input rst,   // 复位信号
  output reg [15:0] led  // 16 位的LED 输出 led
);
  reg[31:0] count; // counter
  always @(posedge clk) begin
    if (rst) 
    begin
      led <= 1; count <= 0; 
    end 
    else  
    begin
      if (count == 0) 
        led <= {led[0:14],led[15]}; // 循环左移
      cout <= (count >= 5000000 ? 32'b0 : count + 1); // 计数与复位
    end
  end
endmodule

