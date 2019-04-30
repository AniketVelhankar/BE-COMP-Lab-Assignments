#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "math.h"

QImage img(600,400,QImage::Format_RGB888);

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    dda_line(300,1,300,399);
    dda_line(1,200,599,200);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::dda_line(float x1, float y1, float x2, float y2)
{
    float dx,dy,len,x,y;
    float i = 0;

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
        img.setPixel(x,y,qRgb(0,255,0));
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


void MainWindow::on_pushButton_clicked()
{
    float x1,y1,x2,y2;

    x1 = ui -> textEdit->toPlainText().toFloat();
    y1 = ui -> textEdit_2->toPlainText().toFloat();
    x2 = ui -> textEdit_3->toPlainText().toFloat();
    y2 = ui -> textEdit_4->toPlainText().toFloat();

    dda_line(x1+300,y1+200,x2+300,y2+200);

}

void MainWindow::on_pushButton_2_clicked()
{
    float x1,y1,x2,y2;

    x1 = ui -> textEdit->toPlainText().toFloat();
    y1 = ui -> textEdit_2->toPlainText().toFloat();
    x2 = ui -> textEdit_3->toPlainText().toFloat();
    y2 = ui -> textEdit_4->toPlainText().toFloat();

    reflectIt(x1,y1,x2,y2);

    dda_line(resY[0][0]+300,resY[0][1]+200,resY[1][0]+300,resY[1][1]+200);
}

void MainWindow::reflectIt(float x1,float y1,float x2,float y2)
{
    float mat1[2][3] = {{x1,y1,1},{x2,y2,1}};
    float refY[3][3] = {{-1,0,0},{0,1,0},{0,0,1}};
    float refX[3][3] = {{1,0,0},{0,-1,0},{0,0,1}};
    float refO[3][3] = {{-1,0,0},{0,-1,0},{0,0,1}};

    for(int i=0;i<2;i++)
    {
        for(int j=0;j<3;j++)
        {
            resY[i][j] = 0;
            resX[i][j] = 0;
            resO[i][j] = 0;
        }
    }

    for(int i=0;i<2;i++)
    {
        for(int j=0;j<3;j++)
        {
            for(int k=0;k<3;k++)
            {
                resY[i][j] = resY[i][j] + mat1[i][k] * refY[k][j];
            }
        }
    }

    for(int i=0;i<2;i++)
    {
        for(int j=0;j<3;j++)
        {
            for(int k=0;k<3;k++)
            {
                resX[i][j] = resX[i][j] + mat1[i][k] * refX[k][j];
            }
        }
    }

    for(int i=0;i<2;i++)
    {
        for(int j=0;j<3;j++)
        {
            for(int k=0;k<3;k++)
            {
                resO[i][j] = resO[i][j] + mat1[i][k] * refO[k][j];
            }
        }
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    float x1,y1,x2,y2;

    x1 = ui -> textEdit->toPlainText().toFloat();
    y1 = ui -> textEdit_2->toPlainText().toFloat();
    x2 = ui -> textEdit_3->toPlainText().toFloat();
    y2 = ui -> textEdit_4->toPlainText().toFloat();

    reflectIt(x1,y1,x2,y2);

    dda_line(resO[0][0]+300,resO[0][1]+200,resO[1][0]+300,resO[1][1]+200);
}

void MainWindow::on_pushButton_4_clicked()
{
    float x1,y1,x2,y2;

    x1 = ui -> textEdit->toPlainText().toFloat();
    y1 = ui -> textEdit_2->toPlainText().toFloat();
    x2 = ui -> textEdit_3->toPlainText().toFloat();
    y2 = ui -> textEdit_4->toPlainText().toFloat();

    reflectIt(x1,y1,x2,y2);

    dda_line(resX[0][0]+300,resX[0][1]+200,resX[1][0]+300,resX[1][1]+200);
}

void MainWindow::on_pushButton_5_clicked()
{
    float x1,y1,x2,y2,tx,ty;
    int t;

    x1 = ui -> textEdit->toPlainText().toFloat();
    y1 = ui -> textEdit_2->toPlainText().toFloat();
    x2 = ui -> textEdit_3->toPlainText().toFloat();
    y2 = ui -> textEdit_4->toPlainText().toFloat();
    tx = ui -> textEdit_5->toPlainText().toFloat();
    ty = ui -> textEdit_6->toPlainText().toFloat();
    t = ui -> textEdit_7->toPlainText().toInt();

    rotateABT(x1,y1,x2,y2,tx,ty,t);

    dda_line(rot2[0][0]+300,rot2[0][1]+200,rot2[1][0]+300,rot2[1][1]+200);
}

void MainWindow::rotateABT(float x1,float y1,float x2,float y2, float tx,float ty, int t)
{
    int T = (t*3.14)/180;
    float mat1[2][3] = {{x1,y1,1},{x2,y2,1}};
    float t1[3][3] = {{1,0,0},{0,1,0},{-tx,-ty,1}};
    float t2[3][3] = {{1,0,0},{0,1,0},{tx,ty,1}};
    float r1[3][3] = {{cos(T),sin(T),0},{-sin(T),cos(T),0},{0,0,1}};

    for(int i=0;i<2;i++)
        for(int j=0;j<3;j++)
        {
            rot[i][j] = 0;
            rot1[i][j] = 0;
            rot2[i][j] = 0;
        }

    for(int i=0;i<2;i++)
        for(int j=0;j<3;j++)
            for(int k=0;k<3;k++)
                rot[i][j] = rot[i][j] + mat1[i][k] * t1[k][j];

    for(int i=0;i<2;i++)
        for(int j=0;j<3;j++)
            for(int k=0;k<3;k++)
                rot1[i][j] = rot1[i][j] + rot[i][k] * r1[k][j];

    for(int i=0;i<2;i++)
        for(int j=0;j<3;j++)
            for(int k=0;k<3;k++)
                rot2[i][j] = rot2[i][j] + rot1[i][k] * t2[k][j];

}
