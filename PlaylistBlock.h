#ifndef PLAYLISTBLOCK_H
#define PLAYLISTBLOCK_H

#include "ImageBlock.h"
#include "Playlist.h"

class PlaylistBlock : public ImageBlock
{
public:
    PlaylistBlock();

    void setPlaylist(Playlist* playlist);
    Playlist* playlist();

private:
    Playlist* playlist_;
};

#endif // PLAYLISTBLOCK_H
