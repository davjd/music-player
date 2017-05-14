#include "SongScreen.h"
#include "ui_SongScreen.h"

SongScreen::SongScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SongScreen)
{
    ui->setupUi(this);
}

SongScreen::~SongScreen()
{
    delete ui;
}
