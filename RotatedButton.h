#ifndef ROTATEDBUTTON_H
#define ROTATEDBUTTON_H

#include <QPushButton>
#include <QIcon>


class RotatedButton : public QPushButton
{
public:
    RotatedButton();
    RotatedButton(QWidget* parent = 0);
    RotatedButton(const QString& text, QWidget* parent = 0);
    RotatedButton(const QIcon& icon, const QString& text, QWidget* parent = 0);

protected:
    virtual void paintEvent(QPaintEvent* event);


};

#endif // ROTATEDBUTTON_H
