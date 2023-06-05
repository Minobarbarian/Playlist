#include <string>

#include "Funcs.h"

void manageMusics(Lista<Musica *> &musics)
{
    std::string action;
    while (action != "0")
    {
        std::cout << "====================-Manage Musics-===================" << std::endl;
        std::cout << "1) Registrar nova música;" << std::endl;
        std::cout << "2) Remover música;" << std::endl;
        std::cout << "3) Listar músicas;" << std::endl;
        std::cout << "0) Voltar;" << std::endl;
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
                    break;
                }
            }
            //std::cout << musics.busca(0)->dado->getTitulo() << std::endl;

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
        std::cout << "1) Adicionar nova playlist;"  << std::endl;
        std::cout << "2) Editar uma playlist;"  << std::endl;
        std::cout << "3) Mover música" << std::endl;
        std::cout << "4) Remover uma playlist;"  << std::endl;
        std::cout << "5) Listar Playlists;"  << std::endl;
        std::cout << "0) Voltar;"  << std::endl;
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
            system("clear || cls");
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
            system("clear || cls");
        }

        if(action == "3")
        {
            std::string origem, destino, mNome,aNome;
            std::cout << "Insira o nome da playlist origem:" << std::endl;
            std::getline(std::cin, origem);
            std::cout << "Insira o nome da música:" << std::endl;
            std::getline(std::cin, mNome);
            std::cout << "Insira o nome da playlist destino:" << std::endl;
            std::getline(std::cin, destino);
            Playlist *o;
            Playlist *d;
            
            for(int i = 0; i < playlists.tamanho; i++)
            {
                if(playlists.busca(i)->dado->getNome().compare(origem) == 0) o = playlists.busca(i)->dado;
                if(playlists.busca(i)->dado->getNome().compare(destino) == 0) d = playlists.busca(i)->dado;
            }
            for(int i = 0; i < o->getMusicas().tamanho; i++)
            {
                if(o->getMusicas().busca(i)->dado->getTitulo().compare(mNome) == 0)
                {
                    aNome = o->getMusicas().busca(i)->dado->getArtista();
                    break;
                }
            }
            o->rem_musica(mNome);
            d->add_musica(mNome, aNome);
            system("clear || cls");
        }

        if (action == "4")
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
            system("clear || cls");
        }

        if (action == "5")
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
        std::cout << "2 - Remover música" << std::endl;
        std::cout << "3 - Listar músicas da playlist" << std::endl;
        std::cout << "0 - Voltar" << std::endl;
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

            p->add_musica(musicName,artistName);

            system("clear || cls");
        }

        if (action == "2")
        {
            std::string musicName;
            std::cout << "Insira o nome da música que será removida:" << std::endl;
            std::getline(std::cin, musicName);

            p->rem_musica(musicName);

            system("clear || cls");
        }

        if (action == "3")
        {
            p->print_musics();
        }

        if (action == "0") { break; }
    }
    system("clear || cls");
}