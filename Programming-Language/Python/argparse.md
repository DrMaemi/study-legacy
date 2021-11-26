# argparse: 명령행 옵션, 인자, 부속 명령을 위한 라이브러리

## 기본
<p>

```python
# argparse-test.py
import argparse
parser = argparse.ArgumentParser()
parser.parse_args()
```
</p>
<p>


```bash
$ python argparse-test.py # 아무 반응 없음
$ python argparse-test.py --help
usage: argparse-test.py [-h]

optional arguments:
  -h, --help  show this help message and exit
```
```bash
$ python argparse-test.py --verbose
usage: argparse-test.py [-h]
argparse-test.py: error: unrecognized arguments: --verbose
$ python argparse-test.py foo
usage: argparse-test.py [-h]
argparse-test.py: error: unrecognized arguments: foo
```
</p>

<br>

## 위치 인자
<p>

```python
# argparse-test.py
import argparse
parser = argparse.ArgumentParser()
parser.add_argument("echo")
args = parser.parse_args()

print(f"type(args): {type(args)}")
print(f"args: {args}")
print(f"type(args.echo): {type(args.echo)}")
print(f"args.echo: {args.echo}")
```
</p>
<p>

```bash
$ python argparse-test.py foo
type(args): <class 'argparse.Namespace'>
args: Namespace(echo='foo')
type(args.echo): <class 'str'>
args.echo: foo
```
</p>

<br>

## 옵션 인자
<p>

```python
# argparse-test.py
import argparse
parser = argparse.ArgumentParser()
parser.add_argument("-v", "--verbosity", help="increase output verbosity")
parser.add_argument("-d", "--direction", help="change direction")
args = parser.parse_args()

print(f"type(args): {type(args)}")
print(f"args: {args}")
print(f"type(args.verbosity): {type(args.verbosity)}")
print(f"args.verbosity: {args.verbosity}")
print(f"type(args.direction): {type(args.direction)}")
print(f"args.direction: {args.direction}\n")

if args.verbosity:
    print("verbosity turned on")
if args.direction:
    print(f"change direction to {args.direction}")
```
```bash
$ python argparse-test.py --verbosity 12 -d left
type(args): <class 'argparse.Namespace'>
args: Namespace(direction='left', verbosity='12')
type(args.verbosity): <class 'str'>
args.verbosity: 12
type(args.direction): <class 'str'>
args.direction: left

verbosity turned on
change direction to left
```
</p>