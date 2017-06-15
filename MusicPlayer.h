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
    ~MusicPlayer();
    QVector<Song*>* songList();
    void setList();
    void insert(Song* content);
    int index();
    int songIndex();
    int length();
    bool isShuffled();
    Repeat repeatState();
    void insert(QVector<Song*>* content);
    void initializeContent();
    bool hasPlayed();
    bool played();
    void setPlayed(bool p);

    int setIndex(const int v); // will emit signal when index changes.



private:
    QVector<Song*>* list_;
    QVector<int>* shuffledList_;
    Repeat repeatState_;
    int index_;
    bool shuffleOn_;
    int length_;
    bool played_;

    void remove(const int idx);
    int nextIndex();
    int previousIndex();
    void shuffle();
    int increment();
    int decrement();

signals:
    void idxChanged();


public slots:
    void next();
    void previous();
    void loadedNext();
    void toggleShuffle();
    void toggleRepeat();

};

#endif // MUSICPLAYER_H
