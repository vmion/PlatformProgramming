// Template.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;
// 함수템플릿
// C#에서의 Generic표현과 같은 방식
template<typename T>
T Plus(T a, T b)
{
    return a + b;
}

template<typename T, typename Q>
class Monster
{
public:
    T a;
    Q b;
public:
    Monster() {
        cout << a << endl;
        cout << b << endl;
    }
    Monster(T _a, Q _b) : a(_a), b(_b)
    {
        cout << a << endl;
        cout << b << endl;
    }
    virtual ~Monster() {  }
};

class Test
{
public:
    string name;
public:
    Test() {}
    Test(string str) : name(str) { cout << name.c_str() << endl; }
    virtual ~Test() {}
};

template<class T>
class classTemplate
{
public:
    T a;
    classTemplate() {}
    classTemplate(T _a) {}
    virtual ~classTemplate() {}
};
//
// 가상함수란? 
// virtual키워드로 정의한 함수
// 자식클래스에서 재정의 할 수 있는 함수
// 
// 순수 가상함수란?
// 함수의 정의가 없고 선언만으로 작성한 가상함수
// virtual void pureFunction() = 0;
// 
// 추상클래스란?
// 순수가상함수를 한개이상 포함한 클래스를 추상클래스라고 한다.
// 추상클래스는 객체를 생성할 수 없다.( 다형성을 적용할 수 있음 )
// 추상클래스를 상속받은 클래스는 무조건 함수를 재정의 해야 한다.

// 순수 가상함수로만 정의된 클래스는 인터페이스(Interface)의 역할을 한다.
class Action
{
public:
    virtual void Attack() = 0;
    virtual void Move() = 0;
    virtual void Run() = 0;
    virtual void ChangeAI() = 0;
};
class Character : public Action
{
public:
    int data1;
    float data2;
    string name;
public:
    Character() {}
    Character(const Character& character)   // 복사 생성자
    {
        data1 = character.data1;
        data2 = character.data2;
        name = character.name;
    }
    Character(const Character* pCharacter)   // 복사 생성자
    {
        data1 = pCharacter->data1;
        data2 = pCharacter->data2;
        name = pCharacter->name;
    }
    void DisplayData()
    {
        cout << data1 << "_" << data2 << "_" << name.c_str() << endl;
    }
    virtual ~Character() { }
    virtual void Attack() { }
    virtual void Move() { }
    virtual void Run() { }
    virtual void ChangeAI() { }
};

int main()
{
    // ***************************************
    // 함수템플릿 예제
    int result = Plus(10, 20);
    cout << result << endl;
    float fresult = Plus(10.3, 12.23);
    cout << fresult << endl;
    //
    cout << "*************Template예제" << endl;

    // ***************************************
    //클래스 template 예제
    Monster<int, float> mob1(10, 20.22);
    Monster<float, int> mob2(2.443, 20);
    //
    Monster<int, float>* pMob1 = new Monster<int, float>(10, 1.222);
    Monster<float, float>* pMob2 = new Monster<float, float>(2.333, 2.444);
    delete pMob1;
    delete pMob2;

    // ***************************************
    //클래스 template 예제
    classTemplate<Test> classTemplate;
    Test test("홍길동");
    classTemplate.a.name = test.name;
    cout << classTemplate.a.name << endl;

    // *************************************** 
    // 추상클래스 예제
    Character* pCharacter = new Character();
    //
    // 추상클래스의 다형성 적용
    Action* pCharacter2 = new Character();
    ((Character*)pCharacter2)->data1 = 100;
    ((Character*)pCharacter2)->data2 = 100.222;
    ((Character*)pCharacter2)->name = "안녕하세요";

    // ***************************************
    // 복사생성자 사용
    Action* pCharacter3 = new Character((Character*)pCharacter2);
    ((Character*)pCharacter3)->DisplayData();
    delete pCharacter;
    delete pCharacter2;
    delete pCharacter3;
}
