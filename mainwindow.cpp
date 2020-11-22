#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cstdlib>
#include <ctime>

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


}

void MainWindow::render()
{

    for(int i = 0;i<n;i++)
    {
        float a[2] = {0,1};
        float b[2] = {};
        //GrassEater[i]->GetInput();
    }
}
