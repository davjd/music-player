#include "RotatedButton.h"
#include <QStylePainter>
#include <QStyleOptionButton>

RotatedButton::RotatedButton()
    : QPushButton()
{

}
RotatedButton::RotatedButton(QWidget* parent)
    : QPushButton(parent)
{

}
RotatedButton::RotatedButton(const QString& text, QWidget* parent)
    : QPushButton(text, parent)
{

}
RotatedButton::RotatedButton(const QIcon& icon, const QString& text, QWidget* parent)
    : QPushButton(icon, text, parent)
{

}

void RotatedButton::paintEvent(QPaintEvent *)
{
    QStylePainter painter(this);
    painter.rotate(-45);

    QStyleOptionButton o;
    o.initFrom(this);

    painter.drawControl(QStyle::CE_PushButton, o);
    painter.drawControl(QStyle::CE_PushButtonBevel, o);
    painter.drawControl(QStyle::CE_PushButtonLabel, o);
}
