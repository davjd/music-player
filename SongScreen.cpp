#include "SongScreen.h"
#include "ui_SongScreen.h"
#include <QDebug>

SongScreen::SongScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SongScreen)
{
    ui->setupUi(this);
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
}

void SongScreen::play(){
    qDebug() << "play!!!";
    if(player->isAudioAvailable()){
        if(player->state() != QMediaPlayer::PlayingState){
            player->play();
            qDebug() << "current idx: " << player->playlist()->currentIndex();
            qDebug() << "Starting to play.";
        }
        else qDebug() << "It's playing no need for this click";
    }
}

void SongScreen::pause(){

    qDebug() << "pause!!!";
    if(player->isAudioAvailable()){
        if(player->state() == QMediaPlayer::PausedState){
            player->pause();
            qDebug() << "Player has been paused.";
        }
        else qDebug() << "Player already paused.";
    }
}
