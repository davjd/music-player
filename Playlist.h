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

    enum Type{
        auto_gen,
        user_gen,
        smart_gen
    };

    Playlist();
    void push_back(Song* song);
    QVector<Song* >* list();
    QString title();
    void setTitle(const QString& title);
    void read(const QJsonObject &json);
    void write(QJsonObject &json);
    void open(QJsonObject& json);
    void setType(Type type);
    QTime time();
    Playlist::Type type();



private:
    QVector<Song* >* list_;
    QString title_;
    QTime time_;
    Type type_;

    QString parseTitle(QString title);

public slots:

};

#endif // PLAYLIST_H
