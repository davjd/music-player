#ifndef IMAGEBLOCK_H
#define IMAGEBLOCK_H

#include <QGroupBox>
#include <QPixmap>
#include <QLabel>
#include <QMouseEvent>
#include "ScrollText.h"

class ImageBlock : public QGroupBox
{
        Q_OBJECT
public:
    ImageBlock(QWidget * parent = 0);
    ImageBlock(const QString& title, QWidget* parent = 0);

    QLabel* image();
    ScrollText* title();

    void init();
    void setTitle(const QString& title);
    void setImage(const QString& path);
    void setImage(const QPixmap& pic);
    void setSize(const int width, const int height);

private:
    QLabel* image_;
    ScrollText* title_;

signals:
    void clicked();

protected:
    void mousePressEvent(QMouseEvent* event);

};

#endif // IMAGEBLOCK_H
