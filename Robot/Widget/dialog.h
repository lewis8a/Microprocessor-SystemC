#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <robot.h>

#include <iostream>
using namespace std;


class Dialog : public QGraphicsView
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = 0);
    ~Dialog();
private:
    QGraphicsScene *scene;
    Robot *robot;
};

#endif // DIALOG_H
