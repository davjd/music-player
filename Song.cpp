#include "Song.h"
#include <QDebug>
#include <QMediaMetaData>

Song::Song(QDir ref) : QMediaContent(QUrl("file://" + ref.absolutePath()))
{
    path_ = QUrl("file://" + ref.absolutePath());

//    source_ = new TagLib::FileRef(ref);
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

unsigned Song::track(){
    return source_->tag()->track();
}

unsigned Song::year(){
    return source_->tag()->year();
}

QUrl Song::path(){
    return path_;
}

TagLib::FileRef* Song::source(){
    return source_;
}

//void Song::printMeta(){
//    won't be needed anymore.
//    qDebug() << player_->isMetaDataAvailable();
//    qDebug() << "Title: " << player_->metaData(QMediaMetaData::Title).toString();
//    qDebug() << "Author: " << player_->metaData(QMediaMetaData::Author).toString();
//}
