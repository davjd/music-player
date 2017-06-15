#include "PlaylistScreen.h"
#include "ui_PlaylistScreen.h"

#include "Serializer.h"
#include "ImageBlock.h"
#include <QJsonArray>
#include <QScrollArea>
#include <QScrollBar>

#include "PlaylistGroup.h"

PlaylistScreen::PlaylistScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PlaylistScreen)
{
    ui->setupUi(this);
    list_ = new QVector<Playlist*>();
    qDebug() << "Playlist screen init().";

    // Fake up a grid to scroll
    QWidget *client = new QWidget(this);
    client->setObjectName("client");
    QGridLayout *gl = new QGridLayout(client);

//    int ctr = 0;
//    const int LENGTH = 3;

//    for(int i = 0; i < LENGTH; ++i){

//        PlaylistGroup* p = new PlaylistGroup("Playlist: " + QString::number(i));
//        p->setFixedHeight(410);
//        p->setFixedWidth(810);
//        gl->addWidget(p, i, 0);
//        gl->setSpacing(80);
//        ++ctr;
//    }



    client->setLayout(gl);

    // Put it into a scroll area
    QScrollArea *area = new QScrollArea(this);
    area->setObjectName("scroll");
    area->setWidgetResizable(true);
    area->setWidget(client);
    area->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


//    PlaylistGroup* p = new PlaylistGroup("Playlist: " + QString::number(1));
//    p->update();
//    p->setFixedHeight(410);
//    p->setFixedWidth(810);

//    gl->addWidget(p, 0, 0);
//    gl->setSpacing(80);

//    qDebug() << "after;size: " <<  gl->count();

    // Make the scroll step the same width as the fixed widgets in the grid
    area->horizontalScrollBar()->setSingleStep(client->width() / 24);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(new QLabel("Select the playlist", this));
    layout->addWidget(area);

    setLayout(layout);

//    client->setStyleSheet("background-color:blue;");
//    area->setStyleSheet("background-color:red;");
    area->setAlignment(Qt::AlignCenter);
    loadPlaylists(gl);



//    gl->update();
//    client->update();
//    layout->update();
//    area->repaint();
//    area->update();
//    update();
//    repaint();
//    parent->update();
//    parent->repaint();




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

Ui::PlaylistScreen* PlaylistScreen::screen()
{
    return ui;
}

PlaylistScreen::~PlaylistScreen()
{
    delete ui;
}

void PlaylistScreen::loadPlaylists(QGridLayout* &grid)
{
    Serializer loader;
    QJsonArray json = loader.loadJson("playlists.json").array();

    for(QJsonValue type: json){
        // create playlist groups for each type.
        PlaylistGroup* group = new PlaylistGroup(
                    Playlist::typeName((Playlist::Type) type.toObject()["type"].toInt()));
        group->setObjectName("p" + Playlist::typeName((Playlist::Type) type.toObject()["type"].toInt()));
        group->setStyleSheet("color: red;");
        group->setFixedHeight(450);
        group->setFixedWidth(810);


        group->loadGroup(type.toObject()["playlists"].toArray(), list_);
        grid->addWidget(group);


//        qDebug() << playlist.toObject()["playlists"];

//        for(QJsonValue playlist: type.toObject()["playlists"].toArray()){

//        }
    }


    qDebug() << "stuff loaded.";
//    int ctr = 0;
//    const int LENGTH = 3;
//    for(QJsonValue playlist: json){


//        PlaylistGroup* p = new PlaylistGroup(playlist.toObject()["title"].toString());
//        p->setFixedHeight(410);
//        p->setFixedWidth(810);
//        grid->addWidget(p, i, 0);
//        grid->setSpacing(80);
//        ++ctr;



////        qDebug() << playlist.toObject()["title"].toString();
    //    }
}

void PlaylistScreen::append(QJsonDocument &doc, QJsonObject& playlist)
{
    Serializer s;
    QJsonArray ar = doc.array();

    int idx = -1;
    for(QJsonValue v: ar){
        ++idx;
        if(playlist["type"] ==  v.toObject()["type"]){
            QString path = "[" + QString::number(idx) + "]" + ".playlists";
            QJsonArray newDoc = v.toObject()["playlists"].toArray();
            newDoc.push_back(playlist);
            s.modifyJsonValue(doc, path, newDoc);
            s.saveJson(doc, "playlists.json");
            break;
        }
    }

}

QLayout* PlaylistScreen::grid()
{
    for(int i = 0, end = layout()->count(); i < end; ++i){
        if(layout()->itemAt(i)->widget()->objectName() == "scroll"){
            return layout()->itemAt(i)->widget()->findChild<QWidget *>("client")->layout();
        }
    }
    return nullptr;
}
