#include <cstdlib>
#include <iostream>
#include<memory>
// verilator仿真库文件
#include <verilated.h>
// VCD波形库
#include <verilated_vcd_c.h>

// 导入模型类
#include "Valu.h"
// 导入模型中的enum
#include "Valu___024unit.h"

// 终止时间
#define MAX_SIM_TIME 200
// 全局仿真时间
vluint64_t sim_time = 0;

// 记录时钟周期
vluint64_t posedge_cnt = 0;

// 初始化函数
void dut_reset(Valu *dut, vluint64_t &sim_time)
{
    dut->rst = 0;
    if (sim_time >= 3 && sim_time < 6)
    {
        dut->rst = 1;
        dut->a_in = 0;
        dut->b_in = 0;
        dut->op_in = Valu___024unit::nop;
        dut->in_valid = 0;
    }
}

int main(int argc, char **argv, char **env)
{
    // 初始化C++随机数生成器
    srand(time(NULL));
    // 向仿真器传入参数
    Verilated::commandArgs(argc, argv);
    // 初始化电路模型
    Valu *dut = new Valu;

    // 启用波形记录
    Verilated::traceEverOn(true);
    // 创建波形
    VerilatedVcdC *m_trace = new VerilatedVcdC;
    // 指定波形和深度
    dut->trace(m_trace, 5);
    // 打开波形文件
    m_trace->open("waveform.vcd");

    while (sim_time < MAX_SIM_TIME)
    {
        // 初始化
        dut_reset(dut, sim_time);

        // 时钟翻转
        dut->clk ^= 1;
        // 计算波形
        dut->eval();

        // 检测上升沿 0->1
        if (dut->clk == 1)
        {
            // 测试用例延迟，等待初始化结束
            if (sim_time >= 10)
                posedge_cnt++;

            dut->op_in = Valu___024unit::nop;
            dut->in_valid = 0;
            // 输入加法测试用例
            if (posedge_cnt == 2)
            {
                dut->a_in = rand();
                dut->b_in = rand();
                dut->op_in = Valu___024unit::add;
                dut->in_valid = 1;
            }
            // 检查加法结果
            if (posedge_cnt == 4)
            {
                if (dut->out_valid != 1 || dut->out != uint8_t(dut->a_in + dut->b_in))
                    std::cout << "ERROR: add mismatch, "
                              << "input: a=" << int(dut->a_in) << ", "
                              << "b=" << int(dut->b_in) << ", "
                              << "exp: " << int(uint8_t(dut->a_in + dut->b_in)) << ", "
                              << "recv:" << int(dut->out) << ", "
                              << "simtime:" << int(sim_time) << std::endl;
            }
            // 输入减法测试用例
            if (posedge_cnt == 6)
            {
                dut->a_in = rand();
                dut->b_in = rand();
                dut->op_in = Valu___024unit::sub;
                dut->in_valid = 1;
            }
            // 检查减法结果
            if (posedge_cnt == 8)
            {
                if (dut->out_valid != 1 || dut->out != uint8_t(dut->a_in - dut->b_in))
                    std::cout << "ERROR: sub mismatch, "
                              << "input: a=" << int(dut->a_in) << ", "
                              << "b=" << int(dut->b_in) << ", "
                              << "exp: " << int(uint8_t(dut->a_in - dut->b_in)) << ", "
                              << "recv:" << int(dut->out) << ", "
                              << "simtime:" << int(sim_time) << std::endl;

                posedge_cnt = 0;
            }
        }

        // 记录当前时刻波形
        m_trace->dump(sim_time);
        // 全局时钟计时
        sim_time++;
    }

    // 关闭波形文件
    m_trace->close();
    // 释放内存
    delete dut;
    exit(EXIT_SUCCESS);
}
