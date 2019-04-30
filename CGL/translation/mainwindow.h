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

    float res[2][3];
    float res2[2][3];
    float res3[2][3];

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;
    void dda_line(float,float,float,float);
    float sign(float);
    void multiply(float,float,float,float,float,float);
    void rotateIt(float,float,float,float,int);

};

#endif // MAINWINDOW_H
