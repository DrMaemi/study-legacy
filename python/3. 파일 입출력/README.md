## 파일 입출력

## 목차
<p>

[1. 텍스트 파일 입출력](#1-텍스트-파일-입출력)
</p>
<p>

[2. JSON 파일 입출력](#2-JSON-파일-입출력)<br>
&nbsp; &nbsp; [2.1. 쓰기](#21-쓰기)<br>
&nbsp; &nbsp; [2.2. 읽기](#22-쓰기)<br>
&nbsp; &nbsp; [2.3. 수정](#23-수정)<br>
</p>
<p>

[3. CSV 파일 입출력](#3-csv-파일-입출력)<br>
&nbsp; &nbsp; [3.1. 쓰기](#31-쓰기)<br>
&nbsp; &nbsp; [3.2. 읽기](#32-쓰기)<br>
&nbsp; &nbsp; [3.3. 수정](#33-수정)<br>
&nbsp; &nbsp; [3.A. CSV 파일 인코딩 방식을 UTF-8로 변경](#3a-csv-파일-인코딩-방식을-utf-8로-변경)
</p>

## 1. 텍스트 파일 입출력
<p>작성 중</p>

## 2. JSON 파일 입출력
<p>json 라이브러리를 이용해 .json 파일을 입출력할 수 있다.</p>

### 2.1. 쓰기

<p>

```python
# write-json.py
import json

car_group = {}

k5 = {}
k5['price'] = "5000"
k5['year'] = "2015"
car_group['K5'] = k5

avante = {}
avante['price'] = "3000"
avante['year'] = "2014"
car_group['Avante'] = avante

# json 데이터 저장
with open('write.json', 'w', encoding='utf-8') as f:
    json.dump(car_group, f, indent='  ')

# 저장한 파일 출력
with open('write.json', 'r') as f:
    json_data = json.load(f)
print(json.dumps(json_data, indent='  '))
```
</p>

### 2.2. 읽기
<p>

```python
# read_json.py
import json

with open('data.json', 'r') as f:
    json_data = json.load(f)

print("print(json.dumps(json_data))")
print(json.dumps(json_data))

print("print(json_data)")
print(json_data)

print("print(json.dumps(json_data, indent='  '))")
print(json.dumps(json_data, indent='  '))

k5_price = json_data['K5']['price']
print("print(k5_price)")
print(k5_price)
```
</p>

### 2.3. 수정
<p>

```python
# update-json.py
import json

with open('data.json', 'r') as f:
    data = json.load(f)

print(json.dumps(data, indent='  '))

data_to_add = { "key" : "value" }
data.update(data_to_add)

print(json.dumps(data, indent='  '))
```
</p>

## 3. CSV 파일 입출력
<p>pandas 라이브러리를 이용해 .csv 파일을 입출력할 수 있다.</p>


### 3.1. 쓰기

### 3.2. 읽기
```python
# read_csv.py
import pandas as pd

data = pd.read_csv('./data.csv', encoding='utf-8')
data.describe(include='all')
```

### 3.A. CSV 파일 인코딩 방식을 UTF-8로 변경
<p>공공 데이터 포털(data.go.kr)을 통해서 받거나 간혹 .csv 파일이 UTF-8로 인코딩되어있지 않는 경우 파이썬에서 해당 데이터 이용 시 한글이 깨질 수 있다.</p>
<p>이 경우, 해당 파일을 메모장으로 열어 '다른 이름으로 저장' → 인코딩 방식을 'UTF-8'로 변경 → 파일 이름을 '[파일 이름].csv'로 저장한다.</p>