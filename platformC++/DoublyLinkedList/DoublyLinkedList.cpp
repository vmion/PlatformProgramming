// DoublyLinkedList.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.

#include <iostream>
#include "CList.h"
using namespace std;

int main()
{
    CList* pList = new CList();
    pList->Insert(10, pList->pTail);
    pList->Insert(20, pList->pTail);
    pList->Insert(30, pList->pTail);
    pList->Insert(40, pList->pTail);
    pList->Insert(50, pList->pTail);
    pList->DisplayData();

    cout << "*************** " << endl;
    pList->Find(30);
    pList->Find(0);

    cout << "*************** " << endl;
    pList->PushFront(5);
    pList->DisplayData();

    cout << "*************** " << endl;
    pList->PushBack(55);
    pList->DisplayData();

    cout << "*************** " << endl;
    pList->Remove(30);
    pList->DisplayData();

    cout << "*************** " << endl;
    pList->Clear();
    pList->DisplayData();    

    delete pList;
}