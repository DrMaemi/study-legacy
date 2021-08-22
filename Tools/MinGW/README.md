# MinGW: MS 윈도우로 포팅한 GNU 소프트웨어 도구 모음

## 설치
<p>
윈도우 환경에서 C/C++ 컴파일러인 gcc와 g++을 설치하기 위해서는 MinGW라는 프로그램을 설치해야 한다.
</p>
<p>

MinGW는 32비트 버전과 64비트 버전이 따로 있으므로 자신의 시스템 환경에 따라 적절히 설치할 것을 권한다.<br>
</p>

<br>

### 32비트
MinGW 32비트 다운로드 링크 - [https://sourceforge.net/projects/mingw](https://sourceforge.net/projects/mingw)

<div align="center">
  <figure>
      <img src="resources/설치/32비트/1. MinGW 공식 사이트 - 설치 파일 다운로드.png" alt="1. MinGW 공식 사이트 - 설치 파일 다운로드" width="70%">
      <div align="center"><figcation>1. MinGW 공식 사이트 - 설치 파일 다운로드</figcation></div>
  </figure>
</div>
<br>
<div align="center">
  <figure>
      <img src="resources/설치/32비트/2. 설치 파일 - mingw-get-setup.exe 실행.png" alt="2. 설치 파일 - mingw-get-setup.exe 실행" width="60%">
      <div align="center"><figcation>2. 설치 파일 - mingw-get-setup.exe 실행</figcation></div>
  </figure>
</div>
<br>
<div align="center">
  <figure>
      <img src="resources/설치/32비트/3. 설치 진행.png" alt="3. 설치 진행" width="60%">
      <div align="center"><figcation>3. 설치 진행</figcation></div>
  </figure>
</div>
<br>
<div align="center">
  <figure>
      <img src="resources/설치/32비트/4. 설치 항목 선택.png" alt="4. 설치 항목 선택" width="70%">
      <div align="center"><figcation>4. 설치 항목 선택</figcation></div>
  </figure>
</div>
<br>
<div align="center">
  <figure>
      <img src="resources/설치/32비트/5. Installation - Apply Changes로 설치 진행.png" alt="5. Installation - Apply Changes로 설치 진행" width="70%">
      <div align="center"><figcation>5. Installation - Apply Changes로 설치 진행</figcation></div>
  </figure>
</div>
<br>
<div align="center">
  <figure>
      <img src="resources/설치/32비트/6. Apply - 설치 진행.png" alt="6. Apply - 설치 진행" width="50%">
      <div align="center"><figcation>6. Apply - 설치 진행</figcation></div>
  </figure>
</div>
<br>
<div align="center">
  <figure>
      <img src="resources/설치/32비트/7. 시스템 변수 - Path 편집.png" alt="7. 시스템 변수 - Path 편집" width="50%">
      <div align="center"><figcation>7. 시스템 변수 - Path 편집</figcation></div>
  </figure>
</div>
<br>
<div align="center">
  <figure>
      <img src="resources/설치/32비트/8. 시스템 변수 MinGW 경로 설정.png" alt="8. 시스템 변수 MinGW 경로 설정" width="50%">
      <div align="center"><figcation>8. 시스템 변수 MinGW 경로 설정</figcation></div>
  </figure>
</div>

<br>

### 64비트
MinGW 64비트 다운로드 링크 - [https://sourceforge.net/projects/mingw-w64](https://sourceforge.net/projects/mingw-w64)

<div align="center">
  <figure>
      <img src="resources/설치/64비트/1. Download 클릭 시 5초 뒤 mingw-w64-install.exe 파일 다운 시작.png" alt="1. Download 클릭 시 5초 뒤 mingw-w64-install.exe 파일 다운 시작" width="70%">
      <div align="center"><figcation>1. Download 클릭 시 5초 뒤 mingw-w64-install.exe 파일 다운 시작</figcation></div>
  </figure>
</div>
<br>
<div align="center">
  <figure>
      <img src="resources/설치/64비트/2. .exe 파일 실행 후 그림과 같이 설정.png" alt="2. .exe 파일 실행 후 그림과 같이 설정" width="50%">
      <div align="center"><figcation>2. .exe 파일 실행 후 그림과 같이 설정</figcation></div>
  </figure>
</div>
<br>
<div align="center">
  <figure>
      <img src="resources/설치/64비트/3. 하지만 설치 시도 시 그림과 같은 오류를 계속 반환.png" alt="3. 하지만 설치 시도 시 그림과 같은 오류를 계속 반환" width="50%">
      <div align="center"><figcation>3. 하지만 설치 시도 시 그림과 같은 오류를 계속 반환...</figcation></div>
  </figure>
</div>
<br>
<p>

필자처럼 설치 중 위와 같은 오류를 만나게 된다면, 완전한 라이브러리 파일을 다운받아야 한다.<br>
</p>
<p>

MinGW 64비트 라이브러리 압축 파일 다운로드 링크 -<br>
[https://sourceforge.net/projects/mingw-w64/files/mingw-w64](https://sourceforge.net/projects/mingw-w64/files/mingw-w64)
</p>
<div align="center">
  <figure>
      <img src="resources/설치/64비트/4. 완전한 라이브러리가 압축된 .7z 파일 다운로드.png" alt="4. 완전한 라이브러리가 압축된 .7z 파일 다운로드" width="70%">
      <div align="center"><figcation>4. 완전한 라이브러리가 압축된 .7z 파일 다운로드</figcation></div>
  </figure>
</div>
<p>

[2021-08-23] 위 .7z 파일을 다운받고 압축 해제한 후 `mingw64` 폴더 내 파일들을 .zip 파일로 압축하여 구글 드라이브에 공유하였다.<br>[라이브러리 .zip 압축 파일 링크(Google Drive)](https://drive.google.com/file/d/1fPPXazezLQKp9OTF6UMf23TJyv5EByob/view?usp=sharing)
</p>

<p>

.7z 파일을 다운받았다면 압축 해제한 후 `mingw64` 폴더만을, .zip 파일을 다운받았다면 압축 해제한 후 폴더 그대로 자신이 원하는 경로에 두면 된다.
</p>
<div align="center">
  <figure>
      <img src="resources/설치/64비트/5. 환경 변수 설정.png" alt="5. 환경 변수 설정" width="70%">
      <div align="center"><figcation>5. 환경 변수 설정</figcation></div>
  </figure>
</div>
<br>

<br>

### 설치 확인
<p>

이후, 설치가 정상적으로 됐는지 다음과 같이 확인한다.
```
$ gcc -v
Using built-in specs.
COLLECT_GCC=C:\dev\mingw64\bin\gcc.exe
COLLECT_LTO_WRAPPER=C:/dev/mingw64/bin/../libexec/gcc/x86_64-w64-mingw32/8.1.0/lto-wrapper.exe
Target: x86_64-w64-mingw32
Configured with: ../../../src/gcc-8.1.0/configure --host=x86_64-w64-mingw32 --build=x86_64-w64-mingw32 --target=x86_64-w64-mingw32 --prefix=/mingw64 --with-sysroot=/c/mingw810/x86_64-810-posix-seh-rt_v6-rev0/mingw64 --enable-shared --enable-static --disable-multilib --enable-languages=c,c++,fortran,lto --enable-libstdcxx-time=yes --enable-threads=posix --enable-libgomp --enable-libatomic --enable-lto --enable-graphite --enable-checking=release --enable-fully-dynamic-string --enable-version-specific-runtime-libs --disable-libstdcxx-pch --disable-libstdcxx-debug --enable-bootstrap --disable-rpath --disable-win32-registry --disable-nls --disable-werror --disable-symvers --with-gnu-as --with-gnu-ld --with-arch=nocona --with-tune=core2 --with-libiconv --with-system-zlib --with-gmp=/c/mingw810/prerequisites/x86_64-w64-mingw32-static --with-mpfr=/c/mingw810/prerequisites/x86_64-w64-mingw32-static --with-mpc=/c/mingw810/prerequisites/x86_64-w64-mingw32-static --with-isl=/c/mingw810/prerequisites/x86_64-w64-mingw32-static --with-pkgversion='x86_64-posix-seh-rev0, Built by MinGW-W64 project' --with-bugurl=https://sourceforge.net/projects/mingw-w64 CFLAGS='-O2 -pipe -fno-ident -I/c/mingw810/x86_64-810-posix-seh-rt_v6-rev0/mingw64/opt/include -I/c/mingw810/prerequisites/x86_64-zlib-static/include -I/c/mingw810/prerequisites/x86_64-w64-mingw32-static/include' CXXFLAGS='-O2 -pipe -fno-ident -I/c/mingw810/x86_64-810-posix-seh-rt_v6-rev0/mingw64/opt/include -I/c/mingw810/prerequisites/x86_64-zlib-static/include -I/c/mingw810/prerequisites/x86_64-w64-mingw32-static/include' CPPFLAGS=' -I/c/mingw810/x86_64-810-posix-seh-rt_v6-rev0/mingw64/opt/include -I/c/mingw810/prerequisites/x86_64-zlib-static/include -I/c/mingw810/prerequisites/x86_64-w64-mingw32-static/include' LDFLAGS='-pipe -fno-ident -L/c/mingw810/x86_64-810-posix-seh-rt_v6-rev0/mingw64/opt/lib -L/c/mingw810/prerequisites/x86_64-zlib-static/lib -L/c/mingw810/prerequisites/x86_64-w64-mingw32-static/lib '
Thread model: posix
gcc version 8.1.0 (x86_64-posix-seh-rev0, Built by MinGW-W64 project)
```
```
$ g++ -v
Using built-in specs.
COLLECT_GCC=C:\dev\mingw64\bin\g++.exe
COLLECT_LTO_WRAPPER=C:/dev/mingw64/bin/../libexec/gcc/x86_64-w64-mingw32/8.1.0/lto-wrapper.exe
Target: x86_64-w64-mingw32
Configured with: ../../../src/gcc-8.1.0/configure --host=x86_64-w64-mingw32 --build=x86_64-w64-mingw32 --target=x86_64-w64-mingw32 --prefix=/mingw64 --with-sysroot=/c/mingw810/x86_64-810-posix-seh-rt_v6-rev0/mingw64 --enable-shared --enable-static --disable-multilib --enable-languages=c,c++,fortran,lto --enable-libstdcxx-time=yes --enable-threads=posix --enable-libgomp --enable-libatomic --enable-lto --enable-graphite --enable-checking=release --enable-fully-dynamic-string --enable-version-specific-runtime-libs --disable-libstdcxx-pch --disable-libstdcxx-debug --enable-bootstrap --disable-rpath --disable-win32-registry --disable-nls --disable-werror --disable-symvers --with-gnu-as --with-gnu-ld --with-arch=nocona --with-tune=core2 --with-libiconv --with-system-zlib --with-gmp=/c/mingw810/prerequisites/x86_64-w64-mingw32-static --with-mpfr=/c/mingw810/prerequisites/x86_64-w64-mingw32-static --with-mpc=/c/mingw810/prerequisites/x86_64-w64-mingw32-static --with-isl=/c/mingw810/prerequisites/x86_64-w64-mingw32-static --with-pkgversion='x86_64-posix-seh-rev0, Built by MinGW-W64 project' --with-bugurl=https://sourceforge.net/projects/mingw-w64 CFLAGS='-O2 -pipe -fno-ident -I/c/mingw810/x86_64-810-posix-seh-rt_v6-rev0/mingw64/opt/include -I/c/mingw810/prerequisites/x86_64-zlib-static/include -I/c/mingw810/prerequisites/x86_64-w64-mingw32-static/include' CXXFLAGS='-O2 -pipe -fno-ident -I/c/mingw810/x86_64-810-posix-seh-rt_v6
-rev0/mingw64/opt/include -I/c/mingw810/prerequisites/x86_64-zlib-static/include -I/c/mingw810/prerequisites/x86_64-w64-mingw32-static/include' CPPFLAGS=' -I/c/mingw810/x86_64-810-posix-seh-rt_v6-rev0/mingw64/opt/include -I/c/mingw810/prerequisites/x86_64-zlib-static/include -I/c/mingw810/prerequisites/x86_64-w64-mingw32-static/include' LDFLAGS='-pipe -fno-ident -L/c/mingw810/x86_64-810-posix-seh-rt_v6-rev0/mingw64/opt/lib -L/c/mingw810/prerequisites/x86_64-zlib-static/lib -L/c/mingw810/prerequisites/x86_64-w64-mingw32-static/lib '
Thread model: posix
gcc version 8.1.0 (x86_64-posix-seh-rev0, Built by MinGW-W64 project)
```
</p>