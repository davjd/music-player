#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "SongScreen.h"
#include "IntroScreen.h"
#include <QDebug>
#include <QPalette>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    setAutoFillBackground(true);
//    QPalette p = palette();
//    p.setColor(QPalette::Window, QColor(200,10,10));
//    setPalette(p);
//    qDebug() << "color: " << p.color(QPalette::Window);

//    connect(ui->iScreen, &QMediaPlayer::mediaStatusChanged, [this](QMediaPlayer::MediaStatus status){

//    });

}

MainWindow::~MainWindow()
{
    delete ui;
}
