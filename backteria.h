#ifndef BACKTERIA_H
#define BACKTERIA_H

#include <QGraphicsEllipseItem>



class Backteria : public QGraphicsEllipseItem
{

public:
    explicit Backteria();
    //Redecor funcs
    void SetCoo(qreal x,qreal y);
    void SetSize(qreal x);
    void SetRandPos(int minX,int maxX,int minY,int maxY);

    void GetInput(float FAngle,float FDist,float EAngle,float EDist,unsigned NFood);

    //temperance
    int size = 15;

    //blue NeuralNetwork
    double Input[5]{};
    double Hide[5]{};
    double Weight1[5][5]{};
    double Weight2[2][5]{};
    double Out[2]{};

signals:

};

#endif // BACKTERIA_H
