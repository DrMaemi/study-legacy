import socket
import cv2, imutils
import pickle, struct

def send_stream(sender_socket):
    print("스트림 전송 시작")
    cap = cv2.VideoCapture('c:/dev/home/data/i-mind_cctv_test2.mp4')
    delay = int(1000/15)

    while True:
        ret, frame = cap.read()

        if ret:
            frame = imutils.resize(frame, width=640)
            # 프레임 직렬화, 전송 준비
            data = pickle.dumps(frame)
            # 메세지 길이 측정
            msg_size = struct.pack('L', len(data))
            # 데이터 전송
            sender_socket.sendall(msg_size + data)

            cv2.imshow('sending', frame)
            if cv2.waitKey(delay) & 0xFF == ord('q'):
                cap.release()
                cv2.destroyAllWindows()
                break

if __name__ == '__main__':
    host = '127.0.0.1'
    port = 13177

    sender_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    sender_socket.connect((host, port))
    print("서버 연결 성공")

    send_stream(sender_socket)
    print("송신 종료")
