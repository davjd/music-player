#include "SongScreen.h"
#include "ui_SongScreen.h"
#include <QDebug>

SongScreen::SongScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SongScreen)
{
    ui->setupUi(this);
//    qDebug() << "player: " << player;
}

SongScreen::~SongScreen()
{
    delete ui;
}

void SongScreen::next(){
    qDebug() << "player: " << player;
    qDebug() << "next!!!";
}

void SongScreen::previous(){
    qDebug() << "player: " << player;
    qDebug() << "previous!!!";
}
