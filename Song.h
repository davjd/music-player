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

    void setS(TagLib::FileRef* s);
    void setP(QUrl p);

    void setContent(QMediaContent* content);
    QMediaContent* content();



private:
    TagLib::FileRef* source_;
    QUrl path_;
    QMediaContent* content_;
};

#endif // SONG_H
