#include "MusicPlayer.h"

MusicPlayer::MusicPlayer(): QMediaPlayer()
{
    list_ = new QMediaPlaylist();
}

QMediaPlaylist* MusicPlayer::list(){
    return list_;
}

void MusicPlayer::setList(){
    setPlaylist(list_);
}

void MusicPlayer::insert(QMediaContent content){
    list_->addMedia(content);
}
