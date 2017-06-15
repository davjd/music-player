#include "PlaylistGroup.h"

#include <QGridLayout>
#include <QVBoxLayout>
#include <QScrollArea>
#include <QScrollBar>
#include <QJsonValue>
#include <QJsonObject>

#include "PlaylistBlock.h"
#include "SongBlock.h"
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
    gl->setObjectName("grid");

    gl->setHorizontalSpacing(80);
    gl->setVerticalSpacing(20);

//    int ctr = 0;
//    const int LENGTH = 16;

//    for(int i = 0; i < LENGTH; ++i){

//        int row, col;
//        row = ctr % 2;

//        if(row == 0) col = ctr;
//        else col = ctr - 1;

//        ImageBlock* b = new ImageBlock();
//        b->setTitle("Song" + QString::number(i + 1));
//        b->setStyleSheet("background-color: white;");
//        b->setFixedHeight(160);
//        gl->addWidget(b, row, col);
//        ++ctr;
//    }

    client->setLayout(gl);

    // Put it into a scroll area
    QScrollArea *area = new QScrollArea(this);
    area->setWidgetResizable(true);
    area->setObjectName("scroll");
    area->setWidget(client);
    area->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // Make the scroll step the same width as the fixed widgets in the grid
    area->horizontalScrollBar()->setSingleStep(client->width() / 24);

    QVBoxLayout *lay = new QVBoxLayout(this);
    lay->setObjectName("vbox");
    QLabel* t = new QLabel(title, this);
    t->setObjectName("label");
    lay->addWidget(t);
    lay->addWidget(area);

    setLayout(lay);

//    ImageBlock* b = new ImageBlock();
//    b->setTitle("Song" + QString::number(i + 1));
//    b->setStyleSheet("background-color: white;");
//    b->setFixedHeight(160);
//    gl->addWidget(b, 0, 0);

    client->setStyleSheet("background-color: white;");
    area->setStyleSheet("background-color:white;");
    area->setAlignment(Qt::AlignVCenter);
}

void PlaylistGroup::loadPlaylist(Playlist *playlist)
{

    qDebug() << "called";
    QGridLayout* g = static_cast<QGridLayout*>(grid());

    int ctr = 0;
    for(Song* song: (*playlist->list())){
        int row, col;
        row = ctr % 2;

        if(row == 0) col = ctr;
        else col = ctr - 1;

        SongBlock* b = new SongBlock();
        b->setSong(song);
        b->setTitle(song->title());
        b->setStyleSheet("background-color: white;");
        g->addWidget(b, row, col);
        ++ctr;
    }
}

void PlaylistGroup::loadGroup(const QJsonArray &items, QVector<Playlist*>* playlists)
{

    QGridLayout* g = static_cast<QGridLayout*>(grid());

    qDebug() << "inside";
    int ctr = 0;
    for(QJsonValue playlist: items){
        qDebug() << "insisde loop";


        playlists->append(new Playlist());
        playlists->last()->read(playlist.toObject());

        qDebug() << playlists->last()->list()->size();

        int row, col;
        row = ctr % 2;

        if(row == 0) col = ctr;
        else col = ctr - 1;

        PlaylistBlock* b = new PlaylistBlock();
//        b->setObjectName(playlists->last()->typeName(playlists->last()->type()) + QString::number(ctr));
        b->setObjectName("playlistbutton");

        b->setPlaylist(playlists->last());
        b->setTitle(playlists->last()->title());
        b->setStyleSheet("background-color: white;");
        g->addWidget(b, row, col);
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
