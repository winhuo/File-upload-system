#include "mainwindow.h"
#include "maps.h"
#include "magictower.h"
#include<QPixmap>
#include<QLabel>
#include<QFont>
#include<QString>
#include<QPalette>
#include<QFrame>
#include<iostream>
using namespace std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    this->setGeometry(200, 200, 1200, 897);
    label_date=new QLabel(this);
    label_date->setGeometry(897,0,303,897);
//    QPixmap pixmap(":/163.jpg");
//    QPixmap fitpixmap=pixmap.scaled(label_date->width(), label_date->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
//    label_date->setPixmap(fitpixmap);
    myHero=new hero();
    gameP[0]=new skeleton();
    gameP[1]=new bigskeleton();
    gameP[2]=new green_slime();
    gameP[3]=new red_slime();
    gameP[4]=new bat();
    gameP[5]=new ghost();
    gameP[6]=new boss();

    show_data();
    showPic();

}
void MainWindow::show_data()


    {
        this->label_date;
       QString shp=QString::number(myHero->lifeValue, 10);
       QString sfight=QString::number(myHero->attackPower, 10);
       QString sdefine=QString::number(myHero->defense, 10);
       QString syellow_number=QString::number(myHero->key_number,10);

        //设置字体类型，大小
        QFont font ( "Microsoft YaHei", 20, 75);
        label_date->setFont(font);

    //    //设置边框的大小
       label_date->resize(400,600);
       label_date->setFrameStyle(QFrame::Panel | QFrame::Sunken);

        //设置字体颜色
        QPalette pe;
        pe.setColor(QPalette::WindowText,Qt::black);
        label_date->setPalette(pe);

        //设置背景颜色
        label_date->setStyleSheet("background-color:white");

        label_date->setText("HP:"+shp+
                      "\n攻击力:"+sfight+
                      "\n防御力:"+sdefine+
                      "\n黄钥匙个数:"+syellow_number
                      );

        label_date->show();
    }


void MainWindow::showPic(){
    for(int j=0;j<13;++j)
        {
            for(int i=0;i<13;i++)
            {
            switch(maps[flood][j][i])
            {
            case 0:
            label[j][i] = new MyLabel(":/0.png", this);
            magicT[j][i]=new null();
            break;
            case 1:
            label[j][i] = new MyLabel(":/1.png", this);
            magicT[j][i]=new wall();
            break;
            case 2:
            label[j][i] =new MyLabel(":/2.png", this);
            magicT[j][i]=new door();
            break;
            case 3:
            label[j][i] = new MyLabel(":/3.png", this);
            magicT[j][i]=new stair_up();
            break;
            case 4:
            label[j][i] = new MyLabel(":/4.png", this);
            magicT[j][i]=new stair_down();
            break;
            case 5:
            label[j][i] = new MyLabel(":/5.png", this);
            magicT[j][i]=new key();
            break;
            case 6:
            label[j][i] =new MyLabel(":/6.png", this);
            magicT[j][i]=new blood_bottle();
            break;
            case 7:
            label[j][i] = new MyLabel(":/7.png", this);
            magicT[j][i]=new red_stone();
            break;
            case 8:
            label[j][i] = new MyLabel(":/8.png", this);
            magicT[j][i]=new blue_stone();
            break;
            case 15:
            label[j][i] = new MyLabel(":/15.png", this);
            magicT[j][i]=myHero;
            break;
            case 20:
            label[j][i] =new MyLabel(":/20.png", this);
            magicT[j][i]=new skeleton();
            break;
            case 21:
            label[j][i] = new MyLabel(":/21.png", this);
            magicT[j][i]=new bigskeleton();
            break;
            case 22:
            label[j][i] = new MyLabel(":/22.png", this);
            magicT[j][i]=new green_slime();
            break;
            case 23:
            label[j][i] = new MyLabel(":/23.png", this);
            magicT[j][i]=new red_slime();
            break;
            case 24:
            label[j][i] = new MyLabel(":/24.png", this);
            magicT[j][i]=new bat();
            break;
            case 25:
            label[j][i] = new MyLabel(":/25.png", this);
            magicT[j][i]=new ghost();
            break;
            case 30:
            label[j][i] = new MyLabel(":/30.png", this);
            magicT[j][i]=new boss();
            break;
            case 31:
            label[j][i] = new MyLabel(":/31.png", this);
            magicT[j][i]=new boss();
            break;
            case 32:
            label[j][i] = new MyLabel(":/32.png", this);
            magicT[j][i]=new boss();
            break;
            case 33:
            label[j][i] = new MyLabel(":/33.png", this);
            magicT[j][i]=new boss();
            break;
            case 34:
            label[j][i] = new MyLabel(":/34.png", this);
            magicT[j][i]=new boss();
            break;
            case 35:
            label[j][i] = new MyLabel(":/35.png", this);
            magicT[j][i]=new boss();
            break;
            case 36:
            label[j][i] = new MyLabel(":/36.png", this);
            magicT[j][i]=new boss();
            break;
            case 37:
            label[j][i] = new MyLabel(":/37.png", this);
            magicT[j][i]=new boss();
            break;
            case 38:
            label[j][i] = new MyLabel(":/38.png", this);
            magicT[j][i]=new boss();
            break;

            }
    label[j][i]->show();
    label[j][i]->setPosition(0+69*j, 0+69*i, 69, 69);
             }
       }

}
void MainWindow::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_Up:
        move(-1,0);
        break;
    case Qt::Key_Down:
        move(1,0);
        break;
    case Qt::Key_Right:
        move(0,1);
        break;
    case Qt::Key_Left:
        move(0,-1);
        break;
    default:
        break;
    }
}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
}
void MainWindow::move(int a,int b)
{

    if(hero_x+a<=12&&hero_x+a>=0&&hero_y+b<=12&&hero_y+b>=0)
    {
    switch(maps[flood][hero_x+a][hero_y+b])

    {
    case 0:
        maps[flood][hero_x+a][hero_y+b]=15;
        maps[flood][hero_x][hero_y]=0;
        hero_x=hero_x+a;
        hero_y=hero_y+b;
        break;
    case 1:
        break;
    case 2:
        if(myHero->getKey()>0)
        {
           myHero->key_number--;

           maps[flood][hero_x+a][hero_y+b]=15;
           maps[flood][hero_x][hero_y]=0;
           hero_x=hero_x+a;
           hero_y=hero_y+b;
        }
        break;
    case 3:
        flood++;
        switch(flood)
        {
        case 1:
            hero_x=11;
            hero_y=2;
            break;
        case 2:
            hero_x=10;
            hero_y=11;
            break;
        case 3:
            hero_x=11;
            hero_y=2;
            break;
        case 4:
            hero_x=2;
            hero_y=1;
            break;
        case 5:
            hero_x=10;
            hero_y=6;
            break;
        }
        break;
    case 4:
        flood--;
        switch(flood)
        {
        case 0:
            hero_x=1;
            hero_y=2;
            break;
        case 1:
            hero_x=11;
            hero_y=10;
            break;
        case 2:
            hero_x=10;
            hero_y=1;
            break;
        case 3:
            hero_x=2;
            hero_y=1;
            break;
        case 4:
            hero_x=10;
            hero_y=11;
            break;
        }

        break;
    case 5:
        myHero->key_number++;

        maps[flood][hero_x+a][hero_y+b]=15;
        maps[flood][hero_x][hero_y]=0;
        hero_x=hero_x+a;
        hero_y=hero_y+b;
        break;
    case 6:
        myHero->lifeValue+=200;

        maps[flood][hero_x+a][hero_y+b]=15;
        maps[flood][hero_x][hero_y]=0;
        hero_x=hero_x+a;
        hero_y=hero_y+b;
        break;
    case 7:
        myHero->attackPower+=3;

        maps[flood][hero_x+a][hero_y+b]=15;
        maps[flood][hero_x][hero_y]=0;
        hero_x=hero_x+a;
        hero_y=hero_y+b;
        break;
    case 8:
        myHero->defense+=3;

        maps[flood][hero_x+a][hero_y+b]=15;
        maps[flood][hero_x][hero_y]=0;
        hero_x=hero_x+a;
        hero_y=hero_y+b;
        break;
    case 20:
        if(myHero->attack(gameP[0]))
        {
        maps[flood][hero_x+a][hero_y+b]=15;
        maps[flood][hero_x][hero_y]=0;
        hero_x=hero_x+a;
        hero_y=hero_y+b;}
        break;
    case 21:
        if(myHero->attack(gameP[1])){

        maps[flood][hero_x+a][hero_y+b]=15;
        maps[flood][hero_x][hero_y]=0;
        hero_x=hero_x+a;
        hero_y=hero_y+b;}
        break;
    case 22:
        if(myHero->attack(gameP[2])){

        maps[flood][hero_x+a][hero_y+b]=15;
        maps[flood][hero_x][hero_y]=0;
        hero_x=hero_x+a;
        hero_y=hero_y+b;}
        break;
    case 23:
        if(myHero->attack(gameP[3])){

        maps[flood][hero_x+a][hero_y+b]=15;
        maps[flood][hero_x][hero_y]=0;
        hero_x=hero_x+a;
        hero_y=hero_y+b;}
        break;

    case 24:
        if(myHero->attack(gameP[4])){

        maps[flood][hero_x+a][hero_y+b]=15;
        maps[flood][hero_x][hero_y]=0;
        hero_x=hero_x+a;
        hero_y=hero_y+b;}
        break;
    case 25:
        if(myHero->attack(gameP[5])){
        maps[flood][hero_x+a][hero_y+b]=15;
        maps[flood][hero_x][hero_y]=0;
        hero_x=hero_x+a;
        hero_y=hero_y+b;}
        break;

    case 26:
        if(myHero->attack(gameP[6])){
        maps[flood][hero_x+a][hero_y+b]=15;
        maps[flood][hero_x][hero_y]=0;
        hero_x=hero_x+a;
        hero_y=hero_y+b;}
        break;
    }
    for(int i=0;i<13;i++)
    {
        for(int j=0;j<13;j++)
        {
            label[i][j]->setVisible(false);
        }
    }
    for(int i=0;i<13;i++)
    {
        for(int j=0;j<13;j++)
        {
              magicT[i][j]->setVisible(false);

        }
    }
    showPic();
    show_data();
    }
}


