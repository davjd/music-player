#include "SongScreen.h"
#include "ui_SongScreen.h"
#include <QDebug>
#include "Song.h"

SongScreen::SongScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SongScreen)
{
    ui->setupUi(this);
//    this->setStyleSheet("background-color: black;");
////    setPaletteBackgroundColor(Qt::black);
//    setAutoFillBackground(true);


    setAutoFillBackground(true);
    QPalette p = palette();
    p.setColor(QPalette::Window, QColor(125,153,153,150));
//    p.setColor(QPalette::Window, Qt::black);

    setPalette(p);

    connect(player, &MusicPlayer::idxChanged, [this](){
        qDebug() << "index changed: " << player->index();
        qDebug() << "Song idx: " << player->songIndex();
        drawArtist();
        drawTitle();
        drawCover();
    });
    connect(ui->progress, &QSlider::sliderReleased, [this](){
        player->setPosition(ui->progress->value());
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
        if(player->index() <= player->length()){
            player->next();
            player->play();
            qDebug() << "Going to next.";
            qDebug() << "new index: " << player->index();
        }
    }
}

void SongScreen::previous(){
    if(player->isAudioAvailable()){
        if(player->index() >= 0){
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
//    else{
//        if(!player->played()){
//            qDebug() << "initializing player...";
//            player->initializeContent();
//            play();
//        }
//    }
}

void SongScreen::drawArtist(){
    int idx = player->index();
    if(idx < 0 || idx > player->length()){
        qDebug() << "Artist won't be loaded, because of index.";
        return;
    }
    QString artist(player->songList()->at(player->songIndex())->artist());
    if(artist.length() == 0){
        artist = player->songList()->at(player->songIndex())->path()->absolutePath();
    }
    ui->artist->setText(artist);
}

void SongScreen::drawCover()
{
    int idx = player->index();
    if(idx < 0 || idx > player->length()){
        qDebug() << "Cover won't be loaded, because of index.";
        return;
    }
    QPixmap cover(player->songList()->at(player->songIndex())->cover());
    if(!cover.isNull()){
        ui->cover->setText("");
        ui->cover->setIcon(QIcon(cover));
    }
}

void SongScreen::drawTitle(){
    int idx = player->index();
    if(idx < 0 || idx > player->length()){
        qDebug() << "Title won't be loaded, because of index.";
        return;
    }
    QString title(player->songList()->at(player->songIndex())->title());
    if(title.length() == 0){
        title = player->songList()->at(player->songIndex())->path()->absolutePath();
    }
    ui->title->setText(title);
}

void SongScreen::toggleRepeat(){
    player->toggleRepeat();
    qDebug() << "New repeat state: " << player->repeatState();
}

void SongScreen::toggleShuffle(){
    player->toggleShuffle();
    qDebug() << "New repeat state: " << player->isShuffled();
}

void SongScreen::setFiller(){
    if( player->mediaStatus() == QMediaPlayer::BufferedMedia){
        ui->progress->setMaximum(player->duration());
    }
    else qDebug() << player->mediaStatus();
}

void SongScreen::fillBuffer(){
    ui->progress->setValue(player->position());
}
