#ifndef LISTA_H
#define LISTA_H

#include "Node.h"
#include <iostream>

/*!
 *@brief Classe de Lista.
 *
 * Uma Lista é uma estrutura de dados que organiza Node em uma fila onde cada Node aponta para um endereço de memória.
*/
template <typename T>

class Lista
{
public:
    Node<T> *cabeca; /*!< O primeiro Node de uma Lista.*/
    Node<T> *cauda; /*!< O último Node de uma Lista.*/
    int tamanho; /*!< Tamanho da Lista.*/

    /*!
     * @brief Construtor de Lista.
     * 
     * Cria uma Lista vazia e de tamanho 0.
     */
    Lista()
    {
        this->cabeca = nullptr;
        this->cauda = nullptr;
        this->tamanho = 0;
    }

    /*!
     * @brief Construtor Cópia de Lista.
     * 
     * Cria uma Lista a partir de outra Lista.
     * 
     * @param l Um ponteiro de uma Lista que deseja-se copiar.
     */
    Lista(Lista *l)
    {
        for(int i = 0; i < l->tamanho; i++)
        {
            this->inserir(l->busca(i)->dado);
        }
    }

    /*!
     * @brief Desconstrutor de Lista.
     * 
     * Remove os Node de uma Lista até o tamanho dela ser 0.
     */
    ~Lista()
    {
        while(tamanho != 0) { remover(0); }
    }

    /*!
     * @brief Inserção de Node.
     * 
     * Cria e insere um Node genério numa Lista de Node genéricos.
     * 
     * @param valor Um valor genérico.
     */
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

    /*!
     * @brief Busca de Node.
     * 
     * Percorre a Lista a procura de um Node específico.
     * 
     * @param n Um inteiro que representa o índice do Node desejado.
     * @return O ponteiro do endereço do Node desejado.
     */
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

    /*!
     * @brief Remoção de Node específico.
     * 
     * Remove um Node específico de uma Lista.
     * 
     * @param indice Um inteiro que representa o índice do Node que deseja-se remover.
     */
    void remover(int indice)
    {
        Node<T> *noAlvo = this->busca(indice);
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
        noAlvo = nullptr;
        delete noAlvo;
        tamanho--;
    }

    /*!
     * @brief Remoção de Node indiscrimanatória.
     * 
     * Remove todos os Node de uma Lista.
     */
    void remove_nos()
    {
        while(tamanho != 0)
        {
            remove(0);
        }
    }

    /*!
     * @brief Adição de Node.
     * 
     * Concatena uma Lista nova na Lista original.
     * @param l Um endereço de uma Lista de tipo genérico.
     */
    void add_nos(Lista<T>& l)
    {
        this->cauda->proximo = l.cabeca;
        this->cauda = l.cauda;
        this->tamanho += l.tamanho;
        std::cout << this->tamanho << std::endl;
    }

    /*!
     * @brief Remoção de Node discriminatória.
     * 
     * Remove todos os Node de uma Lista que são compatíveis aos que estão noutra Lista.
     * @param l Um endereço de uma Lista de tipo genérico.
     */
    void rem_nos(Lista<T>& l)
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

    /*!
     * @brief Cria Lista a partir de outras duas.
     * 
     * Criação de Lista que representa união entre duas Listas.
     * @param l1 Um endereço de uma Lista de tipo genérico.
     * @return A Lista que une os elementos de duas Listas numa só.
     */
    Lista operator+(Lista<T>& l1)
    {
        Lista l(*this);
        l.add_nos(l1);
        return l;
    }

    /*!
     * @brief Extração de Cauda.
     * 
     * Copia o Node da cauda da Lista e salva no Node recebido por parâmetro, caso a Lista esteja vazia, salva nullptr no Node recebido.
     * @param no Um endereço de Node de tipo genérico.
     */
    void operator>>(Node<T>& no)
    {
        if(cabeca == nullptr)
        {
            no = cabeca;
        }
        else
        {
            no->proximo = cauda->proximo;
            no->dado = cauda->dado;
        }
    }

    /*!
     * @brief Inserção de Node condicional.
     * 
     * Caso o Node recebido não seja nullptr, insere o Node recebido por parâmetro no fim da Lista.
     * @param no Um endereço de Node de tipo genérico.
     */
    void operator<<(Node<T>& no)
    {
        if(no != nullptr)
        {
            this->inserir(no.dado);
        }
    }

    
};

#endif