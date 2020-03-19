#include "enemy.h"
#include <cstdlib>
#include <ctime>
#include "mainwindow.h"
#include <mainwindow.cpp>
#include "ui_mainwindow.h"
#include <QDebug>

enemy::enemy() {}

enemy::enemy(health *a): QObject(),QGraphicsPixmapItem(),thehealth(new health) {
    thehealth=a;
//set random pos
    srand(time(NULL));

    int index=qrand() %4;

    setPos(random_num,10);
    if(index  == 0) {
        setPixmap(QPixmap(":/res/mountaintop.png").scaled(80, 160));
    } else if(index == 1) {
        setPixmap(QPixmap(":/res/tomorrow.png").scaled(120, 110));
    } else if(index == 2) {
        setPixmap(QPixmap(":/res/julia.png").scaled(104, 172));
    } else if(index == 3) {
        setPixmap(QPixmap(":/res/rion.png").scaled(112, 186));
    }

    QTimer * timer3 =new QTimer;

    connect(timer3, SIGNAL(timeout()), this, SLOT(enemyfly()));

    timer3->start(700);

    QTimer * timer4 =new QTimer;
    connect(timer4, SIGNAL(timeout()), this, SLOT(shoot()));
    timer4->start(3000);





    QTimer * timer5 =new QTimer;
    connect(timer5, SIGNAL(timeout()), this, SLOT(check()));

    timer5->start(100);
    QTimer * timer6 =new QTimer;
    connect(timer6, SIGNAL(timeout()), this, SLOT(check2()));
    timer6->start(10);
//HP




}


void enemy::enemyfly() {


    setPos(x(), y() + 10);
    if(y() < 0||y() >650) {
        this->scene()->removeItem(this);
        delete this;
        qDebug()<<"enemy flyout";
    }
}



void enemy::shoot() {
    if(thehealth->gethealth()>0) {
        qDebug()<<"created enemybullet";
        enemybullet *b = new enemybullet(thehealth);
        QTimer * timer5 =new QTimer;
        if(qrand() % 2 == 0) {
            b->setPixmap(QPixmap(":/res/condom.png").scaled(30, 60));
        } else {
            b->setPixmap(QPixmap(":/res/condom2.png").scaled(30, 60));
        }
        b->setPos(this->x() + this->pixmap().width() / 2, this->y() + this->pixmap().height() );
        b->connect(timer5, SIGNAL(timeout()), b, SLOT(enemybulletfly()));
        timer5->start(200);
        scene()->addItem(static_cast<QGraphicsPixmapItem*>(b));
    }
}

void enemy::remove() {

    delete this;
}

void enemy::check() {
    QList<QGraphicsItem*> colliding_items =collidingItems();

    for (int i = 0, n = colliding_items.size(); i < n; ++i) {
        if (typeid(*(colliding_items[i])) == typeid(QGraphicsPixmapItem)) {
            thehealth->decrease();
            thehealth->decrease();
            thehealth->decrease();
            thehealth->decrease();
            thehealth->decrease();

            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            delete colliding_items[i];
            delete this;

            qDebug()<<"obj enemy removed";
            return;

        }
    }
}

void enemy::check2() {
    QList<QGraphicsItem*> colliding_items =collidingItems();

    for (int i = 0, n = colliding_items.size(); i < n; ++i) {
        if (typeid(*(colliding_items[i])) == typeid(bullet)) {
            --HP;
            qDebug()<<"HP-";
            if(HP<=0) {
                scene()->removeItem(colliding_items[i]);
                scene()->removeItem(this);
                delete colliding_items[i];
                delete this;

                qDebug()<<"obj enemy removed";
                return;
            }
        }
    }
}


