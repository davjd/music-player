#ifndef PLAYLISTSCREEN_H
#define PLAYLISTSCREEN_H

#include <QWidget>

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
};

#endif // PLAYLISTSCREEN_H
