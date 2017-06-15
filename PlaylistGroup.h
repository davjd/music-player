#ifndef PLAYLISTGROUP_H
#define PLAYLISTGROUP_H

#include <QWidget>
#include <QJsonArray>
#include <QLayout>
#include "Playlist.h"


class PlaylistGroup : public QWidget
{
public:
    PlaylistGroup();
    PlaylistGroup(const QString& title);
    void init(const QString& title  = "Title");
    void loadGroup(const QJsonArray& items, QVector<Playlist*>* playlists);

private:
    QLayout* grid();
};

#endif // PLAYLISTGROUP_H
