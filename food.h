#ifndef FOOD_H
#define FOOD_H

#include <QGraphicsEllipseItem>

class Food : public QGraphicsEllipseItem
{
public:
    explicit Food();
    void SetCoo(qreal x,qreal y);
    void SetSize(qreal x);
    void SetRandPos(int minX,int maxX,int minY,int maxY);

     int size = 15;
};

#endif // FOOD_H
