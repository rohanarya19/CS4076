QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    background.cpp \
    boss.cpp \
    character.cpp \
    enemy.cpp \
    inventory.cpp \
    item.cpp \
    key.cpp \
    main.cpp \
    mainwindow.cpp \
    monster.cpp \
    mytimer.cpp \
    player.cpp \
    potion.cpp \
    princess.cpp \
    room.cpp \
    teleporter.cpp \
    weapon.cpp \
    zork.cpp

HEADERS += \
    background.h \
    boss.h \
    character.h \
    inventory.h \
    item.h \
    key.h \
    mainwindow.h \
    monster.h \
    mytimer.h \
    myvector.h \
    player.h \
    potion.h \
    princess.h \
    room.h \
    teleporter.h \
    weapon.h \
    zork.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc

DISTFILES += \
    .gitignore \
    MYFINALZORKGAME.pro.user \
    Treasure - Copy.jpeg \
    Treasure.jpeg \
    attack - Copy.png \
    attack.png \
    burger.jpg \
    cave - Copy.jpg \
    cave.jpg \
    dragon - Copy.jpg \
    dragon - Copy.png \
    dragon.jpg \
    dragon.png \
    dragon.xcf \
    dragonAttack - Copy.png \
    dragonAttack.png \
    imgres - Copy.jpg \
    imgres.jpg \
    irish-guiness.jpg \
    key - Copy.png \
    key.png \
    pic - Copy.jpg \
    pic.jpg \
    potion - Copy.jpg \
    potion.jpg \
    princess.jpg \
    princess.xcf \
    restaurantmain.jpg \
    sword - Copy.jpg \
    sword.jpg \
    sword2 - Copy.jpg \
    sword2.jpg \
    teleporter - Copy.png \
    teleporter.png \
    treasure - Copy.jpg \
    treasure.jpg \
    vampire - Copy.png \
    vampire.png \
    vampireAttacked.png
