#ifndef LISTA_H
#define LISTA_H

#include "Node.h"
#include <iostream>

//Criação do template
template <typename T>

class Lista
{
public:
    Node<T> *cabeca;
    Node<T> *cauda;
    int tamanho;

    Lista()
    {
        this->cabeca = nullptr;
        this->cauda = nullptr;
        this->tamanho = 0;
    }
    Lista(Lista &l)
    {

    }

    ~Lista()
    {
        while(tamanho) { remover(0); }
    }

    void inserir(T valor)
    {
        Node<T> *no = new Node<T>(valor);

        if (cabeca == nullptr)
        {
            cabeca = cauda = no;
            tamanho++;
        }
        else
        {
            cauda->proximo = no;
            cauda = no;
            tamanho++;
        }
    }

    Node<T> *busca(int n)
    {
        if (n < tamanho && n >= 0)
        {
            Node<T> *p = cabeca;

            for (int i = 0; i < n; i++)
            {
                p = p->proximo;
            }
            return p;
        }

        return nullptr;
    }

    void remover(int indice)
    {
        Node<T> *noAlvo = busca(indice);
        if(indice == 0)
        {
            cabeca = cabeca->proximo;
        }
        else
        {
            Node<T> *noAnterior = busca(indice - 1);
            noAnterior->proximo = noAlvo->proximo;
            if(noAlvo == cauda)
            {
                cauda = noAnterior;
            }
        }
        delete noAlvo;
        tamanho--;
    }

    void add_elementos(Lista &l)
    {
        for(int i = 0; i < l.tamanho; i++)
        {
            inserir(l.busca(i)->dado);
        }
    }

    void rem_elementos(Lista &l)
    {
        if(l.cabeca != nullptr)
        {
            for(int i = 0; i < l.tamanho; i++)
            {
                for(int j = 0; j < tamanho; j++)
                {
                    if(this->busca(j) == l.busca(i)) this->remover(j);
                }
                
            }
        }
    }

    Lista operator+(Lista &l2)
    {
        Lista l;
        for(int i = 0; i < this->tamanho; i++)
        {
            l.inserir(this->busca(i)->dado);
        }
        for(int i = 0; i < l2->tamanho; i++)
        {
            l.inserir(l2->busca(i)->dado);
        }
    }
    void operator>>(Node<T> *no)
    {
        no->dado = cauda->dado;
    }
};

#endif