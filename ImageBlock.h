#ifndef IMAGEBLOCK_H
#define IMAGEBLOCK_H

#include <QGroupBox>
#include <QPixmap>
#include <QLabel>


class ImageBlock : public QGroupBox
{
public:
    ImageBlock();
    ImageBlock(QWidget * parent = 0);
    ImageBlock(const QString& title, QWidget* parent = 0);

    QPixmap* image();
    QLabel* title();

    void init();



private:
    QPixmap* image_;
    QLabel* title_;

};

#endif // IMAGEBLOCK_H
