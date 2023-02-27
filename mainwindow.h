#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "nextwindowsecond.h"
#include "nextwindowthird.h"
#include "nextwindowfourth.h"
#include "nextwindowfifth.h"
#include "nextwindowsixth.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_8_clicked();

private:
    Ui::MainWindow *ui;
    nextWindowSecond *secondWindow;
    nextWindowThird *thirdWindow;
    nextWindowFourth *fourthWindow;
    nextWindowFifth *fifthWindow;
    nextWindowSixth *sixthWindow;

};
#endif // MAINWINDOW_H
