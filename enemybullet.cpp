#include "enemybullet.h"
#include <enemy.h>
enemybullet::enemybullet(health *b):
    iwanthealth(new health) {
    iwanthealth=b;
}

void enemybullet::enemybulletfly() {
    QList<QGraphicsItem*> colliding_items =collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i) {
        if (typeid(*(colliding_items[i])) == typeid(QGraphicsPixmapItem)) {

            iwanthealth->decrease();
            if(iwanthealth->gethealth()==0) {
                scene()->removeItem(colliding_items[i]);
                delete colliding_items[i];

            }

            // remove enemy's bullet


            scene()->removeItem(this);
            // delete them both
            //
            delete this;
            return;
        }
    }

    setPos(x(), y() + 15);
    if(y() < 0||iwanthealth->gethealth()==0) {
        this->scene()->removeItem(this);
        delete this;
    }
}
