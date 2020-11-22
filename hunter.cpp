#include "hunter.h"
#include <QBrush>
Hunterr::Hunterr()
{
    this->setBrush(QBrush(Qt::red));
    this->setRect(0,0,15,15);
}
void Hunterr::SetCoo(qreal x, qreal y)
{
    this->setPos(x,y);
}

void Hunterr::SetSize(qreal x)
{
    this->setRect(this->x(),this->y(),x,x);
    size = x;
}

void Hunterr::SetRandPos(int minX, int maxX, int minY, int maxY)
{
    this->setPos((qrand()%maxX+minX),(qrand()%maxY+minY));
}
