#ifndef IMAGEBLOCK_H
#define IMAGEBLOCK_H

#include <QGroupBox>
#include <QPixmap>
#include <QLabel>
#include <QMouseEvent>


class ImageBlock : public QGroupBox
{
        Q_OBJECT
public:
    ImageBlock(QWidget * parent = 0);
    ImageBlock(const QString& title, QWidget* parent = 0);

    QLabel* image();
    QLabel* title();

    void init();
    void setTitle(const QString& title);
    void setImage(const QString& path);

private:
    QLabel* image_;
    QLabel* title_;

signals:
    void clicked();

protected:
    void mousePressEvent(QMouseEvent* event);

};

#endif // IMAGEBLOCK_H
