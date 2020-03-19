#include "health.h"
#include <QFont>

health::health(QGraphicsItem *parent): QGraphicsTextItem(parent) {
    // initialize the score to 0

    yourhealth = 5;

    // draw the text
    setPlainText(QString("HP: ") + QString::number(yourhealth)); // Score: 0
    setDefaultTextColor(Qt::red);
    setFont(QFont("X",32));
}

void health::decrease() {
    yourhealth--;
    setPlainText(QString("HP: ") + QString::number(yourhealth)); // Score: 1
}

int health::gethealth() {
    return yourhealth;
}
