# VS Code
<p>단축키, 원격접속에 대한 내용 작성 예정</p>

<br>

## 목차
<p>

- [터미널](https://github.com/DrMaemi/Study/tree/main/Tools/VS-Code/터미널)
- [C++ 개발환경 구축](#c++-개발환경-구축)
    - [윈도우](#윈도우)
    - [오류들](#오류들)
</p>

<br>

## C++ 개발환경 구축
### 윈도우
<p>

C/C++ 소스를 컴파일할 수 있는 MinGW가 설치되어 있다고 가정한다.<br>
만약 설치되어있지 않다면 [링크](https://github.com/DrMaemi/Study/tree/master/Tools/MinGW) 참조<br>
MinGW가 정상적으로 설치됐다면, VS Code에 연동해야 한다.
</p>
<p>

이후 VS Code에서 워킹 디렉토리 최상위 경로에 `.vscode` 폴더를 생성하고, 내부에 `tasks.json` 파일을 생성하여 다음 코드를 추가한다.
```json
{
    "version": "2.0.0",
    "runner": "terminal",
    "type": "shell",
    "echoCommand": true,
    "presentation": {
        "reveal": "always"
    },
    "tasks": [
        //C++ 컴파일
        {
            "label": "save and compile for C++",
            "command": "g++",
            "args": [
                "${file}",
                "-o",
                "${fileDirname}/${fileBasenameNoExtension}"
            ],
            "group": "build",
            //컴파일시 에러를 편집기에 반영
            //참고:   https://code.visualstudio.com/docs/editor/tasks#_defining-a-problem-matcher
            "problemMatcher": {
                "fileLocation": [
                    "relative",
                    "${workspaceRoot}"
                ],
                "pattern": {
                    // The regular expression. 
                    //Example to match: helloWorld.c:5:3: warning: implicit declaration of function 'prinft'
                    "regexp": "^(.*):(\\d+):(\\d+):\\s+(warning error):\\s+(.*)$",
                    "file": 1,
                    "line": 2,
                    "column": 3,
                    "severity": 4,
                    "message": 5
                }
            }
        },
        //C 컴파일
        {
            "label": "save and compile for C",
            "command": "gcc",
            "args": [
                "${file}",
                "-o",
                "${fileDirname}/${fileBasenameNoExtension}"
            ],
            "group": "build",
            //컴파일시 에러를 편집기에 반영
            //참고:   https://code.visualstudio.com/docs/editor/tasks#_defining-a-problem-matcher
            "problemMatcher": {
                "fileLocation": [
                    "relative",
                    "${workspaceRoot}"
                ],
                "pattern": {
                    // The regular expression. 
                    //Example to match: helloWorld.c:5:3: warning: implicit declaration of function 'prinft'
                    "regexp": "^(.*):(\\d+):(\\d+):\\s+(warning error):\\s+(.*)$",
                    "file": 1,
                    "line": 2,
                    "column": 3,
                    "severity": 4,
                    "message": 5
                }
            }
        },
        // // 바이너리 실행(Windows)
        {
            "label": "execute",
            "command": "",
            "group": "test",
            "args": ["${fileDirname}\\${fileBasenameNoExtension}"]
        }
    ]
}
```
</p>
<p>

`tasks.json` 파일을 작성하게 되면 VS Code에서 .c 혹은 .cpp 파일을 작성한 후 `Ctrl` + `Shift` + `B` 단축키를 통해 컴파일할 수 있다.<br>
이는 VS Code에 해당 단축키가 **C/C++ 컴파일/빌드를 하기 위해서 이미 지정되어 있기 때문**이다.<br>
그러나 **소스코드가 컴파일된 .exe 파일을 실행시키는 단축키는 지정되어 있지 않다**.
</p>

<div align="center">
  <figure>
      <img src="resources/C++ 개발환경 구축/1.  Ctrl + K + S 단축키를 사용하여 Keyboard Shortcuts 세팅 확인.png" alt="1.  Ctrl + K + S 단축키를 사용하여 Keyboard Shortcuts 세팅 확인" width="70%">
      <div align="center"><figcation>1.  Ctrl + K + S 단축키를 사용하여 Keyboard Shortcuts 세팅 확인</figcation></div>
  </figure>
</div>
<br>
<div align="center">
  <figure>
      <img src="resources/C++ 개발환경 구축/2. 소스코드가 컴파일된 .exe 파일을 실행시키는 단축키는 지정되어 있지 않음.png" alt="2. 소스코드가 컴파일된 .exe 파일을 실행시키는 단축키는 지정되어 있지 않음" width="70%">
      <div align="center"><figcation>2. 소스코드가 컴파일된 .exe 파일을 실행시키는 단축키는 지정되어 있지 않음</figcation></div>
  </figure>
</div>
<br>
<div align="center">
  <figure>
      <img src="resources/C++ 개발환경 구축/3. keybindings.json 파일을 열기 위해 우측 상단 아이콘 클릭.png" alt="3. keybindings.json 파일을 열기 위해 우측 상단 아이콘 클릭" width="70%">
      <div align="center"><figcation>3. keybindings.json 파일을 열기 위해 우측 상단 아이콘 클릭</figcation></div>
  </figure>
</div>
<br>

<p>

단축키 설정을 위해 `keybindings.json` 파일 [] 내부에 다음 객체 코드를 추가한다.
```json
// keybindings.json
[
    // 실행
    {
        "key": "ctrl+shift+r",
        "command": "workbench.action.tasks.test"
    }
]
```
`keybindings.json` 파일은 윈도우에서 C:/Users/<유저 이름>/AppData/Roaming/Code/User 경로에 있다.
</p>
<p>

여기까지 설정했다면 `Ctrl` + `Shift` + `B`, `Ctrl` + `Shift` + `R`로 C/C++ 소스코드를 컴파일 및 실행할 수 있다.
</p>
<p>

이 부분도 해줘야 하는지 모르겠는데, Command Pallet에 C/C++ 편집 구성에 관한 설정이 있어서 관련 자료를 올린다.
</p>
<div align="center">
  <figure>
      <img src="resources/C++ 개발환경 구축/4. Command Pallet에서 C C++ 검색.png" alt="4. Command Pallet에서 C C++ 검색" width="70%">
      <div align="center"><figcation>4. Command Pallet에서 C/C++ 검색</figcation></div>
  </figure>
</div>
<br>
<div align="center">
  <figure>
      <img src="resources/C++ 개발환경 구축/5. C, C++ 편집기 구성 설정.png" alt="5. C, C++ 편집기 구성 설정" width="70%">
      <div align="center"><figcation>5. C/C++ 편집기 구성 설정</figcation></div>
  </figure>
</div>
<br>
<p>

위 설정을 끝내면 `.vscode` 폴더 내에 `c_cpp_properties.json` 파일이 생성된다.
</p>

<br>

### 오류들
<p>

윈도우에서 git bash를 VS Code의 기본 터미널로 설정한 경우, C/C++ 컴파일 시 `:\`와 같은 디렉토리 구분자를 인식하지 못해 `No such file or directory` 오류를 만났었다.
</p>
<p>

위 오류를 해결하기 위해선 `tasks.json` 파일 내부에서 `gcc`, `g++` 명령어 인자인 `args`에 파일 및 경로와 관련된 부분을 `''`(작은 따옴표)로 감싸야 한다. 또한 바이너리 실행에 필요한 인자에서 `/C`를 제거한다.
</p>
<p>

예시 - `// 참조`, `// 제거` 주석 유의
```json
{
    "version": "2.0.0",
    ...
    "tasks": [
        {
            "label": "save and compile for C++",
            "command": "g++",
            "args": [
                "'${file}'", // 참조
                "-o",
                "'${fileDirname}/${fileBasenameNoExtension}'" // 참조
            ],
            "group": "build",
            ...
        },
        //C 컴파일
        {
            "label": "save and compile for C",
            "command": "gcc",
            "args": [
                "'${file}'", // 참조
                "-o",
                "'${fileDirname}/${fileBasenameNoExtension}'" // 참조
            ],
            ...
        },
        // // 바이너리 실행(Windows)
        {
            "label": "execute",
            "command": "cmd",
            "group": "test",
            "args": [
                // "/C", // 제거
                "'${fileDirname}\\${fileBasenameNoExtension}'" // 참조
            ]
        }
    ]
}
```
</p>