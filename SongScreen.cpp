#include "SongScreen.h"
#include "ui_SongScreen.h"
#include <QDebug>
#include "Song.h"

SongScreen::SongScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SongScreen)
{
    ui->setupUi(this);
    connect(player, SIGNAL(currentMediaChanged(QMediaContent)), this, SLOT(drawArtist()));
    connect(player, SIGNAL(currentMediaChanged(QMediaContent)), this, SLOT(drawTitle()));
}

SongScreen::~SongScreen()
{
    delete ui;
}

void SongScreen::next(){
    if(player->isAudioAvailable()){
        if(player->playlist()->currentIndex() < player->playlist()->mediaCount() - 1){
            player->playlist()->next();
            qDebug() << "Going to next.";
            qDebug() << "new index: " << player->playlist()->currentIndex();
        }
    }
}

void SongScreen::previous(){
    if(player->isAudioAvailable()){
        if(player->playlist()->currentIndex() > 0){
            player->playlist()->previous();
            qDebug() << "Going to previous.";
            qDebug() << "new index: " << player->playlist()->currentIndex();
        }
    }
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

void SongScreen::togglePlay(){
    if(player->isAudioAvailable()){
        if(player->state() == QMediaPlayer::PausedState || player->state() == QMediaPlayer::StoppedState){
            play();
        }
        else if(player->state() == QMediaPlayer::PlayingState){
            pause();
        }
    }
    else{
        if((player->playlist() == NULL) /*&& player->playlist()->mediaCount() > 0*/){
            qDebug() << "setting playlist...";
            player->setList();
            play();
        }
    }
}

void SongScreen::drawArtist(){
    qDebug() << "artist-current: " << player->playlist()->currentIndex();
    if(player->playlist()->currentIndex() < 0 || player->playlist()->currentIndex() > player->songList()->size() - 1){
        qDebug() << "Title won't be loaded, because of index.";
        return;
    }
    qDebug() << "artist: " << player->songList()->at(player->playlist()->currentIndex())->artist();
    ui->artist->setText(player->songList()->at(player->playlist()->currentIndex())->artist());
}

void SongScreen::drawTitle(){
    qDebug() << "title-current: " << player->playlist()->currentIndex();
    if(player->playlist()->currentIndex() < 0 || player->playlist()->currentIndex() > player->songList()->size() - 1){
        qDebug() << "Title won't be loaded, because of index.";
        return;
    }
    qDebug() << "title: " << player->songList()->at(player->playlist()->currentIndex())->title();
    ui->title->setText(player->songList()->at(player->playlist()->currentIndex())->title());
}
