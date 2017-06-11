#include "ImageBlock.h"
#include <QVBoxLayout>
#include <QPalette>

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

void ImageBlock::setTitle(const QString& title){
    title_->setText(title);
}

void ImageBlock::setImage(const QString& path){
    image_->setPixmap(QPixmap(path));
}

void ImageBlock::init(){
    title_ = new QLabel();
    image_ = new QLabel();

    setImage(":/buttons/musical-note.svg");
    setTitle("Title");
    title_->setAlignment(Qt::AlignCenter);

    QVBoxLayout* grid = new QVBoxLayout();
    grid->addWidget(image_);
    grid->addWidget(title_);
    setLayout(grid);
}
