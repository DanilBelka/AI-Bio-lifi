#ifndef HUNTER_H
#define HUNTER_H

#include <QGraphicsEllipseItem>

class Hunterr : public QGraphicsEllipseItem
{
public:
    explicit Hunterr();
    void SetCoo(qreal x,qreal y);
    void SetSize(qreal x);
    void SetRandPos(int minX,int maxX,int minY,int maxY);

     int size = 15;
};

#endif // HUNTER_H
