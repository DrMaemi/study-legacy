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
&nbsp; &nbsp; [4.6. 브랜치 삭제](#46-브랜치-삭제)<br>
&nbsp; &nbsp; [4.7. test 브랜치의 commit을 master 브랜치에 반영](#47-test-브랜치의-commit을-master-브랜치에-반영)
</p>
<p>

[5. 브랜치 심화](#5-브랜치-심화)<br>
&nbsp; &nbsp; [5.1. A 브랜치의 HEAD를 B 브랜치의 HEAD로 병합(Merge)](#51-a-브랜치의-head를-b-브랜치의-head로-병합(merge))<br>
&nbsp; &nbsp; [5.2. Merge 시 conflict 발생할 때, branch A가 무조건 이기는 방법](#52-merge-시-conflict-발생할-때-branch-a가-무조건-이기는-방법)<br>
&nbsp; &nbsp; [5.3. Merge 시 conflict 발생할 때, branch A의 특정 파일 F가 무조건 이기는 방법](#53-merge-시-conflict-발생할-때-branch-a의-특정-파일-f가-무조건-이기는-방법)<br>
&nbsp; &nbsp; [5.4. Default 브랜치 변경](#54-default-브랜치-변경)<br>
</p>
<p>

[6. 취소와 삭제](#6-취소와-삭제)<br>
&nbsp; &nbsp; [6.1. 직전 HEAD의 commit 상황으로 로컬 파일들 전부 변경](#61-직전-HEAD의-commit-상황으로-로컬-파일들-전부-변경)<br>
&nbsp; &nbsp; [6.2. 깃 최근 commit 취소하기](#62-깃-최근-commit-취소하기)<br>
&nbsp; &nbsp; [6.3. 원격 저장소 파일 삭제](#63-원격-저장소-파일-삭제)
</p>
<p>

[7. Subtree](#7-subtree)<br>
&nbsp; &nbsp; [7.1. 사용법](#71-사용법)<br>
&nbsp; &nbsp; [7.2. 관리](#72-관리)
</p>
<p>

[8. git log](#8-git-log)
</p>
<p>

[9. Git Submodule](#9-git-submodule)<br>
&nbsp; &nbsp; [9.1. 시작](#91-시작)<br>
&nbsp; &nbsp; [9.2. 서브모듈을 포함한 프로젝트 Clone](#92-서브모듈을-포함한-프로젝트-clone)<br>
&nbsp; &nbsp; [9.3. 서브모듈을 포함한 프로젝트 작업](#93-서브모듈을-포함한-프로젝트-작업)<br>
&nbsp; &nbsp; [9.4. 서브모듈 위치 변경](#94-서브모듈-위치-변경)<br>
&nbsp; &nbsp; [9.5. 자주 보는 에러](#95-자주-보는-에러)
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

<br>

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

```
git remote set-url origin [새로 생성한 원격 저장소 url]
git push
```
</p>

<br>

### 3.2. git remote
#### 3.2.1. 확인
`$ git remote`, `$ git remove show`, `$ git remote -v`

<br>

#### 3.2.2. 등록
<p>

```
$ git remote add <이름> <원격 저장소 url>
```
</p>
<p>

예시
```
$ git remote add javascript https://github.com/DrMaemi/javascript.git
```
</p>

<br>

#### 3.2.3. 삭제
<p>

```
git remote remove <이름>
```
</p>
<p>

예시
```
git remote remove javascript
```
</p>

<br><br>

## 4. 브랜치
### 4.1. 원격 저장소의 브랜치 정보 보기
```
git remote update
git branch -r
```

<br>

### 4.2. 원격 저장소의 브랜치 가져오기
만약 /feature/created-branch 브랜치를 가져오고 싶다면
```
git checkout -t origin/feature/created-branch
```

<br>

### 4.3. 브랜치 생성
```
git branch test
```

<br>

### 4.4. 생성한 브랜치로 이동
```
git checkout test
```

<br>

### 4.5. 생성한 브랜치를 원격 저장소에 push
```
git checkout test
git push --set-upstream origin test
```

<br>

### 4.6. 브랜치 삭제
<p>

로컬 브랜치 삭제
```
git branch -d local-branch
```
</p>
<p>

원격 브랜치 삭제
```
git push origin --delete remote-branch
```
</p>
<p>

삭제한 원격 브랜치가 계속 보인다면
```
git remote show origin      // origin 저장소의 stale한 remote branch들이 보임
git remote update --prune   // delete all stale remote branch
```
</p>

<br>

### 4.7. test 브랜치의 commit을 master 브랜치에 반영
<p>test 브랜치의 head가 master 브랜치의 head로 병합됨을 의미</p>
<p>

```
git checkout test
git add .
git commit -m 'comment'
```
이후 Merge
</p>

<br><br>

## 5. 브랜치 심화
### 5.1. A 브랜치의 HEAD를 B 브랜치의 HEAD로 병합(Merge)
<p>

```
git checkout A
git merge B
```
</p>

<br><br>

### 5.2. Merge 시 conflict 발생할 때, branch A가 무조건 이기는 방법
<p>

```
git checkout A
git merge -s ours master        // -s ours: ours라는 strategy를 사용. ours는 깃에서 제공?
git checkout master
git merge A                     // 기존 master 내용이 branch A의 내용으로 수정된다.
```
</p>

<br><br>

### 5.3. Merge 시 conflict 발생할 때, branch A의 특정 파일 F가 무조건 이기는 방법
<p>

```
git checkout A
```
작성 중
</p>

<br><br>

### 5.4. Default 브랜치 변경
<p></p>


<br><br>

## 6. 취소와 삭제
### 6.1. 직전 HEAD의 commit 상황으로 로컬 파일들 전부 변경
<p>

```
git reset --hard
```
자세한 설명은 밑의 6.2.에서 참조
</p>

<br>

### 6.2. 깃 최근 commit 취소하기
<p>

가장 최근 commit 취소
```
git reset HEAD^
```
</p>
<p>

가장 최근 commit 3개 취소
```
git reset HEAD~3
```
</p>
<p>

git reset 옵션
- `--soft` - git index 보존(add한 상태, 즉 staged), 로컬 디렉토리 파일 보존
- `--mixed` - 기본 설정. git index 보존x(unstaged 상태), 로컬 디렉토리 파일 보존
- `--hard` - 로컬 디렉토리도 전부 reset. **사용 시 주의 요망**
</p>
<p>

이후 커밋을 되돌린 상태로 원격 저장소에 push하고 싶다면, `-f` 옵션을 주어야 동작한다.
```bash
git push -f origin master
```
</p>

<br>

### 6.3. 원격 저장소 파일 삭제
<p>

이미 원격 저장소에 push한 상태라면 로컬 저장소의 파일을 삭제해도 원격에서는 삭제되지 않는다. 이럴 때 `git rm` 명령어를 사용한다.
</p>

<p>

`git rm <파일 이름>` - 원격 저장소와 로컬 저장소에 있는 파일을 삭제한다.
</p>
<p>

`git rm --cached <파일 이름>` - 원격 저장소의 파일을 삭제한다. 로컬은 삭제되지 않는다.
</p>
<p>

따라서, 원격 저장소에서 node폴더의 하위에 있는 node_modules 폴더를 삭제하고 싶다면
```
git rm --cached node/node_modules
```
</p>

<br><br>

## 7. Subtree
### 7.1. 사용법
<p>가장 처음, 빈 저장소에서 다른 저장소들을 합하려면 initial commit이 존재해야 한다. 그렇지 않으면 오류 발생.</p>
<p>이후, 다음과 같은 순서로 subtree를 설정한다.</p>

<p>

**1. 원격 저장소의 url을 추가한다.**
</p>
<p>

```
git remote add <이름> <원격 저장소 url>
```
</p>
<p>

예시
```
git remote add javascript https://github.com/drmaemi/javascript
```
</p>

<br>

<p>

**2. subtree 추가**
</p>
<p>

```
git subtree add --prefix <원하는 폴더> <원격 저장소 이름> <브랜치>
```
</p>
<p>

예시
```
git subtree add --prefix javascript javascript master
```
주의) <원하는 폴더>는 미리 만들어져있으면 안된다.
</p>

<br>

<p>

**3. 푸쉬**</p>

```
git push
```

<p>

<br>

**4. 연동된 git remote들을 제거, 깃허브에서 하위 저장소들을 전부 삭제한다.**</p>

<br>

### 7.2. 관리
<p>

Subtree 관리는 두 가지 방법이 있다.
</p>
<p>

1. Parent 저장소에서 Child 저장소를 관리. Parent 입장에서 Subtree는 평범한 폴더일 뿐
2. Child 저장소를 직접 관리. 이 경우 git subtree push, git subtree pull 명령어를 사용해야 한다.
</p>
   
<p>

Parent 저장소에서 Child 관리
```
git add <child path>
git commit -m '<commit message>'
git push origin <branch>
```
</p>
<p>

Child 저장소 직접 관리

```
# push
git subtree push --prefix <child path> <remote name> <child branch>

# pull
git subtree pull --prefix <child path> <remote name> <child branch>
```
</p>

<br>

### 7.3. 저장소 분리, 새 저장소에 push
<p>

Catch/<br>
 &nbsp; CatchNet/
 &nbsp; ...
</p>
<p>

```bash
cd <프로젝트 경로>
git subtree split -P <분리하려는 하위 디렉토리> -b <분리할 브랜치 이름>
git checkout <브랜치 이름>
git push --set-upstream origin <분리된 브랜치 이름>
```
</p>
<p>

결과
```bash
$ cd Catch
$ git subtree split -P CatchNet -b splitted
Created branch 'splitted'
d0f57a39ff17385dbbde9834ccec7088ec7bfc60
$ git checkout splitted
Switched to branch 'splitted'
$ git push --set-upstream origin splitted
Username for 'https://github.com': drmaemi
Password for 'https://drmaemi@github.com': 
Enumerating objects: 496, done.
Counting objects: 100% (496/496), done.
Delta compression using up to 16 threads
Compressing objects: 100% (401/401), done.
Writing objects: 100% (496/496), 12.26 MiB | 3.07 MiB/s, done.
Total 496 (delta 86), reused 465 (delta 83)
remote: Resolving deltas: 100% (86/86), done.
remote: 
remote: Create a pull request for 'splitted' on GitHub by visiting:
remote:      https://github.com/DrMaemi/Catch/pull/new/splitted
...
```
</p>
<p>

깃허브 홈페이지에서 README 없이 비어있는 새 저장소를 생성한 후<br>
```bash
git clone <새 저장소 url>
cd <새 저장소>
git remote add <기존 저장소 이름> <기존 저장소 url>
git pull <기존 저장소 이름> <분리된 브랜치 이름>
```
</p>
<p>

결과
```bash
$ git clone https://github.com/DrMaemi/CatchNet.git
Cloning into 'CatchNet'...
warning: You appear to have cloned an empty repository.
$ cd CatchNet
$ git remote add Catch https://github.com/DrMaemi/Catch.git
$ git pull Catch splitted
From https://github.com/DrMaemi/Catch
 * branch            splitted   -> FETCH_HEAD
$ git push origin master
```
이후 기존 저장소에서 해당 디렉토리를 삭제하면 된다.
</p>


<br><br>

## 8. git log
<p>깃 로그를 깔끔하게 볼 수 있는 명령어</p>
<p>

git log --graph --pretty=oneline --all/
</p>

<br><br>

## 9. Git Submodule
<p>

큰 프로젝트를 여러 개의 프로젝트로 나누는 개념이다.
</p>

### 9.1. 시작
<p>

```bash
git submodule add <Git URL> <원하는 이름>
```
예시
```bash
git submodule add https://github.com/chaconinc/DbConnector
```
기본적으로 서브모듈은 프로젝트 저장소의 이름으로 디렉토리를 만든다. 명령의 마지막에 원하는 이름을 넣어 다른 디렉토리 이름으로 서브모듈을 추가할 수 있다.
</p>
<p>

서브모듈을 추가하고 난 후 `git status` 명령을 실행하면 몇 가지 정보를 알 수 있다.
```bash
$ git status
On branch master
Your branch is up-to-date with 'origin/master'.

Changes to be committed:
  (use "git reset HEAD <file>..." to unstage)

    new file:   .gitmodules
    new file:   DbConnector
```
우선 `.gitmodules` 파일이 만들어지는데, 이 파일은 서브디렉토리와 하위 프로젝트 URL의 매핑 정보를 담은 설정 파일이다.
</p>
<p>

이제 하위 프로젝트를 포함한 커밋을 생성하면 아래와 같은 결과를 확인할 수 있다.
```bash
$ git commit -am 'added DbConnector module'
[master fb9093c] added DbConnector module
 2 files changed, 4 insertions(+)
 create mode 100644 .gitmodules
 create mode 160000 DbConnector
```
모드 160000은 Git에 있어 일반적인 파일이나 디렉토리가 아니라 특별하다는 의미이다.
</p>
<p>
끝으로, push한다.
```
$ git push origin master
```
</p>

<br>

### 9.2. 서브모듈을 포함한 프로젝트 Clone
<p>

서브모듈을 포함하는 프로젝트를 clone하면 기본적으로 서브모듈 디렉토리가 빈 디렉토리이다. 완전히 clone하려면 다음 두 가지 중 하나를 수행해야 한다.
1. `git submodule init` + `git submodule update`
2. `git clone --recurse-submodules <Git URL>`
2를 수행하면 1을 수행하는 것과 같다.
</p>

<br>

### 9.3. 서브모듈을 포함한 프로젝트 작업
<p>

우선 서브모듈 코드를 건드리지 않는 것이 정신건강에 좋다. 서브모듈을 최신으로 업데이트 하려면 서브모듈을 업데이트한 후에 프로젝트에서 커밋하는 것이 좋다.
</p>
<p>

서브모듈 업데이트는 다음 두 가지 방식으로 수행할 수 있다.
1. 서브모듈 디렉토리에서 `git pull`
2. 프로젝트에서 `git submodule update --remote <원하는 서브모듈 디렉토리 이름>`
예시
```bash
$ git submodule update --remote DBConnector
remote: Counting objects: 4, done.
remote: Compressing objects: 100% (2/2), done.
remote: Total 4 (delta 2), reused 4 (delta 2)
Unpacking objects: 100% (4/4), done.
From https://github.com/chaconinc/DbConnector
   3f19983..d0354fc  master     -> origin/master
Submodule path 'DbConnector': checked out 'd0354fc054692d3906c85c3af05ddce39a1c0644'
```
</p>
<p>

서브모듈 저장소의 특정 브랜치로 업데이트하고 싶다면 .gitmodules 파일을 다음과 같은 명령어로 수정할 수 있다.
```bash
$ git config -f .gitmodules submodule.DbConnector.branch <원하는 브랜치 이름>
```
</p>

<br>

### 9.4. 서브모듈 위치 변경
<p>

```bash
git mv <서브모듈 이름> ./my-folder1/<서브모듈 이름>
```
결과 `.gitmodules`에서 해당 서브 모듈의 path가 변경됨을 확인할 수 있다.
</p>

<br>

### 9.5. 자주 보는 에러
<p>

```
A git directory for '<서브모듈 이름>' is found locally with remote(s):
  origin        https://github.com/DrMaemi/<서브모듈 이름>.git
If you want to reuse this local git directory instead of cloning again from
  https://github.com/drmaemi/<서브모듈 이름>.git
use the '--force' option. If the local git directory is not the correct repo
or you are unsure what this means choose another name with the '--name' option.
```
위와 같은 에러를 보는 경우는, 모종의 이유로 서브 모듈을 추가했다가 `git reset` 등으로 되돌린 경우에 볼 수 있다.
</p>
<p>

이 때 `.gitmodules`, `.git/modules` 에서 해당 서브 모듈과 관련된 코드를 지워 해결할 수 있다.
</p>