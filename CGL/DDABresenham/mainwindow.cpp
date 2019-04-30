#include "mainwindow.h"
#include "ui_mainwindow.h"

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

void MainWindow::on_pushButton_clicked()
{
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

    i = 1;

    while (i<=len) {
        img.setPixel(x,y,qRgb(255,0,0));
        x = x + dx;
        y = y + dy;
        i = i + 1;
    }
    ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::on_pushButton_2_clicked()
{
    float x1,y1,x2,y2;

    x1 = ui -> textEdit->toPlainText().toFloat();
    y1 = ui -> textEdit_2->toPlainText().toFloat();
    x2 = ui -> textEdit_3->toPlainText().toFloat();
    y2 = ui -> textEdit_4->toPlainText().toFloat();

    bresenham_line(x1,y1,x2,y2);
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
            img.setPixel(x,y,qRgb(0,255,0));

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
            img.setPixel(x,y,qRgb(0,255,0));

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

float MainWindow::sign(float p)
{
    if(p<0)
        return -1;
    else
        return 1;
}
