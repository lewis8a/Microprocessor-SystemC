#include "dialog.h"
#include <QTimer>

Dialog::Dialog(QWidget *parent)
    : QGraphicsView(parent) {
    int width = 900;
    int height = 700;
    setFixedSize(width, height);

    scene = new QGraphicsScene(rect(), this);
    setScene(scene);
    scene->setSceneRect(0, 0, width, height);

    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    robot = new Robot();
    robot->setRect(0, 0, 100, 100);
    robot->setFlag(QGraphicsItem::ItemIsFocusable);
    robot->setFocus();

    scene->addItem(robot);
    obs1 = scene->addPixmap(QPixmap(":/bomb.png"));
    obs2 = scene->addPixmap(QPixmap(":/bomb.png"));
    obs3 = scene->addPixmap(QPixmap(":/bomb.png"));
    obs4 = scene->addPixmap(QPixmap(":/bomb.png"));
    obs5 = scene->addPixmap(QPixmap(":/bomb.png"));

    obs1->setPos(200, 500);
    obs2->setPos(400, 100);
    obs3->setPos(800, 400);
    obs4->setPos(100, 200);
    obs5->setPos(600, 600);
    setStyleSheet("background-color: rgb(190,190,190)");
}

Dialog::~Dialog() {
}
