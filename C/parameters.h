#ifndef PARAMETERS_H_
#define PARAMETERS_H_

// [不可变]
#define N 1024 // Hanning窗的长度
// analysis frame
#define F_A 1024 // 需要乘Hanning窗 长度一致
// synthesis frame
#define F_S 1024 // 乘Hanning窗的结果 长度一致
// synthesis hopsize
#define H_S 512 // 一次输出512个点
// input hopsize
#define H_I 512 // 每次输入的间隔 与Hs相等

// [可变]
// 请先确定alpha
#define ALPHA 1.5 // 频率变为原来的多少倍
// 在通过`Ha=Hs/alpha`算出Ha 向下取整
// analysis hopsize
#define H_A 341 // 2倍时为256, 1.5倍时为341

#endif
