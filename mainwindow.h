#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include "enemy.h"
#include "bullet.h"
#include "enemybullet.h"
#include "score.h"
#include <QObject>
#include <QKeyEvent>
#include "health.h"
#include "energy.h"
#include "enemyhealth.h"
#include "poly.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow, public poly {
    Q_OBJECT

  public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

  public slots:
    virtual void keyPressEvent(QKeyEvent *e);
    virtual void mousePressEvent(QMouseEvent *e);
    void create();
    int GG();
    void shoot();

  private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QGraphicsPixmapItem *player;
    QTimer *timer;
    score *thescore;
    health *thehealth;
    energy *theenergy;
};

#endif // MAINWINDOW_H














