#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QColorDialog"
#include "QMouseEvent"
#include<cmath>
QImage image(400,400,QImage::Format_RGB888);


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
void MainWindow::bresenham(int x1,int y1,int x2,int y2)
{
    int x,y,dx,dy,p;
    int i=0;
    x=x1;
    y=y1;
    dx=abs(x2-x1);
    dy=abs(y2-y1);
    if(dx>=dy)
    {
        p=2*dy-dx;
        while(i<dx)
        {
            image.setPixel(x,y,qRgb(255,0,0));
            if(p<0)
                p=p+2*dy;
            else
            {
                p=p+2*(dy-dx);
                y=y+sign(y2-y1);
            }
            x=x+sign(x2-x1);
            i++;
        }
    }
    else
    {
        p=2*dx-dy;
        while(i<dy)
        {
            image.setPixel(x,y,qRgb(255,0,0));
            if(p<0)
                p=p+2*dx;
            else
            {
                p=p+2*(dx-dy);
                x=x+sign(x2-x1);
            }
            y=y+sign(y2-y1);
            i++;
    }
}
    ui->label->setPixmap(QPixmap::fromImage(image));
}

void MainWindow::on_pushButton_clicked()
{
    rotate(200-200,200-200,175-200,150-200,120);
    rotate(200-200,200-200,225-200,150-200,120);
    rotate(200-200,100-200,175-200,150-200,120);
    rotate(200-200,100-200,225-200,150-200,120);
    bresenham(200,200,175,150);
    bresenham(200,200,225,150);
    bresenham(200,100,175,150);
    bresenham(200,100,225,150);
    rotate(200-200,200-200,175-200,150-200,-120);
    rotate(200-200,200-200,225-200,150-200,-120);
    rotate(200-200,100-200,175-200,150-200,-120);
    rotate(200-200,100-200,225-200,150-200,-120);

}

int MainWindow::sign(int test)
{
    if(test<0)
        return -1;
    else
        return 1;
}

void MainWindow::rotate(int x1,int y1,int x2,int y2,int angle)
{
    float a=((angle*3.14159)/180);
    int v[2][3]={{x1,y1,1},{x2,y2,1}};
    float ro[3][3]={{cos(a),sin(a),0},{-sin(a),cos(a),0},{0,0,1}};
    multiply(v,ro);
}

void MainWindow::multiply(int v[2][3],float m[3][3])
{
    float result[2][3]={{0.0,0.0,0.0},{0.0,0.0,0.0}};

    for(int i=0;i<2;i++)
    {
        for(int j=0;j<3;j++)
        {
            for(int k=0;k<3;k++)
            {
                result[i][j]+=v[i][k]*m[k][j];
            }
        }
    }
    float x1,x2,y1,y2;
    x1=result[0][0];
    y1=result[0][1];
    x2=result[1][0];
    y2=result[1][1];
    bresenham(x1+200,y1+200,x2+200,y2+200);
}
