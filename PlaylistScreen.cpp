#include "PlaylistScreen.h"
#include "ui_PlaylistScreen.h"

#include "Serializer.h"
#include "ImageBlock.h"
#include <QJsonDocument>

PlaylistScreen::PlaylistScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PlaylistScreen)
{
    ui->setupUi(this);
    list_ = new QVector<Playlist*>();
    qDebug() << "Playlist screen init().";

//    ImageBlock* b = new ImageBlock();
//    b->setTitle("Song" + QString::number(1));
//    ui->grid->addWidget(b, 1, 1);

    int ctr = 0;
    const int COL_NUM = 3;

    for(int i = 1; i < 6; ++i){
        int col = ctr % COL_NUM;
        int row;

        if(col != 0) row = ctr - col;
        else row = (ctr / COL_NUM);

        ImageBlock* b = new ImageBlock();
        b->setTitle("Song" + QString::number(i));
        ui->grid->addWidget(b, row, col);
        ++ctr;
    }



}

PlaylistScreen::~PlaylistScreen()
{
    delete ui;
}

void PlaylistScreen::loadPlaylists()
{
    Serializer loader;
    QJsonObject json = loader.loadJson("Playlist.json").object();
    for(auto playlist: json){
        qDebug() << "playlist";
    }
}
