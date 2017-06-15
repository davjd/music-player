#ifndef PLAYLISTSCREEN_H
#define PLAYLISTSCREEN_H

#include <QWidget>
#include <QVector>
#include <QGridLayout>
#include "Playlist.h"

namespace Ui {
class PlaylistScreen;
}

class PlaylistScreen : public QWidget
{
    Q_OBJECT

public:
    explicit PlaylistScreen(QWidget *parent = 0);
    ~PlaylistScreen();

private:
    Ui::PlaylistScreen *ui;
    QVector<Playlist*>* list_;


    void loadPlaylists(QGridLayout* grid);
    void append(QJsonDocument& doc, QJsonObject& playlist);
};

#endif // PLAYLISTSCREEN_H
