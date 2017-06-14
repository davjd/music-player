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

#include <QJsonDocument>
#include <QFile>

#include "PlaylistGroup.h"

#include "ImageBlock.h"

#include "Serializer.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include "Playlist.h"
#include "Song.h"




MusicPlayer* player;

QJsonDocument loadJson(QString fileName) {
    QFile jsonFile(fileName);
    jsonFile.open(QFile::ReadOnly);
    return QJsonDocument().fromJson(jsonFile.readAll());
}

void saveJson(QJsonDocument document, QString fileName) {
    QFile jsonFile(fileName);
    jsonFile.open(QFile::WriteOnly);
    jsonFile.write(document.toJson());
}

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
//                        qDebug() << "value: " << f.baseName() << "\nkey: "
//                                 << f.absolutePath();
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
//           qDebug() << "value: " << f.baseName() << "\nkey: "
//                    << f.absolutePath();
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


    player = new MusicPlayer();
    player->setVolume(100);

    QHash<QString, QVector<Song*>* >* list = new QHash<QString, QVector<Song*>*>();
    QDir base(QString(getenv("HOME")) + "/Music");
    iterate(list, QDir(base));


//    Playlist* pl = new Playlist();
//    pl->setTitle("ALLSONGS");

//    for(auto i = list->begin(); i != list->end(); ++i){
//        for(auto ii = i.value()->begin(); ii != i.value()->end(); ++ii){
//            pl->push_back((*ii));
//        }
//    }






//    Serializer s;
//    QJsonArray recordsArray;
//    QJsonObject o;
//    pl->write(o);
//    pl->open(o);

//    recordsArray.push_back(o);

//    QJsonDocument doc(recordsArray);
//    s.saveJson(doc, "playlists.txt");


//    qDebug() << doc.toJson();






//    qDebug() << "Path: " <<base.absolutePath();

//    player->insert(list->value(list->begin()));

    MainWindow *w = new MainWindow();
    w->show();

//    PlaylistGroup* group = new PlaylistGroup("Auto Playlists");
//    group->show();


//    SongScreen* screen = new SongScreen();
//    screen->show();

//    QDir* d = new QDir(QString(getenv("HOME")) + "/Music/trav/butterfly.mp3");

////    qDebug() << "p: " << d->absolutePath();







//    Playlist* pl = new Playlist();




//    Serializer s;

//    QJsonArray recordsArray;
////    recordsArray.push_back(recordObject);
////    QJsonDocument doc(recordsArray);
////    qDebug() << doc.toJson();

////    QJsonObject so1;
//    Song* s1 = new Song(new QDir(QString(getenv("HOME")) + "/Music/trav/butterfly.mp3"));
////    s1->write(so1);

////    QJsonObject so2;
//    Song* s2 = new Song(new QDir(QString(getenv("HOME")) + "/Music/trav/a man.mp3"));
////    s2->write(so2);

////    recordsArray.push_back(so1);
////    recordsArray.push_back(so2);

//    QJsonArray doc = s.loadJson("playlists.txt").array();
//    auto o = doc.first().toObject();
//    s1->read(o);

//    qDebug() << "title: " << s1->title();




//    for(auto keys: doc){
//        qDebug() << keys;
//    }

//    s.saveJson(doc, "songs.txt");

//    qDebug() << doc;









//    QJsonObject recordObject;
//    recordObject.insert("FirstName", QJsonValue::fromVariant("John"));
//    recordObject.insert("LastName", QJsonValue::fromVariant("Doe"));
//    recordObject.insert("Age", QJsonValue::fromVariant(43));

//    QJsonObject addressObject;
//    addressObject.insert("Street", "Downing Street 10");
//    addressObject.insert("City", "London");
//    addressObject.insert("Country", "Great Britain");
//    recordObject.insert("Address", addressObject);

//    QJsonArray phoneNumbersArray;
//    phoneNumbersArray.push_back("+44 1234567");
//    phoneNumbersArray.push_back("+44 2345678");
//    recordObject.insert("Phone Numbers", phoneNumbersArray);

//    QJsonArray recordsArray;
//    recordsArray.push_back(recordObject);
//    QJsonDocument doc(recordsArray);
//    qDebug() << doc.toJson();



    return a.exec();
}
