#include "CList.h"
#include <iostream>
using namespace std;

//Template ������ �ƴ� ����
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
//���ϴ� �����͸� ã�Ƽ� ��带 ��ȯ����
Node* CList::Find(int data)
{
	Node* tmp = pHead->pNext;
	while (tmp != pTail)
	{
		if (tmp->data == data)
		{
			cout << "ã�� data = " << tmp->data << endl;
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
//���� ��� p�� �˰� �־�� �Ѵ�.
void CList::Remove(Node* p)
{
	if (p == pHead || p == pTail)
		return;
	p->pPrev->pNext = p->pNext;
	p->pNext->pPrev = p->pPrev;
	delete p;
}
//DisplayData�� �̿��Ͽ� ������ �����͸� ã�Ƽ� �� �κи� ����
//������ ���ϴ� �����Ͱ� ���ö����� �˻��Ͽ� �����Ͱ� ã������ ����
void CList::Remove(int data)
{
	Node* tmp = pHead->pNext;
	while (tmp != pTail)
	{
		if (tmp->data == data)
		{
			cout << "������ ������ = " << tmp->data << endl;
			//���� ���� ����κ��� �̸� ���������� ��
			tmp->pPrev->pNext = tmp->pNext;
			tmp->pNext->pPrev = tmp->pPrev;
			delete tmp;
			break;
		}
		tmp = tmp->pNext;
	}
}
//��ü ������ ����
//���� ������ ����
void CList::Clear()
{
	Node* s;
	Node* tmp;
	s = pHead->pNext;
	while (s != pTail)
	{		
		tmp = s;
		s = s->pNext;
		cout << "������ ������ = " << tmp->data << endl;
		tmp->pPrev->pNext = tmp->pNext;
		tmp->pNext->pPrev = tmp->pPrev;
		delete tmp;
	}
	pHead->pNext = pTail;
	pTail->pPrev = pHead;
}
//������ �˻��
void CList::DisplayData() 
{
	Node* tmp = pHead->pNext;
	while (tmp != pTail)
	{
		cout << tmp->data << endl;
		tmp = tmp->pNext;
	}
}