//#pragma once
#ifndef _CLIST_H_
#define _CLIST_H_

#include<iostream>
using namespace std;
template<typename T>
class Node
{
public:
    T data;
    Node<T>* pPrev;
    Node<T>* pNext;
    Node() {}
    ~Node() {}
};
template<typename T>
class CList
{
public:
    Node<T>* pHead;
    Node<T>* pTail;
public:
    CList()
    {
        pHead = new Node<T>();
        pTail = new Node<T>();
        pHead->pNext = pTail;
        pHead->pPrev = pHead;
        pTail->pPrev = pHead;
        pTail->pNext = pTail;
    };
    ~CList()
    {
        delete pHead;
        delete pTail;
    }
    void Insert(T data, Node<T>* t) {
        Node<T>* pNewNode = new Node<T>();
        pNewNode->data = data;
        t->pPrev->pNext = pNewNode;
        pNewNode->pPrev = t->pPrev;
        t->pPrev = pNewNode;
        pNewNode->pNext = t;
    }
    Node<T>* Find(T data)
    {
        Node<T>* tmp = pHead->pNext;
        while (tmp != pTail)
        {
            if (tmp->data == data)
            {
                return tmp;
            }
            tmp = tmp->pNext;
        }
        return nullptr;
    }
    void PushFront(T data) 
    {
        Node<T>* pNewNode = new Node<T>;
        pNewNode->data = data;        
        pHead->pNext->pPrev = pNewNode;
        pNewNode->pNext = pHead->pNext;
        pHead->pNext = pNewNode;
        pNewNode->pPrev = pHead;
    }
    void PushBack(T data) 
    {
        Node<T>* pNewNode = new Node<T>;
        pNewNode->data = data;
        pTail->pPrev->pNext = pNewNode;
        pNewNode->pPrev = pTail->pPrev;
        pNewNode->pNext = pTail;
        pTail->pPrev = pNewNode;
    }
    void Remove(Node<T>* p)
    {
        if (p == pHead || p == pTail)
            return;
        p->pPrev->pNext = p->pNext;
        p->pNext->pPrev = p->pPrev;
        delete p;
    }
    void Remove(T data)
    {
        Node<T>* tmp = pHead->pNext;
        while (tmp != pTail)
        {
            if (tmp->data == data)
            {
                cout << "삭제한 데이터=" << tmp->data << endl;
                tmp->pPrev->pNext = tmp->pNext;
                tmp->pNext->pPrev = tmp->pPrev;
                delete tmp;
                return;
            }
            tmp = tmp->pNext;
        }
    }
    void Clear()
    {
        Node<T>* s;
        Node<T>* tmp;
        s = pHead->pNext;
        while (s != pTail)
        {
            tmp = s;
            s = s->pNext;
            cout << "지운데이터" << tmp->data << endl;
            tmp->pPrev->pNext = tmp->pNext;
            tmp->pNext->pPrev = tmp->pPrev;
            delete tmp;
        }
    }
    void DisplayData()
    {
        Node<T>* tmp = pHead->pNext;
        while (tmp != pTail)
        {
            cout << tmp->data << endl;
            tmp = tmp->pNext;
        }
    }
};

#endif