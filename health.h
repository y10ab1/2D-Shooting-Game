#ifndef HEALTH_H
#define HEALTH_H

#include "bullet.h"
#include <QGraphicsTextItem>
class enemy;
class health: public QGraphicsTextItem {
  public:
    health(QGraphicsItem * parent=0);
    void decrease();
    int gethealth();

  private:
    int yourhealth;
};
#include "enemy.h"
#endif // HEALTH_H
