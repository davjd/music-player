#include "MusicPlayer.h"

MusicPlayer::MusicPlayer(): QMediaPlayer()
{
    list_ = new QList<Song*>();
}

QList<Song*>* MusicPlayer::songList(){
    return list_;
}

void MusicPlayer::setList(){
    QMediaPlaylist* p = new QMediaPlaylist();
    for(int i = 0, end = list_->size(); i < end; ++i){
        p->addMedia(*(list_->at(i)));
    }
    setPlaylist(p);
}

void MusicPlayer::insert(Song* content){
    list_->append(content);
}
