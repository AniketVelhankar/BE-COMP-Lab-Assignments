#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMouseEvent"
#include "math.h"

QImage img(600,400,QImage::Format_RGB888);

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    bresenham_line(300,1,300,399);
    bresenham_line(1,200,599,200);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    int x1,y1,x2,y2;
    x1 = ui -> textEdit->toPlainText().toFloat();
    y1 = ui -> textEdit_2->toPlainText().toFloat();
    x2 = ui -> textEdit_3->toPlainText().toFloat();
    y2 = ui -> textEdit_4->toPlainText().toFloat();

    bresenham_line(x1+300,y1+200,x2+300,y2+200);
}

void MainWindow::bresenham_line(int x1, int y1, int x2, int y2)
{
    int dx,dy,x,y,p;
    int i = 0;

    x = x1;
    y = y1;

    dx = abs(x2-x1);
    dy = abs(y2-y1);

    if(dx>=dy)
    {
        p = 2*dy-dx;

        while(i<dx)
        {
            img.setPixel(x,y,qRgb(255,255,255));

            if(p<0)
                p = p+2*dy;
            else
            {
                p = p+2*(dy-dx);
                y = y+sign(y2-y1);
            }

            x = x+sign(x2-x1);
            i++;
        }
    }
    else
    {
        p = 2*dx-dy;

        while(i<dy)
        {
            img.setPixel(x,y,qRgb(255,255,255));

            if(p<0)
                p = p+2*dx;
            else
            {
                p = p+2*(dx-dy);
                x = x+sign(x2-x1);
            }

            y = y+sign(y2-y1);
            i++;
        }
    }
    ui->label->setPixmap(QPixmap::fromImage(img));
}

int MainWindow::sign(int p)
{
    if(p<0)
        return -1;
    else
        return 1;
}

void MainWindow::mouseDoubleClickEvent(QMouseEvent *ev)
{
    int np,nq;
    np = ev->pos().x();
    nq = ev->pos().y();
    seedfill(np,nq);
    ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::seedfill(int x,int y)
{
    QRgb col;
    col = img.pixel(x,y);

    if(col != qRgb(255,255,255))
    {
       img.setPixel(x,y,qRgb(255,255,255));
       seedfill(x+1,y);
       seedfill(x,y+1);
       seedfill(x-1,y);
       seedfill(x,y-1);
    }
}

void MainWindow::rotateIt(float x1,float y1,float x2,float y2,int t)
{
    float T = (3.14*t)/180;
    float mat1[2][3] = {{x1,y1,1},{x2,y2,1}};
    float mat4[3][3] = {{cos(T),sin(T),0},{-sin(T),cos(T),0},{0,0,1}};



    for(int i=0;i<2;i++)
    {
        for(int j =0 ;j<3;j++)
        {
            res3[i][j] = 0;
        }
    }

    for(int i=0;i<2;i++)
        for(int j =0;j<3;j++)
            for(int k=0;k<3;k++)
            {
                res3[i][j] = res3[i][j] + mat1[i][k] * mat4[k][j] ;
            }
}

void MainWindow::on_pushButton_2_clicked()
{
    float x1,y1,x2,y2;
    x1 = ui -> textEdit->toPlainText().toFloat();
    y1 = ui -> textEdit_2->toPlainText().toFloat();
    x2 = ui -> textEdit_3->toPlainText().toFloat();
    y2 = ui -> textEdit_4->toPlainText().toFloat();

    rotateIt(x1,y1,x2,y2,45);
    bresenham_line(res3[0][0]+300,res3[0][1]+200,res3[1][0]+300,res3[1][1]+200);
}
