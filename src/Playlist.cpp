#include "Playlist.h"
#include "Musica.h"
#include <string>
#include <iostream>

Playlist::Playlist(std::string nome)
{
    this->nome = nome;
    this->contador = 0;
}

Playlist::~Playlist()
{
    for(int i = 0; i < this->musicas.tamanho; i++)
    {
        this->musicas.remover(i);
    }
}

std::string Playlist::getNome()
{
    return this->nome;
}

void Playlist::setNome(std::string nome)
{
    this->nome = nome;
}

Lista<Musica *> Playlist::getMusicas()
{
    return this->musicas;
}

void Playlist::setMusicas(Lista<Musica *> musicas)
{
    this->musicas = musicas;
}

void Playlist::adicionarMusica(std::string titulo, std::string artista)
{
    Musica *musica = new Musica(titulo, artista);
    musicas.inserir(musica);
}

void Playlist::removerMusica(std::string titulo)
{
    for (int i = 0; i < musicas.tamanho; i++)
    {
        if (musicas.busca(i)->dado->getTitulo().compare(titulo) == 0)
        {
            musicas.remover(i);
        }
    }
}

Node<Musica *> Playlist::next_music()
{
    Node<Musica *> *proxima = musicas.busca(contador);
    if((contador+1) == musicas.tamanho)
    {
        return nullptr;
    }
    else
    {
        proxima = musicas.busca(++contador);
        return *proxima;
    }
}

void Playlist::print_musics()
{
    for(int i = 0; i < this->musicas.tamanho; i++)
    {
        std::cout << this->musicas.busca(i)->dado->getTitulo() << " - " << this->musicas.busca(i)->dado->getArtista() << std::endl;
    }
}