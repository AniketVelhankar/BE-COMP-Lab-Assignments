#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    float res3[2][3];

    void bresenham_line(int,int,int,int);
    int sign(int);
    void mouseDoubleClickEvent(QMouseEvent *);
    void seedfill(int,int);
    void rotateIt(float,float,float,float,int);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
