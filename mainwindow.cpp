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
    QImage img(w,h,QImage::Format_Mono);
    for(int i = 0; i<w; ++i){
        for(int j =0; j<h; ++j){
            lol(i,j) = rand()%256;
            img.setPixel(i,j,rand()%2);
        }
    }
    ui->textEdit->append(QString::number(lol(10,10)));
    ui->label->setPixmap(QPixmap::fromImage(img));
    ui->label->setScaledContents(true);

}

MainWindow::~MainWindow()
{
    delete ui;
}
