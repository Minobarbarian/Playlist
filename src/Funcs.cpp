#include <string>

#include "Funcs.h"

void manageMusics(Lista<Musica *> &musics)
{
    std::string action;
    while (action != "0")
    {
        std::cout << "====================-Manage Musics-===================" << std::endl;
        std::cout << "1) Registrar nova música;\n";
        std::cout << "2) Remover música;\n";
        std::cout << "3) Listar músicas;\n";
        std::cout << "0) Voltar;\n";
        std::cout << "======================================================" << std::endl;
        std::cout << "Escolha uma opção: ";
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
                }
            }

            system("clear || cls");

        }

        if (action == "3")
        {
            for (int i = 0; i < musics.tamanho; i++)
            {
                std::cout << musics.busca(i)->dado->getTitulo() << " - " << musics.busca(i)->dado->getArtista() << std::endl;
            }
        }

    if (action == "0") break;
  }
  system("clear || cls");
}



void managePlaylist(Lista<Playlist *> playlists)
{
    std::string action;
    while (action != "0")
    {
        std::cout << "====================-Gerenciar Playlists-===================" << std::endl;
        std::cout << "1) Adicionar nova playlist;\n";
        std::cout << "2) Editar uma playlist;\n";
        std::cout << "3) Remover uma playlist;\n";
        std::cout << "4) Listar Playlists;\n";
        std::cout << "0) Voltar;\n";
        std::cout << "============================================================" << std::endl;
        std::cout << "Escolha uma opção: ";
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
            std::cout << "Insira o nome da playlist que será editada:" << std::endl;
            std::getline(std::cin, playlistName);
            for (int i = 0; i < playlists.tamanho; i++)
            {
                if (playlists.busca(i)->dado->getNome().compare(playlistName) == 0)
                {
                    editPlaylist(playlists.busca(i)->dado);
                }
            }
        }

        if (action == "3")
        {
            std::string playlistName;
            std::cout << "Insira o nome da playlist que será removida:" << std::endl;
            std::getline(std::cin, playlistName);

            for (int i = 0; i < playlists.tamanho; i++)
            {
                if (playlists.busca(i)->dado->getNome().compare(playlistName) == 0)
                {
                    playlists.remover(i);
                }
            }

        }

        if (action == "4")
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

void editPlaylist(Playlist *p)
{
    std::string action;
    while (action != "0")
    {
        std::cout << "====================-Manage " << p->getNome() << "-===================" << std::endl;
        std::cout << "1 - Inserir música" << std::endl;
        std::cout << "2 - Mover música" << std::endl;
        std::cout << "3 - Remover música" << std::endl;
        std::cout << "4 - Listar músicas da playlist" << std::endl;
        std::cout << "5 - Voltar" << std::endl;
        std::cout << "========================================================" << std::endl;
        std::cout << "Escolha uma opção: ";
        std::getline(std::cin, action);

        if (action == "1")
        {
            std::string musicName;
            std::string artistName;
            std::cout << "Insira o nome da música:" << std::endl;
            std::getline(std::cin, musicName);
            std::cout << "Insira o nome do artista da música:" << std::endl;      
            std::getline(std::cin, artistName);

            p->adicionarMusica(musicName,artistName);

            system("clear || cls");
        }

        if (action == "3")
        {
            std::string musicName;
            std::cout << "Insira o nome da música que será removida:" << std::endl;
            std::getline(std::cin, musicName);

            for (int i = 0; i < p->getMusicas().tamanho; i++)
            {
                if (p->getMusicas().busca(i)->dado->getTitulo().compare(musicName) == 0)
                {   
                    p->removerMusica(musicName);
                }
            }
            system("clear || cls");
        }

        if (action == "4")
        {

            p->print_musics(p->getMusicas().tamanho - 1);
        }

        if (action == "5")
        {
            break;
        }
    }
}