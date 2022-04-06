QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    background.cpp \
    bar.cpp \
    cafe.cpp \
    coldstorageitem.cpp \
    dining.cpp \
    dishwasher.cpp \
    inventory.cpp \
    item.cpp \
    kitchen.cpp \
    lounge.cpp \
    main.cpp \
    mainwindow.cpp \
    player.cpp \
    room.cpp \
    storageitem.cpp \
    zork.cpp

HEADERS += \
    background.h \
    bar.h \
    cafe.h \
    coldstorageitem.h \
    dining.h \
    dishwasher.h \
    inventory.h \
    item.h \
    kitchen.h \
    lounge.h \
    mainwindow.h \
    myvector.h \
    player.h \
    room.h \
    storageitem.h \
    zork.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

SUBDIRS += \
    MYFINALZORKGAME.pro \
    myfinalzork.pro

RESOURCES += \
    images.qrc

DISTFILES += \
    Treasure - Copy.jpeg \
    attack - Copy.png \
    cave - Copy.jpg \
    dragon - Copy.jpg \
    dragon - Copy.png \
    dragonAttack - Copy.png \
    imgres - Copy.jpg \
    key - Copy.png \
    pic - Copy.jpg \
    potion - Copy.jpg \
    potion.jpg \
    sword - Copy.jpg \
    sword2 - Copy.jpg \
    teleporter - Copy.png \
    treasure - Copy.jpg \
    vampire - Copy.png
