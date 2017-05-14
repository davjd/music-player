#ifndef SONGSCREEN_H
#define SONGSCREEN_H

#include <QWidget>

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
};

#endif // SONGSCREEN_H
