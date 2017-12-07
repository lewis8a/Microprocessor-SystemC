#ifndef ROBOT_H
#define ROBOT_H

#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QPixmap>
#include <QPaintEvent>
#include <QPainter>

class Robot : public QObject, public QGraphicsRectItem {
 public:
  Robot();
  ~Robot() {}

  void keyPressEvent(QKeyEvent *event);

 private slots:
  void nextFrame();   // Slot for turning images into QPixmap
  void walk();
  void turn();

 private:
  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
    QWidget *widget);
  QRectF boundingRect() const;

  int move;
  QPixmap *spriteImage;   // In this QPixmap object will be placed sprite
  int currentFrame;  // Coordinates X, which starts the next frame of the sprite
  QTimer *timer;
  QTimer *timer2;
};

#endif  // ROBOT_H
