#include "Musica.h"

Musica::Musica(std::string titulo, std::string artista)
{
    this->titulo = titulo;
    this->artista = artista;
}

Musica::~Musica()
{
}

std::string Musica::getTitulo()
{
    return this->titulo;
}

std::string Musica::getArtista()
{
    return this->artista;
}

void Musica::setTitulo(std::string titulo)
{
    this->titulo = titulo;
}

void Musica::setArtista(std::string artista)
{
    this->artista = artista;
}