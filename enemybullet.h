#ifndef ENEMYBULLET_H
#define ENEMYBULLET_H
#include "enemy.h"
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
class health;

class enemybullet :  public enemy {
    Q_OBJECT
  public:
    enemybullet(health *);
    health *iwanthealth;

  public slots:
    void enemybulletfly();
};


#include "health.h"
#endif // ENEMYBULLET_H
