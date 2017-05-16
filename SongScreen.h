#ifndef SONGSCREEN_H
#define SONGSCREEN_H

#include <QWidget>
#include "Player.h"

namespace Ui {
class SongScreen;
}

class SongScreen : public QWidget
{
    Q_OBJECT

public:
    explicit SongScreen(QWidget *parent = 0);
    ~SongScreen();

private:
    Ui::SongScreen *ui;

public slots:
    void next();
    void previous();
    void togglePlay();
    void drawTitle();
    void drawArtist();
    void toggleRepeat();
    void toggleShuffle();
private slots:
    void play();
    void pause();
};

#endif // SONGSCREEN_H
