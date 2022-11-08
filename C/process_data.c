#include "process_data.h"

#include "all.h"
#include "hanning_window.h"
#include "parameters.h"

// [DMA RX and TX Ping-Pong Buffer Definitions]
// SPORT0 DMA Receive Double Buffer, ping + pong
short RxBuffer[2 * H_I + 2 * H_I];
// SPORT0 DMA Transmit Double Buffer, ping + pong
short TxBuffer[2 * H_I + 2 * H_I];
// Ping Pong Buffer Pointers
short* RxPing = RxBuffer;
short* RxPong = RxBuffer + 2 * H_I;
short* TxPing = TxBuffer;
short* TxPong = TxBuffer + 2 * H_I;

// -----

fract16 resampled_buffer[F_A] = {0};
int resampled_buffer_input_position = F_A - H_A;
fract16 stretched_buffer[F_S] = {0};
int stretched_buffer_output_position = F_S - H_S;

void Pass(const fract16 x[], fract16 y[], int n, int step) {
  for (int i = 0; i < n; i++) {
    y[i * step] = x[i * step];
  }
}

void IncreasePitchTwice(const fract16 x[], fract16 y[], int h_i, int step) {
  // 插值重采样
  fract16 resampled_data[H_A] = {0};
  for (int i = 0; i < H_A; i++) {
    float position = (float)i * ALPHA;
    int left = (int)position;
    int right = left + 1;
    float offset = position - (float)left;
    resampled_data[i] =
        (1.0 - offset) * x[step * left] + offset * x[step * right];
  }
  // 拷贝差值重采样的数据
  int resampled_buffer_copy_position = resampled_buffer_input_position;
  for (int i = 0; i < H_A; i++) {
    resampled_buffer[resampled_buffer_copy_position] = resampled_data[i];
    resampled_buffer_copy_position += 1;
    if (resampled_buffer_copy_position == N) {
      resampled_buffer_copy_position = 0;
    }
  }
  resampled_buffer_input_position += H_A;  // 这里需要做循环处理
  if (resampled_buffer_input_position >= F_A) {
    resampled_buffer_input_position -= F_A;
  }
  // 乘窗函数
  int resampled_start_position = resampled_buffer_input_position;
  fract16 dot_production_result[N] = {0};
  for (int i = 0; i < N; i++) {
    int temp = resampled_buffer[resampled_start_position] * w[i];  // 32位
    dot_production_result[i] = (temp + 0x3FFFF) >> 15;             // 16位
    resampled_start_position += 1;
    if (resampled_start_position == N) {
      resampled_start_position = 0;
    }
  }
  // 叠加和输出
  for (int i = 0; i < H_S; i++) {
    // 输出
    y[step * i] = stretched_buffer[stretched_buffer_output_position + i] +
                  dot_production_result[i];
    // 已经输出了所以置零
    stretched_buffer[stretched_buffer_output_position + i] = 0;
  }
  if (stretched_buffer_output_position == 0) {
    stretched_buffer_output_position = H_S;
  } else {
    stretched_buffer_output_position = 0;
  }
  for (int i = 0; i < H_S; i++) {
    // 需要存储给下一次加和的值
    stretched_buffer[stretched_buffer_output_position + i] =
        dot_production_result[H_S + i];
  }
  return;
}

// This function is called for each DMA RX Complete Interrupt,
// or 2*H_I samples for a stereo signal. Then left and
// right channels are separately filtered ping-pong mode.
void Process_Data(void) {
  // Ping-Pong Flag
  static int ping = 0;
  /* core processing in ping-pong mode */
  if (ping == 0) {
    // left and right channels filtering, ping slot
    // Pass(RxPing+0, TxPing+0, H_I, 2);
    // Pass(RxPing+1, TxPing+1, H_I, 2);
    IncreasePitchTwice(RxPing + 0, TxPing + 0, H_I, 2);
    // IncreasePitchTwice(RxPing + 1, TxPing + 1, H_I, 2);
  } else {
    // left and right channels filtering, pong slot
    // Pass(RxPong+0, TxPong+0, H_I, 2);
    // Pass(RxPong+1, TxPong+1, H_I, 2);
    IncreasePitchTwice(RxPong + 0, TxPong + 0, H_I, 2);
    // IncreasePitchTwice(RxPong + 1, TxPong + 1, H_I, 2);
  }
  ping ^= 0x1;
}
