#include "MusicPlayer.h"
#include <QMediaPlaylist>

MusicPlayer::MusicPlayer(): QMediaPlayer()
{
    list_ = new QList<Song*>();
    playlist_ = new QMediaPlaylist;
}

QList<Song*>* MusicPlayer::list(){
    return list_;
}

void MusicPlayer::setList(){
    for(int i = 0, end = list_->size(); i < end; ++i){
        playlist_->addMedia(*(list_->at(i)));
    }
    setPlaylist(playlist_);
}

void MusicPlayer::insert(Song* content){
    list_->append(content);
//    list_->addMedia(content);
}
