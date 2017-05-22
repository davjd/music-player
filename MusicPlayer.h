#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H

#include <QObject>
#include <QMediaPlayer>
#include <QMediaContent>
#include <QMediaPlaylist>
#include "Song.h"

class MusicPlayer: public QMediaPlayer
{
    Q_OBJECT
public:
    enum Repeat{
        individual, playlist, off
    };

    MusicPlayer();
    QList<Song*>* songList();
    void setList();
    void insert(Song* content);
    unsigned int index();
    bool isShuffled();
    Repeat repeatState();



private:
    QList<Song*>* list_;
    unsigned int index_;


private slots:
    void next();
    void previous();
    void toggleShuffle();
    void toggleRepeat();

};

#endif // MUSICPLAYER_H
