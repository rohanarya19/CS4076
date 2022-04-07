#include "restaurant.h"

//constructor that sets blank window and creates rooms
restaurant::restaurant(Zork* zork1)
{
    this->zork1 = zork1;
    player=zork1->play();
    inventoryContString = "";
    setRoomExits(zork1->currentRoom);
    setSceneRect(0,0,1250,500);
    createrestaurantmain();
    createTextBox();
    inventoryBox();
    addText();
    addToScene();
}

restaurant::~restaurant()
{
    clearrestaurant();
    player=nullptr;
    zork1=nullptr;
    delete restaurantmain;
    delete smallEditor;
    delete inventoryComboBox;
}

//Sets a new scne when you move rooms
void restaurant::setScene(const string direction)
{
    nextRoom = zork1->currentRoom->nextRoom(direction);
    bool flag=nextRoom->getCanEnter();
    if(flag==true)
    {
        clearrestaurant();

        nextRoom = zork1->currentRoom->nextRoom(direction);
        zork1->currentRoom=nextRoom;

        setRoomExits(zork1->currentRoom);
        addToScene();
        addText();
    }
}

void restaurant::refreshScene()
{
    clearrestaurant();
    setRoomExits(zork1->currentRoom);
    addToScene();
}


//creates buttons depending on room exits
void restaurant::setRoomExits(Room * r)
{
    zork1->currentRoom = r;

    vector<string> listOfExits= zork1->currentRoom->exitString();
    int i=0;
    while(i<listOfExits.size())
    {
        if(listOfExits[i]=="north")
        {
            button1= new QPushButton();
            button1->move(1050,50);
            button1->raise();
            button1->setText("North");
            delB1=1;
            this->addWidget(button1);

            connect(button1,SIGNAL(released()),this, SLOT(on_button1_clicked()));
        }
        else if(listOfExits[i]=="south")
        {
            button2= new QPushButton();
            button2->move(1050,50);
            button2->setText("South");
            button2->raise();
            delB2=1;
            connect(button2,SIGNAL(released()),this, SLOT(on_button2_clicked()));
            this->addWidget(button2);
        }
        else if(listOfExits.at(i)=="east")
        {
            button3= new QPushButton();
            button3->move(1050,50);
            button3->setText("East");
            button3->raise();
            delB3=1;
            connect(button3,SIGNAL(released()),this, SLOT(on_button3_clicked()));
            this->addWidget(button3);
        }
        else if(listOfExits.at(i)=="west")
        {
            button4= new QPushButton();
            button4->move(1050,50);
            button4->setText("West");
            button4->raise();
            delB4=1;
            this->addWidget(button4);
            connect(button4,SIGNAL(released()),this, SLOT(on_button4_clicked()));
        }
        i++;
    }

}
void restaurant::createrestaurantmain()
{
    restaurantmain= new QGraphicsPixmapItem();
    restaurantmain->setPos(50,0);
    restaurantmain->setPixmap(QPixmap(":/Images/restaurantmain.jpg"));
    restaurantmain->setZValue(-1);
}

void restaurant:: createTextBox()
{
    smallEditor = new QTextEdit;
    smallEditor->move(975,300);
    smallEditor->setReadOnly(true);
    this->addWidget(smallEditor);
}

void restaurant:: addText()
{
     string x=""+zork1->currentRoom->getDescription();
     smallEditor->setPlainText(QString::fromStdString(x));
}

void restaurant::inventoryBox()
{
    inventoryComboBox=new QComboBox();
    inventoryComboBox->move(1050,125);
    inventoryComboBox->setSizeAdjustPolicy(QComboBox::AdjustToContents);
    this->addWidget(inventoryComboBox);
}

void restaurant::addToScene()
{
    if(zork1->currentRoom->getDescription()=="WELCOME : Click on Start")
    {
        button15= new QPushButton();
        button15->move(1050,200);
        button15->raise();
        button15->setText("START");
        delB15=1;
        this->addWidget(button15);

        connect(button15,SIGNAL(released()),this, SLOT(on_button15_clicked()));
    }
    if(zork1->currentRoom->getDescription()=="BAR : Click on 'Make Drinks' ")
    {
        button5= new QPushButton();
        button5->move(650,200);
        button5->raise();
        button5->setText("MAKE DRINKS");
        delB5=1;
        this->addWidget(button5);

        connect(button5,SIGNAL(released()),this, SLOT(on_button5_clicked()));

    }
    if(zork1->currentRoom->getDescription()=="COLD STORAGE : Click on the button 'Collect Cold Items' ")
    {
        button6= new QPushButton();
        button6->move(232,200);
        button6->raise();
        button6->setText("Collect Cold Items");
        delB6=1;
        this->addWidget(button6);

        connect(button6,SIGNAL(released()),this, SLOT(on_button6_clicked()));

    }
    if(zork1->currentRoom->getDescription()=="DISHWASHER : Click on 'Wash Dishes' to continue")
    {
        button7= new QPushButton();
        button7->move(232,200);
        button7->raise();
        button7->setText("WASH DISHES");
        delB7=1;
        this->addWidget(button7);

        connect(button7,SIGNAL(released()),this, SLOT(on_button7_clicked()));
    }
    if(zork1->currentRoom->getDescription()=="BILLING : Click on the Cash button to pay by by Cash. Alternatively, click on the Card button to pay by card.")
    {
        button8= new QPushButton();
        button8->move(232,200);
        button8->raise();
        button8->setText("CASH");
        delB8=1;
        this->addWidget(button8);

        connect(button8,SIGNAL(released()),this, SLOT(on_button8_clicked()));

        button20= new QPushButton();
        button20->move(650,200);
        button20->raise();
        button20->setText("CARD");
        delB20=1;
        this->addWidget(button20);

        connect(button20,SIGNAL(released()),this, SLOT(on_button20_clicked()));
    }
    if(zork1->currentRoom->getDescription()=="CAFE : Click on 'Prepare Beverages'")
    {
        button9= new QPushButton();
        button9->move(650,200);
        button9->raise();
        button9->setText("PREPARE BEVERAGE");
        delB9=1;
        this->addWidget(button9);

        connect(button9,SIGNAL(released()),this, SLOT(on_button9_clicked()));

    }
    if(zork1->currentRoom->getDescription()=="LOUNGE : Select alcohol from drop down box to continue. Click on serve beverage twice to proceed.")
    {
        button10= new QPushButton();
        button10->move(650,200);
        button10->raise();
        button10->setText("SERVE BEVERAGES");
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
    if(zork1->currentRoom->getDescription()=="DINING : Click on 'Collect Dishes' to vollect already dirty dishes")
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
    if(zork1->currentRoom->getDescription()=="KITCHEN : Click on 'Collect Order' ")
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
    if(zork1->currentRoom->getDescription()=="STORAGE : Click on 'Collect Raw Materials' ")
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
    if(zork1->currentRoom->getDescription()=="WELCOME : Click on Start")
    {
        label = new QLabel();
        QFont font = label->font();
        font.setPointSize(20);
        label->setFont(font);
        label->move(350,50);
        label->setText("WELCOME TO RESTAURANT ZORK");
        dellabel=1;
        this->addWidget(label);
    }
    this->addItem(restaurantmain);

    if(zork1->currentRoom->itemInRoom())
    {
        item=zork1->currentRoom->item;
        item->setVisible(true);
        this->addItem(item);
    }
}


void restaurant::on_button1_clicked()
{
    setScene("north");
}

void restaurant::on_button2_clicked()
{
    setScene("south");
}
void restaurant::on_button3_clicked()
{
    setScene("east");
}
void restaurant::on_button4_clicked()
{
    setScene("west");
}

void restaurant::on_button5_clicked()
{
    msgBox14.setText("Drinks are Ready to Serve. \nClick on South to proceed to Cafe.");
    int ret = msgBox14.exec();
    switch(ret)
    {
        case QMessageBox::Ok:
        if(zork1->currentRoom->getDescription()=="BAR : Click on 'Make Drinks' ")
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
void restaurant::on_button6_clicked()
{
    msgBox1.setText("Cold Items Collected.\nClick on North to proceed to the Storage Room.");
    int ret = msgBox1.exec();
    switch(ret)
    {
        case QMessageBox::Ok:
        if(zork1->currentRoom->getDescription()=="COLD STORAGE : Click on the button 'Collect Cold Items' ")
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
void restaurant::on_button7_clicked()
{
    msgBox2.setText("Dishes Clean. \nClick on North to proceed to Billing.");
    int ret = msgBox2.exec();
    switch(ret)
    {
        case QMessageBox::Ok:
        if(zork1->currentRoom->getDescription()=="DISHWASHER : Click on 'Wash Dishes' to continue")
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
void restaurant::on_button8_clicked()
{
    msgBox16.setText("Your payment with Cash was sucessful. \nHope to see you soon!");
    int ret = msgBox16.exec();
    switch (ret)
    {
        case QMessageBox::Ok:
            close();
            break;
        case QMessageBox::Cancel:
            break;
        default:
            break;
    }

}
void restaurant::on_button9_clicked()
{
    msgBox4.setText("Hot Beverage and snacks Ready. \nClick on South to proceed to Lounge.");
    int ret = msgBox4.exec();
    switch(ret)
    {
        case QMessageBox::Ok:
        if(zork1->currentRoom->getDescription()=="CAFE : Click on 'Prepare Beverages'")
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
void restaurant::on_button10_clicked()
{
    msgBox5.setText("Once 'Serve Beverages' clicked twice, \nthen click on 'Collect Dishes' to collect the already dirty dishes.");
    int ret = msgBox5.exec();
    switch(ret)
    {
        case QMessageBox::Ok:
        if(zork1->currentRoom->getDescription()=="LOUNGE : Select alcohol from drop down box to continue. Click on serve beverage twice to proceed.")
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
void restaurant::on_button11_clicked()
{
    msgBox6.setText("Dishes Collected. \nClick on serve food to serve the cook food. ");
    int ret = msgBox6.exec();
    switch(ret)
    {
        case QMessageBox::Ok:
        if(zork1->currentRoom->getDescription()=="DINING : Click on 'Collect Dishes' to vollect already dirty dishes")
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
void restaurant::on_button12_clicked()
{
    msgBox7.setText("Order Collected. \nClick on 'Cook Food' to cook items from Storage.");
    int ret = msgBox7.exec();
    switch(ret)
    {
        case QMessageBox::Ok:
        if(zork1->currentRoom->getDescription()=="KITCHEN : Click on 'Collect Order' ")
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
void restaurant::on_button13_clicked()
{
    msgBox8.setText("Items Collected from Storage.\nClick on Store Items to store cold items in the storage room.");
    int ret = msgBox8.exec();
    switch(ret)
    {
        case QMessageBox::Ok:
        if(zork1->currentRoom->getDescription()=="STORAGE : Click on 'Collect Raw Materials' ")
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
void restaurant::on_button15_clicked()
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

void restaurant::on_button16_clicked()
{
    msgBox11.setText("Items Stored. \nClick on North to proceed to Kitchen.");
    msgBox11.setInformativeText("");
    int ret = msgBox11.exec();
    switch(ret)
    {
        case QMessageBox::Ok:
        if(zork1->currentRoom->getDescription()=="STORAGE : Click on 'Collect Raw Materials' ")
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

void restaurant::on_button17_clicked()
{
    msgBox12.setText("Food is being Cooked. \nClick on East to proceed to Dining Area.");
    int ret = msgBox12.exec();
    switch(ret)
    {
        case QMessageBox::Ok:
        if(zork1->currentRoom->getDescription()=="KITCHEN : Click on 'Collect Order' ")
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

void restaurant::on_button18_clicked()
{
    msgBox13.setText("Food has been Served. \nClick on East to proceed to the bar.");
    int ret = msgBox13.exec();
    switch(ret)
    {
        case QMessageBox::Ok:
        if(zork1->currentRoom->getDescription()=="DINING : Click on 'Collect Dishes' to vollect already dirty dishes")
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

void restaurant::on_button19_clicked()
{
    msgBox15.setText("Dishes Collected. \nClick on West to proceed to Dishwashing area.");
    int ret = msgBox15.exec();
    switch(ret)
    {
        case QMessageBox::Ok:
        if(zork1->currentRoom->getDescription()=="LOUNGE : Select alcohol from drop down box to continue. Click on serve beverage twice to proceed.")
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

void restaurant::on_button20_clicked()
{
    msgBox17.setText("Your payment with Card was sucessful. \nHope to see you soon!");
    int ret = msgBox17.exec();
    switch (ret)
    {
        case QMessageBox::Ok:
            close();
            break;
        case QMessageBox::Cancel:
            break;
        default:
            break;
    }

}
void restaurant::clearrestaurant()
{

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
    if(delB20)
        {
                button20->deleteLater();
                delB20=0;
        }
    if(dellabel)
        {
                label->deleteLater();
                dellabel=0;
        }
    this->removeItem(restaurantmain);

    if(zork1->currentRoom->itemInRoom())
    {
        this->removeItem(item);
    }


}
void restaurant::close()
{
    delete this;
    delete zork1;
    exit(1);
}




