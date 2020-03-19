#include "enemyhealth.h"
#include "mainwindow.h"
#include <QFont>

//enemyhealth::enemyhealth(enemy *a){}
enemyhealth::enemyhealth(enemy *a,QGraphicsItem *parent): QGraphicsTextItem(parent),theenemy(new enemy) {
    // initialize the score to 0
    theenemy=a;

    yourhealth = 3;

    // draw the text
    setPlainText(QString("HP: ") + QString::number(yourhealth)); // Score: 0
    setDefaultTextColor(Qt::red);
    setFont(QFont("X",32));
    QTimer * timer3 =new QTimer;
    QObject::connect(timer3, SIGNAL(timeout()), this, SLOT(enemyhealthfly()));
    timer3->start(700);
    QTimer * timer4 =new QTimer;
    QObject::connect(timer4, SIGNAL(timeout()), this, SLOT(deletethis()));
    timer4->start(10);
}

void enemyhealth::decrease() {
    yourhealth--;
    setPlainText(QString("HP: ") + QString::number(yourhealth)); // Score: 1
}

int enemyhealth::getenemyhealth() {
    return yourhealth;
}

void enemyhealth::enemyhealthfly() {
    setPos(x(), y() + 10);
    if(y() < 0||y() >650) {
        this->scene()->removeItem(this);
        delete this;
    }

}

void enemyhealth::deletethis() {
    setPlainText(QString("HP: ") + QString::number(theenemy->HP)); // Score: 1
    if(theenemy->HP==0) {
        this->scene()->removeItem(this);
        delete this;
    }
}
