#include "IntroScreen.h"
#include "ui_IntroScreen.h"
#include "Player.h"
#include <QLabel>
#include <QDebug>
#include <QVectorIterator>
#include <QGridLayout>

#include "RotatedButton.h"

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

    QGridLayout *l = new QGridLayout(viewport);

    QVectorIterator<Song*> i((*player->songList()));
    int ctr = 0;
    while (i.hasNext()){
        QPushButton *pb = new QPushButton((*i.next()).title());

        connect(pb, &QPushButton::clicked, [pb](bool checked){
            qDebug() << "Title: " << pb->text();

        });


        int col = ctr % 2;
        int row;

        if(col) row = ctr - 1;
        else row = ctr;

        l->addWidget(pb, row, col);
        ++ctr;
    }
    l->addWidget(new RotatedButton("Rotated.", this));
}
