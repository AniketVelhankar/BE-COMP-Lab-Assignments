#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
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

void MainWindow::on_pushButton_clicked()
{
    float x1,y1,x2,y2;

    x1 = ui -> textEdit->toPlainText().toFloat();
    y1 = ui -> textEdit_2->toPlainText().toFloat();
    x2 = ui -> textEdit_3->toPlainText().toFloat();
    y2 = ui -> textEdit_4->toPlainText().toFloat();

    dda_line(x1+300,y1+200,x2+300,y2+200);
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

void MainWindow::on_pushButton_2_clicked() //translation
{
    float x1,y1,x2,y2,tx,ty;

    x1 = ui -> textEdit->toPlainText().toFloat();
    y1 = ui -> textEdit_2->toPlainText().toFloat();
    x2 = ui -> textEdit_3->toPlainText().toFloat();
    y2 = ui -> textEdit_4->toPlainText().toFloat();
    tx = ui -> textEdit_5 ->toPlainText().toFloat();
    ty = ui -> textEdit_6 ->toPlainText().toFloat();

    multiply(x1,y1,x2,y2,tx,ty);
    dda_line(res[0][0]+300,res[0][1]+200,res[1][0]+300,res[1][1]+200);
}

void MainWindow :: multiply(float x1,float y1,float x2,float y2,float tx,float ty)
{
    float mat1[2][3] = {{x1,y1,1},{x2,y2,1}};
    float mat2[3][3] = {{1,0,0},{0,1,0},{tx,ty,1}};
    float mat3[3][3] = {{tx,0,0},{0,ty,0},{0,0,1}};

    for(int i=0;i<2;i++)
    {
        for(int j=0;j<3;j++)
        {
            res[i][j] = 0;
            res2[i][j] = 0;
        }
    }

    for(int i=0;i<2;i++)
        for(int j =0;j<3;j++)
            for(int k=0;k<3;k++)
            {
                res[i][j] = res[i][j] + mat1[i][k] * mat2[k][j] ;
            }

    for(int i=0;i<2;i++)
        for(int j =0;j<3;j++)
            for(int k=0;k<3;k++)
            {
                res2[i][j] = res2[i][j] + mat1[i][k] * mat3[k][j] ;
            }

    //    for(int i=0;i<2;i++)
    //        for(int j=0;j<3;j++)
    //            qDebug()<<res[i][j];

}

void MainWindow::on_pushButton_3_clicked()//scaling
{
    float x1,y1,x2,y2,Sx,Sy;

    x1 = ui -> textEdit->toPlainText().toFloat();
    y1 = ui -> textEdit_2->toPlainText().toFloat();
    x2 = ui -> textEdit_3->toPlainText().toFloat();
    y2 = ui -> textEdit_4->toPlainText().toFloat();
    Sx = ui -> textEdit_5 ->toPlainText().toFloat();
    Sy = ui -> textEdit_6 ->toPlainText().toFloat();

    multiply(x1,y1,x2,y2,Sx,Sy);
    dda_line(res2[0][0]+300,res2[0][1]+200,res2[1][0]+300,res2[1][1]+200);
}

void MainWindow::on_pushButton_4_clicked() //rotate
{
    float x1,y1,x2,y2,T;

    x1 = ui -> textEdit->toPlainText().toFloat();
    y1 = ui -> textEdit_2->toPlainText().toFloat();
    x2 = ui -> textEdit_3->toPlainText().toFloat();
    y2 = ui -> textEdit_4->toPlainText().toFloat();
    T =  ui -> textEdit_7->toPlainText().toFloat();

    rotateIt(x1,y1,x2,y2,T);
    dda_line(res3[0][0]+300,res3[0][1]+200,res3[1][0]+300,res3[1][1]+200);
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
