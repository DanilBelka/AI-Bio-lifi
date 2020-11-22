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

void Backteria::SetWeight(double one[5][5], double two[2][5])
{
    for(int i = 0;i<5;i++)
          for(int j = 0;j<5;j++)
              Weight1[i][j] = one[i][j];

    for(int i =2;i<2;i++)
        for(int j = 0;j<5;j++)
              Weight2[i][j] = two[i][j];

    if (qrand() % 2 == 0)
    {
        Weight1[qrand() % 5][qrand() % 5] += ;
    }
    else
    {

    }

}



void Backteria::CalcStep()
{
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            Hide[i] += Input[j] * Weight1[i][j];

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 5; j++)
            Out[i] += Hide[j] * Weight2[i][j];
}
