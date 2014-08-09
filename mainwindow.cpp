#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    timerTest(new QTimer)
{
    ui->setupUi(this);
    whyNoTest();
}

void MainWindow::whyNoTest(){
    for(int i = 0; i<w; ++i){
        for(int j =0; j<h; ++j){
            spinTable(i,j) = rand()%2;
        }
    }
    QImage img(w,h,QImage::Format_Mono);
    eigenToQImage(spinTable,img);

    ui->textEdit->append(QString::number(spinTable(10,10)));
    ui->label->setPixmap(QPixmap::fromImage(img));
    ui->label->setScaledContents(true);

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

void MainWindow::eigenToQImage(const ArrayXXi & arr, QImage & img){
    for (int i = 0; i < arr.rows(); ++i){
        for (int j = 0;j < arr.cols(); ++j){
            img.setPixel(i,j,spinTable(i,j));
        }
    }
}


MainWindow::~MainWindow()
{
    delete ui;
}
