#ifndef PLAYLISTGROUP_H
#define PLAYLISTGROUP_H

#include <QWidget>
#include <QJsonArray>
#include <QLayout>


class PlaylistGroup : public QWidget
{
public:
    PlaylistGroup();
    PlaylistGroup(const QString& title);
    void init(const QString& title  = "Title");
    void loadGroup(const QJsonArray& items);

private:
    QLayout* grid();
};

#endif // PLAYLISTGROUP_H
