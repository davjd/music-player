#include "SongScreen.h"
#include "ui_SongScreen.h"
#include <QDebug>
#include "Song.h"

SongScreen::SongScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SongScreen)
{
    ui->setupUi(this);

    connect(player, &MusicPlayer::idxChanged, [this](){
        qDebug() << "index changed: " << player->index();
        drawArtist();
        drawTitle();
    });
    connect(player, SIGNAL(mediaStatusChanged(QMediaPlayer::MediaStatus)), this, SLOT(setFiller()));
    connect(player, SIGNAL(positionChanged(qint64)), this, SLOT(fillBuffer()));
}

SongScreen::~SongScreen()
{
    delete ui;
}

void SongScreen::next(){
    if(player->isAudioAvailable()){
        if(player->index() < player->length()){
            player->next();
            player->play();
            qDebug() << "Going to next.";
            qDebug() << "new index: " << player->index();
        }
    }
}

void SongScreen::previous(){
    if(player->isAudioAvailable()){
        if(player->index() > 0){
            player->previous();
            player->play();
            qDebug() << "Going to previous.";
            qDebug() << "new index: " << player->index();
        }
    }
}

void SongScreen::play(){
    qDebug() << "Player will be played.";
    player->play();
    ui->middle->setIcon(QIcon(":/buttons/pause.svg"));
}

void SongScreen::pause(){
    qDebug() << "len: " << player->duration();
    qDebug() << "Player will be paused.";
    player->pause();
    ui->middle->setIcon(QIcon(":/buttons/play-button.svg"));
}

void SongScreen::togglePlay(){
    qDebug() << "Toggling play.";
    if(player->isAudioAvailable()){
        if(player->state() == QMediaPlayer::PausedState || player->state() == QMediaPlayer::StoppedState){
            play();
        }
        else if(player->state() == QMediaPlayer::PlayingState){
            pause();
        }
    }
    else{
        if(!player->hasPlayed()){
            qDebug() << "initializing player...";
            player->initializeContent();
            play();
        }
    }
}

void SongScreen::drawArtist(){
    int idx = player->index();
    qDebug() << "artist-current: " << idx;
    if(idx < 0 || idx > player->length()){
        qDebug() << "Title won't be loaded, because of index.";
        return;
    }
    qDebug() << "artist: " << player->songList()->at(player->index())->artist();
    ui->artist->setText(player->songList()->at(player->index())->artist());
}

void SongScreen::drawTitle(){
    int idx = player->index();
    qDebug() << "title-current: " << idx;
    if(idx < 0 || idx > player->length()){
        qDebug() << "Title won't be loaded, because of index.";
        return;
    }
    qDebug() << "title: " << player->songList()->at(player->index())->title();
    ui->title->setText(player->songList()->at(player->index())->title());
}

void SongScreen::toggleRepeat(){
    qDebug() << "Toggling repeat.";
    player->toggleRepeat();
    qDebug() << "New repeat state: " << player->repeatState();
}

void SongScreen::toggleShuffle(){
    qDebug() << "shuffling";
    player->toggleShuffle();
    qDebug() << "New shuffle state: " << player->isShuffled();
}

void SongScreen::setFiller(){
    if( player->mediaStatus() == QMediaPlayer::BufferedMedia){
        qDebug() << "length: " << player->duration();
        ui->position->setMaximum(player->duration());
    }
    else qDebug() << player->mediaStatus();
}

void SongScreen::fillBuffer(){
    ui->position->setValue(player->position());
}

void SongScreen::out(){
    if(player->mediaStatus() == QMediaPlayer::EndOfMedia){
        qDebug() << "End of song!";
    }
    else{
        qDebug() << "something else..";
    }
}
