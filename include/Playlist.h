#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "Lista.h"
#include "Musica.h"
#include <iostream>

class Playlist
{

private:
    std::string nome;
    Lista<Musica *> musicas;
    int contador;

public:

    Playlist(std::string nome);
    ~Playlist();

    std::string getNome();
    void setNome(std::string nome);

    Lista<Musica *> getMusicas();
    void setMusicas(Lista<Musica *> musicas);

    void adicionarMusica(std::string titulo, std::string artista);
    void removerMusica(std::string nome_musica);
    Node <Musica*> next_music();
    void print_musics();
};

#endif