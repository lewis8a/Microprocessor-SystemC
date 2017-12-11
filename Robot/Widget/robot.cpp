#include "robot.h"
#include "dialog.h"

#include <QTimer>
#include <QDebug>
#include <fstream>
#include <cstdlib>
#include <string>
#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

Robot::Robot() : QObject() {
    currentFrame = 0;
    move = 0;
    spriteImage = new QPixmap(":/nazi-walk.png");

    timer = new QTimer(this);
    timer2 = new QTimer(this);
    QObject::connect(timer, &QTimer::timeout, this, &Robot::walk);
    //QObject::connect(timer2, &QTimer::timeout, this, &Robot::turn);
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

  turn();

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
    std::fstream datamemory;
    datamemory.open ("datamemory.txt");

    srand(time(0));
    if (move == 0 or move == 1)   { // Baja

      datamemory.seekg(2*(6), ios::beg);
      qDebug() << pos();

      if (x() > 150 and x() < 250)
       {
        int n = abs(y() - 500);
        string s = decimal_to_binary(to_string(n));
        datamemory<<right << setw(5) << setfill('0') <<s;

        if (n < 100)
            move = 3;

        cout <<  n << endl;
        cout << s << endl;
      }


      if (x() > 350 and x() < 450)
       {
        int n = abs(y() - 100);
        string s =  decimal_to_binary(to_string(n));
        datamemory<<right << setw(5) << setfill('0') <<s;

        cout <<  n << endl;
        cout << s << endl;

        if (n < 100)
            move = 3;

        datamemory << "pto" << endl;
      }

      if (x() > 650 and x() < 750)
       {
        int n = abs(y() - 300);
        string s = decimal_to_binary(to_string(n));
        datamemory<<right << setw(5) << setfill('0') <<s;

        if (n < 100)
            move = 3;

        cout <<  n << endl;
        cout << s << endl;
      }



  } else {

        datamemory.seekg(3*(6), ios::beg);
        qDebug() << pos();

        if (y() > 450 and y() < 550)
         {
          int n = abs(x() - 200);
          string s = decimal_to_binary(to_string(n));

          if (n < 100)
              move = 1;
          datamemory << s;
          cout << n << endl;
          cout << s << endl;
        }


        if (y() > 50 and y() < 150)
         {
          int n = abs(x() - 400);
          if (n < 100)
              move = 0;
          string s =  decimal_to_binary(to_string(n));
          datamemory << s;
          cout << n << endl;
          cout << s << endl;
        }

        if (y() > 250 and y() < 350)
         {
          int n = abs(x() - 700);
          string s = decimal_to_binary(to_string(n));

          if (n < 100)
              move = 1;
          datamemory << s;
          cout << n << endl;
          cout << s << endl;
        }

    }


   std::system("../../main/test");

}

string decimal_to_binary (string dir)
{
	string binary;
	dir = dir.substr(1,dir.length()-1);
	int number;
	number = atoi(dir.c_str());
	if (number > 0)
	{
		while(number > 0)
		{
			if (number%2 == 0)
				binary = "0" + binary;
			else
				binary = "1" + binary;
			number = (int)number/2;
		}
	} 
	else
		return "0";
	return binary;
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




