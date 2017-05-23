#include "MainWindow.h"
#include "SongScreen.h"
#include <QApplication>
#include <QDebug>
#include <QFileInfo>
#include <QDir>
#include <QDirIterator>
#include <QHash>
#include "Song.h"
#include "Player.h"
#include <QVector>


MusicPlayer* player;

void setList(QVector< QVector<Song*> >* &playlist){
    QDir p = QDir(QString(getenv("HOME")) + "/Music");
    QDirIterator it(p.absolutePath(), QDir::Files, QDirIterator::Subdirectories);

    // most common audio files:
    QHash<QString, unsigned int> valids;
    QString valid[] = {"m4a","mp3", "aac","ogg","flac","alac","wma","wav","aiff"};
    for(int i = 0; i < 9; ++i){
        valids.insert(valid[i], 1);
    }
}

void iterateDir(QVector< QVector<Song*> >* &playlist, QDirIterator iter, QHash<QString, unsigned int> valids){
    while(iter.hasNext()){
        QFileInfo f(iter.filePath());

        if(f.isFile()){
            if(valids.contains(f.suffix().toLower())){
                qDebug() << "base: " << f.baseName();
                player->insert(new Song(QDir(f.filePath())));
            }
        }
        iter.next();
    }

     //there will still be one more file, because of hasNext().
    QFileInfo f(iter.filePath());
    if(f.isFile()){
        if(valids.contains(f.suffix().toLower())){
            qDebug() << "base: " << f.baseName();
            player->insert(new Song(QDir(f.filePath())));
        }
    }
}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    player = new MusicPlayer();
    player->setVolume(100);

    QVector< QVector<Song*> >* list = new QVector< QVector<Song*> >();


    QDir p = QDir(QString(getenv("HOME")) + "/Music/trav");
    QDirIterator it(p.absolutePath(), QDir::Files, QDirIterator::Subdirectories);

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
                player->insert(new Song(QDir(f.filePath())));
            }
        }
        it.next();
    }

     //there will still be one more file, because of hasNext().
    QFileInfo f(it.filePath());
    if(f.isFile()){
        if(valids.contains(f.suffix().toLower())){
            qDebug() << "base: " << f.baseName();
            player->insert(new Song(QDir(f.filePath())));
        }
    }


//    MainWindow w;
    SongScreen screen;

//    w.show();
    screen.show();

    return a.exec();
}
