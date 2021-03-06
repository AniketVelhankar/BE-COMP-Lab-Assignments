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

private slots:
    void on_pushButton_3_clicked();
    void dda_line(float,float,float,float);
    void on_pushButton_clicked();
    void bresenhamc(float,float,float);
    void on_pushButton_2_clicked();
    void ddac(float,float,float);
    float sign(float);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
