#include "Valu.h"          // Verilog 生成的模块
#include "verilated.h"      // Verilator 头文件
#include "verilated_vcd_c.h" // VCD 头文件

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);

    Valu* top = new Valu;   // 创建仿真实例
    Verilated::traceEverOn(true); // 启用波形跟踪
    VerilatedVcdC* tfp = new VerilatedVcdC; // 创建 VCD 对象
    top->trace(tfp, 99);    // 绑定跟踪器
    tfp->open("wave.vcd");  // 打开 VCD 文件

    // 仿真主循环
    for (int i = 0; i < 100; i++) {
        top->clk = (i % 2);  // 产生时钟信号
        top->eval();         // 计算逻辑
        tfp->dump(i);        // 记录波形
    }

    tfp->close(); // 关闭 VCD 文件
    delete top;
    delete tfp;
    return 0;
}
