#include "IntroScreen.h"
#include "ui_IntroScreen.h"
#include "Player.h"
#include <QLabel>
#include <QDebug>
#include <QVectorIterator>

IntroScreen::IntroScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::IntroScreen)
{
    ui->setupUi(this);

}

IntroScreen::~IntroScreen()
{
    delete ui;
}

void IntroScreen::addItem(){
    qDebug() << "new button.";
    QWidget *viewport = new QWidget;
    ui->scrollArea->setWidget(viewport);
    ui->scrollArea->setWidgetResizable(true);
    QVBoxLayout *l = new QVBoxLayout(viewport);

    QVectorIterator<Song*> i((*player->songList()));
    while (i.hasNext()){
        QPushButton *pb = new QPushButton((*i.next()).title());
        l->addWidget(pb);
    }
}
