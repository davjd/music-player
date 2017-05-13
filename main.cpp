#include "MainWindow.h"
#include <QApplication>
#include <QMediaPlayer>
#include <QDebug>
#include <QFileInfo>
#include "Song.h"
#include <QDir>
#include <QDirIterator>
#include <QHash>
#include <QQueue>


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
    QQueue<Song*> playlist;

    while(it.hasNext()){
        QFileInfo f(it.filePath());
        if(f.isFile()){
            if(valids.contains(f.suffix().toLower())){
                qDebug() << "base: " << f.baseName();
                playlist.enqueue(new Song(QDir(f.filePath())));
            }
        }
        it.next();
    }

    qDebug() << "\n\n\n\nPlaylist: ";
    QList<Song*>::iterator iter;
    for(iter = playlist.begin(); iter != playlist.end(); ++iter){
        qDebug() << "album: " << (*iter)->album() << "\nartist: " << (*iter)->artist();
        qDebug() << "genre: " << (*iter)->genre() << "\ncomment: " << (*iter)->comment();
        qDebug() << "title: " << (*iter)->title();

        qDebug() << "track: " << (*iter)->track() << "\nyear: " << (*iter)->year();
        qDebug() << (*iter)->path() << "\n\n";
    }




    w.show();

    return a.exec();
}
