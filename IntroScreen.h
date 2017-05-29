#ifndef INTROSCREEN_H
#define INTROSCREEN_H

#include <QWidget>

namespace Ui {
class IntroScreen;
}

class IntroScreen : public QWidget
{
    Q_OBJECT

public:
    explicit IntroScreen(QWidget *parent = 0);
    ~IntroScreen();

private:
    Ui::IntroScreen *ui;
public slots:
    void addItem();
};

#endif // INTROSCREEN_H
