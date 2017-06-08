#ifndef SONG_H
#define SONG_H

#include <QObject>
#include <QUrl>
#include <QMediaContent>
#include <QMediaPlayer>
#include <fileref.h>
#include <QString>
#include <QDir>
#include <QJsonObject>

class Song : public QObject
{
    Q_OBJECT
public:
    Song();
    Song(QDir* ref);
    ~Song();
    QString artist();
    QString title();
    QString album();
    QString genre();
    unsigned int track();
    unsigned int year();
    QString comment();
    QDir* path();
    TagLib::FileRef* source();
//    QMediaContent

    void read(const QJsonObject &json);
    void write(QJsonObject &json);

    void setS(TagLib::FileRef* s);
    void setP(QDir* p);

    void setContent(QMediaContent* content);
    QMediaContent* content();



private:
    TagLib::FileRef* source_;
    QDir* path_;
    QMediaContent* content_;
};

#endif // SONG_H
