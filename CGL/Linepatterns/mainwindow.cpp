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

void MainWindow::on_pushButton_4_clicked() //standard line
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
    float dx,dy,len,x,y;
    int i = 0;

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

float MainWindow::sign(float p)
{
    if(p<0)
        return -1;
    else
        return 1;
}

void MainWindow::on_pushButton_2_clicked() //for dotted
{
    float x1,y1,x2,y2;

    x1 = ui -> textEdit->toPlainText().toFloat();
    y1 = ui -> textEdit_2->toPlainText().toFloat();
    x2 = ui -> textEdit_3->toPlainText().toFloat();
    y2 = ui -> textEdit_4->toPlainText().toFloat();

    dda_line_dotted(x1,y1,x2,y2);
}

void MainWindow::dda_line_dotted(float x1, float y1, float x2, float y2)
{
    float dx,dy,len,x,y;
    int i = 0;

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
        if(i%2 == 0)
        {
            img.setPixel(x,y,qRgb(255,0,0));
        }
        x = x + dx;
        y = y + dy;
        i = i + 1;
    }
    ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::on_pushButton_clicked() //dashed line
{
    float x1,y1,x2,y2;

    x1 = ui -> textEdit->toPlainText().toFloat();
    y1 = ui -> textEdit_2->toPlainText().toFloat();
    x2 = ui -> textEdit_3->toPlainText().toFloat();
    y2 = ui -> textEdit_4->toPlainText().toFloat();

    dda_line_dashed(x1,y1,x2,y2);
}

void MainWindow::dda_line_dashed(float x1, float y1, float x2, float y2)
{
    float dx,dy,len,x,y;
    int i = 0;

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
        if(i%15>3)
        {
            img.setPixel(x,y,qRgb(0,255,255));
        }
        x = x + dx;
        y = y + dy;
        i = i + 1;
    }
    ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::on_pushButton_3_clicked()
{
    float x1,y1,x2,y2;

    x1 = ui -> textEdit->toPlainText().toFloat();
    y1 = ui -> textEdit_2->toPlainText().toFloat();
    x2 = ui -> textEdit_3->toPlainText().toFloat();
    y2 = ui -> textEdit_4->toPlainText().toFloat();

    dda_line_dashed_dotted(x1,y1,x2,y2);
}

void MainWindow::dda_line_dashed_dotted(float x1, float y1, float x2, float y2)
{
    float dx,dy,len,x,y;
    int i = 0;

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
        if(i%12 == 2)
        {
            img.setPixel(x,y,qRgb(255,255,255));
        }
        if(i%12>3)
        {
            img.setPixel(x,y,qRgb(0,255,255));
        }
        x = x + dx;
        y = y + dy;
        i = i + 1;
    }
    ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::on_pushButton_5_clicked()
{
    float x1,y1,x2,y2;
    int width;

    x1 = ui -> textEdit->toPlainText().toFloat();
    y1 = ui -> textEdit_2->toPlainText().toFloat();
    x2 = ui -> textEdit_3->toPlainText().toFloat();
    y2 = ui -> textEdit_4->toPlainText().toFloat();
    width = ui->textEdit_5->toPlainText().toFloat();

    while(width!=0)
    {
        dda_line_thick(x1,y1,x2,y2);

        if(x1 == x2)
        {
            x1 = x1 + 1;
            x2 = x2 + 1;
        }
        else if(y1 == y2)
        {
            y1 = y1 + 1;
            y2 = y2 + 1;
        }
        else
        {
            x1 = x1 + 1;
            x2 = x2 + 1;
        }
        width = width -1;
    }
}

void MainWindow::dda_line_thick(float x1,float y1,float x2,float y2)
{
    float dx,dy,len,x,y;
    int i = 0;

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
        img.setPixel(x,y,qRgb(0,255,255));
        x = x + dx;
        y = y + dy;
        i = i + 1;
    }
    ui->label->setPixmap(QPixmap::fromImage(img));
}
