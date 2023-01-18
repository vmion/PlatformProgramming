//#pragma once
#ifndef _CLIST_H_
#define _CLIST_H_

struct Node
{
    int data;
    Node* pPrev;
    Node* pNext;
};
class CList
{
public:
    Node* pHead;
    Node* pTail;
public:
    CList();
    ~CList();
    void Insert(int data, Node* t);
    Node* Find(int data);
    void PushFront(int data);
    void PushBack(int data);
    void DisplayData();
    void Remove(Node* p);
    void Remove(int data);
    void Clear();
};
/*
template<typename T>
class Node
{
    T data;
    Node<T>* pPrev;
    Node<T>* pNext;
};

template<typename T>
class CList
{
public:
    Node<T>* pHead;
    Node<T>* pTail;
public:
    CList<T>();
    ~CList<T>();
    void Insert(T data, Node<T>* t);
    Node<T>* Find(T data);
    void PushFront(T data);
    void PushBack(T data);
    void DisplayData();
    void Remove(Node<T>* p);
    void Remove(T data);
    void Clear();
};
*/

#endif