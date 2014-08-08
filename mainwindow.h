#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <Eigen/Core>
using namespace Eigen;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    const int w = 350,h = 350;
    ArrayXXi lol=ArrayXXi(w,h);

public:
    explicit MainWindow(QWidget *parent = 0);

    void whyNoTest();
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
