#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    timerTest(new QTimer),
    shiftingTimer(new QTimer),
    J(double(1.0)),
    T(double(1.5))
{
    ui->setupUi(this);
    spinTable = MyMatrix(w,h);
    neighTable = MyMatrix(w,h);
    tempForShifting = MyMatrix(w,h);
    imgMono = QImage(w,h,QImage::Format_Mono);
    imgRGB = QImage(w,h,QImage::Format_RGB32);
    valA = qRgb(30,22,77);
    valB = qRgb(44,144,44);
    ui->label->setScaledContents(true);

    initEverything();
//    whyNoTest();
    ui->heatLCD->display(T);
    ui->couplingLCD->display(J);
}

void MainWindow::initEverything(){
    initSpinTable();
    initNeighBors();
    calcProbabilities();

    QObject::connect(timerTest,SIGNAL(timeout()),
                     this,SLOT(initFlipMaybe()));
    timerTest->start(25);

    QObject::connect(shiftingTimer,SIGNAL(timeout()),
                     this,SLOT(shiftSomeRows()));
    shiftingTimer->start(75);
}

void MainWindow::initFlipMaybe(){

    for(int i = 0; i < h; ++i){
        for(int j = 0; j < w; ++j){
            spinTable(i,j) =
            (boltzmanMap[neighTable(i,j)] > (rand()%400)*0.01) ?
                        abs(spinTable(i,j)-1) : spinTable(i,j);
        }
    }
    initNeighBors();
    eigenToQImage(spinTable,imgMono);
    ui->textEdit->setText(QString::number(boltzmanMap[0]));
}



void MainWindow::whyNoTest(){
    for(int i = 0; i<w; ++i){
        for(int j =0; j<h; ++j){
            spinTable(i,j) = rand()%2;
        }
    }

//    testRows();

    eigenToQImage(spinTable,imgMono);
    //t = Translation<int,2>(1,0);


    timerTest->start(1000/30);
    QObject::connect(timerTest,SIGNAL(timeout()),
                     this,SLOT(shiftSomeRows()));

    ui->textEdit->append(QString::number(spinTable(10,10)));
    ui->textEdit->append(QString::number(w));
    ui->label->setPixmap(QPixmap::fromImage(imgMono));
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
            // tutaj mozliwe wartosc to {-2,-1,0,1,2}
            neighTable(i,j) = 2*(spinTable(i,j)-0.5)*(spinTable(iNext,j)+
                                spinTable(iPrev,j)+
                                spinTable(i,jNext)+
                                spinTable(i,jPrev)-2);
        }
    }
}

void MainWindow::calcProbabilities(){
    for (int i = - 2; i < 3; ++i){
        boltzmanMap[i] = exp(-4*(J*i)/T);

    }
}

void MainWindow::eigenToQImage(const MyMatrix &arr, QImage & img){
    for (int i = 0; i < arr.rows(); ++i){
        for (int j = 0;j < arr.cols(); ++j){
            img.setPixel(i,j,spinTable(i,j));
        }
    }
    ui->label->setPixmap(QPixmap::fromImage(img));
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
            img.setPixel(i,j,qRgb(arr(i,j)*(rand()%255),33,44));
        }
    }
}

void MainWindow::shiftSomeRows(){
    int rest = w - k;
    tempForShifting.bottomRows(k) = neighTable.topRows(k);
    neighTable.topRows(rest) = neighTable.bottomRows(rest);
    neighTable.bottomRows(k) = tempForShifting.bottomRows(k);

}

MainWindow::~MainWindow()
{
    delete ui;
}
