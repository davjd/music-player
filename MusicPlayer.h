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
    MusicPlayer();
    QMediaPlaylist* list();
    void setList();
    void insert(Song* content);
private:
    QList<Song*>* list_;
    QMediaPlaylist* playlist_;
};

#endif // MUSICPLAYER_H
