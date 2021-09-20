# moviepy: Python을 이용한 비디오 처리 라이브러리

## 비디오에 오디오 합성
```python
import moviepy.editor as mp

video_clip = mp.VideoFileClip('video1.mp4')
audio_clip = mp.AudioFileClip('video2.mp4')

# video2.mp4의 오디오를 video1.mp4에 합성한다.
video_clip.audio = audio_clip

# 결과 저장
video_clip.write_videofile('result.mp4')
```