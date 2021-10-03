# 드라이브 파일 다운

참조 - [soonbee.log](https://velog.io/@soonbee/구글-드라이브에-있는-파일을-터미널에서-curlwget으로-다운받기)
<br><br>

## 목차
- [1. 파일 ID 가져오기](#1-파일-id-가져오기)
- [2. 일반 용량 다운로드](#2-일반-용량-다운로드)
- [3. 큰 용량 다운로드](#3-큰-용량-다운로드)
- [4. gdown을 이용해 파일 다운로드](#4-gdown을-이용해-파일-다운로드)

<br><br>

## 1. 파일 ID 가져오기
<p>먼저 구글 드라이브에서 다운로드할 파일의 공유 링크를 생성한다.</p>
<p>

```
https://drive.google.com/file/d/<file id>/view?usp=sharing
```
위와 같은 형식으로 생성되며, `<file-id>`에 해당하는 부분이 필요하다.

<div align="center">
  <figure>
      <img src="./resources/1.png" alt="공유 링크 생성">
      <div align="center"><figcation>공유 링크 생성</figcation></div>
  </figure>
</div>

<br>

<div align="center">
  <figure>
      <img src="./resources/2.png" alt="생성된 공유 링크">
      <div align="center"><figcation>생성된 공유 링크</figcation></div>
  </figure>
</div>

</p>

<br><br>

## 2. 일반 용량 다운로드
<p>

아래 코드를 직접 입력해도 좋고 스크립트 파일로 만들어 사용해도 좋다. `file_id` 에서는 공유링크를 통해 알아낸 값을 넣고 `file_name` 에는 다운로드 후 저장될 파일의 이름을 작성한다(구글 드라이브에 저장된 파일의 이름과 동일하지 않아도 된다).
</p>

<p>

예시
```
file_id="1O8XjiTnwHZcsrt4TrflbBUn7J7GHMTyy"
file_name="download.file"
wget "https://drive.google.com/uc?export=download&id=${file_id}" -O ${file_name}
```
</p>


<br><br>

## 3. 큰 용량 다운로드
<p>구글 드라이브에서 종종 용량이 큰 파일을 다운로드하는 경우 바이러스 검사를 진행할 수 없다며 정말로 다운로드 하겠냐고 물어보는 화면이 나오는데, 이 때문에 위의 방법들로는 다운로드가 안된다. 스크립트에 변형이 조금 필요하다.</p>
<p>

예시
```
file_id="1O8XjiTnwHZcsrt4TrflbBUn7J7GHMTyy"
file_name="download.file"
curl -sc /tmp/cookie "https://drive.google.com/uc?export=download&id=${file_id}" > /dev/null
code="$(awk '/_warning_/ {print $NF}' /tmp/cookie)"
curl -Lb /tmp/cookie "https://drive.google.com/uc?export=download&confirm=${code}&id=${file_id}" -o ${file_name}
```
</p>
<p>

좀 더 간단한 형태
`wget --load-cookies /tmp/cookies.txt "https://docs.google.com/uc?export=download&confirm=$(wget --quiet --save-cookies /tmp/cookies.txt --keep-session-cookies --no-check-certificate 'https://docs.google.com/uc?export=download&id=파일ID' -O- | sed -rn 's/.*confirm=([0-9A-Za-z_]+).*/\1\n/p')&id=파일ID" -O 파일명 && rm -rf /tmp/cookies.txt`
</p>
<p>

예시: yolov3-spp.weights 약 240MB 파일 다운
```
wget --load-cookies /tmp/cookies.txt "https://docs.google.com/uc?export=download&confirm=$(wget --quiet --save-cookies /tmp/cookies.txt --keep-session-cookies --no-check-certificate 'https://docs.google.com/uc?export=download&id=1-D-bk-8XuUK4n3Vfv8YU0EdlZsH2y0I8' -O- | sed -rn 's/.*confirm=([0-9A-Za-z_]+).*/\1\n/p')&id=1-D-bk-8XuUK4n3Vfv8YU0EdlZsH2y0I8" -O yolov3-spp.weights && rm -rf /tmp/cookies.txt
```
</p>

<br><br>

## 4. gdown을 이용해 파일 다운로드
<p>

이 방법을 이용하기 위해서는 pip 패키지를 사용할 수 있도록 파이썬이나 아나콘다가 설치되어 있어야 한다.
</p>
<p>

`gdown https://drive.google.com/uc?id=<file_id>` 명령어를 사용해 파일을 다운받는다.
</p>
<p>

예시
```
$ conda activate <virtual env>
$ pip install gdown
...
$ gdown https://drive.google.com/uc?id=1cNCu4d3_YaUIf_z5jekuiY6v5r8y7812
Downloading...
From: https://drive.google.com/uc?id=1cNCu4d3_YaUIf_z5jekuiY6v5r8y7812
To: /home/ubuntu/dev/git-stars/DAN/resnet18_msceleb.pth
182MB [00:07, 24.1MB/s]
```
</p>