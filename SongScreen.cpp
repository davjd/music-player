#include "SongScreen.h"
#include "ui_SongScreen.h"
#include "Player.h"
#include <QDebug>

SongScreen::SongScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SongScreen)
{
    ui->setupUi(this);
    qDebug() << "player: " << player;
}

SongScreen::~SongScreen()
{
    delete ui;
}
