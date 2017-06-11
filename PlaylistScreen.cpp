#include "PlaylistScreen.h"
#include "ui_PlaylistScreen.h"

#include "Serializer.h"
#include <QJsonDocument>

PlaylistScreen::PlaylistScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PlaylistScreen)
{
    ui->setupUi(this);
    list_ = new QVector<Playlist*>();


}

PlaylistScreen::~PlaylistScreen()
{
    delete ui;
}

void PlaylistScreen::loadPlaylists()
{
    Serializer loader();
}
