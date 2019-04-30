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
    void brescircle(int x1,int y1, int r);
       void flower(int,int,int);
    void petal1(int x1,int y1, int r);
    void petal2(int x1,int y1, int r);
    void petal3(int x1,int y1, int r);
    void petal4(int x1,int y1, int r);

    void clearimage();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
