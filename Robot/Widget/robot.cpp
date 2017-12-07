#include "robot.h"
#include "dialog.h"
#include <QTimer>

Robot::Robot() : QObject() {
    currentFrame = 0;
    move = 0;
    spriteImage = new QPixmap(":/nazi-walk.png");
}

void Robot::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left) {
            move = 2;
            setPos(x()-10,y());
        }
        else if (event->key() == Qt::Key_Right) {
            move = 3;
            setPos(x()+10,y());
        }
        else if (event->key() == Qt::Key_Up) {
            move = 1;
            setPos(x(),y()-10);

        }
        else if (event->key() == Qt::Key_Down){
            move = 0;
            setPos(x(),y()+10);
    }
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




