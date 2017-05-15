#include "SongScreen.h"
#include "ui_SongScreen.h"
#include <QDebug>

SongScreen::SongScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SongScreen)
{
    ui->setupUi(this);
//    connect(player, SIGNAL())
}

SongScreen::~SongScreen()
{
    delete ui;
}

void SongScreen::next(){
    qDebug() << "next!!!";
    if(player->isAudioAvailable()){
        if(player->list()->currentIndex() < player->playlist()->mediaCount() - 1){
            player->playlist()->next();
            qDebug() << "Going to next.";
            qDebug() << "new index: " << player->playlist()->currentIndex();
        }
    }

    qDebug() << ui->middle->icon().name();
}

void SongScreen::previous(){
    qDebug() << "previous!!!";
    if(player->isAudioAvailable()){
        if(player->list()->currentIndex() > 0){
            player->playlist()->previous();
            qDebug() << "Going to previous.";
            qDebug() << "new index: " << player->playlist()->currentIndex();
        }
    }

    qDebug() << ui->middle->icon().name();
}

void SongScreen::play(){
    qDebug() << "Player will be played.";
    player->play();
    ui->middle->setIcon(QIcon(":/buttons/pause.svg"));
}

void SongScreen::pause(){
    qDebug() << "Player will be paused.";
    player->pause();
    ui->middle->setIcon(QIcon(":/buttons/play-button.svg"));
}



void SongScreen::toggle(){
    if(player->isAudioAvailable()){
        if(player->state() == QMediaPlayer::PausedState || player->state() == QMediaPlayer::StoppedState){
            play();
        }
        else if(player->state() == QMediaPlayer::PlayingState){
            pause();
        }
    }
}
