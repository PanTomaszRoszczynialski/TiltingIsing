#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QMap>

#include <Eigen/Core>
#include <Eigen/Dense>

using namespace Eigen;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    const int w = 250, h = 250;
    int rest;

// + TUTAJ DEFINIUJE SIE ROZDZIELCZOSC
    typedef MatrixXi MyMatrix;
    MyMatrix spinTable, neighTable, tempForShifting;
    QRgb valA, valB;
    QImage imgMono, imgRGB;
    QMap <int, double> boltzmanMap;

    void initEverything();

    void initNeighBors();
    void initButtons();

    void eigenToQImage(const MyMatrix&, QImage&);
    void eigenToQImageRGB(const MyMatrix&, QImage&);
    void eigenToQImageRGBC(const MyMatrix&, QImage&);
    void calcProbabilities();

public:
    explicit MainWindow(QWidget *parent = 0);

    void whyNoTest();
    ~MainWindow();
public slots:
    void shiftSomeRows();
    void initFlipMaybe();
    void initSpinTable();

    void increaseHeat();
    void decreaseHeat();
    void increaseCoupling();
    void decreaceCoupling();

private:
    Ui::MainWindow *ui;
    QTimer *timerTest;
    QTimer *shiftingTimer;
    double J,T;
    int k;

};

#endif // MAINWINDOW_H
