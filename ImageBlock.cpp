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

void ImageBlock::init(){
    title_ = new QLabel();
    image_ = new QPixmap();
    QLabel *l = new QLabel();

    title_->setText("Title");
    image_->load(":/buttons/musical-note.svg");
    l->setPixmap((*image_));
    title_->setAlignment(Qt::AlignCenter);



    QVBoxLayout* grid = new QVBoxLayout();
    grid->addWidget(l);

    grid->addWidget(title_, Qt::AlignCenter);
    setLayout(grid);
}
