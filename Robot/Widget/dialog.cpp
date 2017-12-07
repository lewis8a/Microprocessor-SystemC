#include "dialog.h"

Dialog::Dialog(QWidget *parent)
    : QGraphicsView(parent)
{
    int width = 600;
    int height = 400;

    scene = new QGraphicsScene(0, 0, width, height, this);
    this->setScene(scene);

    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    robot = new Robot();
    robot->setRect(0,0,100,100);
    robot->setFlag(QGraphicsItem::ItemIsFocusable);
    robot->setFocus();

    scene->addItem(robot);

    this->setSceneRect(0, 0, width, height);
    this->setFixedSize(width, height);
    //this->fitInView(0, 0, width, height, Qt::KeepAspectRatio);

}

Dialog::~Dialog()
{

}
