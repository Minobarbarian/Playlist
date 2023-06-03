#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "Lista.h"
#include "Musica.h"

class Playlist
{

private:
    std::string nome;
    Lista<Musica *> musicas;
    int contador;

public:

    Playlist(std::string nome);
    Playlist(Playlist *p);
    ~Playlist();

    std::string getNome();
    void setNome(std::string nome);

    Lista<Musica *> getMusicas();
    void setMusicas(Lista<Musica *> musicas);

    void add_musica(std::string titulo, std::string artista);
    void rem_musica(std::string nome_musica);

    void add_musicas(Playlist *p);
    void rem_musicas(Playlist *p);

    Node <Musica*> next_music();
    void print_musics();

    Lista<Musica *> operator+(Playlist *p1);
    Playlist operator+(Musica *m);

    Lista<Musica *> operator-(Playlist *p1);
    Playlist operator-(Musica *m);

    void operator>>(Musica *m);
    void operator<<(Musica *m);
};

#endif