#include "PlaylistScreen.h"
#include "ui_PlaylistScreen.h"

#include "Serializer.h"
#include "ImageBlock.h"
#include <QJsonDocument>
#include <QGridLayout>
#include <QScrollArea>
#include <QScrollBar>

PlaylistScreen::PlaylistScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PlaylistScreen)
{
    ui->setupUi(this);
    list_ = new QVector<Playlist*>();
    qDebug() << "Playlist screen init().";

    // Fake up a grid to scroll
    QWidget *client = new QWidget(this);
    QGridLayout *gl = new QGridLayout(client);


    int ctr = 0;
    const int COL_NUM = 4;
    const int LENGTH = 20;

    for(int i = 0; i < LENGTH; ++i){

        int row, col;
        row = ctr % 2;

        if(row == 0) col = ctr;
        else col = ctr - 1;

        ImageBlock* b = new ImageBlock();
        b->setTitle("Song" + QString::number(i + 1));
        b->setStyleSheet("background-color: white;");
        b->setFixedSize(150,200);
        gl->addWidget(b, row, col);
        ++ctr;
    }

    client->setLayout(gl);

    // Put it into a scroll area
    QScrollArea *area = new QScrollArea(this);
    area->setWidget(client);
    area->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // Make the scroll step the same width as the fixed widgets in the grid
    area->horizontalScrollBar()->setSingleStep(client->width() / 24);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(new QLabel("Something else", this));
    layout->addWidget(area);

    setLayout(layout);



//    int ctr = 0;
//    int row = 0;
//    const int COL_NUM = 3;
//    const int LENGTH = 20;

//    for(int i = 1; i < LENGTH; ++i){
//        int col = ctr % COL_NUM;
//        if(col == 0) ++row;

//        ImageBlock* b = new ImageBlock();
//        b->setTitle("Song" + QString::number(i));
//        b->setStyleSheet("background-color: green;");
//        ui->grid->addWidget(b, row, col);
//        ++ctr;
//    }
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
