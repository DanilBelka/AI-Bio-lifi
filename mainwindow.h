#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QTimer>
#include <QMainWindow>
#include <QRectF>
#include <QPainter>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QVector>
#include "backteria.h"
#include "hunter.h"
#include "food.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    //ANIMALS
    QVector<Food*> Grass;
    QVector<Backteria*> GrassEater;
    QVector<Hunterr*> Hunter;
    int n = 10;
    //Scene
    QGraphicsScene *scene;
    QTimer *timer;
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void render();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
