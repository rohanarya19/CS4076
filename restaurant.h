#ifndef RESTAURANT_H
#define RESTAURANT_H
//-----------------------------------
#include <QGraphicsScene>
#include <QPushButton>
#include "room.h"
#include "item.h"
#include "player.h"
#include "coldstorageitem.h"
#include "storageitem.h"
#include "kitchen.h"
#include "dining.h"
#include "bar.h"
#include "cafe.h"
#include "lounge.h"
#include "billing.h"
#include "dishwasher.h"
#include <QtCore>
#include <string>
#include <QTextEdit>
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
#include <QLabel>
#include <QFont>
//-----------------------------------
class restaurant : public QGraphicsScene
{
    Q_OBJECT
    public:
        explicit restaurant(Zork* zork);
        ~restaurant();
        void setScene(const string direction);
        inline void refreshScene();
        void setRoomExits(Room * r);
        void createrestaurantmain();
        void createTextBox();
        inline void addToScene();
        inline void clearrestaurant();
        void addText();
        void inventoryBox();
        void close();
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
        void on_button15_clicked();
        void on_button16_clicked();
        void on_button17_clicked();
        void on_button18_clicked();
        void on_button19_clicked();
        void on_button20_clicked();
    private:
        QMessageBox msgBox1;
        QMessageBox msgBox2;
        QMessageBox msgBox4;
        QMessageBox msgBox5;
        QMessageBox msgBox6;
        QMessageBox msgBox7;
        QMessageBox msgBox8;
        QMessageBox msgBox10;
        QMessageBox msgBox11;
        QMessageBox msgBox12;
        QMessageBox msgBox13;
        QMessageBox msgBox14;
        QMessageBox msgBox15;
        QMessageBox msgBox16;
        QMessageBox msgBox17;
        QString inventoryContString;
        Zork* zork1;
        QGraphicsPixmapItem *restaurantmain;
        QString inventoryString;
        QTextEdit * smallEditor;
        QTextEdit * inventoryEditor;
        Room * nextRoom;
        Player * player;
        int delB1=0;
        int delB2=0;
        int delB3=0;
        int delB4=0;
        int delB5=0;
        int delB6=0;
        int delB7=0;
        int delB8=0;
        int delB9=0;
        int delB10=0;
        int delB11=0;
        int delB12=0;
        int delB13=0;
        int delB15=0;
        int delB16=0;
        int delB17=0;
        int delB18=0;
        int delB19=0;
        int delB20=0;
        int dellabel=0;
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
        QPushButton * button15;
        QPushButton * button16;
        QPushButton * button17;
        QPushButton * button18;
        QPushButton * button19;
        QPushButton * button20;
        QLabel * label;
        Inventory * inventory;
        Item * item;
        Item * itemToDrop;
        vector<Item*> itemsInInventory;
        QComboBox *inventoryComboBox;
};

#endif // RESTAURANT_H
