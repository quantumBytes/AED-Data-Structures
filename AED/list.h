#ifndef LIST_H
#define LIST_H

#include "foundations.h"

template<typename T>
class list
{
    protected:
        Node<T> * m_pHead;
        sizet m_size;

    public:
        list() : m_pHead(0), m_size(0) {}
        virtual ~list() {}

        void push_front(T&);
        void push_back(T&);
        T& at(sizet);

        sizet size() {return m_size;}
};

#endif // LIST_H

template<typename T>
void list<T>::push_front(T&d)
{
    Node<T> * nu = new Node<T> (d);
    if(m_pHead)
        nu->m_pNext=m_pHead;
    m_pHead=nu;
    m_size++;
}

template<typename T>
void list<T>::push_back(T&d)
{
    Node<T> * nu = new Node<T> (d);

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

    Node<T> * tmp=m_pHead;
    while(position)
    {
        tmp=tmp->m_pNext;
        position--;
    }
    return tmp->m_dato;
}
