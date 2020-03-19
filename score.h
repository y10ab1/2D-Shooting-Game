#ifndef SCORE_H
#define SCORE_H

#include "bullet.h"
#include <QGraphicsTextItem>

class score: public QGraphicsTextItem {
  public:
    score(QGraphicsItem * parent=0);
    void increase();
    int getscore();
  private:
    int yourscore;

};

#endif // SCORE_H
