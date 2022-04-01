#include "mytimer.h"
#include <QtCore>
#include <QDebug>
#include <background.h>
#include <QSignalMapper>

MyTimer::MyTimer(Character * enemy, Player * p, Room* r)
{
    villian=enemy;
    room=r;
    play=p;
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this, SLOT(villianSlot()));
    timer->start(1000);
    x=0;
}

MyTimer::~MyTimer()
{
    timer->deleteLater();
    room=nullptr;
    play=nullptr;
    villian=nullptr;
}

void MyTimer::stopTimer()
{
    timer->stop();
}




