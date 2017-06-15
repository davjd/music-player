#include "Playlist.h"
#include <QJsonArray>


Playlist::Playlist()
{
    list_ = new QVector<Song*>();
    time_ = time_.currentTime();
    type_ = Type::auto_gen;
}

void Playlist::push_back(Song *song){
    list_->push_back(song);
}

QVector<Song* >* Playlist::list(){
     return list_;
}

void Playlist::setTitle(const QString& title){
    title_ = title;
}

QString Playlist::title(){
    return title_;
}

void Playlist::read(const QJsonObject& json){

//    qDebug() << "title: " <<
    title_ = parseTitle(json["title"].toString());
    QJsonArray songs = json["songs"].toArray();
    for(QJsonValue data: songs){
        Song* song = new Song();
        song->read(data.toObject());
        list_->push_back(song);
    }
    type_ = (Type)json["type"].toInt();

    QJsonObject time = json["time"].toObject();
    time_ = QTime(time["hour"].toInt(),
            time["minute"].toInt(),
            time["ms"].toInt());
}

void Playlist::write(QJsonObject& json){
    json["title"] = QString::number(type_) + "." + title_;
    QJsonArray songs;
    for(Song* song : (*list_)){
      QJsonObject data;
      song->write(data);
      songs.push_back(data);
    }
    json["songs"] = QJsonValue(songs);
    json["type"] = type_;
    open(json);
}

QTime Playlist::time()
{
    return time_;
}

Playlist::Type Playlist::type(){
    return type_;
}

QString Playlist::typeName(Playlist::Type type)
{
   switch(type){
        case Playlist::Type::auto_gen :
            return "Auto Playlists";
            break;
        case Playlist::Type::user_gen :
            return "Your Playlists";
            break;
        case Playlist::Type::smart_gen :
            return "Curated Playlists";
            break;
        default : return "";
   }
}

void Playlist::open(QJsonObject& json){
    time_ = time_.currentTime();
    QJsonObject o;
    o["hour"] = time_.hour();
    o["minute"] = time_.minute();
    o["ms"] = time_.msec();
    json["time"] = o;
}

void Playlist::setType(Playlist::Type type)
{
   type_ = type;
}

QString Playlist::parseTitle(QString title){
    const int i = title.indexOf('.');
    return title.mid(1 + i);

}
