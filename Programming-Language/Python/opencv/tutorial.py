import cv2

def main():
    cap = cv2.VideoCapture('c:/dev/home/data/i-mind_cctv_test2.mp4')

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

    print('Frame width:', width)
    print('Frame height:', height)
    print('Frame count:', count)
    print("Frame current msec:", pos_msec)
    print('Frame FPS:', fps)

    while True:
        ret, frame = cap.read()

        if ret:
            cv2.imshow('input video', frame)
            pos_msec = cap.get(cv2.CAP_PROP_POS_MSEC)
            fn = cap.get(cv2.CAP_PROP_POS_FRAMES)
            print("Frame current msec:", pos_msec, "Frame num:", fn)
            if cv2.waitKey(delay) & 0xFF == ord('q'):
                print("You stopped playing video. Program terminated.")
                break

    cap.release()
    cv2.destroyAllWindows()

if __name__ == '__main__':
    main()
