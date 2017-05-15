#include "MusicPlayer.h"
#include <QMediaPlaylist>

MusicPlayer::MusicPlayer(): QMediaPlayer()
{
    list_ = new QList<Song*>();
}

QList<Song*>* MusicPlayer::list(){
    return list_;
}

void MusicPlayer::setList(){
    QMediaPlaylist* p;
    for(int i = 0, end = list_->size(); i < end; ++i){
        p->addMedia(*(list_->at(i)));
    }
    setPlaylist(p);
}

void MusicPlayer::insert(Song* content){
    list_->append(content);
//    list_->addMedia(content);
}
