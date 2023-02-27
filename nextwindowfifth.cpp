#include "nextwindowfifth.h"
#include "./ui_nextwindowfifth.h"
#include "task.h"
#include <QMessageBox>
#include <QStack>
// Все задачи
#include <algorithm>
task* allTasks = new task();
QStack<task*> takenActions;

nextWindowFifth::nextWindowFifth(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::nextWindowFifth)
{
    ui->setupUi(this);
}

nextWindowFifth::~nextWindowFifth()
{
    delete ui;
}


void nextWindowFifth::on_pushButton_clicked()
{
    this->close();      // Закрываем окно
    emit fifthWindow(); // И вызываем сигнал на открытие главного окна
}


void nextWindowFifth::on_pushButton_2_clicked()         // добавить задачу
{
    if(allTasks->containTask(ui->lineEdit->text())){
        QMessageBox* msg = new QMessageBox();
        msg->setWindowTitle("Неправильный ввод");
        msg->setText("Вы записали уже существующую задачу");
        msg->exec();
        return;
    }
    ui->tableWidget->clear();
    QString temp;
    allTasks->appendTask(ui->lineEdit->text());
    int i = 0;
    ui->tableWidget->insertRow(0);
    foreach(temp, allTasks->getTasks()){
        if(!allTasks->containEndedTask(temp)){
            QTableWidgetItem *itm1= new QTableWidgetItem();
            itm1->setText(temp);
            ui->tableWidget->setItem(i,0,itm1);
            i++;
        }
    }
    takenActions.push(allTasks);
}


void nextWindowFifth::on_pushButton_3_clicked()         // добавить в выполненные задачи
{
    if(!allTasks->containTask(ui->lineEdit_2->text())){
        QMessageBox* msg = new QMessageBox();
        msg->setWindowTitle("Предупреждение");
        msg->setText("Задача не была найдена");
        msg->exec();
        return;
    }
    if(allTasks->containEndedTask(ui->lineEdit_2->text())){
        QMessageBox* msg = new QMessageBox();
        msg->setWindowTitle("Предупреждение");
        msg->setText("Задача уже была добавлена в список");
        msg->exec();
        return;
    }
    QString temp;
    allTasks->appendEndedTasks(ui->lineEdit_2->text());

    int i = 0;
    ui->tableWidget_2->insertRow(0);
    foreach(temp, allTasks->getEndedTasks()){
        QTableWidgetItem *itm1= new QTableWidgetItem();
        itm1->setText(temp);
        ui->tableWidget_2->setItem(i,0,itm1);
        i++;
    }
    ui->tableWidget->clear();
    i = 0;
    ui->tableWidget->removeRow(0);
    foreach(temp, allTasks->getTasks()){
        if(!allTasks->containEndedTask(temp)){
            QTableWidgetItem *itm1= new QTableWidgetItem();
            itm1->setText(temp);
            ui->tableWidget->setItem(i,0,itm1);
            i++;
        }
    }
    takenActions.push(allTasks);
}




void nextWindowFifth::on_pushButton_5_clicked()         // запись в файл
{
    ofstream out;          // поток для записи
    out.open("D:\\My shit)\\coursachTry\\tasks.txt"); // окрываем файл для записи
    out << *allTasks;
    out.close();
}


void nextWindowFifth::on_pushButton_6_clicked()         // чтение из файла
{
    ifstream in;
    allTasks->clearAllTasks();
    in.open("D:\\My shit)\\coursachTry\\tasks.txt");
    in >> *allTasks;
    in.close();

    ui->tableWidget->clear();
    ui->tableWidget_2->clear();
    while(ui->tableWidget->rowCount() > 0){
        ui->tableWidget->removeRow(0);
    }
    while(ui->tableWidget_2->rowCount() > 0){
        ui->tableWidget_2->removeRow(0);
    }

    QString temp;
    int i = 0;

    foreach(temp, allTasks->getTasks()){
        ui->tableWidget->insertRow(i);
        QTableWidgetItem *itm1= new QTableWidgetItem();
        itm1->setText(temp);
        ui->tableWidget->setItem(i,0,itm1);
        i++;
    }

    QString temp2;
    i = 0;
    foreach(temp2, allTasks->getEndedTasks()){
        ui->tableWidget_2->insertRow(i);
        QTableWidgetItem *itm1= new QTableWidgetItem();
        itm1->setText(temp2);
        ui->tableWidget_2->setItem(i,0,itm1);
        i++;
    }

    takenActions.push(allTasks);
}

void nextWindowFifth::on_pushButton_7_clicked()         // сортировка по параметру
{
    if(ui->lineEdit_5->text() == "Задачи"){
        allTasks->sortTasks();
        ui->tableWidget->clear();
        while(ui->tableWidget->rowCount() > 0){
            ui->tableWidget->removeRow(0);
        }

        int i = 0;
        foreach(QString temp, allTasks->getTasks()){
            ui->tableWidget->insertRow(i);
            QTableWidgetItem *itm1= new QTableWidgetItem();
            itm1->setText(temp);
            ui->tableWidget->setItem(i,0,itm1);
            i++;
        }
    }
    else if (ui->lineEdit_5->text() == "Выполненные задачи"){
        allTasks->sortEndedTasks();
        ui->tableWidget_2->clear();
        while(ui->tableWidget_2->rowCount() > 0){
            ui->tableWidget_2->removeRow(0);
        }

        int i = 0;
        foreach(QString temp, allTasks->getEndedTasks()){
            ui->tableWidget_2->insertRow(i);
            QTableWidgetItem *itm1= new QTableWidgetItem();
            itm1->setText(temp);
            ui->tableWidget_2->setItem(i,0,itm1);
            i++;
        }
    }else{
        QMessageBox* msg = new QMessageBox();
        msg->setWindowTitle("Предупреждение");
        msg->setText("Неверно задан поиск параметра");
        msg->exec();
        return;
        return;
    }
}


void nextWindowFifth::on_pushButton_11_clicked()        // Установить название
{
    if(ui->lineEdit_3->text().isEmpty()){
        QMessageBox* msg = new QMessageBox();
        msg->setWindowTitle("Предупреждение");
        msg->setText("Вы ничего не ввели");
        msg->exec();
        return;
    }
    allTasks->setDescription(ui->lineEdit_3->text().toStdString());
    ui->label->setText(ui->lineEdit_3->text());
}


void nextWindowFifth::on_pushButton_12_clicked()        // найти задачу
{
    if(ui->lineEdit_4->text().isEmpty()){
        QMessageBox* msg = new QMessageBox();
        msg->setWindowTitle("Предупреждение");
        msg->setText("Вы ничего не ввели");
        msg->exec();
        return;
    }
    if(!allTasks->containTask(ui->lineEdit_4->text())){
        QMessageBox* msg = new QMessageBox();
        msg->setWindowTitle("Предупреждение");
        msg->setText("Ничего не найдено");
        msg->exec();
        return;
    }

    ui->tableWidget_3->clear();
    while(ui->tableWidget_3->rowCount() > 0){
        ui->tableWidget_3->removeRow(0);
    }


    foreach(QString temp, allTasks->getTasks()){
        if(temp == ui->lineEdit_4->text()){
            ui->tableWidget_3->insertRow(0);
            QTableWidgetItem *itm1= new QTableWidgetItem();
            itm1->setText(ui->lineEdit_4->text());
            ui->tableWidget_3->setItem(0,0,itm1);
        }
    }
}


void nextWindowFifth::on_pushButton_13_clicked()        // найти выполненную задачу
{
    if(ui->lineEdit_4->text().isEmpty()){
        QMessageBox* msg = new QMessageBox();
        msg->setWindowTitle("Предупреждение");
        msg->setText("Вы ничего не ввели");
        msg->exec();
        return;
    }
    if(!allTasks->containEndedTask(ui->lineEdit_4->text())){
        QMessageBox* msg = new QMessageBox();
        msg->setWindowTitle("Предупреждение");
        msg->setText("Ничего не найдено");
        msg->exec();
        return;
    }

    ui->tableWidget_3->clear();
    while(ui->tableWidget_3->rowCount() > 0){
        ui->tableWidget_3->removeRow(0);
    }


    foreach(QString temp, allTasks->getEndedTasks()){
        if(temp == ui->lineEdit_4->text()){
            ui->tableWidget_3->insertRow(0);
            QTableWidgetItem *itm1= new QTableWidgetItem();
            itm1->setText(ui->lineEdit_4->text());
            ui->tableWidget_3->setItem(0,0,itm1);
        }
    }
}


void nextWindowFifth::on_pushButton_8_clicked()         // очистка окна поиска
{
    ui->tableWidget_3->clear();
    while(ui->tableWidget_3->rowCount() > 0){
        ui->tableWidget_3->removeRow(0);
    }
}

