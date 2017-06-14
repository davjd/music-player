#ifndef SERIALIZER_H
#define SERIALIZER_H

#include <QJsonDocument>
#include <QJsonValue>


class Serializer
{
public:

    Serializer();
    QJsonDocument loadJson(const QString& fileName);
    void saveJson(QJsonDocument& document, const QString& fileName);
    void loadTxt(const QString& fileName, QVector<QString>* paths);
    void saveTxt(const QString &fileName, const QVector<QString>* paths);

    void modifyJsonValue(QJsonDocument& doc, const QString& path, const QJsonValue& newValue);
    void modifyJsonValue(QJsonValue& destValue, const QString& path, const QJsonValue& newValue);



};

#endif // SERIALIZER_H
