#ifndef MUSICA_H
#define MUSICA_H

//#include <iostream>
#include <string>

/*!
 *@brief Classe de Musica.
 *
 * Um objeto da classe Musica possui strings de título e nome de artista.
*/
class Musica
{

private:
    std::string titulo /*!< String referente ao título da Musica.*/;
    std::string artista; /*!< String referente ao nome do artista que produziu a Musica.*/;

public:

    /*!
     * @brief Construtor de Musica.
     * 
     * Cria uma Musica a partir de strings de título e nome de artista.
     * @param titulo Nome da Musica.
     * @param artista Nome do artista que produziu a Musica.
     */
    Musica(std::string titulo, std::string artista);

    /*!
     * @brief Desconstrutor de Musica.
     * 
     * Apaga as informações de string salvas da Musica.
     */
    ~Musica();

    /*!
     * @brief Retorna título de Musica.
     * 
     * Busca e retorna o título da Musica.
     * @return O título da Musica.
     */
    std::string getTitulo();

    /*!
     * @brief Salva título de Musica.
     * 
     * Recebe e salva o título recebido como o novo título da Musica.
     * @param titulo Um título de Musica.
     */
    void setTitulo(std::string titulo);

    /*!
     * @brief Retorna nome do artista da Musica.
     * 
     * Busca e retorna o nome do artista da Musica.
     * @return O nome do artista da Musica.
     */
    std::string getArtista();

    /*!
     * @brief Salva nome do artista da Musica.
     * 
     * Recebe e salva o nome do artista recebido como o novo nome do artista da Musica.
     * @param artista Um nome de artista de Musica.
     */
    void setArtista(std::string artista);
};

#endif