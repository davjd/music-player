#include "Song.h"
#include <QDebug>

Song::Song()
{

}

Song::Song(QDir ref)
{
    // ugly but for now i'll leave it like this...
    path_ = QUrl("file://" + ref.absolutePath());
    source_ = new TagLib::FileRef(ref.absolutePath().toStdString().data());
    content_ = new QMediaContent(QUrl("file://" + ref.absolutePath()));
}

Song::~Song(){
    delete source_;
    delete content_;
}

QString Song::artist()
{
    return QString::fromStdString(source_->tag()->artist().to8Bit());
}

QString Song::title()
{
    return QString::fromStdString(source_->tag()->title().to8Bit());
}

QString Song::genre()
{
    return QString::fromStdString(source_->tag()->genre().to8Bit());
}

QString Song::comment()
{
    return QString::fromStdString(source_->tag()->comment().to8Bit());
}

QString Song::album()
{
    return QString::fromStdString(source_->tag()->album().to8Bit());
}

unsigned int Song::track(){
    return source_->tag()->track();
}

unsigned int Song::year(){
    return source_->tag()->year();
}

QUrl Song::path(){
    return path_;
}

TagLib::FileRef* Song::source(){
    return source_;
}

void Song::setS(TagLib::FileRef* s){
    source_ = s;
}

void Song::setP(QUrl p){
    path_ = p;
}

void Song::setContent(QMediaContent* content){
    content_ = content;
}

QMediaContent* Song::content(){
    return content_;
}
