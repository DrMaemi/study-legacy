import cv2
from monitor import logging_time

@logging_time
def normal():
    print("Running normal()")
    cap = cv2.VideoCapture('./data/i-mind_cctv_test2.mp4')

    width = cap.get(cv2.CAP_PROP_FRAME_WIDTH)
    height = cap.get(cv2.CAP_PROP_FRAME_HEIGHT)
    count = cap.get(cv2.CAP_PROP_FRAME_COUNT)
    fps = cap.get(cv2.CAP_PROP_FPS)
    delay = int(1000/fps)

    while True:
        fn = cap.get(cv2.CAP_PROP_POS_FRAMES) # start from 0

        if fn == 50:
            break

        ret, frame = cap.read()

        if not ret:
            break

        cv2.imshow('input video play', frame)

        if cv2.waitKey(delay) & 0xFF == ord('q'):
            break

    cap.release()
    cv2.destroyAllWindows

@logging_time
def target(start):
    print("Running target()")
    cap = cv2.VideoCapture('./data/i-mind_cctv_test2.mp4')

    count = cap.get(cv2.CAP_PROP_FRAME_COUNT)
    fps = cap.get(cv2.CAP_PROP_FPS)
    delay = int(1000/fps)

    while True:
        fn = cap.get(cv2.CAP_PROP_POS_FRAMES) # start from 0

        if fn == 50:
            break

        ret, frame = cap.read()
        if not ret:
            break

        if start < fn:
            cv2.imshow('input video play', frame)

            if cv2.waitKey(delay) & 0xFF == ord('q'):
                break
        
    cap.release()
    cv2.destroyAllWindows

@logging_time
def skip():
    print("Running skip()")
    cap = cv2.VideoCapture('./data/i-mind_cctv_test2.mp4')

    count = cap.get(cv2.CAP_PROP_FRAME_COUNT)
    fps = cap.get(cv2.CAP_PROP_FPS)
    delay = int(1000/fps)

    print(f"Total frames: {int(count)}")

    while True:
        fn = cap.get(cv2.CAP_PROP_POS_FRAMES) # start from 0

        ret, frame = cap.read()
        if not ret:
            break
        
    cap.release()
    cv2.destroyAllWindows

@logging_time
def intermediate_start(start):
    print("Running intermidiate_start()")
    cap = cv2.VideoCapture('./data/i-mind_cctv_test2.mp4')

    count = cap.get(cv2.CAP_PROP_FRAME_COUNT)
    fps = cap.get(cv2.CAP_PROP_FPS)
    delay = int(1000/fps)

    print(f"Total frames: {int(count)}")

    while True:
        fn = cap.get(cv2.CAP_PROP_POS_FRAMES) # start from 0

        ret, frame = cap.read()
        if not ret:
            break

        if start < fn:
            cv2.imshow('input video play', frame)
            
            if cv2.waitKey(delay) & 0xFF == ord('q'):
                break
        
    cap.release()
    cv2.destroyAllWindows


if __name__ == '__main__':
    normal()
    target(25)
    skip()
    intermediate_start(4000)
    print("Done.")
