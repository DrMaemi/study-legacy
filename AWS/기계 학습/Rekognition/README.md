# Amazon Rekognition: 이미지 및 비디오 분석
<p>

[AWS Rekognition API 공식 문서](https://boto3.amazonaws.com/v1/documentation/api/1.9.42/reference/services/rekognition.html)
</p>
<p>

Amazon Rekognition을 사용하면 기계 학습 전문 지식을 사용하지 않고도 확장성이 뛰어난 입증된 딥 러닝 기술을 사용하여 애플리케이션에 이미지 및 비디오 분석을 쉽게 추가할 수 있다.
</p>

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
```python
# test.py
import boto3

S3_ACCESS_KEY_ID = '...'
S3_SECRET_ACCESS_KEY = '...'
bucket_name = 'test.i-mind101.com'
prefix = 'public/test/'
file_name = 'processed.mp4'
obj_key = prefix+file_name

# AWS Rekognition
print('Creating AWS S3, Rekognition Object')
s3 = boto3.resource(
    's3',
    aws_access_key_id=S3_ACCESS_KEY_ID,
    aws_secret_access_key=S3_SECRET_ACCESS_KEY
)

rekog = boto3.client(
    'rekognition',
    aws_access_key_id=S3_ACCESS_KEY_ID,
    aws_secret_access_key=S3_SECRET_ACCESS_KEY
)

bucket = s3.Bucket(name=bucket_name)
obj = bucket.Object(key=obj_key)

print(f'type(obj): {type(obj)}')
print(f"obj.key: {obj.key}")
print(f"obj.get(): {obj.get()}")

# Rekognition Request
start_face_detection_response = rekog.start_face_detection(
    Video={
        'S3Object': {
            'Bucket': bucket_name,
            'Name': obj_key
        }
    },
    ClientRequestToken='1',
    FaceAttributes = 'ALL'
)

print(f'\n\nstart_face_detection_response: {start_face_detection_response}')

get_face_detection_response = rekog.get_face_detection(
    JobId=start_face_detection_response['JobId'],
    MaxResults=123
)

print(f'\n\nget_face_detection_response: {get_face_detection_response}')

```
결과 요약은 아래와 같다. 전체 결과를 보고 싶다면 `get_face_detection_result.txt` 파일 참조
```
$ python test.py
Creating AWS S3, Rekognition
type(obj): <class 'boto3.resources.factory.s3.Object'>
obj.key: public/test/processed.mp4
obj.get():
{
  "ResponseMetadata":{
    "RequestId":"6XN4Z5JX4NKG2RKD",
    "HostId":"rstYxxCTPZ1MsEL5/ip/l+aCuwI8a2kOsUs8T9qVsSXpp5TNm7DTocgREP/61o7dIuJDgC0jYfU=",
    "HTTPStatusCode":200,
    "HTTPHeaders":{
      "x-amz-id-2":"rstYxxCTPZ1MsEL5/ip/l+aCuwI8a2kOsUs8T9qVsSXpp5TNm7DTocgREP/61o7dIuJDgC0jYfU=",
      "x-amz-request-id":"6XN4Z5JX4NKG2RKD",
      "date":"Mon, 04 Oct 2021 13:18:23 GMT",
      "last-modified":"Thu, 30 Sep 2021 03:42:26 GMT",
      "etag":"\"805fd4325b210fb3f119b1492f67c07f\"",
      "accept-ranges":"bytes",
      "content-type":"binary/octet-stream",
      "server":"AmazonS3",
      "content-length":"536810"
    },
    "RetryAttempts":0
  },
  "AcceptRanges":"bytes",
  "LastModified":datetime.datetime(2021,
  9,
  30,
  3,
  42,
  26,
  "tzinfo=tzutc())",
  "ContentLength":536810,
  "ETag":"\"805fd4325b210fb3f119b1492f67c07f\"",
  "ContentType":"binary/octet-stream",
  "Metadata":{},
  "Body":<botocore.response.StreamingBody object at 0x00000164078C1108>
}


start_face_detection_response:
{
  "JobId":"376e40bc4cfa85227aa1cdda037a5f3a67b7bc4ef99f229ee44f75ed8cdd7d1e",
  "ResponseMetadata":{
    "RequestId":"ae0c2e29-8a2e-4e11-ad51-de1c053a7a9d",
    "HTTPStatusCode":200,
    "HTTPHeaders":{
      "x-amzn-requestid":"ae0c2e29-8a2e-4e11-ad51-de1c053a7a9d",
      "content-type":"application/x-amz-json-1.1",
      "content-length":"76",
      "date":"Mon, 04 Oct 2021 13:18:21 GMT"
    },
    "RetryAttempts":0
  }
}


get_face_detection_response:
{
  "JobStatus":"SUCCEEDED",
  "VideoMetadata":{
    "Codec":"mpeg4",
    "DurationMillis":2100,
    "Format":"QuickTime / MOV",
    "FrameRate":30.0,
    "FrameHeight":480,
    "FrameWidth":640,
    "ColorRange":"LIMITED"
  },
  "Faces":[
    {
      "Timestamp":0,
      "Face":{
        "BoundingBox":{
          "Width":0.07185359299182892,
          "Height":0.11709137260913849,
          "Left":0.5844056010246277,
          "Top":0.5287467837333679
        },
        "AgeRange":{
          "Low":8,
          "High":18
        },
        "Smile":{
          "Value":false,
          "Confidence":87.75666046142578
        },
        "Eyeglasses":{
          "Value":false,
          "Confidence":97.33329010009766
        },
        "Sunglasses":{
          "Value":false,
          "Confidence":98.85018157958984
        },
        "Gender":{
          "Value":"Female",
          "Confidence":98.88495635986328
        },
        "Beard":{
          "Value":false,
          "Confidence":97.68183135986328
        },
        "Mustache":{
          "Value":false,
          "Confidence":99.14466094970703
        },
        "EyesOpen":{
          "Value":true,
          "Confidence":97.54438018798828
        },
        "MouthOpen":{
          "Value":false,
          "Confidence":61.58392333984375
        },
        "Emotions":[
          {
            "Type":"FEAR",
            "Confidence":97.35118865966797
          },
          {
            "Type":"SURPRISED",
            "Confidence":0.8967244029045105
          },
          {
            "Type":"SAD",
            "Confidence":0.5359881520271301
          },
          {
            "Type":"CALM",
            "Confidence":0.4084347188472748
          },
          {
            "Type":"DISGUSTED",
            "Confidence":0.26789671182632446
          },
          {
            "Type":"HAPPY",
            "Confidence":0.19481568038463593
          },
          {
            "Type":"CONFUSED",
            "Confidence":0.1820559948682785
          },
          {
            "Type":"ANGRY",
            "Confidence":0.1629035472869873
          }
        ],
        "Landmarks":[
          {
            "Type":"eyeLeft",
            "X":0.6036236882209778,
            "Y":0.5802827477455139
          },
          {
            "Type":"eyeRight",
            "X":0.632908046245575,
            "Y":0.5735681056976318
          },
          {
            "Type":"mouthLeft",
            "X":0.6117229461669922,
            "Y":0.6234184503555298
          },
          {
            "Type":"mouthRight",
            "X":0.6361144781112671,
            "Y":0.6177844405174255
          },
          {
            "Type":"nose",
            "X":0.620803952217102,
            "Y":0.5999025702476501
          },
          {
            "Type":"leftEyeBrowLeft",
            "X":0.5915805101394653,
            "Y":0.5727818608283997
          },
          {
            "Type":"leftEyeBrowRight",
            "X":0.5991716384887695,
            "Y":0.5655567049980164
          },
          {
            "Type":"leftEyeBrowUp",
            "X":0.6078915596008301,
            "Y":0.5658304691314697
          },
          {
            "Type":"rightEyeBrowLeft",
            "X":0.6247039437294006,
            "Y":0.561939001083374
          },
          {
            "Type":"rightEyeBrowRight",
            "X":0.6330289840698242,
            "Y":0.5577481389045715
          },
          {
            "Type":"rightEyeBrowUp",
            "X":0.6425621509552002,
            "Y":0.5610506534576416
          },
          {
            "Type":"leftEyeLeft",
            "X":0.5984152555465698,
            "Y":0.5813177227973938
          },
          {
            "Type":"leftEyeRight",
            "X":0.6094632744789124,
            "Y":0.5793426036834717
          },
          {
            "Type":"leftEyeUp",
            "X":0.6032096743583679,
            "Y":0.5780840516090393
          },
          {
            "Type":"leftEyeDown",
            "X":0.6039889454841614,
            "Y":0.5821545124053955
          },
          {
            "Type":"rightEyeLeft",
            "X":0.6271534562110901,
            "Y":0.5752829909324646
          },
          {
            "Type":"rightEyeRight",
            "X":0.6381293535232544,
            "Y":0.572196900844574
          },
          {
            "Type":"rightEyeUp",
            "X":0.6326306462287903,
            "Y":0.5713222622871399
          },
          {
            "Type":"rightEyeDown",
            "X":0.6330087184906006,
            "Y":0.575486958026886
          },
          {
            "Type":"noseLeft",
            "X":0.61617511510849,
            "Y":0.6059448719024658
          },
          {
            "Type":"noseRight",
            "X":0.6270537972450256,
            "Y":0.6034384369850159
          },
          {
            "Type":"mouthUp",
            "X":0.6229227185249329,
            "Y":0.614971935749054
          },
          {
            "Type":"mouthDown",
            "X":0.6247000098228455,
            "Y":0.6280691027641296
          },
          {
            "Type":"leftPupil",
            "X":0.6036236882209778,
            "Y":0.5802827477455139
          },
          {
            "Type":"rightPupil",
            "X":0.632908046245575,
            "Y":0.5735681056976318
          },
          {
            "Type":"upperJawlineLeft",
            "X":0.5870406031608582,
            "Y":0.5853821635246277
          },
          {
            "Type":"midJawlineLeft",
            "X":0.5990194082260132,
            "Y":0.630674421787262
          },
          {
            "Type":"chinBottom",
            "X":0.6278296709060669,
            "Y":0.6505264043807983
          },
          {
            "Type":"midJawlineRight",
            "X":0.651094913482666,
            "Y":0.6187332272529602
          },
          {
            "Type":"upperJawlineRight",
            "X":0.6511062383651733,
            "Y":0.5706537961959839
          }
        ],
        "Pose":{
          "Roll":-13.049662590026855,
          "Yaw":-6.247223854064941,
          "Pitch":15.38106632232666
        },
        "Quality":{
          "Brightness":96.50359344482422,
          "Sharpness":16.49492073059082
        },
        "Confidence":99.97515106201172
      }
    },
    ...
  ],
  "ResponseMetadata":{
    "RequestId":"6b3b694b-da26-4912-95b8-4110e5c74148",
    "HTTPStatusCode":200,
    "HTTPHeaders":{
      "x-amzn-requestid":"6b3b694b-da26-4912-95b8-4110e5c74148",
      "content-type":"application/x-amz-json-1.1",
      "content-length":"50344",
      "date":"Mon, 04 Oct 2021 13:18:21 GMT"
    },
    "RetryAttempts":0
  }
}
```