#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    timerTest(new QTimer)
{
    ui->setupUi(this);
    spinTable = MyMatrix(w,h);
    neighTable = MyMatrix(w,h);
    whyNoTest();
}

void MainWindow::whyNoTest(){
    for(int i = 0; i<w; ++i){
        for(int j =0; j<h; ++j){
            spinTable(i,j) = rand()%2;
        }
    }
    valA = qRgb(30,22,77);
    valB = qRgb(44,144,44);
    testRows();
    QImage imgMono(w,h,QImage::Format_Mono);
    QImage img(w,h,QImage::Format_RGB16);
    eigenToQImage(spinTable,imgMono);
    //t = Translation<int,2>(1,0);

    ui->textEdit->append(QString::number(spinTable(10,10)));
    ui->textEdit->append(QString::number(w));
    ui->label->setPixmap(QPixmap::fromImage(imgMono));
    ui->label->setScaledContents(false);

}

void MainWindow::initSpinTable(){
    for(int i = 0; i<w; ++i){
        for(int j =0; j<h; ++j){
            spinTable(i,j) = rand()%2;
        }
    }
}

void MainWindow::initNeighBors(){
    //scisle rzecz biora w tej macierzy sa sumy spinow
    //sasiednich pol przemnozone przez rozwazany spin
    for(int i = 0; i < h; ++i){
        for(int j = 0; j < w; ++j){
            int iNext = i==h-1 ? 0 : i+1;
            int iPrev = i==0 ? h-1 : i-1;
            int jNext = j==w-1 ? 0 : j+1;
            int jPrev = j==0 ? w-1 : j-1;
            neighTable(i,j) = 2*(spinTable(i,j)-0.5)*(spinTable(iNext,j)+
                                spinTable(iPrev,j)+
                                spinTable(i,jNext)+ //troloo
                                spinTable(i,jPrev)-2)+2;
        }
    }
}

void MainWindow::eigenToQImage(const MyMatrix &arr, QImage & img){
    for (int i = 0; i < arr.rows(); ++i){
        for (int j = 0;j < arr.cols(); ++j){
            img.setPixel(i,j,spinTable(i,j));
        }
    }
}

void MainWindow::eigenToQImageRGB(const MyMatrix &arr, QImage & img){
    for (int i = 0; i < arr.rows(); ++i){
        for (int j = 0;j < arr.cols(); ++j){
            spinTable(i,j) ? img.setPixel(i,j,valA) : img.setPixel(i,j,valB);
        }
    }
}

void MainWindow::eigenToQImageRGBC(const MyMatrix &arr, QImage & img){
    for (int i = 0; i < arr.rows(); ++i){
        for (int j = 0;j < arr.cols(); ++j){
            img.setPixel(i,j,qRgb(arr(i,j),33,44));
        }
    }
}

void MainWindow::testRows(){
    for (int i = 0; i < spinTable.rows(); ++i){
        spinTable.row(i) = spinTable.row(50);
    }
//    spinTable.leftCols(145) = spinTable.rightCols(145);
}

MainWindow::~MainWindow()
{
    delete ui;
}
