# .gitignore 작성 규칙
## .gitignore 파일이란?
사용자가 원격 저장소에 커밋되길 원치 않는 파일을 제외(무시)하기 위해 작성하는 파일

<br>

## 주로 제외되는 파일
- IDE 도구와 관련된 설정 파일
- 프로그램 빌드 결과물, 로그, 패키지 관련 파일
- 그 외 용량이 지나치게 큰 파일 등 사용자가 제외하길 원하는 파일

커밋 대상에서 제외시킬 파일 종류에 대한 가이드라인을 얻고 싶다면 [Github에서 제시하는 가이드라인](https://github.com/github/gitignore) 참조

<br>

## .gitignore 파일 위치
프로젝트 최상단 폴더에 생성(타 경로에 생성 가능하나 비효율적)

<br>

## 작성 규칙
- 표준 glob 패턴 사용
- `#` - 주석
- `/` - 폴더
- `!` - 무시 해제
<p>사용법에 대한 자세한 예시 아래 참조</p>

<br>

## 예시
```
.
|-- A
|   |-- AA
|   `-- TODO
|       `-- a.txt
|-- B
|   |-- BB
|   |   |-- BBB
|   |   `-- TODO
|   |       `-- bb.txt
|   `-- TODO
|       `-- b.txt
|-- README.md
|-- TODO
|   `-- td.txt
|-- r.txt
`-- .gitignore
```

디렉토리 구조가 위와 같을 때,
```bash
# .gitignore

# 모든 .txt 파일 무시
*.txt

# b.txt 파일은 무시 해제
!b.txt

# '절대 경로' 상의 TODO 폴더 무시
# 즉, 해당 폴더 내 td.txt 파일은 무시되고 r.txt a.txt b.txt bb.txt는 무시되지 않음
/TODO

# '프로젝트 전체 폴더' 중 TODO라는 폴더명을 사용하는 모든 폴더 무시
# 즉, a.txt b.txt bb.txt는 무시되고 r.txt는 무시되지 않음
# **/TODO/ 와 같은 효과
TODO/

# '.gitignore 파일이 위치한' 경로 중 TODO 폴더 바로 밑에 있는 .txt 파일 무시
# TODO/example/td2.txt 가 존재하는 경우 td2.txt 파일은 무시되지 않음
TODO/*.txt

# '.gitignore 파일이 위치한' 경로 중 TODO 폴더 하위 모든 .txt 파일 무시
# TODO 폴더 하위 어떤 폴더에 존재하더라도 .txt 파일 무시
TODO/**/*.txt

# '.gitignore 파일이 위치한' 경로 바로 밑에 있는 TODO 폴더 바로 밑에 있는 .txt 파일 무시
# 즉, a.txt만 무시되고 나머지 .txt 파일들은 무시되지 않음
*/TODO/*.txt

# '프로젝트 전체 폴더' 중 TODO라는 폴더명을 사용하는 모든 폴더 바로 밑에 있는 .txt 파일 무시
# /**/TODO/*.txt 와 같은 효과
**/TODO/*.txt 

# '프로젝트 전체 폴더' 중 TODO라는 폴더명을 사용하는 모든 폴더 하위 모든 .txt 파일 무시
**/TODO/**/*.txt
```

<br>

## 참조
".gitignore 파일 작성 규칙", 알파카친구, 2018년 3월 12일 수정, 2021년 11월 24일 접속, https://shilan.tistory.com/entry/gitignore-파일-작성-규칙