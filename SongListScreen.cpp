#include "SongListScreen.h"
#include "ui_SongListScreen.h"

#include <QScrollArea>
#include <QScrollBar>
#include <QGridLayout>
#include <QLabel>
#include <QDebug>
#include "PlaylistGroup.h"

SongListScreen::SongListScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SongListScreen)
{
    ui->setupUi(this);

    playlist_ = new Playlist();

    qDebug() << "Songlist init";

    // Fake up a grid to scroll
    QWidget *client = new QWidget(this);
    client->setObjectName("client");
    QGridLayout *gl = new QGridLayout(client);

//    int ctr = 0;
//    const int LENGTH = 3;

//    for(int i = 0; i < LENGTH; ++i){

//        PlaylistGroup* p = new PlaylistGroup("Playlist: " + QString::number(i));
//        p->setFixedHeight(410);
//        p->setFixedWidth(810);
//        gl->addWidget(p, i, 0);
//        gl->setSpacing(80);
//        ++ctr;
//    }



    client->setLayout(gl);

    // Put it into a scroll area
    QScrollArea *area = new QScrollArea(this);
    area->setObjectName("scroll");
    area->setWidgetResizable(true);
    area->setWidget(client);
    area->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


//    PlaylistGroup* p = new PlaylistGroup("Playlist: " + QString::number(1));
//    p->update();
//    p->setFixedHeight(410);
//    p->setFixedWidth(810);

//    gl->addWidget(p, 0, 0);
//    gl->setSpacing(80);

//    qDebug() << "after;size: " <<  gl->count();

    // Make the scroll step the same width as the fixed widgets in the grid
    area->horizontalScrollBar()->setSingleStep(client->width() / 24);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(new QLabel("Select the playlist", this));
    layout->addWidget(area);

    setLayout(layout);

//    client->setStyleSheet("background-color:blue;");
//    area->setStyleSheet("background-color:red;");
    area->setAlignment(Qt::AlignCenter);

//    loadPlaylist();




}

SongListScreen::~SongListScreen()
{
    delete ui;
}

Playlist* SongListScreen::playlist()
{
    return playlist_;
}

void SongListScreen::loadPlaylist()
{

    if(playlist_== nullptr){
        // playlist must first be loaded.
        qDebug() << "null right now.";
        return;
    }

    QGridLayout* g = static_cast<QGridLayout*>(grid());
    PlaylistGroup* group = new PlaylistGroup(playlist_->title());
    group->loadPlaylist(playlist_);
    g->addWidget(group);
}

void SongListScreen::setPlaylist(Playlist* playlist)
{
    playlist_ = playlist;
}

QLayout* SongListScreen::grid()
{
    for(int i = 0, end = layout()->count(); i < end; ++i){
        if(layout()->itemAt(i)->widget()->objectName() == "scroll"){
            return layout()->itemAt(i)->widget()->findChild<QWidget *>("client")->layout();
        }
    }
    return nullptr;
}
