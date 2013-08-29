#ifndef FOUNDATIONS_H
#define FOUNDATIONS_H

#include <iostream>

typedef size_t sizet;

/** Basic Node Class with just one pointer to next Node */
template <typename T>
class Node
{
    public:
        T m_dato;
        Node<T> * m_pNext;

    public:
        Node(T&d) : m_dato(d), m_pNext(0) {}
        Node(T&d, Node<T> * next) : m_dato(d), m_pNext(next) {}
        virtual ~Node(){}
};

#endif // FOUNDATIONS_H
