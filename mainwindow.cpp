#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    secondWindow = new nextWindowSecond();
    thirdWindow = new nextWindowThird();
    fourthWindow = new nextWindowFourth();
    fifthWindow = new nextWindowFifth();
    sixthWindow = new nextWindowSixth();

    connect(secondWindow, &nextWindowSecond::secondWindow, this, &MainWindow::show);
    connect(thirdWindow, &nextWindowThird::thirdWindow, this, &MainWindow::show);
    connect(fourthWindow, &nextWindowFourth::fourthWindow, this, &MainWindow::show);
    connect(fifthWindow, &nextWindowFifth::fifthWindow, this, &MainWindow::show);
    connect(sixthWindow, &nextWindowSixth::sixthWindow, this, &MainWindow::show);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    secondWindow->show();
    this->close();
}


void MainWindow::on_pushButton_2_clicked()
{
    thirdWindow->show();
    this->close();
}


void MainWindow::on_pushButton_3_clicked()
{
    fourthWindow->show();
    this->close();
}


void MainWindow::on_pushButton_6_clicked()
{
    fifthWindow->show();
    this->close();
}


void MainWindow::on_pushButton_8_clicked()
{
    sixthWindow->show();
    this->close();
}

