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
    const int w = 150, h = 150, k =1;

// + TUTAJ DEFINIUJE SIE ROZDZIELCZOSC
    typedef MatrixXi MyMatrix;
    MyMatrix spinTable, neighTable, tempForShifting;
    QRgb valA, valB;
    QImage imgMono, imgRGB;
    QMap <int, double> boltzmanMap;

    void initEverything();

    void initSpinTable();
    void initNeighBors();

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


private:
    Ui::MainWindow *ui;
    QTimer *timerTest;
    QTimer *shiftingTimer;
    double J,T;

};

#endif // MAINWINDOW_H
