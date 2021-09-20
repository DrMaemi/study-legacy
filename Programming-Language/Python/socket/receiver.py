import socket
import cv2
import pickle, struct


def get_stream(data, payload_size):
    delay = int(1000/15)

    while True:
        # 프레임 사이즈 측정
        while len(data) < payload_size:
            data += conn.recv(4096)

        packed_msg_size = data[:payload_size]
        data = data[payload_size:]
        msg_size = struct.unpack('L', packed_msg_size)[0]
        # print(f"type(msg_size): {type(msg_size)}") -> tuple
        # print(f"msg_size: {msg_size}") -> (691362,)

        # 메세지 사이즈 기준으로 데이터 구성
        while len(data) < msg_size:
            data += conn.recv(4096)

        frame_data = data[:msg_size]
        data = data[msg_size:]

        # 프레임 로드
        frame = pickle.loads(frame_data)

        # 영상 재생
        cv2.imshow('receiving', frame)
        if cv2.waitKey(delay) & 0xFF == ord('q'):
            print("'q'를 누르셨습니다. 스트리밍 수신 종료")
            cv2.destroyAllWindows()
            break

if __name__ == '__main__':
    host = '127.0.0.1'
    port = 13177

    receiver_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    receiver_socket.bind((host, port))
    receiver_socket.listen(1)

    print("수신부 동작. 연결 대기 중")
    conn, addr = receiver_socket.accept()
    print(f"conn: {conn}, addr: {addr}")
    print("연결 성공")

    data = b''
    payload_size = struct.calcsize('L')

    print("스트리밍 수신 시작")
    get_stream(data, payload_size)

    print("수신 종료")
