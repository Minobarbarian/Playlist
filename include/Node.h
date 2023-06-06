#ifndef NODE_H
#define NODE_H

#include <iostream>

/*!
 *@brief Classe de Node.
 *
 * Um Node faz parte de uma estrutura de dados onde cada Node aponta para um endereço de memória e recebe um valor.
*/
template <typename T>

class Node
{
public:
    T dado; /*!< Um valor genérico armazenado no Node.*/
    Node *proximo; /*!< O endereço do próximo Node armazenado num Node.*/

    /*!
     * @brief Construtor de Node.
     * 
     * Cria um Node a partir de um dado com endereço de próximo sendo nulo.
     * @param dado Um valor de genérico
     */
    Node(T dado)
    {
        this->dado = dado;
        this->proximo = nullptr;
    }

    /*!
     * @brief Desconstrutor de Node.
     * 
     * Delete o endereço do Node armazenado.
     */
    ~Node()
    {
        delete proximo;
    }

};

#endif