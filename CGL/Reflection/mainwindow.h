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

    float resY[2][3];
    float resO[2][3];
    float resX[2][3];

    float rot[2][3];
    float rot1[2][3];
    float rot2[2][3];

    void dda_line(float,float,float,float);
    float sign(float);
    void reflectIt(float,float,float,float);
    void rotateABT(float,float,float,float,float,float,int);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
