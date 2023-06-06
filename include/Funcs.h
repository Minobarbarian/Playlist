#ifndef FUNCS_H
#define FUNCS_H

#include "Playlist.h"

/*!
 * @brief Gerenciamento de Musica.
 * 
 * Abre o menú de gerenciamento de Musica.
 * @param musics Um endereço de Lista Ligada de ponteiros de Musica.
*/
void manageMusics(Lista<Musica *>& musics);

/*!
 * @brief Gerenciamento de Playlists.
 * 
 * Abre o menú de gerenciamento de Playlists.
 * @param playlists Um endereço de Lista Ligada de ponteiros de Playlist.
*/
void managePlaylist(Lista<Playlist *>& playlists);

/*!
 * @brief Gerenciamento de Playlist.
 * 
 * Abre o menú de gerenciamento de uma Playlist específica.
 * @param p Um endereço de uma Playlist.
*/
void editPlaylist(Playlist& p);

#endif // FUNCS_H