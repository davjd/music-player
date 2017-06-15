#ifndef SONGLISTSCREEN_H
#define SONGLISTSCREEN_H

#include <QWidget>
#include "PlaylistGroup.h"
#include <QLayout>

namespace Ui {
class SongListScreen;
}

class SongListScreen : public QWidget
{
    Q_OBJECT

public:
    explicit SongListScreen(QWidget *parent = 0);
    ~SongListScreen();

    void setPlaylist(Playlist* playlist);
    Playlist* playlist();
    void loadPlaylist();

private:
    Playlist* playlist_;
    QLayout* grid();
    void clear(QGridLayout* &g);



private:
    Ui::SongListScreen *ui;
};

#endif // SONGLISTSCREEN_H
