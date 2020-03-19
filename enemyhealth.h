#ifndef ENEMYHEALTH_H
#define ENEMYHEALTH_H
#include <QObject>
#include "bullet.h"
#include <QGraphicsTextItem>
class enemy;
class enemyhealth: public QGraphicsTextItem {
    Q_OBJECT
  public:
    //enemyhealth(enemy *);
    enemyhealth(enemy *,QGraphicsItem * parent=0);
    enemy *theenemy;
    void decrease();
    int getenemyhealth();
  public slots:
    void enemyhealthfly();
    void deletethis();
  private:
    int yourhealth;
};
#include "enemy.h"

#endif // ENEMYHEALTH_H
