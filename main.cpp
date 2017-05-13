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
    Song* src = new Song(path);

    player->setMedia((*src));
    qDebug() << "path: " << src->path();
    player->setVolume(100);
    player->play();



    w.show();

    return a.exec();
}
