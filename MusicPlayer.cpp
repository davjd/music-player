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
    setMedia((*list_->at(increment())));

    connect(this, &QMediaPlayer::mediaStatusChanged, [this](QMediaPlayer::MediaStatus status){
        if(status == QMediaPlayer::EndOfMedia){
            qDebug() << "End of song.. Loading next..";
            loadedNext();
        }
    });
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

int MusicPlayer::songIndex(){
    // the difference between index() and this
    // is that this will take into account if the playlist
    // is shuffled, returning its true index on the songList.
    if(shuffleOn_) return shuffledList_->at(index_);
    else return index_;
}

int MusicPlayer::length(){
    return length_;
}

bool MusicPlayer::hasPlayed(){
    return (index_ != -1);
}

void MusicPlayer::next(){
    if(repeatState_ == Repeat::off || repeatState_ == Repeat::single){
        if(index_ == length_) return;
    }




    int idx = nextIndex();
    qDebug() << "Next idx: " << idx;
    if(idx != -1){
        setMedia((*list_->at(idx)));
    }
}

void MusicPlayer::previous(){
    int idx = previousIndex();
    qDebug() << "Previous idx: " << idx;
    if(idx != -1){
        setMedia((*list_->at(idx)));
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
    shuffledList_->removeOne(index_);
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(shuffledList_->begin(), shuffledList_->end(), g);
    shuffledList_->push_front(index_); // current index will be the last item.
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
        if(repeatState_ == Repeat::off || repeatState_ == Repeat::single){
            if(index_ < length_ && index_ > -1) return shuffledList_->at(increment());
            else return setIndex(-1);
        }
        else{
            if(index_ >= length_) setIndex(0);
            else increment();

            return shuffledList_->at(index_);
        }
    }
    else{
        if(repeatState_ == Repeat::off || repeatState_ == Repeat::single){
            if(index_ < length_ && index_ > -1) return increment();
            else return setIndex(-1);
        }
        else{
            if(index_ < length_) return increment();
            else return setIndex(0);
        }
    }
}

int MusicPlayer::previousIndex(){
    if(shuffleOn_){
        if(repeatState_ == Repeat::off || repeatState_ == Repeat::single){
            if(index_ > 0) return shuffledList_->at(decrement());
            else return setIndex(-1);
        }
        else{
            if(index_ <= 0) setIndex(length_);
            else decrement();

            return shuffledList_->at(index_);
        }
    }
    else{
        if(repeatState_ == Repeat::off || repeatState_ == Repeat::single){
            if(index_ <= 0 ) return setIndex(-1);
            else return decrement();
        }
        else{
            if(index_ > 0) return decrement();
            else return setIndex(length_);
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

    play();
}

int MusicPlayer::setIndex(const int v){
    index_ = v;
    emit idxChanged();
    return index_;
}

int MusicPlayer::increment(){
    return setIndex(index_ + 1);
}

int MusicPlayer::decrement(){
    return setIndex(index_ - 1);
}

