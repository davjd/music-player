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
    qDebug() << "index: " << player->playlist()->currentIndex();
    qDebug() << "next!!!";
    if(player->isAudioAvailable()){
        if(player->list()->currentIndex() < player->playlist()->mediaCount() - 1){
            player->playlist()->next();
            qDebug() << "Going to next.";
        }
    }
}

void SongScreen::previous(){
    qDebug() << "index: " << player->playlist()->currentIndex();
    if(player->isAudioAvailable()){
        if(player->list()->currentIndex() > 0){
            player->playlist()->previous();
            qDebug() << "Going to previous.";
        }
    }
    qDebug() << "previous!!!";
}

void SongScreen::play(){
    qDebug() << "play!!!";
    qDebug() << "has media: " << player->isAudioAvailable();
    qDebug() << "is available: " << player->isAvailable();
    qDebug() << "status: " << player->state();
    if(player->isAudioAvailable()){
        if(player->state() != QMediaPlayer::PlayingState){
            player->play();
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
