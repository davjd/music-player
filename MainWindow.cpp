#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "SongScreen.h"
#include "IntroScreen.h"
#include <QDebug>
#include <QPalette>
#include "PlaylistScreen.h"
#include "PlaylistGroup.h";

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    // getting ui objects:
    QStackedWidget* stack = ui->iScreen->findChild<QStackedWidget*>("stack");
    qDebug() << ui->iScreen->findChild<PlaylistGroup*>("pAuto Playlists");
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
