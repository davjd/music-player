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
    int index();
    bool isShuffled();
    Repeat repeatState();
    void insert(QVector<Song*>* content);



private:
    QVector<Song*>* list_;
    QVector<int>* shuffledList_;
    int index_;
    Repeat repeatState_;
    bool shuffleOn_;
    int length_;

    void remove(const int idx);
    int nextIndex();
    int previousIndex();
    void shuffle();


private slots:
    void next();
    void previous();
    void toggleShuffle();
    void toggleRepeat();

};

#endif // MUSICPLAYER_H
