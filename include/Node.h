#ifndef NODE_H
#define NODE_H

#include <iostream>

/*!
 *@brief Classe de Nó.
 *
 * Um Nó faz parte de uma estrutura de dados onde cada Nó aponta para um endereço de memória e recebe um valor.
*/
template <typename T>

class Node
{
public:
    T dado; /*!< Um valor genérico armazenado no Nó.*/
    Node *proximo; /*!< O endereço do próximo Nó armazenado num Nó.*/

    /*!
     * @brief Construtor de Nó.
     * 
     * Cria um Nó a partir de um dado com endereço de próximo sendo nulo.
     * @param T Um valor de genérico
     */
    Node(T dado)
    {
        this->dado = dado;
        this->proximo = nullptr;
    }

    /*!
     * @brief Desconstrutor de Nó.
     * 
     * Delete o endereço do Nó armazenado.
     */
    ~Node()
    {
        delete proximo;
    }

};

#endif