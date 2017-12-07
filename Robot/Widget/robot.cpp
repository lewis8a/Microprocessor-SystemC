#include "robot.h"
#include "dialog.h"

#include <QTimer>
#include <QDebug>
#include <fstream>
#include <cstdlib>

Robot::Robot() : QObject() {
    currentFrame = 0;
    move = 0;
    spriteImage = new QPixmap(":/nazi-walk.png");

    timer = new QTimer(this);
    timer2 = new QTimer(this);
    QObject::connect(timer, &QTimer::timeout, this, &Robot::walk);
    QObject::connect(timer2, &QTimer::timeout, this, &Robot::turn);
    timer->start(75);
    timer2->start(1500);
}

void Robot::keyPressEvent(QKeyEvent *event)
{
  if (event->key() == Qt::Key_Left) {
    move = 2;
    setPos(x() - 10,y());
  } else if (event->key() == Qt::Key_Right) {
    move = 3;
    setPos(x()+10,y());

  } else if (event->key() == Qt::Key_Up) {
    move = 1;
    setPos(x(),y()-10);

  } else if (event->key() == Qt::Key_Down){
    move = 0;
    setPos(x(),y()+10);
  }
}

void Robot::walk()
{
    std::fstream fs;
    fs.open ("test.txt", std::fstream::in | std::fstream::out | std::fstream::app);

    fs << " more lorem ipsum";
    fs.close();

  //qDebug() << pos();
  if (move == 0) { // Baja
      if (pos().y() >= 600)
          move = 3; // Girar derecha.
      else setPos(x(), y() + 10);
  } else if (move == 1) { // Sube
      if (pos().y() <= 0)
          move = 2; // Girar izquierda.
        else setPos(x(), y() - 10);
  } else if (move == 2) { // Izquierda
      if (pos().x() <= 0)
          move = 0; // Girar abajo
      else setPos(x() - 10,y());
  } else  if (move == 3) {
      if (pos().x() >= 800)
          move = 1;
      else setPos(x() + 10 ,y());
  }

  /*
  srand(time(0));

  if (pos() == QPoint(200, 500) or pos() == QPoint(400, 100) or pos() == QPoint(800, 400) or
    pos() == QPoint(100, 200) or pos() == QPoint(600, 600)) {
    move = rand() % 5;
  }
  */
}

void Robot::turn()
{
   srand(time(0));
   move = rand() % 4;
}


QRectF Robot::boundingRect() const
{
    return QRectF(0, 0, 100, 100);
}

void Robot::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    /* In the graphic renderer we draw the sprite
     * The first two arguments - is the X and Y coordinates of where to put QPixmap
     * The third argument - a pointer to QPixmap
     * 4 and 5 of the arguments - The coordinates in the image QPixmap, where the image is displayed
     * By setting the X coordinate with the variable currentFrame we would like to move the camera on the sprite
     * and the last two arguments - the width and height of the displayed area, that is, the frame
     * */
    painter->drawPixmap(0, 0, *spriteImage, currentFrame, move * 100, 100, 100);
    Q_UNUSED(option);
    Q_UNUSED(widget);

    nextFrame();
}

void Robot::nextFrame()
{
    /* At a signal from the timer 20 to move the point of rendering pixels
     * If currentFrame = 300 then zero out it as sprite sheet size of 300 pixels by 20
     * */
    currentFrame += 100;
    if (currentFrame >= 600 ) currentFrame = 0;
    //this->update(0, 0, 100, 100);
}




