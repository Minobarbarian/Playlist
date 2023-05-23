#include <iostream>
#include <string>

#include "Funcs.h"
#include "Playlist.h"

void manageMusics(Lista<Musica *> &musics)
{
    std::string action;
    while (action != "0")
    {
        std::cout << "====================-Manage Musics-===================" << std::endl;
        std::cout << "1) Register new music;\n";
        std::cout << "2) Remove music;\n";
        std::cout << "3) List musics;\n";
        std::cout << "0) Back;\n";
        std::cout << "======================================================" << std::endl;
        std::cout << "Choose your next action: ";
        std::getline(std::cin, action);

        if (action == "1")
        {
            std::string musicName;
            std::string artistName;
            std::cout << "Insira o nome da música:" << std::endl;
            std::getline(std::cin, musicName);
            std::cout << "Insira o nome do artista da música:" << std::endl;      
            std::getline(std::cin, artistName);

            Musica *music = new Musica(musicName,artistName);
            musics.inserir(music);

            system("clear || cls");
        }

        if (action == "2")
        {
            std::string musicName;
            std::cout << "Insira o nome da música que será removida:" << std::endl;
            std::getline(std::cin, musicName);

            for (int i = 0; i < musics.tamanho; i++)
            {
                if (musics.busca(i)->dado->getTitulo().compare(musicName) == 0)
                {
                    musics.remover(i);
                    delete musics.busca(i);
                }
            }

            system("clear || cls");

        }

        if (action == "3")
        {
            for (int i = 0; i < musics.tamanho; i++)
            {
                cout << musics.busca(i)->dado->getTitulo() << " - " << musics.busca(i)->dado->getArtista() << endl;
            }
        }

    if (action == "0") break;
  }
  system("clear || cls");
}

//void editPlaylist

void managePlaylist(Lista<Playlist *> &playlists)
{
    std::string action;
    while (action != "0")
    {
        std::cout << "====================-Manage Playlists-===================" << std::endl;
        std::cout << "1) Add new playlist;\n";
        std::cout << "2) Remove playlist;\n";
        std::cout << "3) List Playlists;\n";
        std::cout << "0) Back;\n";
        std::cout << "======================================================" << std::endl;
        std::cout << "Choose your next action: ";
        std::getline(std::cin, action);

        if (action == "1")
        {
            std::string playlistName;
            std::cout << "Insira o nome da playlist que será adicionada:" << std::endl;
            std::getline(std::cin, playlistName);
            Playlist *play = new Playlist(playlistName);
            playlists.inserir(play);
        }

        if (action == "2")
        {
            std::string playlistName;
            std::cout << "Insira o nome da playlist que será removida:" << std::endl;
            std::getline(std::cin, playlistName);

            for (int i = 0; i < playlists.tamanho; i++)
            {
                if (playlists.busca(i)->dado->getNome().compare(playlistName) == 0)
                {
                    playlists.remover(i);
                    delete playlists.busca(i);
                }
            }

        }

        if (action == "3")
        {
            for (int i = 0; i < playlists.tamanho; i++)
            {
                std::cout << playlists.busca(i)->dado->getNome() << std::endl;
            }
        }

        if (action == "0") break;

    }
    system("clear || cls");
}