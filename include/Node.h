#ifndef NODE_H
#define NODE_H

#include <iostream>

template <typename T>

class Node
{
public:
    T dado;
    Node *proximo;

    Node(T dado)
    {
        this->dado = dado;
        this->proximo = nullptr;
    }

    ~Node()
    {
        delete proximo;
    }

    //Node<T> *getNext() const { return this->proximo; }

};

#endif