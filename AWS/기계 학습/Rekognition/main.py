import cv2
from my_aws_client import AWSClient

def main():
    aws_client = AWSClient()
    bucket_name = '...'
    file_key = '...'

    aws_client.start_face_detection(file_key)
    aws_client.get_face_detection()

    cap = aws_client.video_capture(file_key)

    while True:
        ret, frame = cap.read()

        if not ret:
            break

        cv2.imshow('s3 video', frame)

        if cv2.waitKey(int(1000/30)) & 0xFF == ord('q'):
            break

if __name__ == '__main__':
    main()