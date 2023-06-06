#ifndef LISTA_H
#define LISTA_H

#include "Node.h"
#include <iostream>

/*!
 *@brief Classe de Lista Ligada.
 *
 * Uma Lista Ligada é uma estrutura de dados que organiza Nós em uma fila onde cada Nó aponta para um endereço de memória.
*/
template <typename T>

class Lista
{
public:
    Node<T> *cabeca; /*!< O primeiro Nó de uma Lista Ligada.*/
    Node<T> *cauda; /*!< O último Nó de uma Lista Ligada.*/
    int tamanho; /*!< Tamanho da Lista Ligada.*/

    /*!
     * @brief Construtor de Lista Ligada.
     * 
     * Cria uma Lista Ligada vazia e de tamanho 0.
     */
    Lista()
    {
        this->cabeca = nullptr;
        this->cauda = nullptr;
        this->tamanho = 0;
    }

    /*!
     * @brief Construtor Cópia de Lista Ligada.
     * 
     * Cria uma Lista Ligada a partir de outra Lista Ligada.
     * 
     * @param l Um ponteiro de uma Lista Ligada que deseja-se copiar.
     */
    Lista(Lista *l)
    {
        for(int i = 0; i < l->tamanho; i++)
        {
            this->inserir(l->busca(i)->dado);
        }
    }

    /*!
     * @brief Desconstrutor de Lista Ligada.
     * 
     * Remove os Nós de uma Lista Ligada até o tamanho dela ser 0.
     */
    ~Lista()
    {
        while(tamanho != 0) { remover(0); }
    }

    /*!
     * @brief Inserção de Nó.
     * 
     * Cria e insere um Nó genério numa Lista Ligada de Nós genéricos.
     * 
     * @param T Um valor genérico.
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
     * @brief Busca de Nós.
     * 
     * Percorre a Lista Ligada a procura de um Nó específico.
     * 
     * @param n Um inteiro que representa o índice do Nó desejado.
     * @return O ponteiro do endereço do Nó desejado.
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
     * @brief Remoção de Nó específico.
     * 
     * Remove um Nó específico de uma Lista Ligada.
     * 
     * @param n Um inteiro que representa o índice do Nó que deseja-se remover.
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
     * @brief Remoção de Nós indiscrimanatória.
     * 
     * Remove todos os Nós de uma Lista Ligada.
     */
    void remove_nos()
    {
        while(tamanho != 0)
        {
            remove(0);
        }
    }

    /*!
     * @brief Adição de Nós.
     * 
     * Concatena uma Lista Ligada nova na Lista Ligada original.
     * @param l Um endereço de uma Lista Ligada de tipo genérico.
     */
    void add_nos(Lista<T>& l)
    {
        this->cauda->proximo = l.cabeca;
        this->cauda = l.cauda;
        this->tamanho += l.tamanho;
        std::cout << this->tamanho << std::endl;
    }

    /*!
     * @brief Remoção de Nós discriminatória.
     * 
     * Remove todos os Nós de uma Lista Ligada que são compatíveis aos que estão noutra Lista Ligada.
     * @param l Um endereço de uma Lista Ligada de tipo genérico.
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
     * @brief Cria Lista Ligada a partir de outras duas.
     * 
     * Criação de Lista Ligada que representa união entre duas Listas.
     * @param l Um endereço de uma Lista Ligada de tipo genérico.
     * @return A Lista ligada que une os elementos de duas Listas numa só.
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
     * Copia o Nó da cauda da Lista Ligada e salva no Nó recebido por parâmetro, caso a Lista Ligada esteja vazia, salva nullptr no Nó recebido.
     * @param no Um endereço de Nó de tipo genérico.
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
     * @brief Inserção de Nó condicional.
     * 
     * Caso o Nó recebido não seja nullptr, insere o Nó recebido por parâmetro no fim da Lista Ligada.
     * @param no Um endereço de Nó de tipo genérico.
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