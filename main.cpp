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
#include "IntroScreen.h"
#include <QVector>
#include <QStackedWidget>
#include <QVBoxLayout>
#include <QComboBox>

#include "ImageBlock.h"



MusicPlayer* player;

void iterate(QHash<QString, QVector<Song*>* >* list, const QDir &directory){
    QDirIterator it(directory.absolutePath(), QDir::Files, QDirIterator::Subdirectories);

    // most common audio files:
    QHash<QString, unsigned int> valids;
    QString valid[]
            = {"m4a","mp3", "aac","ogg","flac","alac","wma","wav","aiff"};

    for(int i = 0; i < 9; ++i){
        valids.insert(valid[i], 1);
    }

    while(it.hasNext()){
        QFileInfo f(it.filePath());
        if(f.isFile()){
                    if(valids.contains(f.suffix().toLower())){
                        QString key = f.absolutePath();
                        qDebug() << "Adding " << f.baseName() << " to key "
                                 << f.absolutePath() << " of lists.";
                        if(!list->contains(key)){
                            list->insert(key, new QVector<Song*>());
                        }
                        list->value(key)->push_back(new Song(new QDir(f.filePath())));
                    }
                }
        it.next();
    }
    //there will still be one more file, because of hasNext().
   QFileInfo f(it.filePath());
   if(f.isFile()){
       if(valids.contains(f.suffix().toLower())){
           QString key = f.absolutePath();
           qDebug() << "Adding " << f.baseName() << " to key "
                    << f.absolutePath() << " of lists.";
           if(!list->contains(key)){
               list->insert(key, new QVector<Song*>());
           }
           list->value(key)->push_back(new Song(new QDir(f.filePath())));
       }
   }
}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


//    player = new MusicPlayer();
//    player->setVolume(100);

//    QHash<QString, QVector<Song*>* >* list = new QHash<QString, QVector<Song*>*>();
//    QDir base(QString(getenv("HOME")) + "/Music/Luv");
//    iterate(list, QDir(base));
//    qDebug() << "Path: " <<base.absolutePath();

//    player->insert(list->value(base.absolutePath()));

//    MainWindow *w = new MainWindow();
//    w->show();


//    SongScreen* screen = new SongScreen();
//    screen->show();

    QDir* d = new QDir(QString(getenv("HOME")) + "/Music/trav/butterfly.mp3");
    qDebug() << "p: " << d->absolutePath();



//    w.show();
//    intro.show();
//    screen.show();

//    ImageBlock* i = new ImageBlock();
//    i->show();




    return a.exec();
}
