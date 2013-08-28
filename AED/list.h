#ifndef LIST_H
#define LIST_H

#include "foundations.h"

template<typename T>
class list
{
    typedef Node<T> Node_T;

    protected:
        Node_T * m_pHead;
        sizet m_size;

    public:
        list() : m_pHead(0), m_size(0) {}
        virtual ~list() {}

        bool find(T &d, Node_T **&p);
        void push_front(T&);
        void push_back(T&);
        T& at(sizet);

        sizet size() {return m_size;}
};

template<typename T>
bool list<T>::find(T &d, Node_T **&p) {
    p = &m_pHead;
    while(*p) {
        if((*p)->m_dato == d)
            return true;
        if((*p)->m_dato > d)
            return false;
        p = &((*p)->m_pNext);
    }
    return false;
}

template<typename T>
void list<T>::push_front(T&d)
{
    Node_T * nu = new Node_T(d);
    if(m_pHead)
        nu->m_pNext=m_pHead;
    m_pHead=nu;
    m_size++;
}

template<typename T>
void list<T>::push_back(T&d)
{
    Node_T * nu = new Node_T (d);

    if(!m_pHead)
        m_pHead=nu;
    else
    {
        Node<T> * tmp= m_pHead;

        while(tmp->m_pNext)
            tmp=tmp->m_pNext;

        tmp->m_pNext=nu;
    }
    m_size++;
}

template<typename T>
T& list<T>::at(sizet position)
{
    if(position>m_size)
        throw 0;

    Node_T * tmp = m_pHead;
    while(position)
    {
        tmp = tmp->m_pNext;
        position--;
    }
    return tmp->m_dato;
}

#endif // LIST_H
