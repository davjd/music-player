#include "MusicPlayer.h"

MusicPlayer::MusicPlayer(): QMediaPlayer()
{
    list_ = new QVector<Song*>();
    shuffledList_ = new QVector<int>();
    shuffleOn_ = false;
    repeatState_ = Repeat::off;
    index_ = -1;
    length_ = -1;
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

unsigned int MusicPlayer::index(){
    return index_;
}

void MusicPlayer::next(){
    setMedia(list_->at(nextIndex()));
}

void MusicPlayer::previous(){

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

void MusicPlayer::toggleShuffle(){

}

int MusicPlayer::nextIndex(){
    /*
        possible cases:
            shuffle OFF/ON:
                -repeat: OFF
                -repeat: individual
                -repeat: list
    */

    // check if shuffle is activated.
    if(shuffleOn_){
        // find out what the repeat state is.

        if(repeatState_ == Repeat::off){
            if(index_ < length_){
                return -1;
            }
            else{
                return shuffledList_->at(++index_);
            }
        }
        else if(repeatState_ == Repeat::single){
            return index_;
        }
        else{
            // check whether it's in bound.
            if(index_ >= length_){
                index_ = 0;
            }

            return shuffledList_->at(index_);
        }
    }
    else{ // if shuffle is not ativated:

        if(repeatState_ == Repeat::off){
            if(index_ < length_){
                return -1;
            }
            else{
                return ++index_;
            }
        }
        else if(repeatState_ == Repeat::single){
            return index_;
        }
        else{ // repeatState_ = Repeat::list

            // check whether it's in bound.
            if(index_ < length_){
                return ++index_;
            } // start from the beginning if not.
            else return 0;
        }
    }
}

int MusicPlayer::previousIndex(){
    /*
        possible cases:
            shuffle OFF/ON:
                -repeat: OFF
                -repeat: individual
                -repeat: list
    */

    // check if shuffle is activated.
    if(shuffleOn_){
        // find out what the repeat state is.

        if(repeatState_ == Repeat::off){
            if(index_ > 0){
                return shuffledList_->at(++index_);
            }
            else{
                return -1;
            }
        }
        else if(repeatState_ == Repeat::single){
            return index_;
        }
        else{
            // check whether it's in bound.
            if(index_ >= length_){
                index_ = 0;
            }

            return shuffledList_->at(index_);
        }
    }
    else{ // if shuffle is not ativated:

        if(repeatState_ == Repeat::off){
            if(index_ < length_){
                return -1;
            }
            else{
                return ++index_;
            }
        }
        else if(repeatState_ == Repeat::single){
            return index_;
        }
        else{ // repeatState_ = Repeat::list

            // check whether it's in bound.
            if(index_ < length_){
                return ++index_;
            } // start from the beginning if not.
            else return 0;
        }
    }
}


