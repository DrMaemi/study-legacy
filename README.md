# git-study
협업 시 반드시 알아야할 깃 사용법

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