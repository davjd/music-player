#ifndef SONG_H
#define SONG_H

#include <QObject>
#include <QUrl>
#include <QMediaContent>
#include <QMediaPlayer>
#include <fileref.h>
#include <QString>
#include <QDir>


class Song : public QObject, public QMediaContent
{
    Q_OBJECT
public:
    Song(QDir ref);
    QString artist();
    QString title();
    QString album();
    QString genre();
    unsigned int track();
    unsigned int year();
    QString comment();
    QUrl path();
    TagLib::FileRef* source();


private:
    TagLib::FileRef* source_;
    QUrl path_;

//public slots:
//    void printMeta();
};

#endif // SONG_H
