#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "Lista.h"
#include "Musica.h"

/*!
 *@brief Classe de Playlist.
 *
 * Um objeto da classe Playlist possui string de nome e uma Lista Ligada de ponteiros de Música.
*/
class Playlist
{

private:
    std::string nome; /*!< String referente ao título da Playlist.*/;
    Lista<Musica *> musicas; /*!< A Lista Ligada de ponteiros de Música da Playlist.*/;

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
     * Remove todos os ponteiros de Música de uma Playlist.
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
     * @brief Retorna Lista Ligada de ponteiros de Música da Playlist.
     * 
     * Busca e retorna a Lista Ligada de ponteiros de Música da Playlist.
     * @return A Lista Ligada de ponteiros de Música da Playlist.
     */
    Lista<Musica *> getMusicas();

    /*!
     * @brief Salva a Lista Ligada de ponteiros de Música da Playlist.
     * 
     * Recebe e salva uma Lista Ligada como a nova Lista Ligada de ponteiros de Música da Playlist.
     * @param musicas Um ponteiro de uma Lista Ligada de ponteiros de Música Playlist.
     */
    void setMusicas(Lista<Musica *>* musicas);

    /*!
     * @brief Criação e inserção de Música.
     * 
     * Recebe strings capazes de criar uma Música e salva a Música criada na Lista Ligada de ponteiros de Música da Playlist.
     * @param titulo Um título de uma Música.
     * @param artista Um nome de artista de uma Música.
     */
    void add_musica(std::string titulo, std::string artista);

    /*!
     * @brief Remoção de Música.
     * 
     * Recebe string capazes de identificar uma Música que será removida da Lista Ligada de ponteiros de Música da Playlist.
     * @param nome_musica Um título de uma Música.
     */
    void rem_musica(std::string nome_musica);

    /*!
     * @brief Inserção de Músicas.
     * 
     * Recebe um endereço de Playlist e salva os elementos da Lista Ligada dela na Lista Ligada da Playlist.
     * @param p Um endereço de Playlist.
     */
    void add_musicas(Playlist& p);

    /*!
     * @brief Remoção de Músicas.
     * 
     * Recebe um endereço de Playlist e remove os elementos da Lista Ligada da Playlist compatíveis aos da Lista Ligada da Playlist recebida.
     * @param p Um endereço de Playlist.
     */
    void rem_musicas(Playlist& p);

    /*!
     * @brief Impressão de Playlist.
     * 
     * Imprime todos os elementos da Lista Ligada da Playlist.
     */
    void print_musics();

    /*!
     * @brief Soma de Playlists.
     * 
     * Retorna a Lista Ligada que representa a união das Listas de duas Playlists.
     * @param p1 Um endereço de uma Playlist.
     * @return Um ponteiro de uma Lista Ligada de ponteiros de Música.
     */
    Lista<Musica *>* operator+(Playlist& p1);

    /*!
     * @brief Soma Playlist com Música.
     * 
     * Retorna a Playlist resultante da inserção da Música recebida na Lista Ligada da Playlist.
     * @param m Um ponteiro de uma Música.
     * @return Uma Playlist.
     */
    Playlist operator+(Musica* m);

    /*!
     * @brief Subtração de Playlists.
     * 
     * Retorna a Lista Ligada que representa a diferença das Listas de duas Playlists.
     * @param p1 Um endereço de uma Playlist.
     * @return Uma Lista Ligada de ponteiros de Música.
     */
    Lista<Musica *> operator-(Playlist& p1);

    /*!
     * @brief Subtrai Música de uma Playlist.
     * 
     * Retorna a Playlist resultante da remoção da Música recebida na Lista Ligada da Playlist.
     * @param m Um endereço de uma Música.
     * @return Uma Playlist.
     */
    Playlist operator-(Musica& m);

    /*!
     * @brief Extração de Música.
     * 
     * Remove e copia a última Música da Lista Ligada da Playlist, salvando-a como a Música recebida.
     * @param m Um endereço de uma Música.
     */
    void operator>>(Musica* m);

    /*!
     * @brief Inserção de Música.
     * 
     * Recebe uma Música e a insere na Lista Ligada da Playlist, se possível.
     * @param m Um ponteiro de uma Música.
     */
    void operator<<(Musica* m);
};

#endif