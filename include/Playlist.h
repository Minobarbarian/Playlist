#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "Lista.h"
#include "Musica.h"

/*!
 *@brief Classe de Playlist.
 *
 * Um objeto da classe Playlist possui string de nome e uma Lista de ponteiros de Musica.
*/
class Playlist
{

private:
    std::string nome; /*!< String referente ao título da Playlist.*/;
    Lista<Musica *> musicas; /*!< A Lista de ponteiros de Musica da Playlist.*/;

public:

    /*!
     * @brief Construtor de Playlist.
     * 
     * Cria uma Playlist a partir de um nome de Playlist.
     * @param nome Nome da Playlist.
     */
    Playlist(std::string nome);

    /*!
     * @brief Construtor Cópia de Playlist.
     * 
     * Cria uma Playlist a partir de uma Playlist recebida.
     * @param p Um ponteiro de uma Playlist.
     */
    Playlist(Playlist* p);

    /*!
     * @brief Desconstrutor de Playlist.
     * 
     * Remove todos os ponteiros de Musica de uma Playlist.
     */
    ~Playlist();

    /*!
     * @brief Retorna nome da Playlist.
     * 
     * Busca e retorna o nome da Playlist.
     * @return O nome da Playlist.
     */
    std::string getNome();

    /*!
     * @brief Salva o nome de Playlist.
     * 
     * Recebe e salva o nome recebido como o novo nome da Playlist.
     * @param nome Um nome de Playlist.
     */
    void setNome(std::string nome);

    /*!
     * @brief Retorna Lista de ponteiros de Musica da Playlist.
     * 
     * Busca e retorna a Lista de ponteiros de Musica da Playlist.
     * @return A Lista de ponteiros de Musica da Playlist.
     */
    Lista<Musica *> getMusicas();

    /*!
     * @brief Salva a Lista de ponteiros de Musica da Playlist.
     * 
     * Recebe e salva uma Lista como a nova Lista de ponteiros de Musica da Playlist.
     * @param musicas Um ponteiro de uma Lista de ponteiros de Musica Playlist.
     */
    void setMusicas(Lista<Musica *>* musicas);

    /*!
     * @brief Criação e inserção de Musica.
     * 
     * Recebe strings capazes de criar uma Musica e salva a Musica criada na Lista de ponteiros de Musica da Playlist.
     * @param titulo Um título de uma Musica.
     * @param artista Um nome de artista de uma Musica.
     */
    void add_musica(std::string titulo, std::string artista);

    /*!
     * @brief Remoção de Musica.
     * 
     * Recebe string capazes de identificar uma Musica que será removida da Lista de ponteiros de Musica da Playlist.
     * @param nome_musica Um título de uma Musica.
     */
    void rem_musica(std::string nome_musica);

    /*!
     * @brief Inserção de Musica's.
     * 
     * Recebe um endereço de Playlist e salva os elementos da Lista dela na Lista da Playlist.
     * @param p Um endereço de Playlist.
     */
    void add_musicas(Playlist& p);

    /*!
     * @brief Remoção de Musica's.
     * 
     * Recebe um endereço de Playlist e remove os elementos da Lista da Playlist compatíveis aos da Lista da Playlist recebida.
     * @param p Um endereço de Playlist.
     */
    void rem_musicas(Playlist& p);

    /*!
     * @brief Impressão de Playlist.
     * 
     * Imprime todos os elementos da Lista da Playlist.
     */
    void print_musics();

    /*!
     * @brief Soma de Playlist's.
     * 
     * Retorna a Lista que representa a união das Lista's de duas Playlist's.
     * @param p1 Um endereço de uma Playlist.
     * @return Um ponteiro de uma Lista de ponteiros de Musica.
     */
    Lista<Musica *>* operator+(Playlist& p1);

    /*!
     * @brief Soma Playlist com Musica.
     * 
     * Retorna a Playlist resultante da inserção da Musica recebida na Lista da Playlist.
     * @param m Um ponteiro de uma Musica.
     * @return Uma Playlist.
     */
    Playlist operator+(Musica* m);

    /*!
     * @brief Subtração de Playlist's.
     * 
     * Retorna a Lista que representa a diferença das Lista's de duas Playlist's.
     * @param p1 Um endereço de uma Playlist.
     * @return Uma Lista de ponteiros de Musica.
     */
    Lista<Musica *> operator-(Playlist& p1);

    /*!
     * @brief Subtrai Musica de uma Playlist.
     * 
     * Retorna a Playlist resultante da remoção da Musica recebida na Lista da Playlist.
     * @param m Um endereço de uma Musica.
     * @return Uma Playlist.
     */
    Playlist operator-(Musica& m);

    /*!
     * @brief Extração de Musica.
     * 
     * Remove e copia a última Musica da Lista da Playlist, salvando-a como a Musica recebida.
     * @param m Um endereço de uma Musica.
     */
    void operator>>(Musica* m);

    /*!
     * @brief Inserção de Musica.
     * 
     * Recebe uma Musica e a insere na Lista da Playlist, se possível.
     * @param m Um ponteiro de uma Musica.
     */
    void operator<<(Musica* m);
};

#endif