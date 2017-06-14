#ifndef PLAYLISTGROUP_H
#define PLAYLISTGROUP_H

#include <QWidget>


class PlaylistGroup : public QWidget
{
public:
    PlaylistGroup();
    void init(const QString& title  = "Title");
};

#endif // PLAYLISTGROUP_H
