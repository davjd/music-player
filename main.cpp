#include "MainWindow.h"
#include <QApplication>
#include <QMediaPlayer>
#include <QDebug>
#include <QFileInfo>
#include <QObject>
#include <fileref.h>
#include "Song.h"
#include <QDir>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    QMediaPlayer* player = new QMediaPlayer;
    QDir path = QDir(QString(getenv("HOME")) + "/Music" + "/DAMN" + "/DNA.m4a");

//    Song* src = new Song(QUrl::fromLocalFile(QFileInfo("pride.m4a").absoluteFilePath()));
    Song* src = new Song(path);
//    player->setMedia(QUrl("file://" + path.absolutePath()));
    player->setMedia((*src));
//    qDebug() << "path: " << src->canonicalUrl().toString();
    qDebug() << "path: " << src->path();
//    qDebug() << "from home: " << path.toStdString().data();
//    player->setMedia((*src));
//    src->setPlayer(player);
//    QObject::connect(player, SIGNAL(mediaStatusChanged(QMediaPlayer::MediaStatus)),
//                     src, SLOT(printMeta()));
    player->setVolume(100);
    player->play();

    qDebug() << "url: " << QUrl("file://" + path.absolutePath());
//    qDebug() << "file://" + path.absolutePath();

    TagLib::FileRef f(path.absolutePath().toStdString().data());
    TagLib::String artist = f.tag()->artist();
    qDebug() << QString::fromStdString(artist.to8Bit());
    w.show();

    return a.exec();
}
