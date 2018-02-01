#include "SongBlock.h"

SongBlock::SongBlock() : ImageBlock()
{
    song_ = nullptr;
}

void SongBlock::setSong(Song *song)
{
    if(song_ != nullptr) {
        delete song_;
    }
    song_ = song;
}

Song* SongBlock::song(){
    return song_;
}
