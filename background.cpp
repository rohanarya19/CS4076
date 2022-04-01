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
    controlsBox();
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
    delete controlsComboBox;
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
    if(find(zork1->player->getInventory()->getInventoryList().begin(), zork1->player->getInventory()->getInventoryList().end(), zork1->teleporter) != zork1->player->getInventory()->getInventoryList().end())
    {
        button5= new QPushButton();
        button5->move(750,25);
        button5->setText("Teleport");
        button5->raise();
        this->delB5=1;
        this->addWidget(button5);
        connect(button5,SIGNAL(released()),this, SLOT(on_button5_clicked()));
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
    else if(zork1->currentRoom->getDescription()=="b")
        RoomB->setBrush(Qt::green);
    else if(zork1->currentRoom->getDescription()=="c")
        RoomC->setBrush(Qt::green);
    else if(zork1->currentRoom->getDescription()=="d")
        RoomD->setBrush(Qt::green);
    else if(zork1->currentRoom->getDescription()=="e")
        RoomE->setBrush(Qt::green);
    else if(zork1->currentRoom->getDescription()=="f")
        RoomF->setBrush(Qt::green);
    else if(zork1->currentRoom->getDescription()=="g")
        RoomG->setBrush(Qt::green);
    else if(zork1->currentRoom->getDescription()=="h")
        RoomH->setBrush(Qt::green);
    else if(zork1->currentRoom->getDescription()=="i")
        RoomI->setBrush(Qt::green);
    else if(zork1->currentRoom->getDescription()=="j")
        RoomJ->setBrush(Qt::green);
}

void Background:: addText()
{
     string x="You are in Room "+zork1->currentRoom->getDescription()+ " and you have health of: "+ to_string(zork1->player->getHealth());
     smallEditor->setPlainText(QString::fromStdString(x));
}

void Background::inventoryBox()
{
    inventoryComboBox=new QComboBox();
    inventoryComboBox->move(550,450);
    inventoryComboBox->setSizeAdjustPolicy(QComboBox::AdjustToContents);
    this->addWidget(inventoryComboBox);
}

void Background::controlsBox()
{
    controlsComboBox=new QComboBox();
    controlsComboBox->move(700,450);
    controlsComboBox->setSizeAdjustPolicy(QComboBox::AdjustToContents);
    controlsComboBox->addItem("Controls");

    controls+=("Attack: X");
    controls+=("Pick up item: P");
    controls+=("Drop selected item: D");
    controls+=("Kiss: K");

    for(int i=0; i<controls.size();i++)
       controlsComboBox->addItem(controls.get(i));

    this->addWidget(controlsComboBox);
}
//adds monster and rectangle to scene
void Background::addToScene()
{
    if(zork1->currentRoom->getDescription()=="i")
    {
        button6= new QPushButton();
        button6->move(450,218);
        button6->raise();
        button6->setText("Collect Raw Materials");
        delB6=1;
        this->addWidget(button6);

        connect(button6,SIGNAL(released()),this, SLOT(on_button6_clicked()));
    }
    if(zork1->currentRoom->getDescription()=="d")
    {
        button7= new QPushButton();
        button7->move(450,218);
        button7->raise();
        button7->setText("Cook Food");
        delB7=1;
        this->addWidget(button7);

        connect(button7,SIGNAL(released()),this, SLOT(on_button7_clicked()));
    }
    if(zork1->currentRoom->getDescription()=="e")
    {
        button8= new QPushButton();
        button8->move(450,218);
        button8->raise();
        button8->setText("Serve Food");
        delB8=1;
        this->addWidget(button8);

        connect(button8,SIGNAL(released()),this, SLOT(on_button8_clicked()));
    }
    if(zork1->currentRoom->getDescription()=="b")
    {
        button9= new QPushButton();
        button9->move(450,218);
        button9->raise();
        button9->setText("Serve Food");
        delB9=1;
        this->addWidget(button9);

        connect(button9,SIGNAL(released()),this, SLOT(on_button9_clicked()));
    }
    if(zork1->currentRoom->getDescription()=="g")
    {
        button10= new QPushButton();
        button10->move(450,218);
        button10->raise();
        button10->setText("Serve Food");
        delB10=1;
        this->addWidget(button10);

        connect(button10,SIGNAL(released()),this, SLOT(on_button10_clicked()));
    }
    if(zork1->currentRoom->getDescription()=="f")
    {
        button11= new QPushButton();
        button11->move(450,218);
        button11->raise();
        button11->setText("Serve Food");
        delB11=1;
        this->addWidget(button11);

        connect(button11,SIGNAL(released()),this, SLOT(on_button11_clicked()));
    }
    if(zork1->currentRoom->getDescription()=="h")
    {
        button12= new QPushButton();
        button12->move(450,218);
        button12->raise();
        button12->setText("Serve Food");
        delB12=1;
        this->addWidget(button12);

        connect(button12,SIGNAL(released()),this, SLOT(on_button12_clicked()));
    }
    if(zork1->currentRoom->getDescription()=="c")
    {
        button13= new QPushButton();
        button13->move(450,218);
        button13->raise();
        button13->setText("Serve Food");
        delB13=1;
        this->addWidget(button13);

        connect(button13,SIGNAL(released()),this, SLOT(on_button13_clicked()));
    }
    if(zork1->currentRoom->getDescription()=="a")
    {
        button14= new QPushButton();
        button14->move(450,218);
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
    srand(time(0));
    int randNum = rand() % zork1->rooms.size();
    nextRoom = zork1->rooms[randNum];
    bool flag=nextRoom->getCanEnter();
    if(flag==true)
    {
        clearBackground();
        zork1->currentRoom=nextRoom;
        setRoomExits(zork1->currentRoom);
        addToScene();
        createMapGUI();
        addText();
    }
}
void Background::on_button6_clicked()
{
    msgBox1.setText("Raw Materials Collected.");
    msgBox1.setInformativeText("");
    int ret = msgBox1.exec();
    switch(ret)
    {
        case QMessageBox::Ok:
            button6->deleteLater();
            delB6=0;
            break;
        case QMessageBox::Cancel:
            break;
        default:
            break;
    }

}
void Background::on_button7_clicked()
{
    msgBox2.setText("Food is cooked.");
    msgBox2.setInformativeText("");
    int ret = msgBox2.exec();
    switch(ret)
    {
        case QMessageBox::Ok:
            button7->deleteLater();
            delB7=0;
            break;
        case QMessageBox::Cancel:
            break;
        default:
            break;
    }

}
void Background::on_button8_clicked()
{
    msgBox3.setText("Food is served.");
    msgBox3.setInformativeText("");
    int ret = msgBox3.exec();
    switch(ret)
    {
        case QMessageBox::Ok:
            button8->deleteLater();
            delB8=0;
            break;
        case QMessageBox::Cancel:
            break;
        default:
            break;
    }

}
void Background::on_button9_clicked()
{
    msgBox4.setText("Food is served.");
    msgBox4.setInformativeText("");
    int ret = msgBox4.exec();
    switch(ret)
    {
        case QMessageBox::Ok:
            button9->deleteLater();
            delB9=0;
            break;
        case QMessageBox::Cancel:
            break;
        default:
            break;
    }

}
void Background::on_button10_clicked()
{
    msgBox5.setText("Food is served.");
    msgBox5.setInformativeText("");
    int ret = msgBox5.exec();
    switch(ret)
    {
        case QMessageBox::Ok:
            button10->deleteLater();
            delB10=0;
            break;
        case QMessageBox::Cancel:
            break;
        default:
            break;
    }

}
void Background::on_button11_clicked()
{
    msgBox6.setText("Food is served.");
    msgBox6.setInformativeText("");
    int ret = msgBox6.exec();
    switch(ret)
    {
        case QMessageBox::Ok:
            button11->deleteLater();
            delB11=0;
            break;
        case QMessageBox::Cancel:
            break;
        default:
            break;
    }

}
void Background::on_button12_clicked()
{
    msgBox7.setText("Food is served.");
    msgBox7.setInformativeText("");
    int ret = msgBox7.exec();
    switch(ret)
    {
        case QMessageBox::Ok:
            button12->deleteLater();
            delB12=0;
            break;
        case QMessageBox::Cancel:
            break;
        default:
            break;
    }

}
void Background::on_button13_clicked()
{
    msgBox8.setText("Food is served.");
    msgBox8.setInformativeText("");
    int ret = msgBox8.exec();
    switch(ret)
    {
        case QMessageBox::Ok:
            button13->deleteLater();
            delB13=0;
            break;
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
        if(delB8)
        {
                button8->deleteLater();
                delB8=0;
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


    this->removeItem(cave);

    if(zork1->currentRoom->itemInRoom())
    {
        this->removeItem(item);
    }


}
void Background::keyPressEvent(QKeyEvent *event)
{


    if(event->key()==Qt::Key_P)
    {
            if(zork1->currentRoom->itemsInRoom.size() > 0)
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
                if(item->getDescription()==zork1->potion->getDescription() && !zork1->potion->getUsed())
                {
                    zork1->player->increaseHealth(50);
                    item->setVisible(false);
                    zork1->currentRoom->setItem(false);
                    zork1->potion->setUsed();
                }
                if(item->getDescription()==zork1->key->getDescription())
                {
                    zork1->g->setCanEnter(true);
                }
                if(item->getDescription()==zork1->teleporter->getDescription())
                {
                    item->setVisible(false);
                    zork1->currentRoom->setItem(false);
                    refreshScene();
                }
            }
    }

    if(event->key()==Qt::Key_D)
    {
        if(zork1->currentRoom->itemInRoom()==false && player->getInventory()->inventoryQty() > 0)
        {
            int currentItem = inventoryComboBox->currentIndex();
            itemsInInventory=player->getInventory()->getInventoryList();
            itemToDrop=itemsInInventory.operator [](currentItem);
            itemsInInventory.erase(itemsInInventory.begin() + currentItem);
            zork1->currentRoom->addItem(itemToDrop);
            zork1->currentRoom->setItem(true);
            inventoryComboBox->removeItem(currentItem);
            zork1->player->getInventory()->setInventoryList(itemsInInventory);
            button5->setVisible(false);
            refreshScene();
        }
    }



    if(event->key()==Qt::Key_H)
    {
        controlsBox();
    }
}

void Background::close()
{
    delete this;
    delete zork1;
    exit(1);
}




