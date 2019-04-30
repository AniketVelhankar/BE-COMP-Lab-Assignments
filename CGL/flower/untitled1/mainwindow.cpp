#include "mainwindow.h"
#include "ui_mainwindow.h"
QImage image(300,300,QImage::Format_RGB888);
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::brescircle(int x1,int y1, int r)
{
    int x,y,d;
    x = 0;
    y = r;
    d = 3 - 2*r;
    while(x<=y)
    {

        if(d>=0)
        {
            y--;
            d = d + 4*(x-y) + 10;
        }
        else
            d = d + 4*x + 6;
        image.setPixel(x1 + x,y1 + y,qRgb(255,0,0));
        image.setPixel(x1 - x,y1 - y,qRgb(255,255,0));
        image.setPixel(x1 + x,y1 - y,qRgb(255,255,255));
        image.setPixel(x1 - x,y1 + y,qRgb(255,0,255));
        image.setPixel(x1 - y,y1 + x,qRgb(0,255,255));
        image.setPixel(x1 - y,y1 - x,qRgb(0,255,0));
        image.setPixel(x1 + y,y1 + x,qRgb(0,0,255));
        image.setPixel(x1 + y,y1 - x,qRgb(255,100,255));
        x++;
    }
    ui->label->setPixmap(QPixmap::fromImage(image));
}

void MainWindow::petal1(int x1,int y1, int r)
{
    int x,y,d;
    x = 0;
    y = r;
    d = 3 - 2*r;
    while(x<=y)
    {

        if(d>=0)
        {
            y--;
            d = d + 4*(x-y) + 10;
        }
        else
            d = d + 4*x + 6;
        //image.setPixel(x1 + x,y1 + y,qRgb(255,0,0));
        image.setPixel(x1 - x,y1 - y,qRgb(255,255,0));
        //image.setPixel(x1 + x,y1 - y,qRgb(255,255,255));
        image.setPixel(x1 - x,y1 + y,qRgb(255,0,255));
        image.setPixel(x1 - y,y1 + x,qRgb(0,255,255));
        image.setPixel(x1 - y,y1 - x,qRgb(0,255,0));
        //image.setPixel(x1 + y,y1 + x,qRgb(0,0,255));
        //image.setPixel(x1 + y,y1 - x,qRgb(255,100,255));
        x++;
    }
    ui->label->setPixmap(QPixmap::fromImage(image));
}

void MainWindow::on_pushButton_clicked()
{
    int x1,y1,r;
    x1 = ui->textEdit->toPlainText().toInt();
    y1 = ui->textEdit_2->toPlainText().toInt();
    r = ui->textEdit_3->toPlainText().toInt();
    flower(x1,y1,r);
}

void MainWindow::flower(int x1,int y1,int r)
{
    brescircle(x1,y1,r);
    petal1(x1-r+5,y1,r/2);
    petal2(x1+r-5,y1,r/2);
    petal3(x1,y1+r-5,r/2);
    petal4(x1,y1-r+5,r/2);
}

void MainWindow::clearimage()
{

    for(int i=0; i<300; i++)
        {
            for(int j=0; j<300; j++)
            {
                image.setPixel(i,j,qRgb(0,0,0));
            }
        }
    ui->label->setPixmap(QPixmap::fromImage(image));
}

void MainWindow::on_pushButton_2_clicked()
{
    clearimage();

}

void MainWindow::petal2(int x1,int y1, int r)
{
    int x,y,d;
    x = 0;
    y = r;
    d = 3 - 2*r;
    while(x<=y)
    {

        if(d>=0)
        {
            y--;
            d = d + 4*(x-y) + 10;
        }
        else
            d = d + 4*x + 6;
        image.setPixel(x1 + x,y1 + y,qRgb(255,0,0));
        //image.setPixel(x1 - x,y1 - y,qRgb(255,255,0));
        image.setPixel(x1 + x,y1 - y,qRgb(255,255,255));
        //image.setPixel(x1 - x,y1 + y,qRgb(255,0,255));
        //image.setPixel(x1 - y,y1 + x,qRgb(0,255,255));
        //image.setPixel(x1 - y,y1 - x,qRgb(0,255,0));
        image.setPixel(x1 + y,y1 + x,qRgb(0,0,255));
        image.setPixel(x1 + y,y1 - x,qRgb(255,100,255));
        x++;
    }
    ui->label->setPixmap(QPixmap::fromImage(image));
}

void MainWindow::petal3(int x1,int y1, int r)
{
    int x,y,d;
    x = 0;
    y = r;
    d = 3 - 2*r;
    while(x<=y)
    {

        if(d>=0)
        {
            y--;
            d = d + 4*(x-y) + 10;
        }
        else
            d = d + 4*x + 6;
        image.setPixel(x1 + x,y1 + y,qRgb(255,0,0));
        //image.setPixel(x1 - x,y1 - y,qRgb(255,255,0));
        //image.setPixel(x1 + x,y1 - y,qRgb(255,255,255));
        image.setPixel(x1 - x,y1 + y,qRgb(255,0,255));
        image.setPixel(x1 - y,y1 + x,qRgb(0,255,255));
        //image.setPixel(x1 - y,y1 - x,qRgb(0,255,0));
        image.setPixel(x1 + y,y1 + x,qRgb(0,0,255));
       // image.setPixel(x1 + y,y1 - x,qRgb(255,100,255));
        x++;
    }
    ui->label->setPixmap(QPixmap::fromImage(image));
}

void MainWindow::petal4(int x1,int y1, int r)
{
    int x,y,d;
    x = 0;
    y = r;
    d = 3 - 2*r;
    while(x<=y)
    {

        if(d>=0)
        {
            y--;
            d = d + 4*(x-y) + 10;
        }
        else
            d = d + 4*x + 6;
       // image.setPixel(x1 + x,y1 + y,qRgb(255,0,0));
        image.setPixel(x1 - x,y1 - y,qRgb(255,255,0));
        image.setPixel(x1 + x,y1 - y,qRgb(255,255,255));
        //image.setPixel(x1 - x,y1 + y,qRgb(255,0,255));
        //image.setPixel(x1 - y,y1 + x,qRgb(0,255,255));
        image.setPixel(x1 - y,y1 - x,qRgb(0,255,0));
        //image.setPixel(x1 + y,y1 + x,qRgb(0,0,255));
        image.setPixel(x1 + y,y1 - x,qRgb(255,100,255));
        x++;
    }
    ui->label->setPixmap(QPixmap::fromImage(image));
}
