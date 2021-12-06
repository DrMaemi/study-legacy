#include <iostream>
#include <vector>
#include <string>
using namespace std;

class People {
private:
    string name;
    int age;
    string belong;
public:
    void set(int _age, string _name, string _belong);
    void show();
    People() {
        cout << "=== 기본 생성자 호출 ===" << endl;
        age = 27;
        name = "이상현";
        belong = "kakao";
    }
    People(int _age, string _name, string _belong) {
        cout << "=== 생성자 호출 ===" << endl;
        age = _age;
        name = _name;
        belong = _belong;
    }
};

void People::set(int _age, string _name, string _belong) {
    age = _age;
    name = _name;
    belong = _belong;
}

void People::show() {
    cout << "나이: " << age << endl;
    cout << "이름: " << name << endl;
    cout << "소속: " << belong << endl;
}

vector<People> peoples;

int main(void) {
    // 기본 생성자 사용
    People* p = new People();
    //p[0].show();
    peoples.push_back(p[0]);
    for (int i=0; i<peoples.size(); i++) {
        peoples[i].show();  
    }
    return 0;
}