#include "Playlist.h"

Playlist::Playlist()
{
    list_ = new QVector<Song*>();
}

void Playlist::push_back(Song *song){
    list_->push_back(song);
}

QVector<Song* >* Playlist::list(){
     return list_;
}

void Playlist::setTitle(QString title){
    title_ = title;
}

QString Playlist::title(){
    return title_;
}

void Playlist::read(const QJsonObject &json){

}

void Playlist::write(QJsonObject &json){
//    json["title"] = title_;
//    json["list"] = ;
//    json["title"] = title();
//    json["artist"] = artist();
}
