#-------------------------------------------------
#
# Project created by QtCreator 2017-05-02T17:04:39
#
#-------------------------------------------------

QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = music
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
# include other libs:
INCLUDEPATH += /usr/include/taglib
LIBS += -ltag

SOURCES += main.cpp\
        MainWindow.cpp \
    Song.cpp \
    SongScreen.cpp \
    MusicPlayer.cpp \
    Playlist.cpp \
    IntroScreen.cpp \
    RotatedButton.cpp \
    PlaylistScreen.cpp \
    ImageBlock.cpp \
    Serializer.cpp

HEADERS  += MainWindow.h \
    Song.h \
    SongScreen.h \
    MusicPlayer.h \
    Player.h \
    Playlist.h \
    IntroScreen.h \
    RotatedButton.h \
    PlaylistScreen.h \
    ImageBlock.h \
    Serializer.h

FORMS    += MainWindow.ui \
    SongScreen.ui \
    IntroScreen.ui \
    PlaylistScreen.ui

CONFIG += mobility
MOBILITY = 

RESOURCES += \
    images.qrc

DISTFILES += \
    ../Downloads/151845-music-player-icons/svg/cancel.svg \
    ../Downloads/151845-music-player-icons/svg/plus.svg \
    ../Downloads/151845-music-player-icons/svg/fast-forward.svg \
    ../Downloads/151845-music-player-icons/svg/next-1.svg \
    ../Downloads/151845-music-player-icons/svg/back.svg \
    ../Downloads/151845-music-player-icons/svg/previous.svg \
    ../Downloads/151845-music-player-icons/svg/list.svg \
    ../Downloads/151845-music-player-icons/svg/musical-note.svg \
    ../Downloads/151845-music-player-icons/svg/equalizer.svg \
    ../Downloads/151845-music-player-icons/svg/up-arrow.svg \
    ../Downloads/151845-music-player-icons/svg/minus.svg \
    ../Downloads/151845-music-player-icons/svg/next.svg \
    ../Downloads/151845-music-player-icons/svg/play-button.svg \
    ../Downloads/151845-music-player-icons/svg/power-button.svg \
    ../Downloads/151845-music-player-icons/svg/eject.svg \
    ../Downloads/151845-music-player-icons/svg/rewind.svg \
    ../Downloads/151845-music-player-icons/svg/down-arrow.svg \
    ../Downloads/151845-music-player-icons/svg/stop.svg \
    ../Downloads/151845-music-player-icons/svg/replay.svg \
    ../Downloads/151845-music-player-icons/svg/pause.svg \
    ../Downloads/151845-music-player-icons/svg/speaker.svg \
    ../Downloads/151845-music-player-icons/svg/bar-graph.svg \
    ../Downloads/151845-music-player-icons/svg/share.svg \
    ../Downloads/151845-music-player-icons/svg/checked.svg \
    Data/Storage.txt

