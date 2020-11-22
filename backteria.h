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
    void SetWeight(double one[5][5],double two[2][5]);
    //temperance
    int size = 15;
    float Mutation = 0.0f;

    //blue NeuralNetwork
    double Input[5]{};
    double Hide[5]{};
    double Weight1[5][5]{};
    double Weight2[2][5]{};
    double Out[2]{};
    void CalcStep();
signals:

};

#endif // BACKTERIA_H
