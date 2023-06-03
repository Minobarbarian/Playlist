#ifndef FUNCS_H
#define FUNCS_H

#include "Musica.h"
#include "Lista.h"
#include "Playlist.h"

/**
 * @brief Entra na primeira opção do menu
 * 
*/
void manageMusics(Lista<Musica *> &musics);

void managePlaylist(Lista<Playlist *> playlists);

void editPlaylist(Playlist *p);

#endif // FUNCS_H