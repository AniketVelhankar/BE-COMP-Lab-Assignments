#include "mainwindow.h"
#include "ui_mainwindow.h"
float xl=100,xh=200,yl=100,yh=200;
float a[25],b[25];
int i=0;
QImage I0(300,300,QImage::Format_RGB888);
QImage I1(300,300,QImage::Format_RGB888);
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    drawClip();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::drawClip()
{
    DDA(xl,yl,xl,yh,I0);
    DDA(xh,yl,xh,yh,I0);
    DDA(xl,yl,xh,yl,I0);
    DDA(xl,yh,xh,yh,I0);
    ui->label->setPixmap(QPixmap::fromImage(I0));
    DDA(xl,yl,xl,yh,I1);
    DDA(xh,yl,xh,yh,I1);
    DDA(xl,yl,xh,yl,I1);
    DDA(xl,yh,xh,yh,I1);
    ui->label_2->setPixmap(QPixmap::fromImage(I1));
}

void MainWindow::mousePressEvent(QMouseEvent *eve)
{
   a[i]=QString::number(eve->x()).toFloat();
   b[i]=QString::number(eve->y()).toFloat();
   if(eve->button()==Qt::RightButton)
   {

       clip();
    }
   else
   {
   if(i%2==1)
  DDA(a[i],b[i],a[i-1],b[i-1],I0);
   i++;
  }
   ui->label->setPixmap(QPixmap::fromImage(I0));
   //emit(clicked());
}
void MainWindow::outCode(float x,float y,bool code[4])
{
        if(y>yh)
            code[0]=1;
        else
            code[0]=0;
        if(y<yl)
            code[1]=1;
        else
            code[1]=0;
        if(x>xh)
            code[2]=1;
        else
            code[2]=0;
        if(x<xl)
            code[3]=1;
        else
            code[3]=0;
}
void MainWindow::andCodes(bool a1[4],bool a2[4],bool a3[4])
{
    for(int i=0;i<4;i++)
     a3[i]=a1[i]&&a2[i];
}
bool MainWindow::isZero(bool b1[4])
{
    if(b1[0]||b1[1]||b1[2]||b1[3])
        return(0);
   return(1);
}

bool MainWindow::cSClip(float &x1,float &y1,float &x2,float &y2)
{
    bool codeA[4],codeB[4],codeC[4];

    float yxl,yxh,xyl,xyh,m,c;

    outCode(x1,y1,codeA);
    outCode(x2,y2,codeB);

    andCodes(codeA,codeB,codeC);

    if(!isZero(codeC))
        return(0);

    m=(y2-y1)/(x2-x1);
    c=-m*x2+y2;

    yxl=xl*m+c;
    yxh=xh*m+c;

    xyl=(yl-c)/m;
    xyh=(yh-c)/m;

    if(codeB[0])
    {
        if(xyh<xl)
        {
            x2=xl;
            y2=yxl;
        }
        else if(xyh>xh)
        {
            x2=xh;
            y2=yxh;
        }
        else
        {
            x2=xyh;
            y2=yh;
        }
     }
    else if(codeB[1])
    {
        if(xyl<xl)
        {
            x2=xl;
            y2=yxl;
        }
        else if(xyl>xh)
        {
            x2=xh;
            y2=yxh;
        }
        else
        {
            x2=xyl;
            y2=yl;
        }
     }
    else if(codeB[2])
    {
        y2=yxh;
        x2=xh;
    }
    else if(codeB[3])
    {
        xyl=(yl-c)/m;
        y2=yxl;
        x2=xl;
    }


    if(codeA[0])
    {
        if(xyh<xl)
        {
            x1=xl;
            y1=yxl;
        }
        else if(xyh>xh)
        {
            x1=xh;
            y1=yxh;
        }
        else
        {
            x1=xyh;
            y1=yh;
        }
     }
    else if(codeA[1])
    {
        if(xyl<xl)
        {
            x1=xl;
            y1=yxl;
        }
        else if(xyl>xh)
        {
            x1=xh;
            y1=yxh;
        }
        else
        {
            x1=xyl;
            y1=yl;
        }
     }
    else if(codeA[2])
    {
        y1=yxh;
        x1=xh;
    }
    else if(codeA[3])
    {
        y1=yxl;
        x1=xl;
    }
    return(1);
}
void MainWindow::DDA(float x1,float y1,float x2,float y2,QImage &I)
{
    float dx,dy,len,xinc,yinc,x=x1,y=y1;
    dx=x2-x1;
    dy=y2-y1;
    len=(abs(dy)>abs(dx))?(abs(dy)):(abs(dx));
    xinc=dx/len;
    yinc=dy/len;
    for(int j=0;j<len;j++)
    {
        x+=xinc;
        y+=yinc;
        I.setPixel(int(x),int(y),qRgb(200,150,190));
    }

}
void MainWindow::clip()
{
    float p,q,r,s;
    for(int cnt=0;cnt<i;cnt++)
    {
        if(cnt%2==1)
        {
                p=a[cnt];
                q=b[cnt];
                r=a[cnt-1];
                s=b[cnt-1];
              if(cSClip(p,q,r,s))
                  DDA(p,q,r,s,I1);

               ui->label_2->setPixmap(QPixmap::fromImage(I1));
        }
    }
}
