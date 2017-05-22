#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H

#include <QObject>
#include <QMediaPlayer>
#include <QMediaContent>
#include <QMediaPlaylist>
#include <QVector>
#include "Song.h"

class MusicPlayer: public QMediaPlayer
{
    Q_OBJECT
public:
    enum Repeat{
        single, list, off
    };

    MusicPlayer();
    QVector<Song*>* songList();
    void setList();
    void insert(Song* content);
    unsigned int index();
    bool isShuffled();
    Repeat repeatState();



private:
    QVector<Song*>* list_;
    QVector<int>* shuffledList_;
    unsigned int index_;
    Repeat repeatState_;
    bool shuffleOn_;
    unsigned int length_;

    void remove(const int idx);
    int nextIndex();


private slots:
    void next();
    void previous();
    void toggleShuffle();
    void toggleRepeat();

};

#endif // MUSICPLAYER_H
