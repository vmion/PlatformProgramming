#include "CList.h"
#include <iostream>
using namespace std;

//Template 형식이 아닌 원형
CList::CList()
{
	pHead = new Node;
	pTail = new Node;
	pHead->pNext = pTail;
	pHead->pPrev = pHead;
	pTail->pNext = pTail;
	pTail->pPrev = pHead;
}
CList::~CList()
{
	delete pHead;
	delete pTail;
}
void CList::Insert(int data, Node* t)
{
	Node* pNewNode = new Node;
	pNewNode->data = data;
	t->pPrev->pNext = pNewNode;
	pNewNode->pPrev = t->pPrev;
	t->pPrev = pNewNode;
	pNewNode->pNext = t;
}
//원하는 데이터를 찾아서 노드를 반환해줌
Node* CList::Find(int data)
{
	Node* tmp = pHead->pNext;
	while (tmp != pTail)
	{
		if (tmp->data == data)
		{
			cout << "찾은 data = " << tmp->data << endl;
			return tmp;
		}
		tmp = tmp->pNext;
	}	
	return nullptr;	
}
void CList::PushFront(int data)
{
	Node* pNewNode = new Node;
	pNewNode->data = data;
	pHead->pNext->pPrev = pNewNode;
	pNewNode->pNext = pHead->pNext;	
	pHead->pNext = pNewNode;
	pNewNode->pPrev = pHead;
}
void CList::PushBack(int data)
{
	Node* pNewNode = new Node;
	pNewNode->data = data;
	pTail->pPrev->pNext = pNewNode;
	pNewNode->pPrev = pTail->pPrev;
	pTail->pPrev = pNewNode;
	pNewNode->pNext = pTail;
}
//지울 노드 p를 알고 있어야 한다.
void CList::Remove(Node* p)
{
	if (p == pHead || p == pTail)
		return;
	p->pPrev->pNext = p->pNext;
	p->pNext->pPrev = p->pPrev;
	delete p;
}
//DisplayData를 이용하여 삭제할 데이터를 찾아서 그 부분만 삭제
//헤드부터 원하는 데이터가 나올때까지 검색하여 데이터가 찾아지면 삭제
void CList::Remove(int data)
{
	Node* tmp = pHead->pNext;
	while (tmp != pTail)
	{
		if (tmp->data == data)
		{
			cout << "삭제한 데이터 = " << tmp->data << endl;
			//삭제 후의 연결부분을 미리 관계정리를 함
			tmp->pPrev->pNext = tmp->pNext;
			tmp->pNext->pPrev = tmp->pPrev;
			delete tmp;
			break;
		}
		tmp = tmp->pNext;
	}
}
//전체 데이터 삭제
//헤드와 테일은 남김
void CList::Clear()
{
	Node* s;
	Node* tmp;
	s = pHead->pNext;
	while (s != pTail)
	{		
		tmp = s;
		s = s->pNext;
		cout << "삭제한 데이터 = " << tmp->data << endl;
		tmp->pPrev->pNext = tmp->pNext;
		tmp->pNext->pPrev = tmp->pPrev;
		delete tmp;
	}
	pHead->pNext = pTail;
	pTail->pPrev = pHead;
}
//데이터 검사용
void CList::DisplayData() 
{
	Node* tmp = pHead->pNext;
	while (tmp != pTail)
	{
		cout << tmp->data << endl;
		tmp = tmp->pNext;
	}
}