// platformC++.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;
//치환문을 이용한 매크로함수
#define SAFE_DELETE(x) if(x!=nullptr){delete x;x=nullptr;}
struct A
{
    int data;
    int* pData;
};
int main()
{    
    A* pArr[10];
    for (int i = 0; i < 10; i++)
    {
        pArr[i] = new A;
        pArr[i]->data = -1;
        pArr[i]->pData = new int;
        *(pArr[i]->pData) = i;
        cout << pArr[i] << endl;
    } 
    //to do
    for (int i = 0; i < 10; i++)
    {
        cout << *(pArr[i]->pData) << endl;
        
    }    
    //배열 원소 삭제
    for (int i = 0; i < 10; i++)
    {
        SAFE_DELETE(pArr[i]);
        cout << pArr[i] << endl;
    }
}