# git-study
협업 시 반드시 알아야할 깃 사용법

#### git init으로 프로젝트 시작하기
<p>깃 원격 저장소에 먼저 저장소를 만든 후 git clone으로 로컬 개발을 진행하는 것이 아닌, 로컬에서 먼저 프로젝트를 시작한 경우.</p>
<p>

로컬에서 `git init`으로 로컬 저장소 시작.</p>

<p>

[깃허브](https://github.com)에 접속해서 본인 계정으로 저장소를 만들고, 로컬 작업 디렉토리에서 `git remote add origin [해당 원격 저장소 url]` 커맨드 입력</p>

<p>git add, commit, push</p>

#### 저장소 복제
<p>

git clone으로 저장소 받고 `git remote set-url origin [새로 생성한 원격 저장소 url]`</p>

#### git remote 삭제
<p>

`git remote` 혹은 `git remote -v`를 터미널에 입력해 먼저 연동된 깃 원격 저장소를 확인한다.</p>

```
$ git remote
javascript
origin
python
```

<p>다음과 같이 저장소 연동을 끊는다.</p>

```
git remote remove <name>
```
예시<br>
```
git remote remove javascript
```

#### 원격 저장소의 브랜치 정보 로컬에서 보기
```
git remote update
git branch -r
```

#### 원격 저장소의 브랜치 가져오기
만약 /feature/created-branch 브랜치를 가져오고 싶다면
```
git checkout -t origin/feature/created-branch
```

#### 브랜치 생성
```
git branch test
```

#### 생성한 branch로 이동
```
git checkout test
```

### 생성한 branch를 원격 저장소에 push
```
git checkout test
git push
```

#### test 브랜치의 commit을 master 브랜치에 반영
<p>test 브랜치의 head가 master 브랜치의 head로 병합됨을 의미</p>


```
git checkout test
git add .
git commit -m 'comment'
```
이후 Merge

#### A 브랜치의 HEAD를 B 브랜치의 HEAD로 병합(Merge)
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

#### 깃 최근 commit 취소하기
가장 최근 commit 취소
```
git reset HEAD^
```

가장 최근 commit 3개 취소
```
git reset HEAD~3
```

#### Subtree
<p>가장 처음, 빈 저장소에서 다른 저장소들을 합하려면 initial commit이 존재해야 한다. 그렇지 않으면 오류 발생.</p>
<p>이후, 다음과 같은 순서로 subtree를 설정한다.</p>

<p>

**1. (필요시)원격 저장소의 url을 추가한다.**</p>

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

**3. (필요시) 연동된 git remote들을 제거, 깃허브에서 하위 저장소들을 전부 삭제한다.**</p>

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