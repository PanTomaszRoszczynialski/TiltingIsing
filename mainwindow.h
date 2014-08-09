#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

#include <Eigen/Core>
#include <Eigen/Dense>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsView>

using namespace Eigen;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    const int w = 300, h = 300, k =1;
// + TUTAJ DEFINIUJE SIE ROZDZIELCZOSC
    typedef MatrixXi MyMatrix;
    MyMatrix spinTable, neighTable, tempForShifting;
    QRgb valA, valB;
    QImage imgMono;
    QGraphicsScene *scene;
    QGraphicsPixmapItem *it;

    void initSpinTable();
    void initNeighBors();
    void eigenToQImage(const MyMatrix&, QImage&);
    void eigenToQImageRGB(const MyMatrix&, QImage&);
    void eigenToQImageRGBC(const MyMatrix&, QImage&);
    void testRows();

public:
    explicit MainWindow(QWidget *parent = 0);

    void whyNoTest();
    ~MainWindow();
public slots:
    void shiftSomeRows();


private:
    Ui::MainWindow *ui;
    QTimer *timerTest;

};

#endif // MAINWINDOW_H
