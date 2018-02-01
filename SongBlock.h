#ifndef SONGBLOCK_H
#define SONGBLOCK_H

#include "Song.h"
#include "ImageBlock.h"

class SongBlock : public ImageBlock
{
public:
    SongBlock();
    void setSong(Song* song);
    Song* song();

private:
    Song* song_;
};

#endif // SONGBLOCK_H
