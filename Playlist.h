#ifndef PLAYLIST_H
#define PLAYLIST_H
#include <QVector>
#include <QObject>
#include "Song.h"
#include <QVector>
#include <QTime>


class Playlist
{
public:
    Playlist();
    void push_back(Song* song);
    QVector<Song* >* list();
    QString title();
    void setTitle(const QString& title);
    void read(const QJsonObject &json);
    void write(QJsonObject &json);
    void open(QJsonObject& json);
    QTime time();


private:
    QVector<Song* >* list_;
    QString title_;
    int idx_;
    QTime time_;

public slots:

};

#endif // PLAYLIST_H
