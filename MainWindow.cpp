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

//    this->setStyleSheet("background-color: white;");
    setAutoFillBackground(true);
    QPalette p = ui->sScreen->palette();
    p.setColor(QPalette::Window, QColor(200,10,10));
    ui->sScreen->setPalette(p);
//    p.setColor(QPalette::Background, QColor(200,0,0));

//    p.setPaletteBackgroundColor(Qt::black);
//    qDebug() << ui->sScreen->palette().color(QPalette::Background);
    qDebug() << "color: " << p.color(QPalette::Window);

}

MainWindow::~MainWindow()
{
    delete ui;
}
