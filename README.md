# Real-time Pitch Adjustment on BF533 DSP

This repository shows my course project in Systems Design based on Digital Signal Processors, 2022-2023, Department of Electronic Engineering by Professor Weibei Dou.

The main idea to adjustment pitch of the audio is to:

1. interpolate and resample the audio
1. split and overlap-add frames using a gap equals $\frac{H_s}{H_a}$

## Python

`Python` codes are used to verify the feasibility of the algorithm, which is not real-time.

### Setup Development Environment

```sh
$ conda create -n audioexp python=3.10 pip
$ conda activate audioexp
$ pip install numpy scipy
```

### Resample and Overlap-add (OLA) 

1. Create a folder `output` in `Python/`.
1. Modify parameters such as `wav_name` and `alpha` in `resample-stretch.py`.
1. Run `python resample-stretch.py`
1. Play audios generated in `Python/output/`.

## C

`C` codes are based on demo project `Talk_Through_533_I2S _FIR_2MAC.rar` provided by Systems Design based on Digital Signal Processors. It aujusts pitch of the input audio in real-time.

### Create the Project

1. Open `IDDE CrossCore®Embedded Studio 2.10.1` and create a new project.
1. Choose `BF533` with `Silicon Revision` `any` selected. Do not add `Startup Code/LDF`.
1. In `Project > properties > C/C++ Build > Settings`: 
    - `CrossCore Blackfin Linker > Processor > Tool Settings > Memory usage`, select `Internal SRAM and external SDRAM`. In 
    - `CrossCore Blackfin Linker > General > Tool Settings`, select `Individually map functions and data items`.
1. Rename `C` folder in this repo to `src` to replace the `scr` folder generate by `IDDE`.
1. Build and debug the project.

## Contribute

Issues and PRs are welcome!

## References

- [A Review of Time-Scale Modification of Music Signals, Jonathan Driedger and Meinard Müller, International Audio Laboratories Erlangen, 91058 Erlangen, Germany](https://www.mdpi.com/2076-3417/6/2/57)
- [变声导论-变声器原理及实现(核心算法实现篇)](https://zhuanlan.zhihu.com/p/110278983) [Dbinary@知乎](https://www.zhihu.com/people/DBinary)
- [变声导论-变声器原理及实现(基音分类与滤波系统实现)](https://zhuanlan.zhihu.com/p/111889443) [Dbinary@知乎](https://www.zhihu.com/people/DBinary)
- 语音变调讲解PPT 潘兴 2022.10.20
- 基于数字信号处理器的系统设计 课程课件 窦维蓓
- 基于数字信号处理器的系统设计 课程设计选题指南 窦维蓓 戴喜增 周斌 余吉 张波 何以凡等
- [SoundLab](https://github.com/matrixcascade/SoundLab)
