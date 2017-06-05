#include "ImageBlock.h"
#include <QGridLayout>

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
    QLabel *l = new QLabel();

    title_->setText("Title");
    image_->load(":/buttons/musical-note.svg");
    l->setPixmap((*image_));



    QGridLayout* grid = new QGridLayout();
    grid->addWidget(l, 0, 0);
    grid->addWidget(title_, 1, 0);
    setLayout(grid);
}
