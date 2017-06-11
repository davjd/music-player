#ifndef PLAYLIST_H
#define PLAYLIST_H
#include <QVector>
#include <QObject>
#include "Song.h"
#include <QVector>


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


private:
    QVector<Song* >* list_;
    QString title_;

public slots:

};

#endif // PLAYLIST_H
