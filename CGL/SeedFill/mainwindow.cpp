#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMouseEvent"
#include "QColorDialog"
#include "QColor"
#include "QDebug"

QImage img(400,400,QImage::Format_RGB888);
QColor color;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    j = 0;
    start = true;
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *ev)
{
    if(start == true)
    {
        p = ev->pos().x();
        q = ev->pos().y();
        a[j] = p;
        b[j] = q;

        if(ev->button() == Qt::RightButton)
        {
            bresenham_line(a[0],b[0],a[j-1],b[j-1]);
            start = false;
        }

        else
        {
            if(j>0)
            {
                bresenham_line(a[j-1],b[j-1],a[j],b[j]);
            }
        }
        j++;
    }
}

void MainWindow::mouseDoubleClickEvent(QMouseEvent *ev)
{
    np = ev->pos().x();
    nq = ev->pos().y();
    seedfill(np,nq);
    ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::seedfill(int x,int y)
{
    QRgb col;
    col = img.pixel(x,y);

    if(col != color.rgb())
    {
       img.setPixel(x,y,color.rgb());
       seedfill(x+1,y);
       seedfill(x,y+1);
       seedfill(x-1,y);
       seedfill(x,y-1);
    }
}

int MainWindow::sign(int p)
{
    if(p<0)
        return -1;
    else
        return 1;
}
void MainWindow::bresenham_line(float x1, float y1, float x2, float y2)
{
    float dx,dy,x,y,p;
    float i = 0;

    x = x1;
    y = y1;

    dx = abs(x2-x1);
    dy = abs(y2-y1);

    if(dx>=dy)
    {
        p = 2*dy-dx;

        while(i<dx)
        {
            img.setPixel(x,y,color.rgb());

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
            img.setPixel(x,y,color.rgb());

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

void MainWindow::on_pushButton_clicked()
{
    color = QColorDialog::getColor(Qt::yellow,this);
}
