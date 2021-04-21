# 한 눈에 끝내는 javascript & Node.js
<div align="right">

[강좌 링크](https://swmaestro.goorm.io/learn/lecture/26925/%ED%95%9C-%EB%88%88%EC%97%90-%EB%81%9D%EB%82%B4%EB%8A%94-node-js)</div>

## 목차
<p>

[0. 시작하기 앞서](#0-시작하기-앞서)<br>
[&nbsp; &nbsp; 0-1. 자바스크립트란?](#0-1-자바스크립트란?)<br>
[&nbsp; &nbsp; 0-2. 자바스크립트의 특징](#0-2-자바스크립트의-특징)<br>
[&nbsp; &nbsp; 0-3. 자바스크립트 엔진이란?](#0-3-자바스크립트-엔진이란?)</p>
<p>

[1. 자바스크립트 기초](#1-자바스크립트-기초)<br>
[&nbsp; &nbsp; 1-1. 기본 문법](#1-1-기본-문법)<br>
[&nbsp; &nbsp; 1-2. 연산자](#1-2-연산자)<br>
[&nbsp; &nbsp; 1-3. 데이터 타입](#1-3-데이터-타입)<br>
[&nbsp; &nbsp; 1-4. 조건문](#1-4-조건문)<br>
[&nbsp; &nbsp; 1-5. 반복문](#1-5-반복문)<br>
[&nbsp; &nbsp; 1-6. 함수](#1-6-함수)</p>
<p>

[2. 객체지향 자바스크립트](#2-객체지향-자바스크립트)<br>
[&nbsp; &nbsp; 2-1. 클래스](#2-1-클래스)<br>
[&nbsp; &nbsp; 2-2. 생성자](#2-2-생성자)<br>
[&nbsp; &nbsp; 2-3. 캡슐화](#2-3-캡슐화)<br>
[&nbsp; &nbsp; 2-4. 집합](#2-4-집합)<br>
[&nbsp; &nbsp; 2-5. 상속](#2-5-상속)<br>
[&nbsp; &nbsp; 2-6. 스코프와 호이스팅](#2-6-스코프와-호이스팅)<br>
[&nbsp; &nbsp; 2-7. 클로저](#2-7-클로저)</p>
<p>

[3. Node.js 소개](#3-Nodejs-소개)<br>
[&nbsp; &nbsp; 3-1. 개요](#3-1-개요)<br>
[&nbsp; &nbsp; 3-2. 이벤트 기반 비동기 방식](#3-2-이벤트-기반-비동기-방식)<br>
[&nbsp; &nbsp; 3-3. 그 외 특징들](#3-3-그-외-특징들)<br>
[&nbsp; &nbsp; 3-4. 아키텍처](#3-4-아키텍처)</p>
<p>

[4. Node.js 설치](#4-Nodejs-설치)</p>
<p>

[5. Node.js 간단한 실습](#5-Nodejs-간단한-실습)<br>
[&nbsp; &nbsp; 5-1. 웹 서버](#5-1-웹-서버)<br>
[&nbsp; &nbsp; 5-2. 파일 입출력](#5-2-파일-입출력)<br>
[&nbsp; &nbsp; 5-2. 비동기 이벤트](#5-3-비동기-이벤트)</p>
<p>

[6. Node.js 기본 모듈과 기초](#6-Nodejs-기본-모듈과-기초)<br>
[&nbsp; &nbsp; 6-1. 노드의 모듈화 개념](#6-1-노드의-모듈화-개념)<br>
[&nbsp; &nbsp; 6-2. 전역 객체](#6-2-전역-객체)<br>
[&nbsp; &nbsp; 6-3. 모듈의 종류](#6-3-모듈의-종류)<br>
[&nbsp; &nbsp; 6-4. 기본 모듈들 사용법](#6-4-기본-모듈들-사용법)
</p>

---

## 0. 시작하기 앞서
<p>
node.js를 알아가는 데 중요한 것은 딱 두 가지이다.

1. 싱글 스레드이며 비동기 방식
2. 자바스크립트 기반
</p>
<p>
FE뿐 아니라 BE 또한 자바스크립트로 작성할 수 있다는 것이 큰 장점. 이 점 때문에 Node.js의 성장세가 계속된다.
</p><br>

### 0-1. 자바스크립트란?
<p>
웹 페이지의 동작을 담당한다. 동적으로 콘텐츠를 바꾸고 멀티미디어, 움직이는 이미지 등 웹 페이지를 꾸며주도록 도와준다.
</p>
<p>
자바스크립트는 객체 기반 스크립트 프로그래밍 언어로서 주로 웹 개발에 많이 사용되는 것으로 알려져 있지만, 다른 응용프로그램의 내장 객체에도 접근할 수 있는 기능도 가지기에 응용 범위가 무궁무진하다.
</p>
<p>
오늘날 우리가 자주 사용하는 구글, 페이스북, 트위터, 네이버 등에서 개발한 각종 웹 어플리케이션과 서비스는 모두 자바스크립트와 AJAX 기술을 사용하여 구현한 것이다.
</p>
<p>
React Native, PhoneGap, Ionic 등과 같은 하이브리드 모바일 어플리케이션 개발 프레임워크들은 자바스크립트로 작성한 모바일 어플리케이션을 iOS와 Android를 대상으로 동시 동작할 수 있도록 지원한다.
<p>
Unity 3D 게임엔진과 자바스크립트를 활용해서 플랫폼을 가리지 않는 게임 개발이 가능하다.
</p>
</p>
<p>
이밖에도 자바스크립트의 영향력은 필드 전반에 걸쳐 강력하다. Node.js 또한 자바스크립트를 이용하는 개발 플랫폼이다.
</p><br>

### 0-2. 자바스크립트의 특징
<p>
동적 웹페이지를 만드는 언어는 JS 외에도 JSP, Servlet, ASP 등 많다. 이 중에서 자바스크립트를 가장 많이 쓰는 이유는, 자바스크립트는 웹 브라우저(클라이언트 측)에서 실행되는 반면 다른 나머지들은 서버에서 실행되고 결과를 HTML로 변환하여 보여주는 방식으로 자바스크립트의 실행 속도가 더 빠르기 때문이다.
</p>

#### 동적 형변환
<p>
다른 스크립트 언어들이 그렇듯 JS 역시 값에 따라 변수의 형변환이 자동으로 이루어진다.
</p>

```javascript
var i = 1;
var ch = "a";
consol.log(i+ch);
ch = 1;
console.log(i+ch);
```
```
1a
2
```

#### 프로토타입 기반 객체 지향(Prototypal Object-Oriented)
<p>
객체 생성 시 클래스로부터 그 내용을 상속받아 객체를 만드는 것이 아니라, 객체로부터 특성을 복제하여 새 객체를 생성하기 때문에 런타임 중 객체의 속성과 값의 추가, 변경, 삭제가 가능하다.
</p>

```javascript
var person = { name:"David Ki", age:24 }; 
console.log(person);
// Object
//  age: 24
//  name: "David Ki"
//  __proto__: Object
  
person.height = 187;
console.log(person);
// Object
//  age: 24
//  name: "David Ki"
//  height: 187
//  __proto__: Object
```
```
{ name: 'David Ki, age: 24 }
{ name: 'David Ki', age: 24, height: 187 }
```

#### 실행 시 평가
<p>
프로그램 실행 시 코드 블록을 실행할 수 있는 eval() 함수와 같은 요소를 지니기 때문에 프로그램 실행 도중 동적으로 코드 실행이 가능하다.
</p>

```javascript
eval("var a = 1, b = 2;");
console.log(a, b);
```
```
1 2
```
</p>

#### 고차 함수
<p>
고차 함수는 인자로서 함수를 취하거나, 반환 값으로 함수를 반환할 수 있는 함수를 일컫는다.
</p>
<p>
JS에서 다른 언어에서는 불가능한 방식으로 함수들을 쉽게 조작할 수 있다.
</p>

```javascript
// ho_func는 고차 함수. 인자로 param_func 함수를 받으면 param_func 함수를 실행하는 함수를 반환한다.
var ho_func = function (param_func) { param_func(); };
ho_func(function () { console.log("hello !"); });
```
```
hello !
```
<br>

### 0-3. 자바스크립트 엔진이란?
<p>개발자가 작성한 자바스크립트 코드를 해석하고 실행시켜주는 것이 자바스크립트 엔진으로, 가능한 짧은 시간 내에 가장 최적화된 코드를 생성하는 것을 목표로 한다.</p>
<p>자바스크립트 코드를 실행하는 프로그램 혹은 인터프리터를 일컫는다. 표준 인터프리터로 구현할 수도, 바이트 코드로 컴파일하는 JIT 컴파일러로 구현할 수 있다. 주로 웹 브라우저를 위해 사용된다.</p>
<p>특정 버전의 ECMAScript를 구현하기 때문에 ECMAScript가 발전하는 만큼 엔진도 발전한다. 서로 다른 웹 브라우저, Node.js와 같은 런타임 등에서 동작하도록 많은 엔진이 만들어졌다.</p>

#### 자바스크립트 엔진의 종류
- V8 - 오픈소스로 구글에서 개발했다. C++로 작성되었고 구글 크롬과 Node.js에서 사용된다. 가장 유명한 엔진.
- SpiderMonkey - 최초의 자바스크립트 엔진. 지금은 모질라 파이어폭스에 사용된다.
- Rhino - 모질라 재단에서 운영, 오픈소스이고 자바로 개발되었다.
- JavaScriptCore, Chakra, Nashron, JerryScript 등등

## 1. 자바스크립트 기초
### 1-1. 기본 문법
<p>자바스크립트는 기본적으로 C/C++, java와 유사한 문법을 가진다.</p>

- 세미콜론(;)으로 문장이 종료되어야 한다.
- 변수명은 알파벳 혹은 '_'으로 시작해야 한다.
- 대, 소문자를 구별한다.
- 예약어는 변수명으로 사용할 수 없다.
- 중괄호 {}를 이용해 구역을 나눈다.
- C/C++과 같은 구조의 조건문, 반복문을 가진다.

<p>*자바스크립트 예약어: break, case, catch, continue, default, delete, do, else, false, finally, for, function, if, in, instanceof, new, null, return, switch, this, throw, true, try, typeof, var, void, while, with</p>

코드<br>
```javascript
var a = 1;
b = 2;
console.log("a:"+a);
console.log("b:"+b);
```
결과<br>
```
a:1
b:2
```

코드<br>
```javascript
var c = 3, d = 10;
var str1 = "Hello", str2 = "World !", str3 = null;
console.log("c:"+c);
console.log("d:"+d);
console.log(str1+" "+str2);
console.log(str3);
```
결과<br>
```
c:3
d:10
Hello World !
null
```

### 1-2. 연산자
#### 산술 연산자
<p>산술 연산자로 +, -, *, /, ++, --를 사용할 수 있다. 사용법은 C와 동일하다.</p>

```javascript
var a = 1, b = 2;
console.log(a++, ++b);
```
```
1 3
```

#### 문자열 연산자
<p>문자열 연산자는 +가 있다. 두 문자열을 concat한다.</p>

#### 할당 연산자
<p>+=, -=, *=, /=가 있으며 사용법은 C와 동일하다.</p>

#### 비교 연산자
<p>>, >=, <, <=가 있으며 사용법은 C와 동일하다.</p>

코드<br>
```javascript
var a = 2, b = 1, c = 6, d = 8;
console.log(a > b);     // true
console.log(b >= c);    // false
console.log(c <= 10);   // true
console.log(d < 8);     // true
```
결과<br>
```
true
false
true
true
```

#### 논리 연산자
<p>==, !=, &&, ||, !가 있으며 사용법은 C와 동일하다.</p>

코드<br>
```javascript
var a = 2, b = 1, c = 6, d = 0;
console.log(a == 1);            // false
console.log(b != c);            // true
console.log(!a, !b, !d);        // false false true
console.log(true && false);     // false
console.log(false || true);     // true
console.log(!false);            // true
```
결과<br>
```
false
true
false false true
false
true
true
```

#### 조건 연산자
<p>(조건)? A: B 와 같은 형식으로 C와 마찬가지로 조건이 참일 때 A, 거짓일 때 B를 수행한다.</p>

코드<br>
```javascript
var a = 2, b = 1;
a > b? console.log("a is bigger than b"): console.log("a is smaller than b");
```
결과<br>
```
a is bigger than b
```

### 1-3. 데이터 타입
<p>자바스크립트는 변수를 선언할 때 별도로 자료형을 명시하지 않는다. 'var' 키워드를 사용해서 변수를 선언할 때 자료형에 따라 다른 키워드를 사용해야 한다는 제약사항은 없다. 덕분에 데이터 활용에 있어 자유도가 높다.</p>
<p>지금부터 소개할 자바스크립트의 기본 자료형 Number, String, Boolean  등은 기본적으로 내장형 객체라는 개념으로, '미리 만들어져 내장된 무언가'라고 생각하면 쉽다.</p>

#### Number
<p>수와 관련된 모든 자료형을 가진다. 진수 표기법과 소수점이 있는 실수, 지수를 사용할 수 있다.</p>

코드<br>
```javascript
var int_data = 1, float_data = Number('1.0'), float_obj = new Number('1.0');
typeof int_data;                        // "number"
typeof float_data1;                     // number
typeof float_data2;                     // "object"
console.log(float_data, float_obj);     // 1 >Number {1}
```
결과<br>
```
"number"
number
"object"
1 >Number {1}
```
코드<br>
```javascript
console.log((255).toString(10));    // 255
console.log((255).toString(16));    // ff
console.log((255).toString(8));     // 377
console.log((255).toString(2));     // 11111111
```
결과<br>
```
255
ff
377
11111111
```

#### String
<p>String은 문자열 값을 가지는 자료형이다. 작성 시 큰따옴표(""), 작은따옴표('') 모두 사용 가능하다.</p>

코드<br>
```javascript
var char1 = 'a', char2 = "b";
console.log(char1, char2, char1+char2); // a b ab
var str1 = "Double", str2 = 'single', str3 = new String("str obj");
typeof str1;            // "string"
typeof str2;            // "string"
typeof str3;            // "object"
str2[3];                // "g"
console.log(str2[3]);   // g
str1.length;                // 6
console.log(str1.length);   // 6
console.log(str1.toUpperCase());    // DOUBLE
console.log(str1.toLowerCase());    // double
console.log(str3.indexOf('b'));     // 5
console.log(str3.indexOf(' '));     // 3
str3.indexOf(' ');                  // 3
```
결과<br>
```
a b ab
"string"
"string"
"object"
"g"
g
6
6
DOUBLE
double
5
3
3
```

#### Boolean
<p>Boolean은 참 또는 거짓을 구별하는 값으로 true, false 값을 가진다. true, false는 예약어로서 따옴표를 쓰지 않는다.</p>

코드<br>
```javascript
var result = new Boolean();
typeof result;          // "object"
result;                 // >Boolean {false}
console.log(result);    // >Boolean {false}
result = true;
typeof result;          // "boolean"
result;                 // true
console.log(result);    // true
```
결과<br>
```
"object"
>Boolean {false}
>Boolean {false}
"boolean"
true
true
```

#### Array
<p>Array는 배열 자료형이다. 배열 연산을 할 수 있는 다양한 메소드를 지원하는 객체이다.</p>

코드<br>
```javascript
var arr1 = [1, 2, 3], arr2 = new Array(4, 5);
arr2.push(3);
console.log(arr2);                  // >(3) [4, 5, 3]
typeof arr1;                        // "object"
typeof arr2;                        // "object"
var arr3 = new Array(3);
arr3;                               // >(3) [undefined x 3]
arr3[0];                            // undefined
typeof arr3[0];                     // "undefined"
arr1.toString();                    // "1, 2, 3"
arr1.valueOf();                     // >(3) [1, 2, 3]
arr1.length;                        // 3
arr1.length = 5;
arr1;                               // >(5) [1, 2, 3, undefined x 2]
arr1[10];                           // undefined
console.log(arr2.push("new1"));     // 4
console.log(arr2.push("new2"));     // 5
arr2;                               // >(5) [4, 5, 3, "new1", "new2"];
arr2.pop();
var str = arr2.pop();
str;                                // "new1"
arr2;                               // >(3) [4, 5, 3]
arr3 = new Array(4, 2, 1, 3, 0);
console.log(arr3.sort());           // >(5) [0, 1, 2, 3, 4]
```

### 1-4. 조건문
<p>다른 프로그래밍 언어와 마찬가지로 조건문은 다양한 상황에 맞게 코드를 블록 단위로 작성하여 실행 흐름을 조절한다.</p>
<!-- <p>반복문은 블록 단위의 코드를 특정 조건에서 반복하는 구문이다.</p> -->

#### if - else
<p>C와 동일한 문법과 로직을 지닌다.</p>

코드<br>
```javascript
var a = 2, result;
if (a > 2) { result = "a is greater than 2"; } // 중괄호{}를 이용해 블록처리
else if (a < 2) result = "a is smaller than 2";
else result = "a is equal to 2";
console.log(result);
```
결과<br>
```
a is equal to 2
```

#### switch
<p>C와 동일한 문법과 로직을 지닌다.</p>

코드<br>
```javascript
var a = 1, result;
switch (a) {
    case 1: result = "it's 1"; console.log("hi there !"); break;
    case 2: result = "it's 2"; break;
    default: result = "it's bigger than 2";
}
console.log(result);
```
결과<br>
```
hi there !
it's 1
```

### 1-5. 반복문
<p>조건문이 작성한 코드의 경로를 바꾸는 데 사용된다면, 반복문은 특정 코드 경로를 일정 횟수만큼 반복하는 데 사용된다.</p>

#### for

코드<br>
```javascript
var array = new Array();
for (var i=0; i<10; i++) array.push(i);
console.log(array.toString());
```
결과<br>
```
"0, 1, 2, 3, 4, 5, 6, 7, 8, 9"
```

<p>자바스크립트에는 for문의 다른 형태로 for-in 문이 있다. 배열의 원소들이나 객체를 쉽게 탐색할 수 있도록 해준다.</p>
<p>실제 사용과 적용은 for문보다 제한적이다.</p>

코드<br>
```javascript
var a = ['a', 'b', 'c', 'x', 'y', 'z'];
var result;
for (var i in a) result += 'index:'+i+', value:'+a[i]+'\n';
console.log(result);
```
결과<br>
```
index:0, value:a
index:1, value:b
index:2, value:c
index:3, value:x
index:4, value:y
index:5, value:z
```

#### while, do-while

코드<br>
```javascript
var i = 0;
while (i < 10) i++;
console.log(i);
```
결과<br>
```
10
```

<p>do-while은 C와 마찬가지로, do 구문 뒤에 코드 블록이 위치하며 최소 한 번은 블록이 실행된다.</p>

코드<br>
```javascript
var i = 0;
do { i++; } while (i < 0)
console.log(i);
```
결과<br>
```
1
```

### 1-6. 함수
<p>function 이란 키워드를 사용하며 별도로 함수의 반환값에 대한 자료형은 명시하지 않는다.</p>
<p>함수에 대한 정확한 이해는 어떤 프로그래밍 언어든 중요하지만 자바스크립트에서는 함수를 더욱 다양한 방법으로 사용하기 때문에 다른 언어보다 함수에 대한 이해가 훨씬 중요하다.</p>
<p>자바스크립트의 함수는 다른 언어와 마찬가지로 **반환값을 하나**만 가질 수 있는데, 만약 여러 값을 반환하고 싶다면 **배열**이나 **객체**형태로 반환하면 된다.</p>

#### 데이터로서의 함수
<p>자바스크립트에서 함수의 중요한 개념 중 하나는 **함수가 하나의 데이터로서 취급**된다는 것이다. 함수 또한 하나의 객체이기 때문에 그렇다.</p>

코드<br>
```javascript
function sum(a, b) { return a+b; }
// 함수를 변수(메모리)에 할당할 수 있다
var add = sum;
typeof add;         // return "function"
add(1, 2);          // return 3

var student = { name: 'goorm', age: 20 }
console.log(student.name);  // goorm
delete student.name;        // return true
console.log(student.name);  // undefined
if (!delete student) console.log("It's false");
if (delete not_exist) console.log("It's true");
console.log(student.age);   // 20
```
결과<br>
```
goorm
undefined
20
```

#### 익명 함수(Anonymous Function)
<p>자바스크립트에서는 무기명 또는 익명 함수라는 개념이 있다. C와 java에는 없는 독특한 개념이다. 앞서 함수가 데이터처럼 취급될 수 있다고 설명했는데, 그러한 특징 때문에 익명 함수와 같은 개념이 가능한 것이다.</p>
<p>익명 함수는 단순히 설명하면 이름을 붙여주지 않아도 되는 함수이다. 일회용 혹은 이름이 필요 없는 변수를 사용할 때 효과적이다.</p>
<p>보통 **함수 표현식, 콜백 함수, 즉시 실행 함수**를 익명 함수로 작성한다.</p>

코드<br>
```javascript
var f = function(a) { return "This is anonymous function !"; };
console.log(f());
```
결과<br>
```
This is anonymous function!
```

#### 콜백 함수(Callback Function)
<p>함수가 데이터로서도 사용되고 이름을 가지지 않아도 사용 가능하기 때문에 발생한 개념이 콜백 함수이다.</p>
<p>콜백 함수란 특정 이벤트가 발생하면 호출되는 함수이다. 이벤트 기반 구조를 가지는 자바스크립트에서는 콜백 함수의 개념이 아주 중요하게 사용되기 때문에 필히 익혀둬야 한다.</p>
<p>함수의 인자로서 함수를 넘겨주는 방식으로 구현한다.</p>

코드<br>
```javascript
function one() { return 1; }
var two = function() { return 2; }
function invoke_and_add(a, b) { return a()+b(); }
console.log(invoke_and_add(one, two));
```
결과<br>
```
3
```
<p>위 소스 코드를 살펴보면 one()과 two() 함수 그 자체가 invoke_and_add() 함수의 인자로서 전달되어 연산이 수행된다.</p>
<p>익명 함수를 이용해서 콜백 함수를 구현할 수 있다.</p>

코드<br>
```javascript
function one() { return 1; }
function invoke_and_add(a, b) { return a()+b(); }
console.log(invoke_and_add(one, function() { return 2; }));
```
결과<br>
```
3
```

## 2. 객체 지향 자바스크립트
<p>자바스크립트는 객체 지향 언어이다. 자바스크립트는 기존 C++과 java가 지니는 객체 지향 특성과 조금 다르다. C++과 java는 **클래스 기반**의 언어이고, 자바스크립트는 **프로토타입 기반**의 언어이다.</p>
<p>객체 지향 개념에 대해 간략히 정리하고 자바스크립트의 특징을 살펴본다.</p>

#### 객체 지향의 특징
<p>

'**객체 지향**'은 다음과 같은 요소를 갖는다.</p>

- 클래스
- 객체
- 메소드
- 속성
- 캡슐화
- 집합
- 재사용
- 상속
- 변형

### 2-1. 클래스
코드<br>
```javascript
var SoccerPlayer = function() { };
SoccerPlayer.prototype = {
  name: String,
  age: Number,
  height: Number,
  weight: Number,
  position: String,
  team: String
};
var park_ji_sung = new SoccerPlayer();
park_ji_sung.name = "Park Ji Sung";
park_ji_sung.age = 31;
park_ji_sung.height = 178;
park_ji_sung.weight = 70;
console.log(park_ji_sung);
```
결과<br>
```
{ name: 'Park Ji Sung', age: 31, height: 178, weight: 70 }
```
<p>박지성은 축구선수라는 클래스로 만들어진 하나의 인스턴스(객체)다.</p>

### 2-2. 생성자
<p>자바스크립트에서 객체를 생성할 때 사용하는 방법 중 하나다.</p>

#### 생성자 함수(Constructor Function)
코드
```javascript
function SoccerPlayer() { this.position = "Forward"; }
var VanPersie = new SoccerPlayer();
VanPersie.position;
```
결과
```
"Forward"
```
<p>새로운 객체를 만들 때 다음과 같이 초기값을 전달하여 생성할 수 있다.</p>

코드<br>
```javascript
function SoccerPlayer(name, position) {
  this.name = name;
  this.position = position;
  this.whatIsYourName = function() { return "My name is "+this.name; };
  this.whatIsYourPosition = function() { return "My position is "+this.position; };
}

var player = new SoccerPlayer("Park Ji Sung", "Wing Forward");
player.whatIsYourName();
player.whatIsYourPosition();
```
결과<br>
```
"My name is Park Ji Sung"
"My position is Wing Forward"
```
코드<br>
```javascript
// 인자가 적다면 가장 먼저 입력받는 인자부터 차례로 입력된다
var player2 = new player.constructor("Koo Ja Cheol");
player2.name;
```
결과<br>
```
"Koo Ja Cheol"
```

#### instanceof 연산자와 생성자 속성(Constructor Property)
<p>instanceof 연산자를 이용하면 특정 객체가 어떤 생성자를 이용하여 생성됐는지 알 수 있다. 새로운 객체를 생성하면 내부에 constructor라는 속성이 생기는데, 이 속성이 객체를 만드는데 어떤 클래스를 참조했는지에 대한 정보를 담고 있다.</p>

코드<br>
```javascript
player instanceof SoccerPlayer;
player instanceof Object;
```
결과<br>
```
true
true
```

#### 내장형 객체(Built-In Object)
<p>내장형 객체는 앞서 설명한 자료형을 포함해 다음과 같은 것들이 있다. 이 강의에서 자세히 다루지는 않는다.</p>

- Object, Number, Array, String, Boolean, Function
- RegExp: 정규식을 위한 객체
- Math: 수학과 관련된 값들과 메소드를 가진 객체
- Date: 날짜와 시간에 관련된 메소드를 가진 객체
- Error: 자바스크립트에서 발생하는 에러를 처리하기 위한 객체


### 2-3. 캡슐화
<p>다른 표현으로 정보 은닉(Information Hiding)이라고 한다. 객체가 데이터를 속성에 저장하거나 저장한 데이터를 이용해 어떤 것을 수행하는 메소드를 포함하는 것을 말한다.</p>
<p>캡슐화의 예로 스마트폰을 들 수 있다. 사용자는 스마트폰의 터치스크린, 버튼, 마이크 등의 인터페이스를 알 뿐 내부에서 어떤 동작을 하는지 어떻게 동작하는지에 대해서는 알 수 없다.</p>
<p>객체 지향 건셉에서 다루는 캡슐화도 이와 동일하다. 우리가 써드 파티(third-party) 라이브러리를 이용해 객체를 생성하고 메소드를 호출할 때 내부 코드와 구현 로직에 대한 큰 관심은 없을 것이다. 심지어 컴파일되어 제공되는 라이브러리는 관심을 가지더라도 내부를 볼 수 없다.</p>
<p>캡슐화는 속성과 메소드의 가시성에 대해서도 다룬다. 흔히 아는 public, private, protected와 같은 키워드를 사용하여 외부에서의 접근 권한을 다룬다.
자바스크립트에서는 이런 키워드를 사용하진 않으나 객체의 프라이버시를 보호할 방법은 존재한다.</p>

### 2-4. 집합
<p>객체 지향 컨셉에서 여러 객체를 하나로 구성하는 것을 집합(Aggregation) 또는 구성(Composition)이라 한다. 이 컨셉은 해결하고자 하는 문제를 개발자가 쉽게 다룰 수 있을 만한 부분으로 나누어 해결할 수 있도록 해주는 강력한 방법이다. 집을 예로 들면, 집을 지을 때 바닥, 문, 기둥, 지붕 등의 객체들을 만든 후 하나로 합쳐 집을 만드는 것이 집합 컨셉을 이용한 것이다.</p>

### 2-5. 상속
<p>상속은 이미 작성된 코드를 재사용하는 아주 훌륭한 방법이다. 축구선수 박지성을 예로 들면, 인간이라는 클래스와 축구선수라는 클래스가 있을 때 축구선수는 인간을 상속받는다.</p>

코드<br>
```javascript
function Man() {
  this.name = "Anonymous";
  this.gender = "Man";
  this.Run = function () { return this.name+" is running!"; };
  this.Sleep = function() { return this.name+" is sleeping!"; };
}
function SoccerPlayer () {
  this.base = new Man(); // 상속
  this.name = "Anonymous Soccer Player";
  this.Run = function() { return this.base.Run(); };
  this.Pass = function() { return this.name+" is passing to other player!"; };
}

SoccerPlayer.prototype = new Man(); // 이 코드가 없으면 gender가 undefined
var player = new SoccerPlayer();
console.log(player.name);       // Anonymous Soccer Player
console.log(player.gender);     // Man
console.log(player.Run());      // Anonymous is running!
console.log(player.Pass());     // Anonymous Soccer Player is passing to other player!
console.log(player.Sleep());    // Anonymous Soccer Player is sleeping!
```

### 2-6. 스코프와 호이스팅
<p>자바스크립트에서 스코프와 클로저는 중요한 개념이다. 스코프와 클로저는 연결된 개념이고 다소 어려우므로 헷갈리기 쉬운데 이번 강의에서 확실히 익혀두도록 한다.</p>
<p>또 다른 중요 개념인 호이스팅에 대해서도 다룬다.</p>

#### 유효 범위(Scope)
<p>스코프를 유효 범위라고 부르기도 하지만 스코프라는 말이 더 많이 쓰인다.</p>
<p>자바스크립트에서 스코프란 작성된 코드를 둘러싼 환경으로, 어떤 변수들에 접근할 수 있는지를 정의한다. 변수가 어떤 범위에 속해있는지 정의하는 것과 같다.</p>
<p>스코프는 전역(global)과 지역(local) 스코프로 정의할 수 있다. 다른 프로그래밍 언어의 전역변수와 지역변수랑 비슷한데, 자바스크립트는 대부분의 다른 언어가 가지는 Block-level scope(블록 단위 유효범위)가 아닌 Function-level scope(함수 단위 유효범위)를 가지며 이 점 때문에 차이가 발생한다.</p>

코드<br>
```javascript
function foo() {
  if (true) {
    var a = 1;
    console.log(a);
  }
  console.log(a);
}
foo();
```
결과<br>
```
1
1
```
<p>위 상황에서 자바스크립트는 함수 레벨 스코프이기 때문에 중괄호 밖에서 a에 대한 참조가 가능하다.</p>
<p>자바스크립트 ES6부터는 const, let 키워드를 이용해 블록 단위 유효범위 사용이 가능하다. 따라서 if문 안에 var 대신 const나 let으로 변수를 선언하면 다른 언어들처럼 참조하지 못한다.</p>
<p>const와 let은 블록 단위 유효범위를 갖고 var는 전통 자바스크립트의 함수 범위 유효범위를 가진다는 점을 반드시 기억해둔다.</p>

#### 전역 스코프(Global scope)와 지역 스코프(Local scope)
<p>변수가 함수 바깥이나 중괄호{} 바깥에 선언됐다면 전역 스코프에 정의되었다고 한다. 함수 바깥에서도 해당 변수에 참조 가능하다.</p>
<p>변수가 함수 내 범위에 선언됐다면 지역스코프에 정의되었다고 한다. 함수 바깥에서 해당 변수에 참조 불가능하다.</p>

코드<br>
```javascript
var global_scope = 'global';
var local_function = function() {
  var local_scope = 'local';
  console.log(global_scope);
  console.log(local_scope);
};
console.log(local_scope); // error
```
결과<br>
```
Uncaught ReferenceError: local_scope is not defined at <anonymous>:7:13
```
<p>되도록 지역 스코프에 변수를 선언한다. 지역 스코프 변수는 협업 시 이유를 알 수 없는 에러나 변수 충돌의 원인이 된다.</p>

#### 유효 범위 체인(Scope Chain)
<p>함수 안에 함수가 있는 경우, 내부 함수는 외부 함수의 변수를 참조 가능하나 그 반대는 불가능하다.</p>

코드<br>
```javascript
var a = 1;
function outer() {
  var b = 2;
  console.log(a);     // 1
  function inner() {
    var c = 3;
    console.log(a, b);
  }
  inner();            // 1 2
}
outer();
console.log(c);       // error
```
결과<br>
```
1
1 2
Uncaught ReferenceError: c is not defined at <anonymous>:12:13
```
<div align="center">
  <figure><img src="./git-resource/[그림 1]유효 범위 체인.png" alt="그림1"></figure>
</div>

#### 정적 범위(Lexical scope)
<p>정적 범위란 함수를 어디서 호출하는지가 아니라 어떤 스코프에 선언하였는지에 따라 결정된다는 것을 말한다.</p>

코드<br>
```javascript
var text = 'global';
function foo() { console.log(text); }
function bar() { var text = 'bar'; foo(); }
bar();
```
결과<br>
```
global
```
<p>bar 내부에서 foo가 실행될 때 foo 지역 스코프에서 text 변수를 탐색한 뒤, 없으면 전역 스코프에서 탐색한다. 따라서 global이 출력된다. bar 지역 스코프에 선언된 text 변수가 사용되지 않는다.</p>
<p>C++과 같은 다른 프로그래밍 언어도 이와 같은 정적 범위 개념을 갖는다.</p>

#### 호이스팅(Hoisting)
<p>hoisting의 사전적 의미는 끌어 올리기라는 뜻이다. 호이스팅 또한 자바스크립트의 특징 중 하나인데, 함수 내부에서 변수를 선언할 때 어떤 위치에 있든 함수의 시작 위치로 끌어올리는 현상이다.</p>
<p>단, 선언만 유효하고 값의 할당은 원 위치에서 수행한다.</p>

코드<br>
```javascript
function foo() {
  console.log(a);
  var a = 100;
  console.log(a);
}
foo();
```
결과<br>
```
undefined
100
```
<p>다른 프로그래밍 언어에서 위 코드와 같은 로직을 수행하면 a가 선언되지 않아 첫 출력에서 에러가 발생한다. 그러나 자바스크립트는 호이스팅을 통해 변수 a의 선언이 함수 시작부분에서 이루어지기 때문에 에러 없이 undefined가 출력된다.</p>
<p>위 코드는 다음과 같은 코드이다.</p>

코드<br>
```javascript
function foo() {
  var a;
  console.log(a);
  a = 100;
  console.log(a);
}
foo();
```

<p>변수 뿐 아니라 함수 또한 호이스팅된다.</p>

코드<br>
```javascript
foo();

function foo() { console.log('출력'); }
```
결과<br>
```
출력
```
<p>하지만 다음과 같이 함수 표현식의 경우 오류가 발생한다.</p>

코드<br>
```javascript
foo();

var foo = function() { console.log('출력'); }
```
결과<br>
```
TypeError: foo is not a function
```

<p>위 코드는 사실 아래 코드와 같기 때문에 오류가 발생한다.</p>

코드<br>
```javascript
var foo;
foo();
foo = function() { console.log('출력'); }
```
결과<br>
```
TypeError: foo is not a function
```

<p>호이스팅은 편리하나 코드가 의도치 않게 동작할 가능성이 있어 변수나 함수의 선언을 최상단에 하는 습관을 가지는 것이 좋다.</p>

### 2-7. 클로저
<p>

스코프 체인과 연관이 있다. 클로저란 **외부 함수의 실행이 끝나고 외부 함수가 소멸된 이후에도 내부 함수가 외부 함수의 변수에 접근할 수 있는 구조**를 말한다. 다시 말하면, 자신의 고유 스코프를 가진 상태로 소멸하지 않고 외부 함수에 의해 호출되는 함수를 만드는 것이다.</p>
<p>클로저는 자바스크립트가 가진 하나의 큰 특징이자, Node.js가 높은 효율성을 가지게 해주는 개념이다.</p>
<p>자바스크립트에서는 함수가 호출되면 메모리에 할당되고 함수가 종료되면 메모리에서 해제되기 때문에 함수별로 선언된 지역변수들은 호출할 때마다 같은 값으로 초기화된다. 하지만 함수를 호출할 때 이전에 쓰던 값을 유지하고 싶다면 클로저를 사용한다.</p>

코드<br>
```javascript
var num = 1;
function foo() {
  var num = 2;
  function bar() { console.log(num); }
  return bar;
}
var baz = foo();
baz();
```
결과<br>
```
2
```
<p>위 코드를 실행시켜보면 2가 정상적으로 출력된다. 하지만 여기서 궁금한 점이 생긴다.</p>
<p>

**"foo() 함수가 반환되어 사라진 후 내부 함수 bar가 생성되는 것인데, 여전히 내부함수 bar가 외부 함수인 foo의 지역변수에 접근할 수 있을까?"**</p>

<p>위 코드 결과를 보면 알겠지만, 가능하다. 이와 같이 외부 함수가 반환되고 사라진 후에도 내부 함수가 참조하여 값을 유지하도록 하는 것이 클로저다. 위 코드는 가장 간단한 클로저라고 볼 수 있다.</p>
<p>

정확히 위 같은 코드에서 내부 함수 bar를 **클로저 함수**라 한다.</p>

<p>다음 코드는 또 다른 클로저 예제 코드이다.</p>

코드<br>
```javascript
function f(arg) {
  var n = function() { return arg; }
  arg++;
  return n;
}

var m = f(123);
console.log(m());
```
결과<br>
```
124
```

<p>얼핏 보기에는 f(123)을 실행하면 내부 함수 n이 arg를 이미 반환하면서 123을 반환할 것으로 생각할 수 있다. 그러나 함수 n은 함수 f의 스코프 내에 있는 arg를 참조하고 있기 때문에 함수 f가 모두 실행된 후 n이 실행된다. 즉, m은 클로저 함수 n을 할당받으며 n이 참조하는 외부 함수 f의 arg 값이 유지된다.</p>

<p>다음 코드는 for문을 이용한 클로저 예제 코드이다.</p>

코드<br>
```javascript
function f() {
  var a = [];
  var i;
  for (i=0; i<3; i++) {
    a[i] = function() { return i; }
  }
  return a;
}
var b = f();
console.log(b[0]());
console.log(b[1]());
console.log(b[2]());
```
결과<br>
```
3
3
3
```

<p>

`a[i] = function() { return i; }` 부분은 함수 선언만 이루어진 것이고 실제로 이 함수가 실행되는 부분은 `console.log(b[0]());` 부터이므로 이 시점에서 이미 for문의 모든 실행이 끝난 이후 참조가 이루어진다.</p>

<p>클로저를 이용해서 정상적으로 0 1 2를 출력하게끔 하는 코드는 다음과 같다.</p>

코드<br>
```javascript
fucntion f() {
    var a = [], i;
    for (i=0; i<3; i++) {
        a[i] = (function(x) { return function() { return x; }})(i);
    }
    return a;
}

var b = f();

console.log(b[0]());
console.log(b[1]());
console.log(b[2]());
```
결과<br>
```
0
1
2
```

<p>function 내부 변수 i를 바로 반환하지 않고, 인수를 받는 function을 정의한 다음 인수로 내부 변수 i를 넘겨 클로저가 i가 아닌 인수를 반환하도록 하는 방법을 사용했다. (메모리 상 내부변수 i와 별개인 새로운 데이터를 생성하는 듯?)</p>
<p>클로저를 사용하면 함수를 호출할 때마다 기존 값을 유지할 수 있기 때문에 전역 변수의 오남용 없이 깔끔한 코드 작성이 가능하다. 또한 외부에 해당 변수를 노출시키지 않아 안전성을 보장한다(캡슐화). 클로저를 통해서만 해당 변수를 참조할 수 있기 때문에 외부 사용자가 값을 변경할 수 없다.</p>
<p>하지만 클로저로 참조하는 변수는 프로그램 종료 시까지 메모리에 할당되어 있어 메모리 누수의 원인이 된다. 이는 성능 저하로 이어지므로 신중하게 사용해야 한다.</p>

## 3. Node.js 소개

### 3-1. 개요
<p>

Node.js는 **서버사이드 자바스크립트**이며 구글의 자바스크립트 엔진 V8을 기반으로 구성된 소프트웨어 시스템이다.</p>
<p>이벤트 기반 개발이 가능하고 Non-Blocking I/O를 지원하기 때문에 비동기식 프로그래밍이 가능하다. 이 때문에 I/O 부하가 심한 대규모 서비스를 개발하기 적합하다. 자바스크립트의 표준 라이브러리 프로젝트 CommonJS의 스펙을 따른다.</p>
<p>비동기 프로그래밍 모델은 최근 등장한 새로운 개념은 아니다. 대표적으로 Python의 Twisted, Perl의 Perl Object Environment, C의 libevent, Ruby의 EventMachine 등이 있다.</p>

### 3-2. 이벤트 기반 비동기 방식
<p>지금까지 대부분 어플리케이션은 Blocking I/O를 사용했고, 이 때문에 멀티 쓰레드를 사용했다. 멀티 쓰레드는 개발자 입장에서 직관적이고 멀티 태스킹을 위한 어쩔 수 없는 선택이지만 네트워크 입장에서 동시에 대규모 요청을 동시에 처리하는 데에는 부적절하다.</p>

#### Blocking I/O
<p>

**'하나의 프로세스가 어떤 자원을 사용하고자 할 때 그 자원을 다른 프로세스가 점유하고 있다면, 그 프로세스가 그 자원의 사용을 끝마칠 때까지 기다려야 한다는 것'**을 의미한다.</p>

<div align="center">
  <figure>
    <img src="./git-resource/[그림 2]Blocking IO.png" alt="그림2">
  </figure>
</div>

#### 멀티 쓰레드
<p>CPU의 시분할 개념으로 요청을 처리한다는 개념이다. 여러 프로세스가 시간을 나누어 CPU를 사용하여 동작하게 함으로써 마치 CPU를 공유하여 사용하는 것과 같은 효과를 낸다.</p>

<div align="center">
  <figure>
    <img src="./git-resource/[그림 3]멀티 쓰레드.png" alt="그림3">
  </figure>
</div>

<p>첫 번째 경우가 싱글 쓰레드로 요청을 처리할 때 모습이다. 먼저 들어온 요청이 가장 먼저 처리된다.</p>
<p>두, 세 번째 경우 멀티 쓰레드에 스케쥴링을 적용한 것이다. 특정 쓰레드가 일정 시간만 CPU를 사용할 수 있는데, 프로세스 B, C가 A보다 늦게 요청되었음에도 먼저 처리된다.</p>

#### 쓰레드로 인해 발생하는 문제
<p>멀티 쓰레딩의 근본적인 문제는 여러 쓰레드가 CPU라는 자원을 점유하기 위해 기다릴 수밖에 없고, 문맥 전환(Context switch) 비용이 발생한다는 점이다.</p>
<p>근본적 문제는 차치하더라도, 멀티 쓰레딩의 실질적 문제는 Blocking I/O 자체가 발생시키는 쓰레드 지연에 대한 문제이다. I/O 요청을 하고 응답이 올 때까지 아무것도 하지 않고 시간(자원)을 낭비하게 된다.</p>

#### 싱글 쓰레드와 이벤트 기반 비동기 I/O 처리
<p>노드는 이런 문제들을 해결하는 비동기 프로그래밍 모델을 제공한다.</p>
<p>싱글 쓰레드를 가진 노드는 I/O 작업이 시작되면 응답을 기다리지 않고 바로 다음 작업을 실행한다. 대신 I/O 작업이 종료되면 이벤트를 발생시키고, 이벤트는 해당 프로세스의 이벤트 큐에 등록된다. 노드로 개발된 프로세스는 이 이벤트를 감지하여 해당 이벤트 발생 시 수행해야 할 작업을 실행한다.</p>

#### 이벤트 루프(Event Loop)
<p>이벤트 루프는 작업을 요청하면서 그 작업이 완료됐을 때 어떤 작업을 진행할지에 대한 콜백 함수를 지정하여 해당 콜백 함수를 실행하는 동작 방식을 말한다.</p>

<div align="center">
  <figure>
    <img src="./git-resource/[그림 4]이벤트 루프.png" alt="그림4">
  </figure>
</div>

<p>만약 클라이언트가 웹 서버에 HTTP 형식으로 요청하게 되면, 서버에서 실행중인 이벤트 루프가 이를 감지하고, 워커 쓰레드를 생성하여(? 노드는 싱글 쓰레드라 했는데, 쓰레드를 생성한다?) 알맞은 작업을 실행한다. 이 때 이벤트 루프는 해당 워커 쓰레드가 작업을 마친 뒤 결과와 함께 응답할 때까지 기다리지 않고 루프로 복귀하여 다른 요청을 기다린다.</p>
<p>

정리하자면 이벤트 루프는 **요청이 발생하면 그 요청에 대해 쓰레드 실행**만을 일으킨다. 해당 쓰레드가 작업을 마치면 미리 전달받은 콜백 함수를 실행하도록 이벤트 루프에게 응답하며 이벤트 루프는 이를 실행하고 클라이언트에게 결과를 응답한다.</p>

### 3-3. 그 외 특징들
- 자바스크립트 기반
- NPM을 통한 다양한 확장 모듈들
<p>NPM에 대해서는 7장에서 자세히 다룬다.</p>

### 3-4. 아키텍처

<div align="center">
  <figure>
    <img src="./git-resource/[그림 5]노드 아키텍처.png" alt="그림5">
  </figure>
</div>

<p>노드는 C/C++과 자바스크립트로 만들어졌다. C/C++은 레이어와 시스템 통합을 위해 사용되었다. V8 자바스크립트 엔진은 원래 구글 크롬이라는 웹 브라우저를 위해 만든 것이라 서버를 위해 설계된 것은 아닐 뿐더러 멀티 프로세스 모델에서 실행되는 것을 목표로 설계되었다. 노드에서 V8 엔진은 서버에서 동작할 수 있도록 변경되었다.</p>

<p>기술이 발전하며 초창기 아키텍처와 달리 노드 0.9버전부터 libev 종속성을 제거하며 libeio, libev가 libuv로 대체되었다.</p>

#### 노드 표준 라이브러리(Node standard library)
<p>V8을 이용해 특정 기능들을 수행할 수 있도록 도와주는 자바스크립트 기본 라이브러리다. 자바스크립트 언어로 작성되어 노드 바인딩과 연결된다.</p>

#### 노드 바인딩(Node bindings)
<p>C/C++로 구성된 시스템 바인딩 레이어다. C/C++로 작성된 라이브러리를 자바스크립트에서 사용할 수 있도록 결합하는 핵심 요소다.</p>
<p>소켓, http 등의 통신 기능이 제공되지만 DOM에 관한 기능은 제공하고 있지 않다. 소켓이나 http 등에 대한 노드 바인딩이 노드 표준 라이브러리와의 인터페이스 역할을 한다.</p>

#### V8 엔진
<p>V8 엔진은 구글에서 개발된 오픈소스 JIT 가상머신 형식의 자바스크립트 엔진이다. 구글 크롬 브라우저에 내장되어 있지만 독립적으로 실행 가능하다.</p>
<p>노드는 이 엔진을 이용해 자바스크립트로 개발된 노드 어플리케이션을 동작시킨다.</p>

#### 쓰레드 풀(Thread pool), libio
<p>쓰레드풀은 libio라는 비동기 I/O 라이브러리로 구성되어 있다. 즉, 파일 관련 작업(read, write, open, close, stat, unlink, fdatasync, mknod, readdir 등)을 수행한다. 이는 이벤트 기반 C언어용 I/O 라이브러리다.</p>
<p>노드에서의 비동기 I/O 작업들은 모두 이 라이브러리로 동작한다. 노드도 무조건 싱글 쓰레드만 사용하는 것은 아니고 내부적으로 멀티 쓰레드 풀을 사용하긴 한다.</p>

#### 이벤트 루프(Event Loop), libev
<p>이벤트 루프는 libev를 이용하여 구성된다.</p>

#### C-ares
<p>동시에 복수 DNS 쿼리를 비동기 처리하기 위한 C 라이브러리다.</p>

## 4. Node.js 설치
<p>

다음과 같은 세 가지 방법으로 Node.js를 설치할 수 있다.
- 소스코드 다운 및 빌드, 패스 설정(우분투, 맥)
- 패키지 매니저(우분투, 맥)
- 공식 인스톨러(윈도우, 맥)</p>

<div align="center">
  <figure>
    <img src="./git-resource/[그림 6]노드 설치.png" alt="그림6">
  </figure>
</div>

<p>

**소스 코드 다운 및 빌드** 방법은 필요 라이브러리를 설치하는 것이 우선이다. 이후 소스 코드 다운, gcc를 이용해 컴파일 및 빌드하고 어디서든 노드 명령어를 이용할 수 있게 환경 변수 경로를 설정한다.</p>

<p>

**패키지 매니저** 방법은 `apt-get` 명령어를 이용해 쉽게 소프트웨어를 설치 및 관리할 수 있는데, 우분투에서 기본적으로 제공하는 소프트웨어 저장소에 노드가 없으므로 노드 설치와 관련된 정보를 가진 저장소를 추가하고 이를 이용해 설치하는 방식이다. 맥과 윈도우의 경우 써드파티에서 만든 소프트웨어 패키지 매니저가 있는데 이를 이용해 우분투와 유사하게 설치 가능하다.</p>

<p>

**공식 인스톨러** 방법은 노드 [공식 홈페이지](https://nodejs.org/ko/download/)에서 인스톨러를 다운받아 실행해 설치하는 방법이다. 이렇게 설치한 경우 노드의 여러 버전 관리가 불가능해 불편하다. 이미 노드를 설치했다면 깔끔히 삭제하기도 번거롭다. 이런 문제 때문에 인스톨러 대신 노드를 버전별 설치/관리할 수 있는 NVM(Node Version Manager)를 이용하는 것이 좋다.</p>

<p>노드에는 LTS 버전과 Current 버전이 있는데 차이는 다음과 같다.</p>

<p>

- **LTS 버전**
  - 장기적으로 지원이 제공되는 안정적 버전
  - 안정성과 보안성에 초점</p>
<p>

- **Current 버전**
  - 잦은 업데이트
  - 가장 최신 버전으로 불안정, 숨겨져 있는 버그 많음
  - 추가 기능 개발과 기존 API 기능 개선 우선</p>

#### REPL(Read Eval Print Loop)
<p>노드가 설치되면 터미널과 같은 커맨드 라인 입력 인터페이스를 통해 REPL을 사용할 수 있다.</p>
<p>REPL은 웹 브라우저의 자바스크립트 콘솔(F12를 눌러 이용 가능)과 유사하다. 하지만 HTML 페이지와 연결되지 않기 때문에 DOM이 존재하지 않는다.</p>
<p>REPL을 이용해 간단한 코드를 작성하여 실행해보거나 테스트해볼 수 있다.</p>

## 5. Node.js 간단한 실습
### 5-1. 웹 서버
<p>노드를 이용하면 다음과 같이 단 몇 줄만으로 웹 서버를 만들 수 있다.</p>

hellonode1.js<br>
```javascript
// hellonode1.js
var server = require('http');

server.createServer(function(req, res) {
  res.writeHead(200, { 'Content-Type': 'text/plain' });
  res.end("Hello node.js !\n");
}).listen(3000, 'localhost');

console.log("Server is running at http://localhost:3000/');
```
서버 구동<br>
```
node hellonode1.js
```

### 5-2. 파일 입출력
hello.txt<br>
```
Hello !
```

main.js<br>
```javascript
var fs = require("fs");

fs.readFile('./hello.txt', encoding='utf-8', function(err, data) {
  if (err) throw err;
  console.log(data+" Node.js !");
});
```

### 5-3. 비동기 이벤트
<p>노드에서 비동기 이벤트를 생성하고 관리하도록 기능을 제공하는 events 모듈을 사용해본다.</p>

main.js<br>
```javascript
var EventEmitter = require('events').EventEmitter;
// 이벤트 객체 생성
var evt = new EventEmitter();

// 'helloNode'라는 이벤트가 발생하면
evt.on('helloNode', function(str) {
  // 해당 이벤트를 통해 전달된 인자를 입력받아 콘솔로 출력
  console.log("Hello! "+str);
});

// 자바스크립트 기본 메소드. 밀리 세컨드 단위로 특정 함수를 콜백으로 실행
setTimeout(function() {
  // 'helloNode' 이벤트 발생, 'Node.js' 문자열을 인자로 전달
  evt.emit('helloNode', 'Node.js');
}, 3000);
```

## 6. Node.js 기본 모듈과 기초
<p>노드에서 모듈이라는 개념은 노드로 개발한 어플리케이션을 이루는 기본 조각이라 할 수 있다.</p>
<p>일반적으로 노드로 개발된 어플리케이션은 객체 지향 개념이 아주 잘 녹아 있는 자바스크립트를 기반으로 하며, 파일과 1:1 맵핑이 되는 다양한 모듈로 구성된다.</p>

### 6-1. 노드의 모듈화 개념
<p>노드는 확장성을 위해 모듈 구조를 이용하여 어플리케이션을 구성하도록 한다. 모듈 단위로 구성된다는 것은 객체 지향 컨셉으로 어플리케이션이 구성된다는 것을 의미한다. 모듈화가 가능한 이유는 노드가 CommonJS 스펙을 대부분 준수하기 때문이다.</p>
<p>기본적으로 노드의 모듈은 자바스크립트 파일 하나와 1:1 맵핑되며 이러한 형태는 다음 장에서 설명할 NPM으로 할 수 있는 노드 확장 모듈의 개발을 편리하게 해준다.</p>

### 6-2. 전역 객체
<p>전역 객체는 어디에서나 사용할 수 있는 객체를 말한다. client 사이드 자바스크립트에서 window나 document와 같은 객체를 전역 객체라 말할 수 있다. 예를 들어 우리가 alert()이라는 함수를 사용할 때 단순히 alert('메세지')만 입력하더라도 사실 window라는 객체의 window.alert() 함수를 사용하는 것이다.</p>
<p>마찬가지로 서버 사이드에서 동작하는 노드의 경우 "global"이라는 전역 객체가 존재하는데, 우리가 앞으로 모듈을 불러올 때 사용할 require()를 비롯한 setTimeout(), console.log() 등을 포함하고 있다.</p>

```javascript
// 다음 두 개는 같은 기능을 수행하는 코드이다.
require('./module');
global.require('./module');
```

### 6-3. 모듈의 종류
<p>노드에서는 모듈의 종류를 크게 다음과 같은 기준으로 나눈다.</p>
<p>

- 노드 설치 시 기본적으로 설치되는 모듈: **기본 모듈** / **확장 모듈**
- 자바스크립트로 작성됐는지, C/C++등의 다른 언어로 작성 후 빌드됐는지: **일반 모듈** / **네이티브 모듈**
- 현재 어플리케이션만을 위해서 설치됐는지: **로컬 모듈** / **글로벌 모듈**
</p>

<div align="center">
  <figure>
    <img src="./git-resource/[그림 7]모듈 종류.png" alt="그림7">
  </figure>
</div>

<p>모듈의 종류를 알고 있는 것이 개발에 큰 영향을 미치진 않지만 모듈을 로딩하고 체계적으로 NPM을 배포하기 위해서 각 모듈의 특징 정도는 알아두는 것이 좋다.</p>

#### 기본 모듈 / 확장 모듈
<p>기본 모듈은 파일 입출력, 이벤트 관리, HTTP 프로토콜 관리 등에 관한 내용으로 노드의 비동기 입출력 처리를 위한 기본적 기능들을 제공하는 모듈이다.</p>
<p>확장 모듈은 노드의 기능을 확장하기 위한 것으로 좀 더 쉬운 HTTP 서버 생성, 기본 파일 입출력에서 제공하지 않는 기능 추가 등 노드를 확장하고 더 편리하게 사용하기 위한 모듈이다.</p>
<p>확장 모듈은 나중에 소개할 Express와 같은 모듈들처럼 하나의 프레임워크로서 제공되기도 하며, mongodb를 사용하기 위한 mongoose, mongolian처럼 다른 기술을 쉽게 접목하여 사용할 수 있도록 도와준다.</p>

#### 일반 모듈 / 네이티브(기본) 모듈
<p>개발 방법에 따라 나눌 수 있는 종류다. 노드의 네이티브 모듈은 C/C++로 개발된 경우가 대부분이다.</p>
<p>확장 모듈 또한 네이티브 모듈로 개발할 수 있다. .node라는 확장자를 가졌으면 네이티브 모듈로 컴파일된 것이다.</p>
<p>일반 모듈은 노드의 모듈 인터페이스를 통해 간단히 자바스크립트로 개발된 모듈이다.</p>

#### 글로벌 모듈 / 로컬 모듈
<p>모듈을 설치할 때 해당 어플리케이션에서만 사용하기 위해 설치한 경우 로컬 모듈이다. 글로벌 모듈로 설치하려면 설치 시 옵션 -g 을 이용한다.</p>

#### 복합 모듈
<p>내부 모듈이나 데이터 파일, 템플릿, 테스트 코드 등을 포함하는 모듈을 말한다. 다양한 파일을 포함하기 때문에 모듈을 구성하는 단위가 폴더이며 내부에 폴더를 가질 수 있다.</p>
<p>require() 메소드가 이런 폴더 단위의 모듈을 인식하려면 index.js 파일이나 pakage.json 파일 중 하나가 반드시 있어야 한다.</p>

#### 모듈 식별자(상대적 식별자, 절대적 식별자, 최상위 레벨 식별자)
<p>노드의 모듈 이름으로는 확장자 없는 전체 경로를 사용한다. 앞서 설명한 것처럼 모듈은 파일과 일대일로 대응하기 때문에 .js나 .node라는 확장자를 가지지만 모듈을 불러들일 때는 파일 이름만 사용한다.</p>

#### 상대적 식별자
<p>현재 위치를 기준으로 상대 경로에 있는 모듈을 찾는 식별자이다. ./를 생략하면 상대 경로로 인식하지 않으니 주의한다.</p>

```javascript
require('./sample_module');
```

#### 절대적 식별자
<p>절대 경로에 있는 모듈을 찾는 식별자이다.</p>

```javascript
require('/usr/local/node_modules/sample_module/');
```

#### 최상위 레벨 식별자
<p>모듈 이름만을 입력하면 최상위 레벨 식별자로 인식하고 설치된 전체 확장 모듈과 기본 모듈 중 해당 모듈 이름을 검색하여 로드한다.</p>

```javascript
require('sample_module');
```

<p>

여기서 중요한 점은 sample_module이라는 **모듈 식별자를 찾는 순서**이다. 만약 해당 모듈이 기본 모듈에서 찾을 수 없는 모듈이라면 상위 디렉토리를 차례대로 탐색한다. 예를 들면 다음과 같은 순서로 탐색한다.</p>

```
/home/goorm/example_project/node_modules/sample_module.js
/home/goorm//node_modules/sample_module.js
/home/node_modules/sample_module.js
/node_modules/sample_module.js
```

#### require() 메소드와 module.exports
<p>모듈 개념에서 require() 메소드와 module.exports는 매우 중요하다.</p>
<p>client 사이드 자바스크립트와 비교해보자면, 웹 브라우저에서는 html의 script 태그로 필요한 자바스크립트를 연결하고 호출하게 되어있다.</p>

```html
<!DOCTYPE html>
<html>
  <body>
    <script type="text/javascript" src="goorm1.js"></script>
  </body>
</html>
```

<p>이렇게 html 스크립트를 통해 명시된 자바스크립트 파일들은 웹 브라우저에 의해 로딩되며 서로 참조하거나 호출할 수 있다. 하지만 노드는 html을 사용하지 않으므로 서로 다른 자바스크립트 파일들이 서로 참조하고 호출하는 방법이 필요하다.</p>
<p>

require() 메소드는 모듈 식별자인 module.exports를 이용해 모듈이 제공하는 함수나 객체 등을 반환한다. **불러온 모듈의 모든 의존성 모듈도 같이 로드한다.**</p>

<p>노드에서 하나의 자바스크립트 파일은 하나의 모듈이 될 수 있다. 이 때 자바스크립트 파일 내부의 함수나 변수를 module.exports에 할당하면 외부에서 접근 가능하다.</p>

### 6-4. 기본 모듈들 사용법

#### (1) 전역 객체: Global
#### (1)-(1) console
</p>

[API 문서](https://nodejs.org/api/console.html)</p>
<p>

- console.log(): 콘솔에 로그 메시지 출력
- console.time(label): 시간 측정 시작
- console.timeEnd(label): 시간 측정 종료
</p>

#### (1)-(2) process
<p>

[API 문서](https://nodejs.org/api/process.html)</p>
<p>process 객체는 자바스크립트에는 없는 Node.js만의 객체이다.</p>

<p>

**속성**</p>
<p>

- process.argv: 프로그램의 매개변수 정보
- process.env: 컴퓨터 환경과 관련된 정보
- process.version: Node.js의 버전
- process.versions: Node.js 프로세스에서 사용하는 모듈들의 버전
- process.arch: 프로세서의 아키텍처
- process.platform: 플랫폼 정보
</p>

<p>

**메소드**</p>
<p>

- process.exit(): 프로그램 종료
- process.memoryUsage(): 메모리 사용 정보
- proces.uptime(): 현재 프로그램이 실행된 시간
</p>

예제<br>
```javascript
console.log("process env property: ", process.env);
console.log("uptime method: ", process.uptime());
```

#### (2) Exports 객체
<p>작성한 자바스크립트 파일을 모듈화시키고 외부에서 접근토록 만들어준다.</p>

calculator.js<br>
```javascript
exports.double = function(r) { return r*r; };
exports.plus = function(r) { return r+r; };
```
main.js<br>
```javascript
var calculator = require('./calculator');
console.log('double:', calculator.double(3));
console.log('plus:', calculator.plus(3));
```
결과<br>
```
> node main.js
double: 9
plus: 6 
```

#### (3) OS 모듈
<p>

[API 문서](https://nodejs.org/api/os.html)</p>
<p>실제 개발에서 많이 사용되는 모듈은 아니지만 운영체제와 시스템의 정보를 가져올 수 있는 모듈이다.</p>
<p>CPU, 메모리, 디스크 용량에 대한 정보를 확인할 때 사용한다.</p>
<p>


<p>

**주요 메소드**
- os.tmpdir(): 임시 저장 폴더 위치
- os.endianness(): CPU의 endianness(BE or LE)
- os.hostname(): 호스트(컴퓨터) 이름
- os.type(): 운영체제 이름
- os.platform(): 운영체제 플랫폼
- os.arch(): 운영체제 아키텍처
- os.release(): 운영체제 버전
- os.uptime(): 운영체제가 실행된 시간
- os.loadavg(): 로드 에버리지 정보를 담은 배열
- os.totalmem(): 시스템의 총 메모리
- os.freemem(): 시스템의 가용 메모리
- os.cpus(): CPU의 정보를 담은 객체. 세부 정보를 반환
- os.networkInterfaces(): 네트워크 인터페이스 정보를 담은 배열</p>

<p>

**OS 객체의 유일한 속성**
- os.EOL: 운영체제의 개행문자(\n과 같은)</p>

예제<br>
```javascript
var os = require('os');

console.log(os.tmpdir());
console.log(os.type());

var cpus = os.cpus();

for(var i = 0; i < cpus.length; i++) {
	console.log("CPU[" + (i+1) + "]");
	console.log("model: " + cpus[i].model);
	console.log("speed: " + cpus[i].speed);
}
```