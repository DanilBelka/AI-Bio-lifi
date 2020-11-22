#include "backteria.h"
#include <QBrush>
Backteria::Backteria()
{
    this->setBrush(QBrush(Qt::blue));
    this->setRect(0,0,15,15);
}

void Backteria::SetCoo(qreal x, qreal y)
{
    this->setPos(x,y);
}

void Backteria::SetSize(qreal x)
{
    this->setRect(this->x(),this->y(),x,x);
    size = x;
}

void Backteria::SetRandPos(int minX, int maxX, int minY, int maxY)
{
    this->setPos((qrand()%maxX+minX),(qrand()%maxY+minY));
}

void Backteria::GetInput(float FAngle,float FDist,float EAngle,float EDist,unsigned NFood)
{
    Input[0] = FAngle;
    Input[1] = FDist;
    Input[2] = EAngle;
    Input[3] = EDist;
    Input[4] = NFood;
}
