#include "MainWindow.h"
#include <QApplication>
#include <QMediaPlayer>
#include <QDebug>
#include <QFileInfo>
#include "Song.h"
#include <QDir>
#include <QDirIterator>
#include <QHash>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

//    QMediaPlayer* player = new QMediaPlayer;
//    QDir path = QDir(QString(getenv("HOME")) + "/Music" + "/DAMN" + "/DNA.m4a");
//    Song* src = new Song(path);

//    player->setMedia((*src));
//    qDebug() << "path: " << src->path();
//    player->setVolume(100);
//    player->play();

//    qDebug() << "Testing metadata: ";
//    qDebug() << "album: " << src->album() << "\nartist: " << src->artist();
//    qDebug() << "genre: " << src->genre() << "\ncomment: " << src->comment();
//    qDebug() << "title: " << src->title();

//    qDebug() << "track: " << src->track() << "\nyear: " << src->year();

    QDir p = QDir(QString(getenv("HOME")) + "/Music");
    QDirIterator it(p, QDirIterator::Subdirectories);

    // most common audio files:
    QHash<QString, unsigned int> valids;
    QString valid[] = {"m4a","mp3", "aac","ogg","flac","alac","wma","wav","aiff"};
    for(int i = 0; i < 9; ++i){
        valids.insert(valid[i], 1);
    }


    while(it.hasNext()){
        QFileInfo f(it.filePath());
        if(f.isFile()){
            if(valids.contains(f.suffix().toLower())){
                qDebug() << "base: " << f.baseName();
            }
        }
        it.next();
    }



    w.show();

    return a.exec();
}
