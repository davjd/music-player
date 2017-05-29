#include "IntroScreen.h"
#include "ui_IntroScreen.h"
#include <QLabel>
#include <QDebug>

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
    for(int i=0;i<50;++i) {
        QPushButton *pb = new QPushButton(QString::number(i+1));
        l->addWidget(pb);
    }
}
