#ifndef DIALOG_H
#define DIALOG_H

#include <iostream>

#include <QDialog>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <robot.h>


class Dialog : public QGraphicsView {
  Q_OBJECT
 public:
  Dialog(QWidget *parent = 0);
  ~Dialog();
 private:
  QGraphicsScene *scene;
  QGraphicsPixmapItem *obs1, *obs2, *obs3;
  Robot *robot;
};

#endif  // DIALOG_H
