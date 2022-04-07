#include <QApplication>
#include <QGraphicsScene>
#include "zork.h"
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
#include <QMainWindow>
#include <QDebug>
#include "restaurant.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Zork *zork1=new Zork();
    restaurant *bg = new restaurant(zork1);
    zork1->setScene(bg);
    zork1->show();
    return app.exec();
}
