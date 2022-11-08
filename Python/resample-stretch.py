import scipy
import numpy as np

# [超参数]
N = 1024
wav_name = "po-dashu.wav"
wav_input = f"./input/{wav_name}"
print(f"处理帧长")
alpha = 2.0
Hs = N // 2 # synthesis hopsize
Ha = int(Hs / alpha) # analysis hopsize
print(f"alpha {alpha} Ha {Ha} Hs {Hs}")
# [end]

# [准备窗函数]
w = np.zeros((N,), dtype=np.float32)
for i in range(N):
    w[i] = 0.5 * (1 - np.cos((2 * np.pi * i) / (N - 1)))
# [end]

# [重采样]
# input 长度为1024的音频块
# ratio 频率改变的比例 如ratio=2.0会让频率提高一倍
def resample_audio_block(input: np.array, ratio: float = 1.0) -> np.array:
    input_length = len(input)
    assert input_length == N
    output_length = int(float(input_length) / ratio)
    output = np.zeros((output_length,), dtype=np.int32)
    output[0] = input[0]
    for i in range(1, output_length):
        left = int(np.floor(i * ratio))
        offset = float(i * ratio - left)
        right = int(left + 1)
        output[i] = int((1-offset) * input[left] + offset * input[right])
    return output
# [end]

# [读取音频]
audio_sample_rate, audio_data = scipy.io.wavfile.read(wav_input)
audio_sample_num = audio_data.shape[0]
audio_block_num = audio_sample_num//N
audio_length = audio_block_num*N
audio_data = audio_data[0:audio_length, 0] # 只取出第一通道  可能会报错
print(f"音频采样率 {audio_sample_rate}")
print(f"音频长度 {len(audio_data)}采样点 {audio_block_num}x1024 {len(audio_data)/audio_sample_rate}秒")
# [end]

# [重采样]
audio_resampled = np.array([], dtype=np.int32)
for i in range(audio_block_num):
    input = audio_data[i*N:(i+1)*N]
    output = resample_audio_block(input, alpha)
    audio_resampled = np.append(audio_resampled, output)
print(f"重采样后：音频长度 {len(audio_resampled)}采样点 {len(audio_resampled)/audio_sample_rate}秒")
# [end]

# [对重采样之后的音频做拉伸]
audio_input_start = 0
audio_output_start = 0
audio_stretched_frame_num = (len(audio_resampled) - N) // Ha + 1
audio_stretched_length = (audio_stretched_frame_num - 1) * Hs + N
audio_stretched = np.zeros((audio_stretched_length,), dtype=np.int32)
for i in range(audio_stretched_frame_num):
    input = audio_resampled[audio_input_start:(audio_input_start + N)]
    output = input * w
    audio_stretched[audio_output_start:(audio_output_start + N)] += np.array(output, dtype=np.int32)
    audio_input_start += Ha
    audio_output_start += Hs
print(f"拉伸后：音频长度 {len(audio_stretched)}采样点 {len(audio_stretched)/audio_sample_rate}秒")
# [end]

# [写入音频]
wav_output = f"./output/{wav_name}"
scipy.io.wavfile.write(wav_output, audio_sample_rate, audio_stretched)
# [end]
