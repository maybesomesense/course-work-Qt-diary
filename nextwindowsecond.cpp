#include "nextwindowsecond.h"
#include "./ui_nextwindowsecond.h"
#include <QMessageBox>
#include <QCalendarWidget>
#include <QPainter>
#include <QGraphicsWidget>
#include "phoneBook.h"
#include <QStack>
// Телефонная книга

phoneBook* phones = new phoneBook();
QStack<phoneBook*> takenActions3;
nextWindowSecond::nextWindowSecond(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::nextWindowSecond)
{
    ui->setupUi(this);
}

nextWindowSecond::~nextWindowSecond()
{
    delete ui;
}


void nextWindowSecond::on_pushButton_clicked()
{
    this->close();       // Закрываем окно
    emit secondWindow(); // И вызываем сигнал на открытие главного окна
}


void nextWindowSecond::on_pushButton_2_clicked()
{
    if(phones->phoneContain(ui->lineEdit->text()) && phones->phoneContain(ui->lineEdit_2->text())){
        QMessageBox* msg = new QMessageBox();
        msg->setWindowTitle("Неправильный ввод");
        msg->setText("Вы записали уже существующий номер телефона и ФИО");
        msg->exec();
        return;
    }
    takenActions3.push(phones);
    ui->tableWidget->clear();
    phones->addPhone(ui->lineEdit_2->text(), ui->lineEdit->text());
    int i = 0;
    ui->tableWidget->insertRow(0);
    foreach(QString temp, phones->getPhoneKeys()){
        QTableWidgetItem *itm1= new QTableWidgetItem();
        QTableWidgetItem *itm2 = new QTableWidgetItem();
        itm1->setText(temp);
        ui->tableWidget->setItem(i,0,itm1);
        itm2->setText(phones->getPhone(temp));
        ui->tableWidget->setItem(i,1,itm2);
        i++;
    }
}


void nextWindowSecond::on_pushButton_3_clicked()            // отменить предыдущее действие
{
    if(takenActions3.isEmpty()){
        QMessageBox* msg = new QMessageBox();
        msg->setWindowTitle("Предупреждение");
        msg->setText("Вы не выполнили никаких действий");
        msg->exec();
        return;
    }
    else{            // если стек не пуст
        takenActions3.pop();                 // удаление с вершины элемента стека
        if(!takenActions3.isEmpty()){        // проверка стека на пустоту
            phones = takenActions3.top();
        }
        else{

            ui->tableWidget->clear();
            while(ui->tableWidget->rowCount() > 0){
                ui->tableWidget->removeRow(0);
            }
            return;
        }
    }

    QString temp;
    int i = 0;
    foreach(temp, phones->getPhoneKeys()){
        QTableWidgetItem *itm1= new QTableWidgetItem();
        QTableWidgetItem *itm2 = new QTableWidgetItem();
        itm1->setText(temp);
        ui->tableWidget->setItem(i,0,itm1);
        itm2->setText(phones->getPhone(temp));
        ui->tableWidget->setItem(i,1,itm2);
        i++;
    }
}


void nextWindowSecond::on_pushButton_4_clicked()        // запись в файл
{
    ofstream out;          // поток для записи
    out.open("D:\\My shit)\\coursachTry\\phones.txt"); // окрываем файл для записи
    out << *phones;
    out.close();
}


void nextWindowSecond::on_pushButton_5_clicked()        // чтение из файла
{
    takenActions3.push(phones);
    ifstream in;
    phones->clearPhones();
    in.open("D:\\My shit)\\coursachTry\\phones.txt");
    in >> *phones;
    in.close();
    ui->tableWidget->clear();

    int i = 0;

    foreach(QString temp, phones->getPhoneKeys()){
        ui->tableWidget->insertRow(i);
        QTableWidgetItem *itm1= new QTableWidgetItem();
        QTableWidgetItem *itm2 = new QTableWidgetItem();
        itm1->setText(temp);
        ui->tableWidget->setItem(i,0,itm1);
        itm2->setText(phones->getPhone(temp));
        ui->tableWidget->setItem(i,1,itm2);
        i++;
    }

}


void nextWindowSecond::on_pushButton_6_clicked()        // установить название
{
    if(ui->lineEdit_3->text().isEmpty()){
        QMessageBox* msg = new QMessageBox();
        msg->setWindowTitle("Предупреждение");
        msg->setText("Вы ничего не ввели");
        msg->exec();
        return;
    }
    takenActions3.push(phones);
    phones->setDescription(ui->lineEdit_3->text().toStdString());
    ui->label_2->setText(ui->lineEdit_3->text());
}


void nextWindowSecond::on_pushButton_7_clicked()            // Найти по ФИО
{
    if(!phones->phoneContain(ui->lineEdit_4->text())){
        QMessageBox* msg = new QMessageBox();
        msg->setWindowTitle("Вывод");
        msg->setText("Ничего не найдено");
        msg->exec();
        return;
    }
    if(ui->lineEdit_4->text().isEmpty()){
        QMessageBox* msg = new QMessageBox();
        msg->setWindowTitle("Предупреждение");
        msg->setText("Вы ничего не ввели");
        msg->exec();
        return;
    }

    phoneBook* findedBook = new phoneBook();

    for (auto it = phones->getMap().begin(); it != phones->getMap().end(); ++it)
        if (it.key() == ui->lineEdit_4->text()){
            findedBook->addPhone(it.key(), it.value());
        }

    ui->tableWidget_2->clear();
    while(ui->tableWidget_2->rowCount() > 0){
        ui->tableWidget_2->removeRow(0);
    }

    int i = 0;

    foreach(QString temp, findedBook->getPhoneKeys()){
        ui->tableWidget_2->insertRow(i);
        QTableWidgetItem *itm1= new QTableWidgetItem();
        QTableWidgetItem *itm2 = new QTableWidgetItem();
        itm1->setText(temp);
        ui->tableWidget_2->setItem(i,0,itm1);
        itm2->setText(findedBook->getPhone(temp));
        ui->tableWidget_2->setItem(i,1,itm2);
        i++;
    }
}


void nextWindowSecond::on_pushButton_8_clicked()        // Найти по номеру
{
    if(!phones->phoneContain(ui->lineEdit_4->text())){
        QMessageBox* msg = new QMessageBox();
        msg->setWindowTitle("Вывод");
        msg->setText("Ничего не найдено");
        msg->exec();
        return;
    }
    if(ui->lineEdit_4->text().isEmpty()){
        QMessageBox* msg = new QMessageBox();
        msg->setWindowTitle("Предупреждение");
        msg->setText("Вы ничего не ввели");
        msg->exec();
        return;
    }

    phoneBook* findedBook = new phoneBook();

    for (auto it = phones->getMap().begin(); it != phones->getMap().end(); ++it)
        if (it.value() == ui->lineEdit_4->text()){
            findedBook->addPhone(it.key(), it.value());
        }

    ui->tableWidget_2->clear();
    while(ui->tableWidget_2->rowCount() > 0){
        ui->tableWidget_2->removeRow(0);
    }

    int i = 0;

    foreach(QString temp, findedBook->getPhoneKeys()){
        ui->tableWidget_2->insertRow(i);
        QTableWidgetItem *itm1= new QTableWidgetItem();
        QTableWidgetItem *itm2 = new QTableWidgetItem();
        itm1->setText(temp);
        ui->tableWidget_2->setItem(i,0,itm1);
        itm2->setText(findedBook->getPhone(temp));
        ui->tableWidget_2->setItem(i,1,itm2);
        i++;
    }
}

