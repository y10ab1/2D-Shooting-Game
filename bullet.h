#ifndef BULLET_H
#define BULLET_H
#include "enemy.h"
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
class score;
class energy;
class bullet :public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
  public:
    bullet(score *,energy *);
    score *iwantscore;
    energy *iwantenergy;
  public slots:
    //  virtual void increase();
    void fly();

};

#include "score.h"
#include "energy.h"
#endif // BULLET_H
