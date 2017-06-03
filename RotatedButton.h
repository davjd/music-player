#ifndef ROTATEDBUTTON_H
#define ROTATEDBUTTON_H

#include <QPushButton>
#include <QIcon>

// credits to: http://svn.codingteam.net/emoglerpp/trunk/src/orientationbutton.cpp


class RotatedButton : public QPushButton
{
public:
    RotatedButton();
    RotatedButton(QWidget* parent = 0);
    RotatedButton(const QString& text, QWidget* parent = 0);
    RotatedButton(const QString& text, Qt::Orientation orientation,  bool mirrored, QWidget* parent = 0);
    RotatedButton(const QIcon& icon, const QString& text, QWidget* parent = 0);

    void setMirrored(bool mirrored);
    void setOrientation(Qt::Orientation orientation);
    Qt::Orientation orientation() const;
    bool mirrored() const;
    QSize sizeHint() const;
    QSize minimumSizeHint() const;
    QStyleOptionButton getStyleOption() const;


private:
    Qt::Orientation orientation_;
    bool mirrored_;

    void init();

protected:
    virtual void paintEvent(QPaintEvent* event);


};

#endif // ROTATEDBUTTON_H
