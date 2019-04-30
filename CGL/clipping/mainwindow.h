#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QMouseEvent>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
     void mousePressEvent(QMouseEvent *eve);
    void DDA(float x1,float y1,float x2,float y2,QImage &I);
   void clip();
   bool cSClip(float &x,float &y,float &x2,float &y2);
   bool isZero(bool b1[4]);
   void andCodes(bool a1[4],bool a2[4],bool a3[4]);
   void outCode(float x,float y,bool code[4]);
   void drawClip();
signals:
    void clicked();
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
