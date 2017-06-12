#include "IntroScreen.h"
#include "ui_IntroScreen.h"
#include "Player.h"
#include <QLabel>
#include <QDebug>
#include <QVectorIterator>
#include <QGridLayout>
#include <QPalette>
#include <QColor>

#include "RotatedButton.h"

IntroScreen::IntroScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::IntroScreen)
{
    ui->setupUi(this);


    setAutoFillBackground(true);
    QPalette p = palette();
    p.setColor(QPalette::Window, QColor(10,0,0,150));
    setPalette(p);

    ui->b1->setTextColor(QColor(255,238,173,255));
    ui->b1->setBackgroundColor(QColor(127,55,52,255));
    ui->b1->setOrientation(Qt::Vertical);
    ui->b1->setMirrored(true);

    ui->b2->setTextColor(QColor(255,238,173,255));
    ui->b2->setBackgroundColor(QColor(100,10,10,0));
    ui->b2->setOrientation(Qt::Vertical);
    ui->b2->setMirrored(true);

    ui->b3->setTextColor(QColor(255,238,173,255));
    ui->b3->setBackgroundColor(QColor(100,10,10,0));
    ui->b3->setOrientation(Qt::Vertical);
    ui->b3->setMirrored(true);

    ui->b4->setTextColor(QColor(255,238,173,255));
    ui->b4->setBackgroundColor(QColor(100,10,10,0));
    ui->b4->setOrientation(Qt::Vertical);
    ui->b4->setMirrored(true);

    ui->b5->setTextColor(QColor(255,238,173,255));
    ui->b5->setBackgroundColor(QColor(100,10,10,0));
    ui->b5->setOrientation(Qt::Vertical);
    ui->b5->setMirrored(true);


    ui->b1->setFlat(true);
    ui->b2->setFlat(true);
    ui->b3->setFlat(true);
    ui->b4->setFlat(true);
    ui->b5->setFlat(true);

//    p = ui->scrollArea->palette();
//    p.setColor(QPalette::Window, QColor(136,216,176,20));
//    ui->scrollArea->setPalette(p);




}

IntroScreen::~IntroScreen()
{
    delete ui;
}

void IntroScreen::addItem(){
    qDebug() << "new button.";
//    QWidget *viewport = new QWidget;
//    ui->scrollArea->setWidget(viewport);
//    ui->scrollArea->setWidgetResizable(true);

//    QGridLayout *l = new QGridLayout(viewport);

//    QVectorIterator<Song*> i((*player->songList()));
//    int ctr = 0;
//    while (i.hasNext()){
//        QPushButton *pb = new QPushButton((*i.next()).title());

//        connect(pb, &QPushButton::clicked, [pb](bool checked){
//            qDebug() << "Title: " << pb->text();

//        });

//        int col = ctr % 2;
//        int row;

//        if(col) row = ctr - 1;
//        else row = ctr;

//        l->addWidget(pb, row, col);
//        ++ctr;
//    }
//    l->addWidget(new RotatedButton("Rotated.", Qt::Vertical, true, this));
}
