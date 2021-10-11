import cv2
from my_aws_client import AWSClient
import io
from PIL import Image, ImageDraw


def main():
    cap = cv2.VideoCapture('../aws-s3/gm-test1.mp4')
    # cap = cv2.VideoCapture('test.mp4')
    aws_client = AWSClient()
    aws_client.start_face_detection()
    aws_client.get_face_detection()

    if cap.isOpened():
        print("Video captured")
    else:
        print("Video is not captured properly. Program terminated.")
        return

    # cv2.VideoCapture.get(propID) -> retval
    # propID:
    # CAP_PROP_FRAME_WIDTH - 프레임 가로 크기
    # CPA_PROP_FRAME_HEIGHT - 프레임 세로 크기
    # CAP_PROP_FPS - 초당 프레임 수
    # CAP_PROP_FRAME_COUNT - 비디오 총 프레임 수
    # CAP_PROP_POS_MSEC - 밀리초 단위 현재 위치
    # CAP_PROP_POS_FRAMES - 현재 프레임 번호
    # CAP_PROP_EXPOSURE - 노출?

    width = cap.get(cv2.CAP_PROP_FRAME_WIDTH)
    height = cap.get(cv2.CAP_PROP_FRAME_HEIGHT)
    count = cap.get(cv2.CAP_PROP_FRAME_COUNT)
    fps = cap.get(cv2.CAP_PROP_FPS)
    pos_msec = cap.get(cv2.CAP_PROP_POS_MSEC)
    delay = int(1000/fps)

    fourcc = cv2.VideoWriter_fourcc(*'mp4v')
    out = cv2.VideoWriter('output.mp4', fourcc, fps, (int(width), int(height)))

    print('Frame width:', width)
    print('Frame height:', height)
    print('Frame count:', count)
    print("Frame current msec:", pos_msec)
    print('Frame FPS:', fps)

    pivot = 0
    prev_faces = []
    quit = False
    end_timestamp = -1

    if 'NextToken' in aws_client.get_face_detection_response:
        end_timestamp = aws_client.get_face_detection_response['Faces'][-1]['Timestamp']
        print(f'end_timestamp: {end_timestamp}')

    while True:
        ret, frame = cap.read()

        if not ret:
            break

        pos_msec = cap.get(cv2.CAP_PROP_POS_MSEC)
        fn = cap.get(cv2.CAP_PROP_POS_FRAMES)
        print("Frame current msec:", round(pos_msec, 1), "Frame num:", int(fn))

        pivot_timestamp = aws_client.get_face_detection_response['Faces'][pivot]['Timestamp']

        if abs(pivot_timestamp-pos_msec) < 10:
            box_sets = []
            emotions = []

            for i, face in enumerate(aws_client.get_face_detection_response['Faces'][pivot:]):
                if pivot_timestamp != aws_client.get_face_detection_response['Faces'][pivot+i]['Timestamp']:
                    pivot += i
                    break

                emotions.append(face['Face']['Emotions'][0])
                box_set = face['Face']['BoundingBox']

                l = int(width * box_set['Left'])
                t = int(height * box_set['Top'])
                r = int((width * box_set['Width']) + l)
                b = int((height * box_set['Height']) + t)

                box_sets.append((l, t, r, b))

            faces = []
            for (l, t, r, b), emotion in list(zip(box_sets, emotions)):
                faces.append({'pos': (l, t, r, b), 'emotion': emotion})
            
            print(f'faces: {faces}')
            prev_faces = faces
            for face in faces:
                l, t, r, b = face['pos']
                emotion = face['emotion']
                cv2.rectangle(frame, (l, t), (r, b), (0, 255, 0), thickness=3)
                cv2.putText(frame, emotion['Type']+' '+str(round(emotion['Confidence'], 1)), (l, t), cv2.FONT_HERSHEY_COMPLEX, 0.5, (255, 255, 0), 1)

            cv2.imshow('output', frame)
            if cv2.waitKey(1) & 0xFF == ord('q'):
                quit = True
                break
        
        if not quit and pivot_timestamp == end_timestamp:
            print('\n\n--- GET NEXT ---')
            aws_client.get_next()
            if 'NextToken' in aws_client.get_face_detection_response:
                end_timestamp = aws_client.get_face_detection_response['Faces'][-1]['Timestamp']
                print(f'end_timestamp: {end_timestamp}')
            pivot = 0

        for face in prev_faces:
            l, t, r, b = face['pos']
            emotion = face['emotion']
            cv2.rectangle(frame, (l, t), (r, b), (0, 255, 0), thickness=2)
            cv2.putText(frame, emotion['Type']+' '+str(round(emotion['Confidence'], 1)), (l, t), cv2.FONT_HERSHEY_COMPLEX, 0.5, (255, 255, 0), 1)

        cv2.imshow('output', frame)
        out.write(frame)
        if cv2.waitKey(delay) & 0xFF == ord('q'):
            break

    cap.release()
    cv2.destroyAllWindows()

if __name__ == '__main__':
    main()