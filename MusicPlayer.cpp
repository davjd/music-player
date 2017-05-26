#include "MusicPlayer.h"
#include <random>
#include <algorithm>

MusicPlayer::MusicPlayer(): QMediaPlayer()
{

    list_ = new QVector<Song*>();
    shuffledList_ = new QVector<int>();
    shuffleOn_ = false;
    repeatState_ = Repeat::off;
    index_ = -1;
    length_ = -1;
}

MusicPlayer::~MusicPlayer(){
    delete list_;
    delete shuffledList_;
}

void MusicPlayer::initializeContent(){
    /*

        Initialized the QMediaPlayer's mediaContet.
        This will also initialize all signals and slots required.

    */
    setMedia((*list_->at(0)));

    connect(this, &QMediaPlayer::mediaStatusChanged, [this](QMediaPlayer::MediaStatus status){
        if(status == QMediaPlayer::EndOfMedia){
            qDebug() << "End of song.. Loading next..";
            loadedNext();
        }
    });

//    connect(player, &QMediaPlayer::mediaStatusChanged, [this](QMediaPlayer::MediaStatus status){
//        if(status == QMediaPlayer::EndOfMedia){
//            qDebug() << "End of song.. Loading next..";
//            loadedNext();
//        }
//    });


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
    ++length_;
    list_->push_back(content);
    shuffledList_->push_back(length_);
}

void MusicPlayer::remove(const int idx){
    list_->remove(idx);
    shuffledList_->removeOne(idx);
    --length_;
}

int MusicPlayer::index(){
    return index_;
}

int MusicPlayer::length(){
    return length_;
}

bool MusicPlayer::hasPlayed(){
    return (index_!= -1);
}

void MusicPlayer::next(){
    int idx = nextIndex();
    if(idx != -1){
        setMedia((*list_->at(nextIndex())));
    }
}

void MusicPlayer::previous(){
    int idx = nextIndex();
    if(idx != -1){
        setMedia((*list_->at(previousIndex())));
    }
}

void MusicPlayer::toggleRepeat(){
    if(repeatState_ == Repeat::off){
        repeatState_ = Repeat::single;
    }
    else if(repeatState_ == Repeat::single){
        repeatState_ = Repeat::list;
    }
    else repeatState_ = Repeat::off;
}

void MusicPlayer::shuffle(){
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(shuffledList_->begin(), shuffledList_->end(), g);
}

void MusicPlayer::toggleShuffle(){
    if(length_ < 0) return;

    if(shuffleOn_){
        shuffleOn_ = false;
    } else{
        shuffleOn_ = true;
        shuffle();
        index_ = 0;
    }
}

MusicPlayer::Repeat MusicPlayer::repeatState(){
    return repeatState_;
}

bool MusicPlayer::isShuffled(){
    return shuffleOn_;
}

int MusicPlayer::nextIndex(){
    /*
        possible cases:
            shuffle OFF/ON:
                -repeat: OFF
                -repeat: individual --> only with loadedNext().
                -repeat: list
    */

    if(shuffleOn_){
        if(repeatState_ == Repeat::off){
            if(index_ < length_) return -1;
            else return shuffledList_->at(++index_);
        }
        else{
            if(index_ >= length_) index_ = 0;
            else ++index_;

            return shuffledList_->at(index_);
        }
    }
    else{

        if(repeatState_ == Repeat::off){
            if(index_ < length_) return ++index_;
            else return -1;
        }
        else{
            if(index_ < length_) return ++index_;
            else return 0;
        }
    }
}

int MusicPlayer::previousIndex(){
    if(shuffleOn_){
        if(repeatState_ == Repeat::off){
            if(index_ > 0) return shuffledList_->at(--index_);
            else return -1;
        }
        else{
            if(index_ <= 0) index_ = length_;
            else --index_;

            return shuffledList_->at(index_);
        }
    }
    else{
        if(repeatState_ == Repeat::off){
            if(index_ <= 0 ) return -1;
            else return --index_;
        }
        else{
            if(index_ > 0) return --index_;
            else return length_;
        }
    }
}

void MusicPlayer::insert(QVector<Song *> *content){
    index_ = -1;
    length_ = -1;

    list_->clear();
    shuffledList_->clear();

    for(int i = 0; i < content->size(); ++i){
        insert(content->at(i));
    }
}

void MusicPlayer::loadedNext(){
    // this is like next(), but occurs when the song is finished
    // unlike next(), which occurs when next-button is clicked.
    if(repeatState_ == Repeat::single){
        setMedia((*list_->at(index_)));
    }
    else{
        next();
    }
}


