#include "background.h"

//constructor that sets blank window and creates rooms
Background::Background(Zork* zork1)
{
    this->zork1 = zork1;
    player=zork1->play();
    inventoryContString = "";
    setRoomExits(zork1->currentRoom);
    setSceneRect(0,0,1000,500);
    createCave();
    createMapGUI();
    createTextBox();
    inventoryBox();
    addText();
    addToScene();
}

Background::~Background()
{
    clearBackground();
    player=nullptr;
    zork1=nullptr;
    delete cave;
    delete smallEditor;
    delete RoomA;
    delete RoomB;
    delete RoomC;
    delete RoomD;
    delete RoomE;
    delete RoomF;
    delete RoomG;
    delete RoomH;
    delete RoomI;
    delete RoomJ;
    delete inventoryComboBox;
}

//Sets a new scne when you move rooms
void Background::setScene(const string direction)
{
    nextRoom = zork1->currentRoom->nextRoom(direction);
    bool flag=nextRoom->getCanEnter();
    if(flag==true)
    {
        clearBackground();

        nextRoom = zork1->currentRoom->nextRoom(direction);
        zork1->currentRoom=nextRoom;

        setRoomExits(zork1->currentRoom);
        addToScene();
        createMapGUI();
        addText();
    }
}

void Background::refreshScene()
{
    clearBackground();
    setRoomExits(zork1->currentRoom);
    addToScene();
    createMapGUI();
}


//creates buttons depending on room exits
void Background::setRoomExits(Room * r)
{
    zork1->currentRoom = r;

    vector<string> listOfExits= zork1->currentRoom->exitString();
    int i=0;
    while(i<listOfExits.size())
    {
        if(listOfExits[i]=="north")
        {
            button1= new QPushButton();
            button1->move(450,25);
            button1->raise();
            button1->setText("North");
            delB1=1;
            this->addWidget(button1);

            connect(button1,SIGNAL(released()),this, SLOT(on_button1_clicked()));
        }
        else if(listOfExits[i]=="south")
        {
            button2= new QPushButton();
            button2->move(450,410);
            button2->setText("South");
            button2->raise();
            delB2=1;
            connect(button2,SIGNAL(released()),this, SLOT(on_button2_clicked()));
            this->addWidget(button2);
        }
        else if(listOfExits.at(i)=="east")
        {
            button3= new QPushButton();
            button3->move(750,200);
            button3->setText("East");
            button3->raise();
            delB3=1;
            connect(button3,SIGNAL(released()),this, SLOT(on_button3_clicked()));
            this->addWidget(button3);
        }
        else if(listOfExits.at(i)=="west")
        {
            button4= new QPushButton();
            button4->move(175,200);
            button4->setText("West");
            button4->raise();
            delB4=1;
            this->addWidget(button4);
            connect(button4,SIGNAL(released()),this, SLOT(on_button4_clicked()));
        }
        i++;
    }

}
void Background::createCave()
{
    cave= new QGraphicsPixmapItem();
    cave->setPos(50,0);
    cave->setPixmap(QPixmap(":/Images/restaurantmain.jpg"));
    cave->setZValue(-1);
}

void Background:: createTextBox()
{
    smallEditor = new QTextEdit;
    smallEditor->move(250,450);
    smallEditor->setReadOnly(true);
    this->addWidget(smallEditor);
}

void Background::createMapGUI()
{

    RoomA= new QGraphicsRectItem();
    RoomB= new QGraphicsRectItem();
    RoomC= new QGraphicsRectItem();
    RoomD= new QGraphicsRectItem();
    RoomE= new QGraphicsRectItem();
    RoomF= new QGraphicsRectItem();
    RoomG= new QGraphicsRectItem();
    RoomH= new QGraphicsRectItem();
    RoomI= new QGraphicsRectItem();
    RoomJ= new QGraphicsRectItem();

    RoomA->setRect(10,10,10,10);
    this->addItem(RoomA);

    RoomB->setRect(20,10,10,10);
    this->addItem(RoomB);

    RoomC->setRect(0,10,10,10);
    this->addItem(RoomC);

    RoomD->setRect(10,20,10,10);
    this->addItem(RoomD);

    RoomE->setRect(20,20,10,10);
    this->addItem(RoomE);

    RoomF->setRect(10,0,10,10);
    this->addItem(RoomF);

    RoomG->setRect(20,0,10,10);
    this->addItem(RoomG);

    RoomH->setRect(0,0,10,10);
    RoomH->setZValue(5);
    this->addItem(RoomH);

    RoomI->setRect(0,20,10,10);
    this->addItem(RoomI);

    RoomJ->setRect(0,30,10,10);
    this->addItem(RoomJ);

    if(zork1->currentRoom->getDescription()=="a")
        RoomA->setBrush(Qt::green);
    else if(zork1->currentRoom->getDescription()=="CAFE")
        RoomB->setBrush(Qt::green);
    else if(zork1->currentRoom->getDescription()=="STORAGE")
        RoomC->setBrush(Qt::green);
    else if(zork1->currentRoom->getDescription()=="DISHWASHER")
        RoomD->setBrush(Qt::green);
    else if(zork1->currentRoom->getDescription()=="LOUNGE")
        RoomE->setBrush(Qt::green);
    else if(zork1->currentRoom->getDescription()=="DINING")
        RoomF->setBrush(Qt::green);
    else if(zork1->currentRoom->getDescription()=="BAR")
        RoomG->setBrush(Qt::green);
    else if(zork1->currentRoom->getDescription()=="KITCHEN")
        RoomH->setBrush(Qt::green);
    else if(zork1->currentRoom->getDescription()=="COLD STORAGE")
        RoomI->setBrush(Qt::green);
    else if(zork1->currentRoom->getDescription()=="WELCOME")
        RoomJ->setBrush(Qt::green);
}

void Background:: addText()
{
     string x=""+zork1->currentRoom->getDescription();
     smallEditor->setPlainText(QString::fromStdString(x));
}

void Background::inventoryBox()
{
    inventoryComboBox=new QComboBox();
    inventoryComboBox->move(550,450);
    inventoryComboBox->setSizeAdjustPolicy(QComboBox::AdjustToContents);
    this->addWidget(inventoryComboBox);
}

void Background::addToScene()
{
    if(zork1->currentRoom->getDescription()=="WELCOME")
    {
        button15= new QPushButton();
        button15->move(450,200);
        button15->raise();
        button15->setText("START");
        delB15=1;
        this->addWidget(button15);

        connect(button15,SIGNAL(released()),this, SLOT(on_button15_clicked()));
    }
    if(zork1->currentRoom->getDescription()=="BAR")
    {
        button5= new QPushButton();
        button5->move(650,200);
        button5->raise();
        button5->setText("MAKE DRINKS");
        delB5=1;
        this->addWidget(button5);

        connect(button5,SIGNAL(released()),this, SLOT(on_button5_clicked()));

    }
    if(zork1->currentRoom->getDescription()=="COLD STORAGE")
    {
        button6= new QPushButton();
        button6->move(232,200);
        button6->raise();
        button6->setText("Collect Cold Items");
        delB6=1;
        this->addWidget(button6);

        connect(button6,SIGNAL(released()),this, SLOT(on_button6_clicked()));

    }
    if(zork1->currentRoom->getDescription()=="DISHWASHER")
    {
        button7= new QPushButton();
        button7->move(350,200);
        button7->raise();
        button7->setText("WASH DISHES");
        delB7=1;
        this->addWidget(button7);

        connect(button7,SIGNAL(released()),this, SLOT(on_button7_clicked()));
    }
    if(zork1->currentRoom->getDescription()=="CAFE")
    {
        button9= new QPushButton();
        button9->move(650,200);
        button9->raise();
        button9->setText("PREPARE BEVERAGE");
        delB9=1;
        this->addWidget(button9);

        connect(button9,SIGNAL(released()),this, SLOT(on_button9_clicked()));

    }
    if(zork1->currentRoom->getDescription()=="LOUNGE")
    {
        button10= new QPushButton();
        button10->move(650,200);
        button10->raise();
        button10->setText("SERVE BEVERAGE");
        delB10=1;
        this->addWidget(button10);

        connect(button10,SIGNAL(released()),this, SLOT(on_button10_clicked()));

        button19= new QPushButton();
        button19->move(282,200);
        button19->raise();
        button19->setText("COLLECT DISHES");
        delB19=1;
        this->addWidget(button19);

        connect(button19,SIGNAL(released()),this, SLOT(on_button19_clicked()));
    }
    if(zork1->currentRoom->getDescription()=="DINING")
    {
        button11= new QPushButton();
        button11->move(232,200);
        button11->raise();
        button11->setText("Collect Dishes");
        delB11=1;
        this->addWidget(button11);

        connect(button11,SIGNAL(released()),this, SLOT(on_button11_clicked()));

        button18= new QPushButton();
        button18->move(650,200);
        button18->raise();
        button18->setText("Serve Food");
        delB18=1;
        this->addWidget(button18);

        connect(button18,SIGNAL(released()),this, SLOT(on_button18_clicked()));
    }
    if(zork1->currentRoom->getDescription()=="KITCHEN")
    {
        button12= new QPushButton();
        button12->move(232,200);
        button12->raise();
        button12->setText("Collect Order");
        delB12=1;
        this->addWidget(button12);

        connect(button12,SIGNAL(released()),this, SLOT(on_button12_clicked()));

        button17= new QPushButton();
        button17->move(650,200);
        button17->raise();
        button17->setText("Cook Food");
        delB17=1;
        this->addWidget(button17);

        connect(button17,SIGNAL(released()),this, SLOT(on_button17_clicked()));

    }
    if(zork1->currentRoom->getDescription()=="STORAGE")
    {
        button13= new QPushButton();
        button13->move(232,200);
        button13->raise();
        button13->setText("Collect Raw Materials");
        delB13=1;
        this->addWidget(button13);

        connect(button13,SIGNAL(released()),this, SLOT(on_button13_clicked()));

        button16= new QPushButton();
        button16->move(650,200);
        button16->raise();
        button16->setText("Store Items");
        delB16=1;
        this->addWidget(button16);

        connect(button16,SIGNAL(released()),this, SLOT(on_button16_clicked()));
    }
    if(zork1->currentRoom->getDescription()=="a")
    {
        button14= new QPushButton();
        button14->move(650,200);
        button14->raise();
        button14->setText("Serve Food");
        delB14=1;
        this->addWidget(button14);

        connect(button14,SIGNAL(released()),this, SLOT(on_button14_clicked()));
    }
    this->addItem(cave);

    if(zork1->currentRoom->itemInRoom())
    {
        item=zork1->currentRoom->item;
        item->setVisible(true);
        this->addItem(item);
    }
}


void Background::on_button1_clicked()
{
    setScene("north");
}

void Background::on_button2_clicked()
{
    setScene("south");
}
void Background::on_button3_clicked()
{
    setScene("east");
}
void Background::on_button4_clicked()
{
    setScene("west");
}

void Background::on_button5_clicked()
{
    msgBox14.setText("Drinks are Ready to Serve");
    msgBox14.setInformativeText("");
    int ret = msgBox14.exec();
    switch(ret)
    {
        case QMessageBox::Ok:
        if(zork1->currentRoom->getDescription()=="BAR")
        {
            if(zork1->currentRoom->item->getInvFlag())
            {
                inventory=player->getInventory();
                inventory->addToInventory(zork1->currentRoom->item);
                item->setVisible(false);
                zork1->currentRoom->setItem(false);
                inventoryContString = item->getDescription();
                inventoryComboBox->addItem(inventoryContString);
                }
            button5->deleteLater();
            delB5=0;
            break;
        }
        case QMessageBox::Cancel:
            break;
        default:
            break;
    }

}
void Background::on_button6_clicked()
{
    msgBox1.setText("Cold Items Collected.");
    msgBox1.setInformativeText("");
    int ret = msgBox1.exec();
    switch(ret)
    {
        case QMessageBox::Ok:
        if(zork1->currentRoom->getDescription()=="COLD STORAGE")
        {
            if(zork1->currentRoom->item->getInvFlag())
            {
                inventory=player->getInventory();
                inventory->addToInventory(zork1->currentRoom->item);
                item->setVisible(false);
                zork1->currentRoom->setItem(false);
                inventoryContString = item->getDescription();
                inventoryComboBox->addItem(inventoryContString);
            }
            button6->deleteLater();
            delB6=0;
            break;
        }
        case QMessageBox::Cancel:
            break;
        default:
            break;
    }

}
void Background::on_button7_clicked()
{
    msgBox2.setText("Dishes Clean");
    msgBox2.setInformativeText("");
    int ret = msgBox2.exec();
    switch(ret)
    {
        case QMessageBox::Ok:
        if(zork1->currentRoom->getDescription()=="DISHWASHER")
        {
            if(zork1->currentRoom->item->getInvFlag())
            {
                int currentItem = inventoryComboBox->currentIndex();
                itemsInInventory=player->getInventory()->getInventoryList();
                itemToDrop=itemsInInventory.operator [](currentItem);
                itemsInInventory.erase(itemsInInventory.begin() + currentItem);
                zork1->currentRoom->addItem(itemToDrop);
                zork1->currentRoom->setItem(true);
                inventoryComboBox->removeItem(currentItem);
                zork1->player->getInventory()->setInventoryList(itemsInInventory);
                refreshScene();
            }
            button7->deleteLater();
            delB7=0;
            break;
        }
        case QMessageBox::Cancel:
            break;
        default:
            break;
    }

}
void Background::on_button9_clicked()
{
    msgBox4.setText("Hot Beverage Ready.");
    msgBox4.setInformativeText("");
    int ret = msgBox4.exec();
    switch(ret)
    {
        case QMessageBox::Ok:
        if(zork1->currentRoom->getDescription()=="CAFE")
        {
            if(zork1->currentRoom->item->getInvFlag())
            {
                inventory=player->getInventory();
                inventory->addToInventory(zork1->currentRoom->item);
                item->setVisible(false);
                zork1->currentRoom->setItem(false);
                inventoryContString = item->getDescription();
                inventoryComboBox->addItem(inventoryContString);
                }
            button9->deleteLater();
            delB9=0;
            break;
        }
        case QMessageBox::Cancel:
            break;
        default:
            break;
    }
}
void Background::on_button10_clicked()
{
    msgBox5.setText("Snack Served");
    msgBox5.setInformativeText("");
    int ret = msgBox5.exec();
    switch(ret)
    {
        case QMessageBox::Ok:
        if(zork1->currentRoom->getDescription()=="LOUNGE")
        {
            if(zork1->currentRoom->item->getInvFlag())
            {
                int currentItem = inventoryComboBox->currentIndex();
                itemsInInventory=player->getInventory()->getInventoryList();
                itemToDrop=itemsInInventory.operator [](currentItem);
                itemsInInventory.erase(itemsInInventory.begin() + currentItem);
                zork1->currentRoom->addItem(itemToDrop);
                zork1->currentRoom->setItem(true);
                inventoryComboBox->removeItem(currentItem);
                zork1->player->getInventory()->setInventoryList(itemsInInventory);
                refreshScene();
                break;
            }
            button10->deleteLater();
            delB10=0;
            break;
        }
        case QMessageBox::Cancel:
            break;
        default:
            break;
    }

}
void Background::on_button11_clicked()
{
    msgBox6.setText("Dishes Collected");
    msgBox6.setInformativeText("");
    int ret = msgBox6.exec();
    switch(ret)
    {
        case QMessageBox::Ok:
        if(zork1->currentRoom->getDescription()=="DINING")
        {
            if(zork1->currentRoom->item->getInvFlag())
            {
                inventory=player->getInventory();
                inventory->addToInventory(zork1->currentRoom->item);
                item->setVisible(false);
                zork1->currentRoom->setItem(false);
                inventoryContString = item->getDescription();
                inventoryComboBox->addItem(inventoryContString);
                }
            button11->deleteLater();
            delB11=0;
            break;
        }
        case QMessageBox::Cancel:
            break;
        default:
            break;
    }

}
void Background::on_button12_clicked()
{
    msgBox7.setText("Order Collected");
    msgBox7.setInformativeText("");
    int ret = msgBox7.exec();
    switch(ret)
    {
        case QMessageBox::Ok:
        if(zork1->currentRoom->getDescription()=="KITCHEN")
        {
            if(zork1->currentRoom->item->getInvFlag())
            {
                inventory=player->getInventory();
                inventory->addToInventory(zork1->currentRoom->item);
                item->setVisible(false);
                zork1->currentRoom->setItem(false);
                inventoryContString = item->getDescription();
                inventoryComboBox->addItem(inventoryContString);
            }
            button12->deleteLater();
            delB12=0;
            break;
        }
        case QMessageBox::Cancel:
            break;
        default:
            break;
    }

}
void Background::on_button13_clicked()
{
    msgBox8.setText("Items Collected from Storage");
    msgBox8.setInformativeText("");
    int ret = msgBox8.exec();
    switch(ret)
    {
        case QMessageBox::Ok:
        if(zork1->currentRoom->getDescription()=="STORAGE")
        {
            if(zork1->currentRoom->item->getInvFlag())
            {
                inventory=player->getInventory();
                inventory->addToInventory(zork1->currentRoom->item);
                item->setVisible(false);
                zork1->currentRoom->setItem(false);
                inventoryContString = item->getDescription();
                inventoryComboBox->addItem(inventoryContString);
            }
            button13->deleteLater();
            delB13=0;
            break;
        }
        case QMessageBox::Cancel:
            break;
        default:
            break;
    }

}
void Background::on_button14_clicked()
{
    msgBox9.setText("Food is served.");
    msgBox9.setInformativeText("");
    int ret = msgBox9.exec();
    switch(ret)
    {
        case QMessageBox::Ok:
            button14->deleteLater();
            delB14=0;
            break;
        case QMessageBox::Cancel:
            break;
        default:
            break;
    }

}

void Background::on_button15_clicked()
{
    msgBox10.setText("Click North to enter the Resturant");
    msgBox10.setInformativeText("");
    int ret = msgBox10.exec();
    switch(ret)
    {
        case QMessageBox::Ok:
            button15->deleteLater();
            delB15=0;
            break;
        case QMessageBox::Cancel:
            break;
        default:
            break;
    }

}

void Background::on_button16_clicked()
{
    msgBox11.setText("Items Stored");
    msgBox11.setInformativeText("");
    int ret = msgBox11.exec();
    switch(ret)
    {
        case QMessageBox::Ok:
        if(zork1->currentRoom->getDescription()=="STORAGE")
        {
            if(zork1->currentRoom->item->getInvFlag())
            {
                int currentItem = inventoryComboBox->currentIndex();
                itemsInInventory=player->getInventory()->getInventoryList();
                itemToDrop=itemsInInventory.operator [](currentItem);
                itemsInInventory.erase(itemsInInventory.begin() + currentItem);
                zork1->currentRoom->addItem(itemToDrop);
                zork1->currentRoom->setItem(true);
                inventoryComboBox->removeItem(currentItem);
                zork1->player->getInventory()->setInventoryList(itemsInInventory);
                refreshScene();
            }
            button16->deleteLater();
            delB16=0;
            break;
        }
        case QMessageBox::Cancel:
            break;
        default:
            break;
    }

}

void Background::on_button17_clicked()
{
    msgBox12.setText("Food is being Cooked");
    msgBox12.setInformativeText("");
    int ret = msgBox12.exec();
    switch(ret)
    {
        case QMessageBox::Ok:
        if(zork1->currentRoom->getDescription()=="KITCHEN")
        {
            if(zork1->currentRoom->item->getInvFlag())
            {
                int currentItem = inventoryComboBox->currentIndex();
                itemsInInventory=player->getInventory()->getInventoryList();
                itemToDrop=itemsInInventory.operator [](currentItem);
                itemsInInventory.erase(itemsInInventory.begin() + currentItem);
                zork1->currentRoom->addItem(itemToDrop);
                zork1->currentRoom->setItem(true);
                inventoryComboBox->removeItem(currentItem);
                zork1->player->getInventory()->setInventoryList(itemsInInventory);
                refreshScene();
            }
            button17->deleteLater();
            delB17=0;
            break;
        }
        case QMessageBox::Cancel:
            break;
        default:
            break;
    }

}

void Background::on_button18_clicked()
{
    msgBox13.setText("Food Served");
    msgBox13.setInformativeText("");
    int ret = msgBox13.exec();
    switch(ret)
    {
        case QMessageBox::Ok:
        if(zork1->currentRoom->getDescription()=="DINING")
        {
            if(zork1->currentRoom->item->getInvFlag())
            {
                int currentItem = inventoryComboBox->currentIndex();
                itemsInInventory=player->getInventory()->getInventoryList();
                itemToDrop=itemsInInventory.operator [](currentItem);
                itemsInInventory.erase(itemsInInventory.begin() + currentItem);
                zork1->currentRoom->addItem(itemToDrop);
                zork1->currentRoom->setItem(true);
                inventoryComboBox->removeItem(currentItem);
                zork1->player->getInventory()->setInventoryList(itemsInInventory);
                refreshScene();
            }
            button18->deleteLater();
            delB18=0;
            break;
        }
        case QMessageBox::Cancel:
            break;
        default:
            break;
    }

}

void Background::on_button19_clicked()
{
    msgBox15.setText("Dishes Collected");
    msgBox15.setInformativeText("");
    int ret = msgBox15.exec();
    switch(ret)
    {
        case QMessageBox::Ok:
        if(zork1->currentRoom->getDescription()=="LOUNGE")
        {
            button19->deleteLater();
            delB19=0;
            break;
        }
        case QMessageBox::Cancel:
            break;
        default:
            break;
    }

}

void Background::clearBackground()
{
    RoomA->setBrush(Qt::white);
    RoomB->setBrush(Qt::white);
    RoomC->setBrush(Qt::white);
    RoomD->setBrush(Qt::white);
    RoomE->setBrush(Qt::white);
    RoomF->setBrush(Qt::white);
    RoomG->setBrush(Qt::white);
    RoomH->setBrush(Qt::white);
    RoomI->setBrush(Qt::white);
    RoomJ->setBrush(Qt::white);

    if(delB1)
    {
        button1->deleteLater();
        delB1=0;
    }
    if(delB2)
    {
        button2->deleteLater();
        delB2=0;
    }
    if(delB3)
    {
       button3->deleteLater();
        delB3=0;
    }
    if(delB4)
    {
        button4->deleteLater();
        delB4=0;
    }
    if(delB5)
    {
        button5->deleteLater();
        delB5=0;
    }
    if(delB6)
        {
                button6->deleteLater();
                delB6=0;
        }
    if(delB7)
        {
                button7->deleteLater();
                delB7=0;
        }
    if(delB9)
        {
                button9->deleteLater();
                delB9=0;
        }
    if(delB10)
        {
                button10->deleteLater();
                delB10=0;
        }
    if(delB11)
            {
                    button11->deleteLater();
                    delB11=0;
            }
    if(delB12)
            {
                    button12->deleteLater();
                    delB12=0;
            }
    if(delB13)
            {
                    button13->deleteLater();
                    delB13=0;
            }
    if(delB14)
            {
                    button14->deleteLater();
                    delB14=0;
            }
    if(delB15)
    {
        button15->deleteLater();
        delB15=0;
    }
    if(delB16)
    {
        button16->deleteLater();
        delB16=0;
    }
    if(delB17)
    {
        button17->deleteLater();
        delB17=0;
    }
    if(delB18)
    {
        button18->deleteLater();
        delB18=0;
    }
    if(delB19)
    {
        button19->deleteLater();
        delB19=0;
    }
    this->removeItem(cave);

    if(zork1->currentRoom->itemInRoom())
    {
        this->removeItem(item);
    }


}
void Background::close()
{
    delete this;
    delete zork1;
    exit(1);
}




