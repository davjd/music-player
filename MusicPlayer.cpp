#include "MusicPlayer.h"

MusicPlayer::MusicPlayer(): QMediaPlayer()
{
    list_ = new QList<Song>();
}

QList<Song>* MusicPlayer::list(){
    return list_;
}

void MusicPlayer::setList(){
    setPlaylist((*list_));
}

void MusicPlayer::insert(Song content){
    list_->append(content);
//    list_->addMedia(content);
}
