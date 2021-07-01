# Data-Format

## XML, JSON, YAML 비교
### XML
<p>

- 태그 형식을 통해 Key와 Value 구분
- 태그 안에 태그를 넣어 부모-자식 관계 구조 표현
- object와 array를 명시적으로 구분하진 않음
</p>
<p>

```xml
<?xml version="1.0" encoding="UTf-8" ?>
<root>
  <apiVersion>v1</apiVersion>
  <kind>Pod</kind>
  <metadata>
    <name>hello-pod</name>
    <labels>
      <app>hello</app>
    </labels>
  </metadata>
  <spec> // object
    <containers> // array
      <name>hello-container</name>
      <image>tmkube/hello</image>
      <ports>
        <containerPort>8000</containerPort>
      </ports>
    </containers>
  </spec>
</root>
```
</p>

### JSON
<p>

- object일 경우 `{}`로 감싸고, array일 경우 `[]`로 감싸 표현
</p>
<p>

```json
{
  "apiVersion": "v1",
  "kind": "Pod",
  "metadata": {
    "name": "hello-pod",
    "labels": {
      "app": "hello"
    }
  },
  "spec": {
    "containers": [
      {
        "name": "hello-container",
        "image": "tmkube/hello",
        "ports": [
          {
            "containerPort": 8000
          }
        ]
      }
    ]
  }
}
```
</p>

### YAML
<p>

- `-`(하이픈)을 통해 array 명시
</p>
<p>

```yaml
apiVersion: v1
kind: PPod
metadata:
  name: hello-pod
  labels:
    app: hello
  spec:
    containers:
    - name: hello-container
      image: tmkube/hello
      ports:
      - containerPort: 8000
```
</p>