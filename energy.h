#ifndef ENERGY_H
#define ENERGY_H

#include "bullet.h"
#include <QGraphicsTextItem>

class energy: public QGraphicsTextItem {
  public:
    energy(QGraphicsItem * parent=0);
    void increase();
    void returntozero();
    int getenergy();

  private:
    int yourenergy;

};

#endif // ENERGY_H
