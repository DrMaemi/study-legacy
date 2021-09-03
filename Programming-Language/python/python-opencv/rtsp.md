# RTSP: Real Time Streaming Protocol, 스트리밍 미디어 서버 제어 프로토콜
[빅라이언의 먹신러닝 - [파이썬/python]: 다후아 IP 카메라 실시간 영상 스트리밍](https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=kyy0810&logNo=221514202767) 블로그를 참조하여 작성하였음.

```python
import cv2

def get_stream():
    cam = 'rtsp://admin:imind123!@192.168.254.200'
    cap = cv2.VideoCapture(cam)
    delay = int(1000/15)

    print("Input 'q' to terminate getting stream")
    while True:
        ret, frame = cap.read()

        cv2.imshow('input stream', frame)

        if cv2.waitKey(delay) & 0xFF == ord('q'):
            break
    
    cap.release()
    cv2.destroyAllWindows
    print("Terminated")

if __name__ == '__main__':
    get_stream()
```