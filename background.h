#ifndef BACKGROUND_H
#define BACKGROUND_H
//-----------------------------------
#include <QGraphicsScene>
#include <QPushButton>
#include <QGraphicsRectItem>
#include "monster.h"
#include "room.h"
#include "mytimer.h"
#include "item.h"
#include "player.h"
#include "boss.h"
#include "princess.h"
#include "key.h"
#include "weapon.h"
#include "teleporter.h"
#include "potion.h"
#include <QtCore>
#include <string>
#include <QTextEdit>
#include "character.h"
#include <vector>
#include <QComboBox>
#include "myvector.h"
#include <QGraphicsPixmapItem>
#include <QMessageBox>
#include <QPlainTextEdit>
#include <QDebug>
#include <QObject>
#include "zork.h"
#include <QMessageBox>
//-----------------------------------
class Background : public QGraphicsScene
{
    Q_OBJECT
    public:
        explicit Background(Zork* zork);
        ~Background();
        void setScene(const string direction);
        inline void refreshScene();
        void setRoomExits(Room * r);
        void createCave();
        void createTextBox();
        void createMapGUI();
        inline void addToScene();
        inline void clearBackground();
        void addText();
        void inventoryBox();
        void controlsBox();
        void keyPressEvent(QKeyEvent *event);
        void close();
        int delB5=0;
    public slots:
        void on_button1_clicked();
        void on_button2_clicked();
        void on_button3_clicked();
        void on_button4_clicked();
        void on_button5_clicked();
        void on_button6_clicked();
        void on_button7_clicked();
        void on_button8_clicked();
        void on_button9_clicked();
        void on_button10_clicked();
        void on_button11_clicked();
        void on_button12_clicked();
        void on_button13_clicked();
        void on_button14_clicked();
    private:
        QMessageBox msgBox;
        QMessageBox msgBox1;
        QMessageBox msgBox2;
        QMessageBox msgBox3;
        QMessageBox msgBox4;
        QMessageBox msgBox5;
        QMessageBox msgBox6;
        QMessageBox msgBox7;
        QMessageBox msgBox8;
        QMessageBox msgBox9;
        QString inventoryContString;
        Zork* zork1;
        QGraphicsPixmapItem *cave;
        QString inventoryString;
        QTextEdit * smallEditor;
        QTextEdit * inventoryEditor;
        Room * nextRoom;
        Player * player;
        int delB1=0;
        int delB2=0;
        int delB3=0;
        int delB4=0;
        int delB6=0;
        int delB7=0;
        int delB8=0;
        int delB9=0;
        int delB10=0;
        int delB11=0;
        int delB12=0;
        int delB13=0;
        int delB14=0;
        QPushButton * button1;
        QPushButton * button2;
        QPushButton * button3;
        QPushButton * button4;
        QPushButton * button5;
        QPushButton * button6;
        QPushButton * button7;
        QPushButton * button8;
        QPushButton * button9;
        QPushButton * button10;
        QPushButton * button11;
        QPushButton * button12;
        QPushButton * button13;
        QPushButton * button14;
        MyTimer * timer;
        Inventory * inventory;
        Item * item;
        Item * itemToDrop;
        vector<Item*> itemsInInventory;
        myVector<QString> controls;
        QGraphicsRectItem *RoomA,*RoomB,*RoomC,*RoomD,*RoomE,*RoomF,*RoomG,*RoomH,*RoomI,*RoomJ;
        QComboBox *inventoryComboBox;
        QComboBox *controlsComboBox;
};

#endif // BACKGROUND_H
