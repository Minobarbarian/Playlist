#include "Musica.h"
#include "Playlist.h"
#include "Funcs.h"

#include <string>
#include <iostream>
#include <fstream>

int main(int argc, char** argv)
{
    Lista<Musica *> musics;
    Lista<Playlist *> playlists;

    std::ifstream in("Arquivo.txt");
    //std::ofstream out(argv[1]);

    
    std::string line;

    while(getline(in,line))
    {
        std::size_t pos = line.find(";");
        Playlist *play = new Playlist(line.substr(0,pos));

        playlists.inserir(play);
        std::string resto, musica;
        std::size_t pos1,pos2;
        resto = line.substr(pos+1);
        
        while(resto.find(",") != std::string::npos || resto.find(":") != std::string::npos)
        {
            pos1 = resto.find(",");
            musica = resto.substr(0,pos1);
            pos2 = musica.find(":");
            play->add_musica(musica.substr(0,pos2),musica.substr(pos2+1));
            if(resto.find(",") != std::string::npos) resto = resto.substr(pos1+1);
            else break;
        }
    }

    

    std::string option;
    while (option != "0")
    {
        std::cout << "==========================-Menu-======================" << std::endl;
        std::cout << "1) Manage musics;\n";
        std::cout << "2) Manage playlists;\n";
        std::cout << "0) Exit the program.\n";
        std::cout << "======================================================" << std::endl;
        std::cout << "Choose your next action: ";
        std::getline(std::cin, option);

        if (option == "1") { manageMusics(musics); }

        if (option == "2") { managePlaylist(playlists); }
  }

  system("clear || cls");
}