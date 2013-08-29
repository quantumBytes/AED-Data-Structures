#ifndef LIST_H
#define LIST_H

#include "foundations.h"
#include <iostream>

using namespace std;

template<typename T>
class list
{
    typedef Node<T> Node_T;
    typedef Node_T* pNode_T;

    protected:
        pNode_T m_pHead;
        sizet m_size;

    private:
        bool inner_find(T&d, Node_T ** &);
        void add_rec(T&d,pNode_T& pCurrent);
        bool find_rec(T&d, pNode_T& pCurrent);
        void invert(pNode_T &father, pNode_T &son, pNode_T &grandSon);

    public:
        list() : m_pHead(0), m_size(0) {}
        virtual ~list() {}

        sizet size() {return m_size;}
        T& at(sizet);
        T& operator [](sizet position) {return at(position);}

        bool find(T&, Node_T ** &);

        void push_front(T&);
        void push_back(T&);
        void pop_front();
        void pop_back();
        void remove(T&);
        void add_rec(T&d) {return add_rec(d,m_pHead);}
        bool find_rec(T&d) {return find_rec(d,m_pHead);}
        void invert() {invert(m_pHead, m_pHead->m_pNext, m_pHead->m_pNext->m_pNext);}
        T& find_max();
        sizet count();
        list<T>* op_intersection(list<T> &second);
        list<T>* op_union(list<T> &second);
        sizet count(T &d);
};

template<typename T>
T& list<T>::at(sizet position)
{
    if(position>=m_size || position<0)
        throw 0;

    pNode_T tmp=m_pHead;
    while(position)
    {
        tmp=tmp->m_pNext;
        position--;
    }
    return tmp->m_dato;
}

template<typename T>
void list<T>::push_front(T &d)
{
    pNode_T nu = new Node_T (d);
    if(m_pHead)
        nu->m_pNext=m_pHead;
    m_pHead=nu;
    m_size++;
}

template<typename T>
void list<T>::push_back(T&d)
{
    pNode_T nu = new Node_T (d);

    if(!m_pHead)
        m_pHead=nu;
    else
    {
        pNode_T tmp= m_pHead;

        while(tmp->m_pNext)
            tmp=tmp->m_pNext;

        tmp->m_pNext=nu;
    }
    m_size++;
}

/** Starts looking up d since pointer */
template<typename T>
bool list<T>::inner_find(T&d, Node_T ** &pointer)
{
    while(*pointer)
    {
        if((*pointer)->m_dato==d)
            return true;
        pointer=&((*pointer)->m_pNext);
    }
    return false;
}

/** Looks up data d on the list, starting since head */
template<typename T>
bool list<T>::find(T&d, Node_T ** &pointer)
{
    pointer=&m_pHead;
    return inner_find(d,pointer);
}
//-------------------------a---------------------------
template<typename T>
void list<T>::pop_front()
{
    if(!m_pHead)
        return;

    pNode_T tmp=m_pHead;
    m_pHead=m_pHead->m_pNext;

    delete tmp;
    m_size--;
}
//-------------------------b---------------------------
template<typename T>
void list<T>::pop_back()
{
    if(!m_size)
        return;

    pNode_T tmp=m_pHead;
    pNode_T father;

    while(tmp->m_pNext)
    {
        father=tmp;
        tmp=tmp->m_pNext;
    }
    delete tmp;

    if(m_size!=1)
        father->m_pNext=0;
    m_size--;
}
//-------------------------c--------------------------
/** Removes all the Nodes with the same data than given d */
template<typename T>
void list<T>::remove(T&d)
{
    pNode_T *tmp = &m_pHead;
    pNode_T mem;

    while (inner_find(d, tmp))
    {
        mem=(*tmp);
        (*tmp)=(*tmp)->m_pNext;
        delete mem;
        m_size--;
    }
}
//-------------------------d----------------------------
/** ALGUIEN ARREGLE ESTO xD */
template<typename T>
void list<T>::add_rec(T&d, pNode_T& pCurrent)
{
    pNode_T nu=new Node_T(d);
    if(!pCurrent)
    {
        m_pHead=nu;
        m_size++;
        return;
    }
    if(!pCurrent->m_pNext)
    {
        pCurrent->m_pNext=nu;
        m_size++;
        return;
    }
    add_rec(d,pCurrent->m_pNext);
}
//---------------------------e----------------------------
template<typename T>
bool list<T>::find_rec(T&d, pNode_T& pCurrent)
{
    if(!pCurrent)
        return false;
    if(pCurrent->m_dato==d)
        return true;
    return find_rec(d, pCurrent->m_pNext);
}
//---------------------------f----------------------------
/** INOPERATIVO */
template<typename T>
void list<T>::invert(pNode_T &father, pNode_T &son, pNode_T &grandSon)
{/*
    son->m_pNext=father;
    std::cout<<son->m_dato<<std::endl;
    if(!grandSon->m_pNext)
    {
        grandSon->m_pNext=son;
        m_pHead->m_pNext=0;
        m_pHead=grandSon;

        return;
    }
    invert(son, grandSon, grandSon->m_pNext);*/
}

//---------------------------g----------------------------
//IMPLEMENTAR
template<typename T>
T& list<T>::find_max() {

}

//---------------------------h----------------------------
//IMPLEMENTAR
template<typename T>
sizet list<T>::count() { //Count por bucle, utilizar en el trabajo
    sizet i = 0;
    for(pNode_T tmp = m_pHead; tmp; tmp = tmp->m_pNext, i++);
    return i;
}

//---------------------------i----------------------------
//IMPLEMENTAR
template<typename T>
list<T>* list<T>::op_intersection(list<T> &second) {
    list<T> *ret = new list<T>;
    pNode_T t1 = m_pHead,
            *tmp;
    while(t1) {
        if (second.find(t1->m_dato, tmp))
            ret->add_rec(t1->m_dato);
        t1 = t1->m_pNext;
    }
    return ret;
}

//---------------------------j----------------------------
//IMPLEMENTAR
template<typename T>
list<T>* list<T>::op_union(list<T> &second) {

}

//---------------------------k----------------------------
//IMPLEMENTAR
template<typename T>
sizet list<T>::count(T &d) {

}

#endif // LIST_H
