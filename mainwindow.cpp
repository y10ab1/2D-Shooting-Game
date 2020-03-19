#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <ctime>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    scene(new QGraphicsScene(0, 0, 900, 700)),
    timer(new QTimer),
    thescore(new score),
    thehealth(new health),
    theenergy(new energy) {
    ui->setupUi(this);
    ui->graphicsView->setScene(scene);
    player = new QGraphicsPixmapItem(QPixmap(":/res/guy.png"));
    scene->addItem(player);
    player->setPos(365, 481);
    timer->start(10);
    QObject:: connect(timer, SIGNAL(timeout()), this, SLOT(GG()));

    if(thehealth->gethealth()>0&&GG()!=1) {
        QTimer * timer2 =new QTimer;
        QObject:: connect(timer2, SIGNAL(timeout()), this, SLOT(create()));
        timer2->start(3000);
    }

    scene->addItem(thescore);
    thehealth->setPos(0,40);
    scene->addItem(thehealth);
    theenergy->setPos(0,640);
    scene->addItem(theenergy);
}

MainWindow::~MainWindow() {


    delete ui;
}



void MainWindow::keyPressEvent(QKeyEvent *e) {
    if(GG()==0) {
        switch(e->key()) {
        case Qt::Key_Up:
        case Qt::Key_W:
            if(player->y()>0)
                player->setPos(player->x(), player->y() - 10);
            break;
        case Qt::Key_Down:
        case Qt::Key_S:
            if(player->y()<480)
                player->setPos(player->x(), player->y() + 10);
            break;
        case Qt::Key_Left:
        case Qt::Key_A:
            if(player->x()>0)
                player->setPos(player->x() - 10, player->y());
            break;
        case Qt::Key_Right:
        case Qt::Key_D:
            if(player->x()+player->pixmap().width()<911)
                player->setPos(player->x() + 10, player->y());
            break;

        case Qt::Key_R: {
            if(theenergy->getenergy()>9) {
                for(int n=1; n<=900; n+=30) {
                    bullet *a = new bullet(thescore,theenergy);
                    if(qrand() % 2 == 0) {
                        a->setPixmap(QPixmap(":/res/sperm.png").scaled(30, 90));
                    } else {
                        a->setPixmap(QPixmap(":/res/sperm2.png").scaled(63, 105));
                    }
                    a->setPos(n,player->y());
                    a->connect(timer, SIGNAL(timeout()), a, SLOT(fly()));
                    scene->addItem(static_cast<QGraphicsPixmapItem*>(a));
                }

                theenergy->returntozero();
            }
            break;
        }
        case Qt::Key_Space:
/*
            bullet *b = new bullet(thescore,theenergy);

            if(qrand() % 2 == 0) {
                b->setPixmap(QPixmap(":/res/sperm.png").scaled(30, 90));
            } else {
                b->setPixmap(QPixmap(":/res/sperm2.png").scaled(63, 105));
            }
            b->setPos(player->x() + player->pixmap().width() / 2 - b->pixmap().width() / 2, player->y() - b->pixmap().height()+21 );
            b->connect(timer, SIGNAL(timeout()), b, SLOT(fly()));
            scene->addItem(static_cast<QGraphicsPixmapItem*>(b));
*/
            shoot();
            break;
        }
    }
}

void MainWindow::create() {
    if(GG()!=1&&thehealth->gethealth()>0) {
        qDebug()<<"Enemy created";
        enemy *c = new enemy(thehealth);
        enemyhealth *d =new enemyhealth(c);
        d->setPos(c->random_num+ c->pixmap().width() / 2 -10,c->y()+c->pixmap().height());
        d->setFont(QFont("X",12));
        scene->addItem(d);
        scene->addItem(static_cast<QGraphicsPixmapItem*>(c));
    }
}

int MainWindow::GG() {


    if(thehealth->gethealth()<=0) {

        QTimer * timer2 =new QTimer;
        timer2->start(0.1);


        bullet *b = new bullet(thescore,theenergy);
        b->setPixmap(QPixmap(":/res/white.png").scaled(900, 720));
        b->setPos(1, 650 );
        scene->addItem(static_cast<QGraphicsPixmapItem*>(b));
        b->connect(timer2, SIGNAL(timeout()), b, SLOT(fly()));


        player = new QGraphicsPixmapItem;
        player ->setPixmap(QPixmap(":/res/GG.png"));
        scene->addItem(player);

        return 1;

    }
    return 0;
}

void MainWindow::shoot()
{
    bullet *b = new bullet(thescore,theenergy);

    if(qrand() % 2 == 0) {
        b->setPixmap(QPixmap(":/res/sperm.png").scaled(30, 90));
    } else {
        b->setPixmap(QPixmap(":/res/sperm2.png").scaled(63, 105));
    }
    b->setPos(player->x() + player->pixmap().width() / 2 - b->pixmap().width() / 2, player->y() - b->pixmap().height()+21 );
    b->connect(timer, SIGNAL(timeout()), b, SLOT(fly()));
    scene->addItem(static_cast<QGraphicsPixmapItem*>(b));
}


void MainWindow::mousePressEvent(QMouseEvent *e) {
    if(GG()==0) {
        bullet *b = new bullet(thescore,theenergy);

        if(qrand() % 2 == 0) {
            b->setPixmap(QPixmap(":/res/sperm.png").scaled(24, 72));
        } else {
            b->setPixmap(QPixmap(":/res/sperm2.png").scaled(50, 84));
        }
        b->setPos(player->x() + player->pixmap().width() / 2 - b->pixmap().width() / 2, player->y() - b->pixmap().height()+21 );
        b->connect(timer, SIGNAL(timeout()), b, SLOT(fly()));
        scene->addItem(static_cast<QGraphicsPixmapItem*>(b));
    }
}


