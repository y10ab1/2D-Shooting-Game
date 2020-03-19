#include "bullet.h"
#include "enemybullet.h"
#include <enemy.h>
#include <QDebug>


bullet::bullet(score *a, energy *b):
    iwantscore(new score),iwantenergy(new energy) {
    iwantscore=a;
    iwantenergy=b;
}

void bullet::fly() {
    QList<QGraphicsItem*> colliding_items =collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i) {
        if(typeid(*(colliding_items[i])) == typeid(enemybullet)) {
            iwantscore->increase();
            iwantenergy->increase();
            // remove them both
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            // delete them both

            delete colliding_items[i];
            delete this;
            qDebug()<<"obj bullet removed";
            return;
        }
        if(typeid(*(colliding_items[i])) == typeid(enemy)) {
            iwantscore->increase();
            iwantenergy->increase();
            // remove them both
            //scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            // delete them both

            //delete colliding_items[i];
            delete this;
            qDebug()<<"obj bullet removed";
            return;
        }
    }

    setPos(x(), y() - 3);
    if(y() < 0) {
        this->scene()->removeItem(this);
        delete this;
    }
}
