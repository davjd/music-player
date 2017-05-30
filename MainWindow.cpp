#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "SongScreen.h"
#include "IntroScreen.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    idx = -1;
    SongScreen* screen  = new SongScreen();
    IntroScreen* intro = new IntroScreen();
    stackedWidget = new QStackedWidget();
    stackedWidget->addWidget(intro);
    stackedWidget->addWidget(screen);

    connect(ui->list, &QPushButton::clicked, stackedWidget, [this](){
        qDebug() << "page 0.";
        stackedWidget->setCurrentIndex(0);
    });
    connect(ui->player, &QPushButton::clicked, stackedWidget, [this](){
        stackedWidget->setCurrentIndex(1);
    });
    stackedWidget->show();


}

void MainWindow::setIdx(int i){
    idx = i;
    emit idxChanged();
}

MainWindow::~MainWindow()
{
    delete ui;
}
