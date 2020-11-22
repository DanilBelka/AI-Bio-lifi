#include "food.h"
#include <QBrush>
Food::Food()
{
    this->setBrush(QBrush(Qt::green));
    this->setRect(0,0,15,15);
}
void Food::SetCoo(qreal x, qreal y)
{
    this->setPos(x,y);
}

void Food::SetSize(qreal x)
{
    this->setRect(this->x(),this->y(),x,x);
    size = x;
}

void Food::SetRandPos(int minX, int maxX, int minY, int maxY)
{
    this->setPos((qrand()%maxX+minX),(qrand()%maxY+minY));
}
