import cv2
import numpy as np

BODY_PARTS = { "Head": 0, "Neck": 1, "RShoulder": 2, "RElbow": 3, "RWrist": 4,
                "LShoulder": 5, "LElbow": 6, "LWrist": 7, "RHip": 8, "RKnee": 9,
                "RAnkle": 10, "LHip": 11, "LKnee": 12, "LAnkle": 13, "Chest": 14,
                "Background": 15 }
POSE_PAIRS = [ ["Head", "Neck"], ["Neck", "RShoulder"], ["RShoulder", "RElbow"],
                ["RElbow", "RWrist"], ["Neck", "LShoulder"], ["LShoulder", "LElbow"],
                ["LElbow", "LWrist"], ["Neck", "Chest"], ["Chest", "RHip"], ["RHip", "RKnee"],
                ["RKnee", "RAnkle"], ["Chest", "LHip"], ["LHip", "LKnee"], ["LKnee", "LAnkle"] ]

# 각 파일 path
# protoFile = "./models/pose_deploy.prototxt"
# protoFile = "./models/pose_deploy_linevec.prototxt"
protoFile = "./models/pose_deploy_linevec_faster_4_stages.prototxt"

weightsFile = "./models/pose_iter_160000.caffemodel"
# weightsFile = "./models/pose_iter_584000.caffemodel"
 
# 위의 path에 있는 network 불러오기
net = cv2.dnn.readNetFromCaffe(protoFile, weightsFile)

# 백엔드로 쿠다를 사용하여 속도 향상
# net.setPreferableBackend(cv2.dnn.DNN_BACKEND_CUDA)

# 쿠다 디바이스에 연산 요청
# net.setPreferableTarget(cv2.dnn.DNN_TARGET_CUDA)

# 영상을 가져오기 위해 웹캠과 연결
cap = cv2.VideoCapture(0)

inputHeight = 368
inputWidth = 368
inputScale = 1.0/255
threshold = 0.1

# 아무 키나 누르게 되면 루프가 중지된다
while cv2.waitKey(1) < 0:

    # 웹캠으로부터 영상을 하나 가져온다
    hasFrame, frame = cap.read()

    if not hasFrame:
        cv2.waitKey()
        break

    frameWidth = frame.shape[1]
    frameHeight = frame.shape[0]

    # network에 넣기위해 전처리
    inpBlob = cv2.dnn.blobFromImage(
        frame, # 입력 이미지
        inputScale, # 픽셀값 범위를 0 ~ 1 사이 값으로 정규화. 성능 향상
        (frameWidth, frameHeight), # CNN에서 요구하는 크기로 이미지 크기 조정
        (0, 0, 0), # 입력 영상에서 뺄 mean subtraction 값. 현재는 0으로 설정해서 빼지 않음
        swapRB=False, # OpenCV의 BFR 순서를 RGB로 바꾸기 위해 설정하는 옵션. False로 바꾸지 않음.
        crop=False)
    # inp.shape를 출력하면 (1, 3, 368, 368)

    # blob 영상을 출력. 앞의 mean subtraction 값을 바꾸면 이미지가 변화함
    imgb = cv2.dnn.imagesFromBlob(inpBlob)
    cv2.imshow('inp', (imgb[0]*255.0).astype(np.uin8))

    # network에 넣어주기
    net.setInput(inpBlob)

    # 결과 받아오기
    output = net.forward()

    # 키포인트 검출시 이미지에 그려줌
    points = []

    # output.shape[0] = 이미지 ID, [1] = 출력 맵의 높이, [2] = 너비

    # 모든 관절에 대하여
    for i in range(len(BODY_PARTS)):

        # 해당 신체부위 신뢰도를 얻음
        probMap = output[0, i, :, :]

        # 최대값과 그 위치를 찾음
        minVal, prob, minLoc, point = cv2.minMaxLoc(probMap)

        # 원본 영상에 맞게 좌표 조정
        x = int(frameWidth * point[0]) / output.shape[3]
        y = int(frameHeight * point[1]) / output.shape[2]

        # 키포인트 검출한 결과가 0.1보다 크면(검출한곳이 위 BODY_PARTS랑 맞는 부위면) points에 추가, 검출했는데 부위가 없으면 None으로
        # threshold 값이 커지면 관절이 덜 검출. 오인식 가능성 낮아짐.
        # threshold 값이 낮아지면 관절 검출을 많이 하지만 오인식 가능성 커짐.
        if prob > threshold :
            cv2.circle(frame, (x, y), 3, (0, 255, 255), thickness=-1, lineType=cv2.FILLED)       # circle(그릴곳, 원의 중심, 반지름, 색)
            cv2.putText(frame, "{}".format(i), (x, y), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 0, 255), 1, lineType=cv2.LINE_AA)
            points.append((x, y))
        else :
            points.append(None)

    # 각 POSE_PAIRS별로 선 그어줌 (머리 - 목, 목 - 왼쪽어깨, ...)
    for pair in POSE_PAIRS:
        partA = pair[0]             # Head
        partA = BODY_PARTS[partA]   # 0
        partB = pair[1]             # Neck
        partB = BODY_PARTS[partB]   # 1
        
        #print(partA," 와 ", partB, " 연결\n")
        if points[partA] and points[partB]:
            cv2.line(frame, points[partA], points[partB], (0, 255, 0), 1)

    # 추론하는 데 걸린 시간을 화면에 출력
    t, _ = net.getPerfProfile()
    freq = cv2.getTickFrequenct() / 1000
    cv2.putText(frame, '%2.fms' % (t / freq), (10, 20), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 0, 0))

    cv2.imshow("OpenPose using OpenCV", frame)

# cv2.waitKey(0)
# cv2.destroyAllWindows()