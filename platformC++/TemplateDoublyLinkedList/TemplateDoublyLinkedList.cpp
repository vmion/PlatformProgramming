// TemplateDoublyLinkedList.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.

#include <iostream>
#include "TemplateDoublyLinkedList.h"
using namespace std;

int main()
{
    CList<float>* pList = new CList<float>();
    pList->Insert(10.1, pList->pTail);
    pList->Insert(20.2, pList->pTail);
    pList->Insert(30.3, pList->pTail);
    pList->Insert(40.4, pList->pTail);
    pList->Insert(50.5, pList->pTail);
    pList->DisplayData();

    cout << "*************** " << endl;
    pList->Find(30.3);
    pList->Find(0);

    cout << "*************** " << endl;
    pList->PushFront(5.55);
    pList->DisplayData();

    cout << "*************** " << endl;
    pList->PushBack(55.55);
    pList->DisplayData();

    cout << "*************** " << endl;
    pList->Remove(30.3);
    pList->DisplayData();

    cout << "*************** " << endl;
    pList->Clear();
    pList->DisplayData();

    delete pList;
}
