#ifndef MUSICA_H
#define MUSICA_H

//#include <iostream>
#include <string>

/*!
 *@brief Classe de Música.
 *
 * Um objeto da classe Música possui strings de título e nome de artista.
*/
class Musica
{

private:
    std::string titulo /*!< String referente ao título da Música.*/;
    std::string artista; /*!< String referente ao nome do artista que produziu a Música.*/;

public:

    /*!
     * @brief Construtor de Música.
     * 
     * Cria uma Música a partir de strings de título e nome de artista.
     * @param titulo Nome da Música.
     * @param artista Nome do artista que produziu a Música.
     */
    Musica(std::string titulo, std::string artista);

    /*!
     * @brief Desconstrutor de Música.
     * 
     * Apaga as informações de string salvas da Música.
     */
    ~Musica();

    /*!
     * @brief Retorna título de Música.
     * 
     * Busca e retorna o título da Música.
     * @return O título da Música.
     */
    std::string getTitulo();

    /*!
     * @brief Salva título de Música.
     * 
     * Recebe e salva o título recebido como o novo título da Música.
     * @param titulo Um título de Música.
     */
    void setTitulo(std::string titulo);

    /*!
     * @brief Retorna nome do artista da Música.
     * 
     * Busca e retorna o nome do artista da Música.
     * @return O nome do artista da Música.
     */
    std::string getArtista();

    /*!
     * @brief Salva nome do artista da Música.
     * 
     * Recebe e salva o nome do artista recebido como o novo nome do artista da Música.
     * @param artista Um nome de artista de Música.
     */
    void setArtista(std::string artista);
};

#endif