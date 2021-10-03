# Amazon Rekognition: 이미지 및 비디오 분석
Amazon Rekognition을 사용하면 기계 학습 전문 지식을 사용하지 않고도 확장성이 뛰어난 입증된 딥 러닝 기술을 사용하여 애플리케이션에 이미지 및 비디오 분석을 쉽게 추가할 수 있다.

## 표정 인식 in Python
### 로컬 이미지 분석
```python
import boto3
import time

t1 = time.time()
rekog = boto3.client(
    'rekognition',
    aws_access_key_id='...',
    aws_secret_access_key='...'
)
print(f'Rekog creating time took {round(time.time()-t1, 3)} seconds')

# Local Storage Image
r = None
with open('test.png', 'rb') as f:
    r = f.read()

t1 = time.time()
rekog_r = rekog.detect_faces(Image={'Bytes':r}, Attributes=['ALL'])
print(rekog_r)

print(f'Detecting time took {round(time.time()-t1, 3)} seconds')
```
결과
```
$ python test.py
Rekog creating time took 0.054 seconds
{'FaceDetails': [{'BoundingBox': {'Width': 0.28324559330940247, 'Height': 0.6691710352897644, 'Left': 0.38976117968559265, 'Top': 0.08535095304250717}, 'AgeRange': {'Low': 13, 'High': 23}, 'Smile': {'Value': True, 'Confidence': 99.71626281738281}, 'Eyeglasses': {'Value': False, 'Confidence': 99.94666290283203}, 'Sunglasses': {'Value': False, 'Confidence': 99.99093627929688}, 'Gender': {'Value': 'Female', 'Confidence': 99.90339660644531}, 'Beard': {'Value': False, 'Confidence': 99.87947082519531}, 'Mustache': {'Value': False, 'Confidence': 99.94550323486328}, 'EyesOpen': {'Value': True, 'Confidence': 82.68566131591797}, 'MouthOpen': {'Value': True, 'Confidence': 99.594970703125}, 'Emotions': [{'Type': 'HAPPY', 'Confidence': 99.54827880859375}, {'Type': 'SURPRISED', 'Confidence': 0.12720225751399994}, {'Type': 'FEAR', 'Confidence': 0.08952789008617401}, {'Type': 'ANGRY', 'Confidence': 0.08362798392772675}, {'Type': 'CONFUSED', 'Confidence': 0.04364757612347603}, {'Type': 'SAD', 'Confidence': 0.03830339014530182}, {'Type': 'CALM', 'Confidence': 0.03647952526807785}, {'Type': 'DISGUSTED', 'Confidence': 0.032933223992586136}], 'Landmarks': [{'Type': 'eyeLeft', 'X': 0.4735998511314392, 'Y': 0.3393913209438324}, {'Type': 'eyeRight', 'X': 0.5984683632850647, 'Y': 0.3624095022678375}, {'Type': 'mouthLeft', 'X': 0.4706311821937561, 'Y': 0.5757579207420349}, {'Type': 'mouthRight', 'X': 0.5747393369674683, 'Y': 0.5953665971755981}, {'Type': 'nose', 'X': 0.5197712779045105, 'Y': 0.4670238494873047}, {'Type': 'leftEyeBrowLeft', 'X': 0.4327649176120758, 'Y': 0.2795569598674774}, {'Type': 'leftEyeBrowRight', 'X': 0.4661792814731598, 'Y': 0.2538311183452606}, {'Type': 'leftEyeBrowUp', 'X': 0.5000587105751038, 'Y': 0.2710830569267273}, {'Type': 'rightEyeBrowLeft', 'X': 0.5715507864952087, 'Y': 0.2838767468929291}, {'Type': 'rightEyeBrowRight', 'X': 0.6101117730140686, 'Y': 0.2796991765499115}, {'Type': 'rightEyeBrowUp', 'X': 0.6496879458427429, 'Y': 0.3188996911048889}, {'Type': 'leftEyeLeft', 'X': 0.45242583751678467, 'Y': 0.33528611063957214}, {'Type': 'leftEyeRight', 'X': 0.49798890948295593, 'Y': 0.3460594713687897}, {'Type': 'leftEyeUp', 'X': 0.47330206632614136, 'Y': 0.3269712030887604}, {'Type': 'leftEyeDown', 'X': 0.4733598828315735, 'Y': 0.34970489144325256}, {'Type': 'rightEyeLeft', 'X': 0.5733779072761536, 'Y': 0.3598635494709015}, {'Type': 'rightEyeRight', 'X': 0.6215412616729736, 'Y': 0.36640194058418274}, {'Type': 'rightEyeUp', 'X': 0.5986498594284058, 'Y': 0.3499694764614105}, {'Type': 'rightEyeDown', 'X': 0.5969724655151367, 'Y': 0.3725035488605499}, {'Type': 'noseLeft', 'X': 0.5000292062759399, 'Y': 0.4938635528087616}, {'Type': 'noseRight', 'X': 0.5461732745170593, 'Y': 0.5023452639579773}, {'Type': 'mouthUp', 'X': 0.5192440748214722, 'Y': 0.5530319213867188}, {'Type': 'mouthDown', 'X': 0.5164843201637268, 'Y': 0.6249279975891113}, {'Type': 'leftPupil', 'X': 0.4735998511314392, 'Y': 0.3393913209438324}, {'Type': 'rightPupil', 'X': 0.5984683632850647, 'Y': 0.3624095022678375}, {'Type': 'upperJawlineLeft', 'X': 0.4124746322631836, 'Y': 0.34319859743118286}, {'Type': 'midJawlineLeft', 'X': 0.42251652479171753, 'Y': 0.5998266339302063}, {'Type': 'chinBottom', 'X': 0.5137342810630798, 'Y': 0.7503209114074707}, {'Type': 'midJawlineRight', 'X': 0.6431874632835388, 'Y': 0.6397919654846191}, {'Type': 'upperJawlineRight', 'X': 0.6845797300338745, 'Y': 0.39211127161979675}], 'Pose': {'Roll': 5.050331115722656, 'Yaw': -3.4494879245758057, 'Pitch': 7.668502330780029}, 'Quality': {'Brightness': 89.63139343261719, 'Sharpness': 60.49041748046875}, 'Confidence': 99.99736785888672}], 'ResponseMetadata': {'RequestId': '6dabe337-5e97-4ea1-a794-2e86e03ba29e', 'HTTPStatusCode': 200, 'HTTPHeaders': {'x-amzn-requestid': '6dabe337-5e97-4ea1-a794-2e86e03ba29e', 'content-type': 'application/x-amz-json-1.1', 'content-length': '3350', 'date': 'Sun, 03 Oct 2021 18:58:22 GMT'}, 'RetryAttempts': 0}}
Detecting time took 0.34 seconds
```

### S3 버킷 비디오 분석
Request syntax는 다음과 같다.
```python
# Request Syntax
response = client.start_face_detection(
    Video={
        'S3Object': {
            'Bucket': 'string',
            'Name': 'string',
            'Version': 'string'
        }
    },
    ClientRequestToken='string',
    NotificationChannel={
        'SNSTopicArn': 'string',
        'RoleArn': 'string'
    },
    FaceAttributes='DEFAULT'|'ALL',
    JobTag='string'
)
```