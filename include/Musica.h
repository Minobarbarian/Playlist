#ifndef MUSICA_H
#define MUSICA_H

//#include <iostream>
#include <string>

class Musica
{

private:
    std::string titulo;
    std::string artista;

public:

    Musica(std::string titulo, std::string artista);
    ~Musica();

    std::string getTitulo();
    void setTitulo(std::string titulo);

    std::string getArtista();
    void setArtista(std::string artista);

    /*void adicionarMusica(Musica *song);
    bool removerMusica(std::string nome_musica);
    void print_music();*/
};

#endif