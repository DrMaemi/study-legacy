# HTML: Hyper Text Markup Language
<p>웹 페이지를 만들기 위한 프로그래밍 언어</p>

<br>

## 이미지
<p>

```html
<div align="center">
  <figure>
      <img src="<파일 경로> or <URL>" alt="<그림 불러오기에 실패했을 경우 대체 설명>" width="200" height="400">
      <div align="center"><figcation>쓰고 싶은 캡션</figcation></div>
  </figure>
</div>
```
- `width`나 `height` 옵션에 200%나 200px와 같이 %, px 단위를 사용하여 설정할 수 있다.
- `width`나 `height` 둘 중 하나만 설정하면, 설정하지 않은 다른 옵션은 설정된 옵션에 기존 이미지 비율을 맞춰 자동 설정된다.
</p>

## 표와 구글 드라이브 이미지 삽입
<p>

코드
```html
<table align='center'>
  <tr>
    <th colspan='2'><div align='center'>성장 일지</div></th>
    <th colspan='2'><div align='center'>생활 기록부</div></th>
  </tr>
  <tr>
    <td>
      <div align="center">
        <figure>
            <img src="https://drive.google.com/uc?export=view&id=1nbLaVoRB_xtGr0GfsO4Bl4HyGAy1q1N8" alt="성장 일지 메인 1">
            <div align="center"><figcation>성장 일지 메인 1</figcation></div>
        </figure>
      </div>
    </td>
    <td>
      <div align="center">
        <figure>
            <img src="https://drive.google.com/uc?export=view&id=1l8xsihDekfLIngvajwV_1REDEdk5NrcW" alt="성장 일지 메인 2">
            <div align="center"><figcation>성장 일지 메인 2</figcation></div>
        </figure>
      </div>
    </td>
    <td>
      <div align="center">
        <figure>
            <img src="https://drive.google.com/uc?export=view&id=1prSDx-ywy3YVNs3RxrMnBwS-Drmcmm2_" alt="생활 기록부 1">
            <div align="center"><figcation>생활 기록부 1</figcation></div>
        </figure>
      </div>
    </td>
    <td>
      <div align="center">
        <figure>
            <img src="https://drive.google.com/uc?export=view&id=1KP60nEdZLzsOoY3FCvkQ5GNGjKJuP7rK" alt="생활 기록부 2">
            <div align="center"><figcation>생활 기록부 2</figcation></div>
        </figure>
      </div>
    </td>
  </tr>
</table>
```
</p>


<p>

결과
<table align='center'>
  <tr>
    <th colspan='2'><div align='center'>성장 일지</div></th>
    <th colspan='2'><div align='center'>생활 기록부</div></th>
  </tr>
  <tr>
    <td>
      <div align="center">
        <figure>
            <img src="https://drive.google.com/uc?export=view&id=1nbLaVoRB_xtGr0GfsO4Bl4HyGAy1q1N8" alt="성장 일지 메인 1">
            <div align="center"><figcation>성장 일지 메인 1</figcation></div>
        </figure>
      </div>
    </td>
    <td>
      <div align="center">
        <figure>
            <img src="https://drive.google.com/uc?export=view&id=1l8xsihDekfLIngvajwV_1REDEdk5NrcW" alt="성장 일지 메인 2">
            <div align="center"><figcation>성장 일지 메인 2</figcation></div>
        </figure>
      </div>
    </td>
    <td>
      <div align="center">
        <figure>
            <img src="https://drive.google.com/uc?export=view&id=1prSDx-ywy3YVNs3RxrMnBwS-Drmcmm2_" alt="생활 기록부 1">
            <div align="center"><figcation>생활 기록부 1</figcation></div>
        </figure>
      </div>
    </td>
    <td>
      <div align="center">
        <figure>
            <img src="https://drive.google.com/uc?export=view&id=1KP60nEdZLzsOoY3FCvkQ5GNGjKJuP7rK" alt="생활 기록부 2">
            <div align="center"><figcation>생활 기록부 2</figcation></div>
        </figure>
      </div>
    </td>
  </tr>
</table>
</p>