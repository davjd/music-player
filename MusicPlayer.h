#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H

#include <QObject>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QMediaContent>
#include "Song.h"

class MusicPlayer: public QMediaPlayer
{
    Q_OBJECT
public:
    MusicPlayer();
    QList<Song>* list();
    void setList();
    void insert(Song content);
private:
    QList<Song>* list_;
};

#endif // MUSICPLAYER_H
