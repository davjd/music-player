#include "RotatedButton.h"
#include <QStylePainter>
#include <QStyleOptionButton>
#include <QPoint>
#include <QMenu>

RotatedButton::RotatedButton()
    : QPushButton()
{
    init();
}
RotatedButton::RotatedButton(QWidget* parent)
    : QPushButton(parent)
{
    init();
}
RotatedButton::RotatedButton(const QString& text, QWidget* parent)
    : QPushButton(text, parent)
{
    init();
}
RotatedButton::RotatedButton(const QIcon& icon, const QString& text, QWidget* parent)
    : QPushButton(icon, text, parent)
{
    init();
}

RotatedButton::RotatedButton(const QString& text, Qt::Orientation orientation,  bool mirrored, QWidget* parent)
    : QPushButton(text, parent)
{
    orientation_ = orientation;
    mirrored_ = mirrored;
}

void RotatedButton::setMirrored(bool mirrored){
    mirrored_ = mirrored;
}

bool RotatedButton::mirrored() const{
    return mirrored_;
}

void RotatedButton::setOrientation(Qt::Orientation orientation){
    orientation_ = orientation;
}

Qt::Orientation RotatedButton::orientation() const{
    return orientation_;
}

QSize RotatedButton::sizeHint() const{

    QSize size = QPushButton::sizeHint();
    if (orientation_ == Qt::Vertical){
        size.transpose();
        size.setWidth(0);
    }
    return size;
}
QSize RotatedButton::minimumSizeHint() const{
    QSize size = QPushButton::minimumSizeHint();
            /*if (orientation_ == Qt::Vertical)
                    size.transpose();*/
    return size;
}
QStyleOptionButton RotatedButton::getStyleOption() const{

    QStyleOptionButton opt;
    opt.initFrom(this);
    if (orientation_ == Qt::Vertical)
    {
        QSize size = opt.rect.size();
        size.transpose();
        opt.rect.setSize(size);
    }
    opt.features = QStyleOptionButton::None;
    if (isFlat())
        opt.features |= QStyleOptionButton::Flat;
    if (menu())
        opt.features |= QStyleOptionButton::HasMenu;
    if (autoDefault() || isDefault())
        opt.features |= QStyleOptionButton::AutoDefaultButton;
    if (isDefault())
        opt.features |= QStyleOptionButton::DefaultButton;
    if (isDown() || (menu() && menu()->isVisible()))
        opt.state |= QStyle::State_Sunken;
    if (isChecked())
        opt.state |= QStyle::State_On;
    if (!isFlat() && !isDown())
        opt.state |= QStyle::State_Raised;
    opt.text = text();
    opt.icon = icon();
    opt.iconSize = iconSize();
    return opt;
}

void RotatedButton::setTextColor(QColor color)
{
    QPalette p = palette();
    p.setColor(QPalette::ButtonText, color);
    setPalette(p);
}

void RotatedButton::setBackgroundColor(QColor color)
{
    QPalette p = palette();
    p.setColor(QPalette::Button, color);
    setPalette(p);
}

void RotatedButton::init(){
    orientation_ = Qt::Horizontal;
    mirrored_ = false;
}

void RotatedButton::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QStylePainter p(this);

    switch (orientation_)
    {
        case Qt::Horizontal:
            if (mirrored_)
            {
                p.rotate(180);
                p.translate(-width(), -height());
            }
            break;

        case Qt::Vertical:
            if (mirrored_)
            {
                p.rotate(-90);
                p.translate(-height(), 0);
            }
            else
            {
                p.rotate(90);
                p.translate(0, -width());
            }
            break;
    }

    p.drawControl(QStyle::CE_PushButton, getStyleOption());
}
