# Git
협업 시 반드시 알아야할 깃 사용법
<br><br>

## 목차
<p>

[1. Git 설치](#1-Git-설치)<br>
&nbsp; &nbsp; [1.1. 윈도우](#11-윈도우)<br>
</p>
<p>

[2. 프로젝트 시작](#2-프로젝트-시작)<br>
&nbsp; &nbsp; [2.1. git clone](#21-git-clone)<br>
&nbsp; &nbsp; [2.2. git init](#22-git-init)
</p>
<p>

[3. 저장소](#3-사용법)<br>
&nbsp; &nbsp; [3.1. 저장소 복제](#31-저장소-복제)<br>
&nbsp; &nbsp; [3.2. git remote](#32-git-remote)<br>
&nbsp; &nbsp; &nbsp; &nbsp; [3.2.1. 확인](#321-확인)<br>
&nbsp; &nbsp; &nbsp; &nbsp; [3.2.2. 등록](#322-등록)<br>
&nbsp; &nbsp; &nbsp; &nbsp; [3.2.3. 삭제](#323-삭제)
</p>
<p>

[4. 브랜치](#4-브랜치)<br>
&nbsp; &nbsp; [4.1. 원격 저장소의 브랜치 정보 보기](#41-원격-저장소의-브랜치-정보-보기)<br>
&nbsp; &nbsp; [4.2. 원격 저장소의 브랜치 가져오기](#42-원격-저장소의-브랜치-가져오기)<br>
&nbsp; &nbsp; [4.3. 브랜치 생성](#43-브랜치-생성)<br>
&nbsp; &nbsp; [4.4. 생성한 브랜치로 이동](#44-생성한-브랜치로-이동)<br>
&nbsp; &nbsp; [4.5. 생성한 브랜치를 원격 저장소에 push](#45-생성한-브랜치를-원격-저장소에-push)<br>
&nbsp; &nbsp; [4.6. test 브랜치의 commit을 master 브랜치에 반영](#46-test-브랜치의-commit을-master-브랜치에-반영)
</p>
<p>

[5. 브랜치 심화](#5-브랜치-심화)
</p>
<br><br>


## 1. Git 설치
### 1.1. 윈도우
<p>

[Git 다운로드 링크](https://git-scm.com/downloads)
</p>
<p>

`git --version`으로 버전이 정상적으로 나오면 설치 성공.
</p>
<br><br>

## 2. 프로젝트 시작
### 2.2. git clone
<p>

깃 원격 저장소에 먼저 저장소를 만든 후 `git clone <원격 저장소 url>`을 터미널에 입력해 프로젝트 파일 다운.
</p>

### 2.1. git init
<p>깃 원격 저장소에 먼저 저장소를 만든 후 git clone으로 로컬 개발을 진행하는 것이 아닌, 로컬에서 먼저 프로젝트를 시작한 경우.</p>
<p>

로컬에서 `git init`으로 로컬 저장소 시작.
</p>

<p>

[깃허브](https://github.com)에 접속해서 본인 계정으로 저장소를 만들고, 로컬 작업 디렉토리에서 `git remote add origin [해당 원격 저장소 url]` 커맨드 입력</p>

<p>git add, commit, push</p>
<br><br>

## 3. 저장소
### 3.1. 저장소 복제
<p>

git clone으로 기존 저장소를 받는다.
</p>
<p>다음, 깃 원격 저장소에 새로운 저장소를 생성한다.</p>
<p>clone한 기존 저장소에서 터미널에 다음과 같이 입력한다.</p>
<p>

`git remote set-url origin [새로 생성한 원격 저장소 url]`
</p>

### 3.2. git remote
#### 3.2.1. 확인
`$ git remote`, `$ git remove show`, `$ git remote -v`

#### 3.2.2. 등록
```
$ git remote add <이름> <원격 저장소 url>
```
예시<br>
```
$ git remote add javascript https://github.com/DrMaemi/javascript.git
```

#### 3.2.3. 삭제
```
git remote remove <이름>
```
예시<br>
```
git remote remove javascript
```

## 4. 브랜치
### 4.1. 원격 저장소의 브랜치 정보 보기
```
git remote update
git branch -r
```

### 4.2. 원격 저장소의 브랜치 가져오기
만약 /feature/created-branch 브랜치를 가져오고 싶다면
```
git checkout -t origin/feature/created-branch
```

### 4.3. 브랜치 생성
```
git branch test
```

### 4.4. 생성한 브랜치로 이동
```
git checkout test
```

### 4.5. 생성한 브랜치를 원격 저장소에 push
```
git checkout test
git push
```

### 4.6. test 브랜치의 commit을 master 브랜치에 반영
<p>test 브랜치의 head가 master 브랜치의 head로 병합됨을 의미</p>


```
git checkout test
git add .
git commit -m 'comment'
```
이후 Merge

## 5. 브랜치 심화
### 5.1. A 브랜치의 HEAD를 B 브랜치의 HEAD로 병합(Merge)
```
git checkout A
git merge B
```

#### merge 시 conflict 발생할 때, branch A가 무조건 이기는 방법
```
git checkout A
git merge -s ours master        // -s ours: ours라는 strategy를 사용. ours는 깃에서 제공?
git checkout master
git merge A                     // 기존 master 내용이 branch A의 내용으로 수정된다.
```

#### merge 시 conflict 발생할 때, branch A의 특정 파일 B가 무조건 이기는 방법
```
git checkout A

```

#### 직전 HEAD의 commit 상황으로 로컬 파일들 전부 변경
```
git reset --hard
```

#### 로컬 브랜치 삭제
```
git branch -d local-branch
```

#### 원격 브랜치 삭제
```
git push origin --delete remote-branch
```

#### 삭제한 원격 브랜치가 계속 보인다면
```
git remote show origin      // origin 저장소의 stale한 remote branch들이 보임
git remote update --prune   // delete all stale remote branch
```

## A. 취소와 삭제
## A.1. 깃 최근 commit 취소하기
가장 최근 commit 취소
```
git reset HEAD^
```

가장 최근 commit 3개 취소
```
git reset HEAD~3
```

## A.2. 원격 저장소 파일 삭제
<p>

이미 원격 저장소에 push한 상태라면 로컬 저장소의 파일을 삭제해도 원격에서는 삭제되지 않는다. 이럴 때 `git rm` 명령어를 사용한다.
</p>

<p>

`$ git rm <파일 이름>` - 원격 저장소와 로컬 저장소에 있는 파일을 삭제한다.
</p>
<p>

`$ git rm --cached <파일 이름>` - 원격 저장소의 파일을 삭제한다. 로컬은 삭제되지 않는다.
</p>
<p>

따라서, 원격 저장소에서 node폴더의 하위에 있는 node_modules 폴더를 삭제하고 싶다면<br>
```
$ git rm --cached node/node_modules
```
</p>

#### Subtree
<p>가장 처음, 빈 저장소에서 다른 저장소들을 합하려면 initial commit이 존재해야 한다. 그렇지 않으면 오류 발생.</p>
<p>이후, 다음과 같은 순서로 subtree를 설정한다.</p>

<p>

**1. 원격 저장소의 url을 추가한다.**</p>

```
git remote add <이름> <원격 저장소 url>
```
예시<br>
```
git remote add javascript https://github.com/drmaemi/javascript
```


<p>

**2. subtree 추가**</p>

```
git subtree add --prefix <원하는 폴더> <원격 저장소 이름> <브랜치>
```
예시<br>
```
git subtree add --prefix javascript javascript master
```
주의) <원하는 폴더>는 미리 만들어져있으면 안된다.

<p>

**3. 푸쉬**</p>

```
git push
```

<p>

**3. 연동된 git remote들을 제거, 깃허브에서 하위 저장소들을 전부 삭제한다.**</p>

<br>

##### Subtree 관리
Subtree 관리는 두 가지 방법이 있다.
1. Parent 저장소에서 Child 저장소를 관리. Parent 입장에서 Subtree는 평범한 폴더일 뿐
2. Child 저장소를 직접 관리. 이 경우 git subtree push, git subtree pull 명령어를 사용해야 한다.
   
<br>
Parent 저장소에서 Child 관리

```
git add <child path>
git commit -m '<commit message>'
git push origin <branch>
```
<br>
Child 저장소 직접 관리

```
# push
git subtree push --prefix <child path> <remote name> <child branch>

# pull
git subtree pull --prefix <child path> <remote name> <child branch>
```

<br><br>

#### git log
<p>깃 로그를 깔끔하게 볼 수 있는 명령어</p>
<p>

git log --graph --pretty=oneline --all/
</p>