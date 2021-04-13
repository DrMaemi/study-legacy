# 한 눈에 끝내는 javascript & Node.js
[강좌 링크](https://swmaestro.goorm.io/learn/lecture/26925/%ED%95%9C-%EB%88%88%EC%97%90-%EB%81%9D%EB%82%B4%EB%8A%94-node-js)

## 목차
[0. 시작하기 앞서](#0-시작하기-앞서)<br>
[&nbsp; &nbsp; 0-1. 자바스크립트란?](#0-1-자바스크립트란?)<br>
[&nbsp; &nbsp; 0-2. 자바스크립트의 특징](#0-2-자바스크립트의-특징)<br>
[&nbsp; &nbsp; 0-3. 자바스크립트 엔진이란?](#0-3-자바스크립트-엔진이란?)<br>
[1. 자바스크립트](#1-자바스크립트)<br>
[&nbsp; &nbsp; 1-1. 기본 문법](#1-1-기본-문법)<br>
[&nbsp; &nbsp; 1-2. 연산자](#1-2-연산자)<br>
[&nbsp; &nbsp; 1-3. 데이터 타입](#1-3-데이터-타입)
[&nbsp; &nbsp; 1-4. 조건문](#1-4-조건문)

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

## 1. 자바스크립트
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