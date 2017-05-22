#include "MusicPlayer.h"

MusicPlayer::MusicPlayer(): QMediaPlayer()
{
    list_ = new QVector<Song*>();
    index_ = -1;
}

QVector<Song*>* MusicPlayer::songList(){
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
    list_->push_back(content);
//    list_->append(content);
}

unsigned int MusicPlayer::index(){
    return index_;
}

void MusicPlayer::next(){

}

void MusicPlayer::previous(){

}

void MusicPlayer::toggleRepeat(){

}

void MusicPlayer::toggleShuffle(){

}

void MusicPlayer::add(Song *song){
//    list_->append();
}

