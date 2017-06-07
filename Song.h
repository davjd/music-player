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

class Song : public QObject, public QMediaContent
{
    Q_OBJECT
public:
    Song();
    Song(QDir ref);
    ~Song();
    QString artist();
    QString title();
    QString album();
    QString genre();
    unsigned int track();
    unsigned int year();
    QString comment();
    QUrl path();
    TagLib::FileRef* source();
//    QMediaContent

    void read(const QJsonObject &json);
    void write(QJsonObject &json) const;



private:
    TagLib::FileRef* source_;
    QUrl path_;
};

#endif // SONG_H
