#include "PlaylistScreen.h"
#include "ui_PlaylistScreen.h"

PlaylistScreen::PlaylistScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PlaylistScreen)
{
    ui->setupUi(this);


}

PlaylistScreen::~PlaylistScreen()
{
    delete ui;
}
