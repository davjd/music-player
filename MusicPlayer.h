#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H

#include <QObject>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QMediaContent>

class MusicPlayer: public QMediaPlayer
{
    Q_OBJECT
public:
    MusicPlayer();
    QMediaPlaylist* list();
    void setList();
    void insert(QMediaContent content);
private:
    QMediaPlaylist* list_;
};

#endif // MUSICPLAYER_H
