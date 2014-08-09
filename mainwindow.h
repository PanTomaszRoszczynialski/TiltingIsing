#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

#include <Eigen/Core>
#include <Eigen/Geometry>
using namespace Eigen;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    const int w = 550,h = 350;
    ArrayXXi spinTable=ArrayXXi(w,h);
    ArrayXXi neighTable=ArrayXXi(w,h);



    void initSpinTable();
    void initNeighBors();
    void eigenToQImage(const ArrayXXi&, QImage&);

public:
    explicit MainWindow(QWidget *parent = 0);

    void whyNoTest();
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QTimer *timerTest;

};

#endif // MAINWINDOW_H
