#include "Serializer.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>

Serializer::Serializer()
{}

void Serializer::loadTxt(const QString &fileName, QVector<QString>* paths){
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        qDebug() << "line: " << line;
    }
}

void Serializer::saveTxt(const QString &fileName, const QVector<QString> *paths){
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;

    QTextStream out(&file);
    for(QString path: (*paths)){
        out << path;
    }
}

QJsonDocument Serializer::loadJson(const QString& fileName) {

    QFile jsonFile(fileName);
    jsonFile.open(QFile::ReadOnly);
    return QJsonDocument().fromJson(jsonFile.readAll());
}

void Serializer::saveJson(QJsonDocument& document, const QString& fileName) {
    QFile jsonFile(fileName);
    jsonFile.open(QFile::WriteOnly);
    jsonFile.write(document.toJson());
}
