#include "PlaylistBlock.h"

PlaylistBlock::PlaylistBlock() : ImageBlock()
{
    playlist_ = new Playlist();
}

void PlaylistBlock::setPlaylist(Playlist* playlist)
{
    delete playlist_;
    playlist_ = playlist;
}

Playlist* PlaylistBlock::playlist()
{
    return playlist_;
}
