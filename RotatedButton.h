#ifndef ROTATEDBUTTON_H
#define ROTATEDBUTTON_H

#include <QPushButton>
#include <QIcon>


class RotatedButton : public QPushButton
{
public:
    RotatedButton();
    RotatedButton(QWidget* parent);
    RotatedButton(const QString& text, QWidget* parent);
    RotatedButton(const QIcon& icon, const QString& text, QWidget* parent);

protected:
    virtual void paintEvent(QPaintEvent* event);


};

#endif // ROTATEDBUTTON_H
