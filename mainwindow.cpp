#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    whyNoTest();
}

void MainWindow::whyNoTest(){
    QImage img(100,100,QImage::Format_Mono);
    for(int i = 0; i<100; ++i){
        for(int j =0; j<100; ++j){
            lol(i,j) = rand()%256;
            img.setPixel(i,j,rand()%2);
        }
    }
    ui->textEdit->append(QString::number(lol(10,10)));
    ui->label->setPixmap(QPixmap::fromImage(img));

}

MainWindow::~MainWindow()
{
    delete ui;
}
