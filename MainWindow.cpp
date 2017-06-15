#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "SongScreen.h"
#include "IntroScreen.h"
#include <QDebug>
#include <QPalette>
#include <QScrollArea>
#include "PlaylistScreen.h"
#include "PlaylistGroup.h";
#include <typeinfo>
#include "PlaylistBlock.h"
#include "ImageBlock.h"
#include "SongListScreen.h";
#include "RotatedButton.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    auto introObjs =  ui->iScreen->findChild<QWidget*>("verticalLayoutWidget")->children();
//    qDebug() << introObjs;

    for(auto w: introObjs){
        if(typeid(*w) == typeid(RotatedButton)){
            PlaylistBlock* g = static_cast<PlaylistBlock*>(w);
            connect(g, &PlaylistBlock::clicked, [this, g](){
                ui->iScreen->findChild<QStackedWidget*>("stack")->setCurrentIndex(1);
                SongListScreen* s =  ui->iScreen->findChild<QStackedWidget*>("stack")->findChild<SongListScreen*>("p2");
                s->setPlaylist(g->playlist());
                s->loadPlaylist();
            });
            qDebug() << w;
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
    auto screen = ui->iScreen->findChild<PlaylistScreen*>("p1")->findChild<QScrollArea*>("scroll")->widget()->findChild<QWidget*>("client");

    for(auto w: screen->children()){
        if(typeid(*w) == typeid(PlaylistBlock)){
            PlaylistBlock* g = static_cast<PlaylistBlock*>(w);
            connect(g, &PlaylistBlock::clicked, [this, g](){
                ui->iScreen->findChild<QStackedWidget*>("stack")->setCurrentIndex(1);
                SongListScreen* s =  ui->iScreen->findChild<QStackedWidget*>("stack")->findChild<SongListScreen*>("p2");
                s->setPlaylist(g->playlist());
                s->loadPlaylist();
            });
        }
    }

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

MainWindow::~MainWindow()
{
    delete ui;
}
