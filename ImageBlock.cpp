#include "ImageBlock.h"
#include <QGridLayout>

ImageBlock::ImageBlock()
    : QGroupBox()
{
    init();
}

ImageBlock::ImageBlock(QWidget* parent)
    :QGroupBox(parent)
{
    init();
}

ImageBlock::ImageBlock(const QString& title, QWidget* parent)
    :QGroupBox(title, parent)
{
    init();

}

void ImageBlock::init(){
    title_ = new QLabel();
    image_ = new QPixmap();

    title_->setText("Hello");
    image_->load(":/buttons/musical-note.svg");

    QGridLayout* grid = new QGridLayout();
    grid->addWidget(title_);
    grid->addWidget(image_);
    setLayout(grid);
}
