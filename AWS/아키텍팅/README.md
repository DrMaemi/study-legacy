# 아키텍팅 기법

## 고가용성 환경 생성
<p>최종 구성:</p>
<p>

- 로드 밸런서
- 여러 어플리케이션 서버
- 다중 가용 영역 데이터베이스
- 각 가용 영역의 NAT 게이트웨이
</p>
<p>→ 확장 가능하고 안정적이며 가용성이 뛰어남</p>

<br><br>

## AWS CloudFormation
<p>

</p>

<br><br>

## AWS Quick Start
<p>Quick Start에서 제시하는 템플릿에서 제공하는 아키텍처가 구상하고 있는 서비스의 아키텍처에 잘 들어맞는다면 그대로 구성</p>

<br><br>

## AWS OpsWorks
<p>인프라 및 배포 자동화를 위한 툴</p>
<p>AWS CloudFormation을 사용해 인프라(VPC, IAM 역할)를 구축하고, AWS OpsWorks Stacks를 사용해서 어플리케이션 계층을 배포한다.</p>

<br><br>

## Elastic Beanstalk
<p>

- 코드<br>
→ 사용자는 코드 작성에 집중(개발에만 집중)
- HTTP 서버, 어플리케이션 서버, 언어 인터프리터, 운영체제, 호스트에 대한 걱정 x <br>
→ Elastic Beanstalk이 다 알아서 해준다
</p>

## Amazon ElastiCache

## 