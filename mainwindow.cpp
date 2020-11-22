#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
       srand(time(NULL));
       ui->setupUi(this);
       //SetScene
       scene = new QGraphicsScene(ui->Field);
       ui->Field->setScene(scene);
       ui->Field->setAlignment(Qt::AlignLeft|Qt::AlignTop);
       ui->Field->setFixedSize(ui->Field->size());


       for(int i = 0;i<10;i++)
        {
           Grass.push_back(new Food());
           GrassEater.push_back(new Backteria());
           Hunter.push_back(new   Hunterr());

           scene->addItem(Grass.back());
           scene->addItem(GrassEater.back());
           scene->addItem(Hunter.back());

           Grass[i]->SetRandPos(0,ui->Field->size().width(),0,ui->Field->size().height());
           GrassEater[i]->SetRandPos(0,ui->Field->size().width(),0,ui->Field->size().height());
           Hunter[i]->SetRandPos(0,ui->Field->size().width(),0,ui->Field->size().height());
       }

       timer = new QTimer(this);
       connect(timer, SIGNAL(timeout()), this, SLOT(render()));
       timer->start(100);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    render();
}

void MainWindow::render()
{
    float FAngle,FDist,EAngle,EDist;
    float MinFAngle,MinFDist,MinEAngle,MinEDist;
    MinFAngle = 6.29f;
    MinFDist = ui->Field->width();
    MinEAngle = 6.29f;
    MinEDist = ui->Field->width();
    n++;
    for(int j = 0;j<numB;j++)
       {

        for(int i = 0;i<numF;i++)
        {

            float a[2] = {0,1};
            float b[2] = {};
            b[0] = Grass[i]->x()-GrassEater[j]->x();
            b[1] = Grass[i]->y()-GrassEater[j]->y();
            FAngle = (a[0]*b[0]+a[1]*b[1])/(sqrt(pow(a[0],2)+pow(a[1],2))+sqrt(pow(b[0],2)+pow(b[1],2)));
            FAngle = acos(FAngle);
            //qDebug()<<b[0]<<b[1];
            if(Grass[i]->x()<GrassEater[j]->x())
            FAngle = 2*3.1415-FAngle;
            FDist = sqrt(pow(GrassEater[j]->x()-Grass[i]->x(),2)+pow(GrassEater[j]->x()-Grass[i]->x(),2));
            if(FAngle<MinFAngle)
                   MinFAngle = FAngle;
            if(FDist<MinFDist)
                   MinFDist = FDist;
            b[0] = Hunter[i]->x()-GrassEater[j]->x();
            b[1] = Hunter[i]->y()-GrassEater[j]->y();
            EAngle = (a[0]*b[0]+a[1]*b[1])/(sqrt(pow(a[0],2)+pow(a[1],2))+sqrt(pow(b[0],2)+pow(b[1],2)));
            EAngle = acos(EAngle);
            if(Hunter[i]->x()<GrassEater[j]->x())
                EAngle = 2*3.1415-FAngle;
            EDist = sqrt(pow(GrassEater[j]->x()-Hunter[i]->x(),2)+pow(GrassEater[j]->x()-Hunter[i]->x(),2));
            if(EAngle<MinEAngle)
                   MinEAngle = EAngle;
            if(EDist<MinEDist)
                   MinEDist = EDist;

        }
        GrassEater[j]->GetInput(MinFAngle,MinFDist,MinEAngle,MinEDist,numF);
    }
}
