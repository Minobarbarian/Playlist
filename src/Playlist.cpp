#include "Playlist.h"
#include <iostream>

Playlist::Playlist(std::string nome)
{
    this->nome = nome;
}

Playlist::Playlist(Playlist* p)
{
    this->nome = p->nome;
    this->setMusicas(p->musicas);
}

Playlist::~Playlist()
{
    musicas.remove_nos();
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

void Playlist::setMusicas(Lista<Musica *>& musicas)
{
    this->musicas = musicas;
}

void Playlist::add_musica(std::string titulo, std::string artista)
{
    Musica *musica = new Musica(titulo, artista);
    musicas.inserir(musica);
}

void Playlist::rem_musica(std::string titulo)
{
    for (int i = 0; i < musicas.tamanho; i++)
    {
        if (musicas.busca(i)->dado->getTitulo().compare(titulo) == 0)
        {
            musicas.remover(i);
        }
    }
}

void Playlist::add_musicas(Playlist& p)
{
    this->getMusicas().add_nos(p.musicas);
    std::cout << "Tamanho pós add: " << this->musicas.tamanho << std::endl;
}

void Playlist::rem_musicas(Playlist& p)
{
    //this->getMusicas().rem_nos(p->getMusicas());
}

void Playlist::print_musics()
{
    for(int i = 0; i < this->musicas.tamanho; i++)
    {
        std::cout << this->musicas.busca(i)->dado->getTitulo() << " - " << this->musicas.busca(i)->dado->getArtista() << std::endl;
    }
}

Lista<Musica *> Playlist::operator+(Playlist& p1)
{
    Lista<Musica *> m(&this->musicas);
    for(int i = 0; i < p1.getMusicas().tamanho; i++)
    {
        int flag = 1;
        for(int j = 0; j < this->getMusicas().tamanho; j++)
        {
            if(p1.getMusicas().busca(i) == this->getMusicas().busca(j)) flag = 0;
        }
        if(flag)
        {
            m.inserir(p1.getMusicas().busca(i)->dado);
        } 
    }
    return m;
}

Playlist Playlist::operator+(Musica* m)
{
    Playlist p(this);
    p.getMusicas().inserir(m);
    return p;
}

Lista<Musica *> Playlist::operator-(Playlist& p1)
{
    Lista<Musica *> m;
    for(int i = 0; i < this->getMusicas().tamanho; i++)
    {
        int flag = 1;
        for(int j = 0; j < p1.getMusicas().tamanho; j++)
        {
            if(p1.getMusicas().busca(j) == this->getMusicas().busca(i)) flag = 0;
        }
        if(flag)
        {
            m.inserir(this->getMusicas().busca(i)->dado);
        }
    }
    return m;
}

Playlist Playlist::operator-(Musica& m)
{
    Playlist p(this);
    p.rem_musica(m.getTitulo());
    return p;
}

void Playlist::operator>>(Musica* m)
{
    m = this->getMusicas().cabeca == nullptr? nullptr : this->getMusicas().cauda->dado;
    this->rem_musica(this->getMusicas().cauda->dado->getTitulo());
}

void Playlist::operator<<(Musica* m)
{
    if(m != nullptr) this->add_musica(m->getTitulo(), m->getArtista());
}