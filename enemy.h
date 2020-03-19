#ifndef ENEMY_H
#define ENEMY_H
#include "bullet.h"
#include "poly.h"
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>


class health;
class enemy : public QObject, public QGraphicsPixmapItem,public poly {
    Q_OBJECT
  public:
    enemy();
    enemy(health *);
    health *thehealth;
    int random_num=rand()%700;
    int HP=3;
  public slots:
    /* virtual void enemybulletfly();*/
    void enemyfly();

    void shoot();
    void remove();
    void check();
    void check2();
};

#include "health.h"
#endif // ENEMY_H
