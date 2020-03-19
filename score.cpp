#include "score.h"
#include <QFont>

score::score(QGraphicsItem *parent): QGraphicsTextItem(parent) {
    // initialize the score to 0
    yourscore = 0;

    // draw the text
    setPlainText(QString("Score: ") + QString::number(yourscore)); // Score: 0
    setDefaultTextColor(Qt::blue);
    setFont(QFont("X",32));


}

void score::increase() {
    yourscore++;

    setPlainText(QString("Score: ") + QString::number(yourscore)); // Score: 1

}

int score::getscore() {
    return yourscore;
}
