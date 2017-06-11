#ifndef SERIALIZER_H
#define SERIALIZER_H

#include <QJsonDocument>


class Serializer
{
public:

    Serializer();
    QJsonDocument loadJson(const QString& fileName);
    void saveJson(QJsonDocument& document, const QString& fileName);
    void loadTxt(const QString& fileName, QVector<QString>* paths);
    void saveTxt(const QString &fileName, const QVector<QString>* paths);



};

#endif // SERIALIZER_H
