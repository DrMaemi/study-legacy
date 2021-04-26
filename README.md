# 한 눈에 끝내는 javascript & Node.js
<div align="right">

[강좌 링크](https://swmaestro.goorm.io/learn/lecture/26925/%ED%95%9C-%EB%88%88%EC%97%90-%EB%81%9D%EB%82%B4%EB%8A%94-node-js)</div>

## 목차
<p>

[0. 시작하기 앞서](#0-시작하기-앞서)<br>
&nbsp; &nbsp; [0-1. 자바스크립트란?](#0-1-자바스크립트란?)<br>
&nbsp; &nbsp; [0-2. 자바스크립트의 특징](#0-2-자바스크립트의-특징)<br>
&nbsp; &nbsp; [0-3. 자바스크립트 엔진이란?](#0-3-자바스크립트-엔진이란?)</p>
<p>

[1. 자바스크립트 기초](#1-자바스크립트-기초)<br>
&nbsp; &nbsp; [1-1. 기본 문법](#1-1-기본-문법)<br>
&nbsp; &nbsp; [1-2. 연산자](#1-2-연산자)<br>
&nbsp; &nbsp; [1-3. 데이터 타입](#1-3-데이터-타입)<br>
&nbsp; &nbsp; [1-4. 조건문](#1-4-조건문)<br>
&nbsp; &nbsp; [1-5. 반복문](#1-5-반복문)<br>
&nbsp; &nbsp; [1-6. 함수](#1-6-함수)</p>
<p>

[2. 객체지향 자바스크립트](#2-객체지향-자바스크립트)<br>
&nbsp; &nbsp; [2-1. 클래스](#2-1-클래스)<br>
&nbsp; &nbsp; [2-2. 생성자](#2-2-생성자)<br>
&nbsp; &nbsp; [2-3. 캡슐화](#2-3-캡슐화)<br>
&nbsp; &nbsp; [2-4. 집합](#2-4-집합)<br>
&nbsp; &nbsp; [2-5. 상속](#2-5-상속)<br>
&nbsp; &nbsp; [2-6. 스코프와 호이스팅](#2-6-스코프와-호이스팅)<br>
&nbsp; &nbsp; [2-7. 클로저](#2-7-클로저)</p>
<p>

[3. 자료구조]
&nbsp; &nbsp; [3-1. Map](#3-1-Map)
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

## 3. 자료구조
### 3-1. Map
<p>key-value 쌍으로 데이터를 저장한다. 자바스크립트의 객체 자료구조와 다른 점은 key로서 다양한 자료형을 허용한다.</p>

코드<br>
```javascript
var m = new Map();
m.set('key1', 'val1');    // key-value 쌍 데이터 저장
m.get('key1');              // key1 에 해당하는 value 반한
m.has('key1');              // key1이 맵에 존재하면 true 반환, 그렇지 않으면 false 반환
m.delete('key1');           // key에 해당하는 값 삭제, 성공 시 true 그렇지 않으면 false 반환
m.clear();                  // 맵 내 모든 데이터 삭제
m.size;                     // 맵 내 모든 데이터 쌍의 개수 반환
```
결과<br>
```
"val1"
true
true
0
```