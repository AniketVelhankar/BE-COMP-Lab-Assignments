#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "math.h"

QImage img(300,300,QImage::Format_RGB888);

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


void MainWindow::on_pushButton_3_clicked()
{
    // dda line

    float x1,y1,x2,y2;

    x1 = ui -> textEdit->toPlainText().toFloat();
    y1 = ui -> textEdit_2->toPlainText().toFloat();
    x2 = ui -> textEdit_3->toPlainText().toFloat();
    y2 = ui -> textEdit_4->toPlainText().toFloat();

    dda_line(x1,y1,x2,y2);
}

void MainWindow::dda_line(float x1, float y1, float x2, float y2)
{
    float dx,dy,len,x,y,i;

    dx = x2-x1;
    dy = y2-y1;

    if(abs(dx)>=abs(dy))
        len = abs(dx);
    else
        len = abs(dy);

    dx = dx/len;
    dy = dy/len;

    x = x1 + 0.5 * sign(x2-x1);
    y = y1 + 0.5 * sign(y2-y1);

    while (i<=len) {
        img.setPixel(x,y,qRgb(255,0,0));
        x = x + dx;
        y = y + dy;
        i = i + 1;
    }
    ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::on_pushButton_clicked()
{
    //bresenham circle

    float xc,yc,r;
    xc=ui->textEdit->toPlainText().toInt();
    yc=ui->textEdit_2->toPlainText().toInt();
    r=ui->textEdit_3->toPlainText().toInt();

    bresenhamc(xc,yc,r);
}

void MainWindow :: bresenhamc(float xc,float yc, float r)
{
    float x,y,d;

    x = 0;
    y = r;
    d = 3-2*r;

    while(x<=y)
    {
        img.setPixel(xc+x, yc+y, qRgb(0,255,0));
        img.setPixel(xc-x, yc+y, qRgb(0,255,0));
        img.setPixel(xc+x, yc-y, qRgb(0,255,0));
        img.setPixel(xc-x, yc-y, qRgb(0,255,0));
        img.setPixel(xc+y, yc+x, qRgb(0,255,0));
        img.setPixel(xc-y, yc+x, qRgb(0,255,0));
        img.setPixel(xc+y, yc-x, qRgb(0,255,0));
        img.setPixel(xc-y, yc-x, qRgb(0,255,0));

        if(d<0)
        {
            d = d+4*x+6;
        }
        else
        {
            d = d+4*(x-y)+10;
            y =y-1;
        }
        x = x+1;
    }
    ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::on_pushButton_2_clicked()
{

    float xc,yc,r;

    xc = ui -> textEdit->toPlainText().toInt();
    yc = ui -> textEdit_2->toPlainText().toInt();
    r = ui -> textEdit_3->toPlainText().toInt();

    ddac(xc,yc,r);
}

void MainWindow :: ddac(float xc, float yc, float r)
{
    float xc1,xc2,yc1,yc2,eps,sx,sy;

    int val,i;

    xc1=r;

    yc1=0;

    sx=xc1;

    sy=yc1;

    i=0;

    do{

        val=pow(2,i);

        i++;

    }while(val<r);

    eps = 1/pow(2,i-1);

    do{

        xc2 = xc1 + eps*yc1;
        yc2 = yc1 - eps*xc2;

        img.setPixel(xc+xc2,yc-yc2,qRgb(0,255,255));

        xc1=xc2;

        yc1=yc2;

    }while((yc1-sy)<eps || (sx-xc1)>eps);

    ui->label->setPixmap(QPixmap::fromImage(img));

}

float MainWindow::sign(float p)
{
    if(p<0)
        return -1;
    else
        return 1;
}
