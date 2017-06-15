#include "PlaylistGroup.h"

#include <QGridLayout>
#include <QVBoxLayout>
#include <QScrollArea>
#include <QScrollBar>
#include <QJsonValue>

#include "ImageBlock.h"
#include <QDebug>
#include <QObjectList>

PlaylistGroup::PlaylistGroup()
    :QWidget()
{
    init();

}

PlaylistGroup::PlaylistGroup(const QString &title)
{
    init(title);
}

void PlaylistGroup::init(const QString &title)
{
    // Fake up a grid to scroll
    QWidget* client = new QWidget(this);
    client->setObjectName("client");
    QGridLayout *gl = new QGridLayout(client);

    gl->setHorizontalSpacing(80);
    gl->setVerticalSpacing(20);

    int ctr = 0;
    const int LENGTH = 16;

    for(int i = 0; i < LENGTH; ++i){

        int row, col;
        row = ctr % 2;

        if(row == 0) col = ctr;
        else col = ctr - 1;

        ImageBlock* b = new ImageBlock();
        b->setTitle("Song" + QString::number(i + 1));
        b->setStyleSheet("background-color: white;");
        b->setFixedHeight(160);
        gl->addWidget(b, row, col);
        ++ctr;
    }

    client->setLayout(gl);

    // Put it into a scroll area
    QScrollArea *area = new QScrollArea(this);
    area->setObjectName("scroll");
    area->setWidget(client);
    area->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // Make the scroll step the same width as the fixed widgets in the grid
    area->horizontalScrollBar()->setSingleStep(client->width() / 24);

    QVBoxLayout *lay = new QVBoxLayout(this);
    lay->addWidget(new QLabel(title, this));
    lay->addWidget(area);

    setLayout(lay);

//    client->setStyleSheet("background-color:blue;");
//    area->setStyleSheet("background-color:red;");
    area->setAlignment(Qt::AlignCenter);
}

void PlaylistGroup::loadGroup(const QJsonArray &items)
{
    QGridLayout* grid;


    int ctr = 0;
    for(QJsonValue playlist: items){
        qDebug() << playlist;

        int row, col;
        row = ctr % 2;

        if(row == 0) col = ctr;
        else col = ctr - 1;

        ImageBlock* b = new ImageBlock();
        b->setTitle("Song" + QString::number(1));
        b->setStyleSheet("background-color: white;");
        b->setFixedHeight(160);
        grid->addWidget(b, row, col);
        ++ctr;
    }

}

QLayout* PlaylistGroup::grid()
{
    for(int i = 0, end = layout()->count(); i < end; ++i){
        if(layout()->itemAt(i)->widget()->objectName() == "scroll"){
            return layout()->itemAt(i)->widget()->findChild<QWidget *>("client")->layout();
        }
    }
    return nullptr;
}
