#include "Song.h"
#include <QDebug>
#include "taglib/mpegfile.h"
#include "id3v2frame.h"
#include"id3v2tag.h"
#include <attachedpictureframe.h>
#include <QFile>

Song::Song()
{

}

Song::Song(QDir* ref)
{
    // ugly but for now i'll leave it like this...
    path_ = ref;
    source_ = new TagLib::FileRef(ref->absolutePath().toStdString().data());
    content_ = new QMediaContent(QUrl("file://" + ref->absolutePath()));
}

Song::~Song(){
    delete source_;
    delete content_;
    delete path_;
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

QDir* Song::path(){
    return path_;
}

TagLib::FileRef* Song::source(){
    return source_;
}

QPixmap Song::cover()
{
    QFileInfo fi(path()->absolutePath());
    QString ext = fi.suffix();
    if(ext == "mp3"){
        TagLib::MPEG::File file((path()->absolutePath().toStdString().data()));
        TagLib::ID3v2::Tag *m_tag = file.ID3v2Tag(true);
        TagLib::ID3v2::FrameList frameList = m_tag->frameList("APIC");
        if(!frameList.isEmpty()) {
           TagLib::ID3v2::AttachedPictureFrame *coverImg =
                   static_cast<TagLib::ID3v2::AttachedPictureFrame *>(frameList.front());
           QPixmap coverQImg;
           coverQImg.loadFromData((const uchar *) coverImg->picture().data(),
                                  coverImg->picture().size());
           coverQImg = coverQImg.scaled(100,100);
           return coverQImg;
        }
    }
    QPixmap coverQImg(":/buttons/musical-note.svg");
    coverQImg = coverQImg.scaled(100,100);
    return coverQImg;
}

void Song::setS(TagLib::FileRef* s){
    source_ = s;
}

void Song::setP(QDir* p){
    path_ = p;
}

void Song::setContent(QMediaContent* content){
    content_ = content;
}

QMediaContent* Song::content(){
    return content_;
}

void Song::read(const QJsonObject &json){
    path_ = new QDir(json["path"].toString());
    source_ = new TagLib::FileRef(path_->absolutePath().toStdString().data());
    content_ = new QMediaContent(QUrl("file://" + path_->absolutePath()));
}

void Song::write(QJsonObject &json) {
    json["path"] = path_->absolutePath();
    json["title"] = title();
    json["artist"] = artist();
}
