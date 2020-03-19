#include "energy.h"
#include <QFont>

energy::energy(QGraphicsItem *parent): QGraphicsTextItem(parent) {
    // initialize the score to 0
    yourenergy = 0;

    // draw the text
    setPlainText(QString("Energy: ") + QString::number(yourenergy)); // Energy: 0
    setDefaultTextColor(Qt::green);
    setFont(QFont("X",32));


}

void energy::increase() {

    if(yourenergy<10)
        yourenergy++;
    setPlainText(QString("Energy: ") + QString::number(yourenergy)); // Energy: 1

}

void energy::returntozero() {
    yourenergy=0;
    setPlainText(QString("Energy: ") + QString::number(yourenergy));
}

int energy::getenergy() {
    return yourenergy;
}
