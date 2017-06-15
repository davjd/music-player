#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "SongScreen.h"
#include "IntroScreen.h"
#include <QDebug>
#include <QPalette>
#include <QScrollArea>
#include "PlaylistScreen.h"
#include "PlaylistGroup.h"
#include <typeinfo>
#include "PlaylistBlock.h"
#include "ImageBlock.h"
#include "SongListScreen.h"
#include "RotatedButton.h"
#include "Serializer.h"
#include "SongBlock.h"

#include "Player.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /*
     *  The window requires that there must be a playlist loaded
     *  into memory. This is because the user might click on the
     *  songs qpushbutton, which will instantiate a SongListScreen.
     *  When the SongListScreen gets instantiated, the instance will have no
     *  initial playlist, which will lead to an empty screen inside the QStackedWidget.
     *  In order to ensure that something is always there, the main window will
     *  always have one playlist loaded. The obvious choice for this initial playlist
     *  is the auto-generated playlist which contains every song.
     *
     * */

    loadInitial();
    SongListScreen* s =  ui->iScreen->findChild<QStackedWidget*>("stack")->findChild<SongListScreen*>("p2");
    s->setPlaylist(initialPlaylist_);
    s->loadPlaylist();

    player->insert(initialPlaylist_->list());


    auto introObjs =  ui->iScreen->findChild<QWidget*>("verticalLayoutWidget")->children();

    int ctr = 0;
    for(auto w: introObjs){
        if(typeid(*w) == typeid(RotatedButton)){
            RotatedButton* g = static_cast<RotatedButton*>(w);
            connect(g, &RotatedButton::clicked, [this, g, ctr](){









                switch(ctr){
//                    case 0:
//                    {
//                        ui->iScreen->findChild<QStackedWidget*>("stack")->setCurrentIndex(0);
//                        break;
//                    }
                    case 0:
                    {
                        ui->iScreen->findChild<QStackedWidget*>("stack")->setCurrentIndex(0);
                        SongListScreen* s =  ui->iScreen->findChild<QStackedWidget*>("stack")->findChild<SongListScreen*>("p2");
                        s->setPlaylist(initialPlaylist_);
                        s->loadPlaylist();
                        break;
                    }
//                    case 2:
//                        // when 3rd button pressed.
//                        qDebug() << "3rd button";
//                        break;
//                    case 3:
//                        // when 4th button pressed.
//                        qDebug() << "4th button";
//                        break;
//                    case 4:
//                        // when 5th button pressed.
//                        qDebug() << "5th button";
//                        break;
                }


//                if(ctr == 1){
//                    SongListScreen* s =  ui->iScreen->findChild<QStackedWidget*>("stack")->findChild<SongListScreen*>("p2");
//                    s->setPlaylist(g->playlist());
//                    s->loadPlaylist();
//                }
            });
            ++ctr;
        }

//        qDebug() << w;
    }

//    PlaylistBlock* g = static_cast<PlaylistBlock*>(w);
//    connect(g, &PlaylistBlock::clicked, [this, g](){
//        ui->iScreen->findChild<QStackedWidget*>("stack")->setCurrentIndex(1);
//        SongListScreen* s =  ui->iScreen->findChild<QStackedWidget*>("stack")->findChild<SongListScreen*>("p2");
//        s->setPlaylist(g->playlist());
//        s->loadPlaylist();
//    });


    // getting ui objects
    auto screen = ui->iScreen->findChild<SongListScreen*>("p2")->findChild<QScrollArea*>("scroll")->widget()->findChild<QWidget*>("client");

    for(auto w: screen->children()){
        if(typeid(*w) == typeid(SongBlock)){
            SongBlock* g = static_cast<SongBlock*>(w);
            connect(g, &SongBlock::clicked, [this, g](){
                // play this song.
                ui->stackedWidget->setCurrentIndex(1);
                player->setIndex(initialPlaylist_->list()->indexOf(g->song()) - 1);
//                player->setMedia(*g->song()->content());
                player->play();

                // toggle played in main window instead of music player.
                // call initiain here.

            });
        }
    }

    QPushButton* bttn = ui->sScreen->findChild<QPushButton*>("menu");
    connect(bttn, &QPushButton::clicked, [this, bttn](){
        // play this song.
        ui->stackedWidget->setCurrentIndex(0);
    });

//    qDebug() << stack->findChild<PlaylistScreen*>("p1")->findChild<PlaylistGroup*>("pAuto Playlists");


//    qDebug() << ui->iScreen->screen()->b1;

//    setAutoFillBackground(true);
//    QPalette p = palette();
//    p.setColor(QPalette::Window, QColor(200,10,10));
//    setPalette(p);
//    qDebug() << "color: " << p.color(QPalette::Window);

//    connect(, &QMediaPlayer::mediaStatusChanged, [this](QMediaPlayer::MediaStatus status){

//    });



}

void MainWindow::setCurrentPlaylist(Playlist *playlist)
{
    if(currentPlaylist_ != nullptr) delete currentPlaylist_;
    currentPlaylist_ = playlist;
}

Playlist *MainWindow::currentPlaylist()
{
    return currentPlaylist_;
}

Playlist *MainWindow::initialPlaylist()
{
    return initialPlaylist_;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadInitial()
{
    initialPlaylist_ =  new Playlist();
    Serializer ser;
    QJsonDocument doc = ser.loadJson("playlists.json");
    QJsonArray ar = doc.array();

    for(QJsonValue v: ar){
        if(Playlist::Type::auto_gen ==  ((Playlist::Type)v.toObject()["type"].toInt())){
            initialPlaylist_->read(v.toObject()["playlists"].toArray().at(0).toObject());
            qDebug() << initialPlaylist_->list()->size();
            break;
        }
    }
}
