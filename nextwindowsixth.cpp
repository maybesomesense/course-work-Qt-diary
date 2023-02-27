#include "nextwindowsixth.h"
#include "ui_nextwindowsixth.h"
#include "Tree.h"
//#include "Alhoritm.h"
#include "Alhoritm.cpp"
#include <QMessageBox>
#include "Stack.h"


Stack<wishNote> stack;							//стек для сохранения предыдущих действий
Tree<wishNote> wishes;
QStack<Tree<wishNote>>* takenActions5;

nextWindowSixth::nextWindowSixth(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::nextWindowSixth)
{
    ui->setupUi(this);
}

nextWindowSixth::~nextWindowSixth()
{
    delete ui;
}

void nextWindowSixth::on_pushButton_clicked()
{
    this->close();      // Закрываем окно
    emit sixthWindow(); // И вызываем сигнал на открытие главного окна
}

void nextWindowSixth::on_pushButton_2_clicked() // отмена предыдущего действия
{
    ui->listWidget->clear();
    TreeIterator<wishNote> iterator(&wishes);
    if(*(*(iterator.Begin())) == nullptr){
        QMessageBox* msg = new QMessageBox();
        msg->setWindowTitle("Предупреждение");
        msg->setText("Вы не совершили никаких действий");
        msg->exec();
        ui->lineEdit->clear();
        ui->textEdit->clear();
        return;
    }
    if(*(*(iterator.Begin())) == *(*(iterator.End()))){
        wishes.DeleteTree();
        ui->listWidget->clear();
        return;
    }
    Alhoritm<wishNote>::Cancellation(&wishes, stack);

    iterator = *iterator.Begin();

    if(*(*(iterator.Begin())) == *(*(iterator.End()))){
        QString way = QString::fromUtf8((*iterator)->value.getWish());
        QString wish = QString::fromUtf8((*iterator)->value.getWay());
        ui->listWidget->addItem(way + "\n" + wish);
    }
    else{
        for(iterator = *iterator.Begin(); iterator != *iterator.End(); iterator++){
            QString way = QString::fromUtf8((*iterator)->value.getWish());
            QString wish = QString::fromUtf8((*iterator)->value.getWay());
            ui->listWidget->addItem(way + "\n" + wish);
        }
        QString way = QString::fromUtf8((*iterator)->value.getWish());
        QString wish = QString::fromUtf8((*iterator)->value.getWay());
        ui->listWidget->addItem(way + "\n" + wish);
    }
}


void nextWindowSixth::on_pushButton_3_clicked() // добавление
{
    if(ui->lineEdit->text().isEmpty() || ui->textEdit->toPlainText().isEmpty()){
        QMessageBox* msg = new QMessageBox();
        msg->setWindowTitle("Неправильный ввод");
        msg->setText("Одно из текстовых полей пустое");
        msg->exec();
        ui->lineEdit->clear();
        ui->textEdit->clear();
        return;
    }
//    takenActions5->push(wishes);
    ui->listWidget->clear();
    wishNote* wishNoteObj = new wishNote(ui->lineEdit->text().toStdString(),
                                         ui->textEdit->toPlainText().toStdString(),
                                         ui->calendar->selectedDate().toString().toStdString());
    Node<wishNote>* node = nullptr;					//узел дерева для вставки
    TreeIterator<wishNote> iterator(&wishes);

    node = new Node<wishNote>(*wishNoteObj);	//создание узла
    Alhoritm<wishNote>::Insert(*iterator.Begin(), *iterator.End(), &wishes, node, stack);
    QTextCharFormat format;
    QBrush brush;
    QColor color;
    int r=139,g=0,b=255,a=155;
    color.setRgb(r,g,b,a);;
    brush.setColor(color);
    format.setBackground(brush);
    ui->calendar->setDateTextFormat(ui->calendar->selectedDate(),format);
    ui->lineEdit->clear();
    ui->textEdit->clear();

    iterator = *iterator.Begin();

    if(*(*(iterator.Begin())) == *(*(iterator.End()))){
        QString way = QString::fromUtf8((*iterator)->value.getWish());
        QString wish = QString::fromUtf8((*iterator)->value.getWay());
        ui->listWidget->addItem(way + "\n" + wish);
    }
    else{
        for(iterator = *iterator.Begin(); iterator != *iterator.End(); iterator++){
            QString way = QString::fromUtf8((*iterator)->value.getWish());
            QString wish = QString::fromUtf8((*iterator)->value.getWay());
            ui->listWidget->addItem(way + "\n" + wish);
        }
        QString way = QString::fromUtf8((*iterator)->value.getWish());
        QString wish = QString::fromUtf8((*iterator)->value.getWay());
        ui->listWidget->addItem(way + "\n" + wish);
    }

}


void nextWindowSixth::on_pushButton_4_clicked()     // установить название
{
    if(ui->lineEdit_2->text().isEmpty()){
        QMessageBox* msg = new QMessageBox();
        msg->setWindowTitle("Предупреждение");
        msg->setText("Вы ничего не ввели");
        msg->exec();
        return;
    }
    ui->label_4->setText(ui->lineEdit_2->text());
}


void nextWindowSixth::on_pushButton_7_clicked()     // запись в файл
{
    FileStream out;          // поток для записи
    //out.Open("D:\\My shit)\\coursachTry\\wishes.txt", 1); // окрываем файл для записи
    Alhoritm<wishNote>::WriteToFile(&wishes, "D:\\My shit)\\coursachTry\\wishes.txt");
    out.Close();
}


void nextWindowSixth::on_pushButton_8_clicked()     // чтение из файла
{
    Node<wishNote>* node = nullptr;					//узел дерева для вставки
    TreeIterator<wishNote> iterator(&wishes);
    Alhoritm<wishNote>::ReadFromFile(*iterator.Begin() , *iterator.End(), &wishes, "D:\\My shit)\\coursachTry\\wishes.txt" , stack);

    QTextCharFormat format;
    QBrush brush;
    QColor color;
    int r=139,g=0,b=255,a=155;
    color.setRgb(r,g,b,a);;
    brush.setColor(color);
    format.setBackground(brush);
    ui->calendar->setDateTextFormat(ui->calendar->selectedDate(),format);
    ui->lineEdit->clear();
    ui->textEdit->clear();

    iterator = *iterator.Begin();

    if(*(*(iterator.Begin())) == *(*(iterator.End()))){
        QString way = QString::fromUtf8((*iterator)->value.getWish());
        QString wish = QString::fromUtf8((*iterator)->value.getWay());
        ui->listWidget->addItem(way + "\n" + wish);
    }
    else{
        for(iterator = *iterator.Begin(); iterator != *iterator.End(); iterator++){
            QString way = QString::fromUtf8((*iterator)->value.getWish());
            QString wish = QString::fromUtf8((*iterator)->value.getWay());
            ui->listWidget->addItem(way + "\n" + wish);
        }
        QString way = QString::fromUtf8((*iterator)->value.getWish());
        QString wish = QString::fromUtf8((*iterator)->value.getWay());
        ui->listWidget->addItem(way + "\n" + wish);
    }
}


void nextWindowSixth::on_pushButton_5_clicked()        // найти желание
{
    TreeIterator<wishNote> iterator(&wishes);
    iterator = *iterator.Begin();
    if(*(*(iterator.Begin())) == nullptr){
        QMessageBox* msg = new QMessageBox();
        msg->setWindowTitle("Предупреждение");
        msg->setText("У вас не имеется желаний");
        msg->exec();
        ui->lineEdit->clear();
        ui->textEdit->clear();
        return;
    }

    if(*(*(iterator.Begin())) == *(*(iterator.End()))){
        if(ui->lineEdit_3->text() == QString::fromUtf8((*iterator)->value.getWish())){
            QString way = QString::fromUtf8((*iterator)->value.getWish());
            QString wish = QString::fromUtf8((*iterator)->value.getWay());
            ui->listWidget_2->addItem(way + "\n" + wish);
            return;
        }
        QMessageBox* msg = new QMessageBox();
        msg->setWindowTitle("Предупреждение");
        msg->setText("Ничего не найдено");
        msg->exec();
        return;
    }
    else{
        for(iterator = *iterator.Begin(); iterator != *iterator.End(); iterator++){
            if(ui->lineEdit_3->text() == QString::fromUtf8((*iterator)->value.getWish())){
                QString way = QString::fromUtf8((*iterator)->value.getWish());
                QString wish = QString::fromUtf8((*iterator)->value.getWay());
                ui->listWidget_2->addItem(way + "\n" + wish);
                return;
            }
        }
        if(ui->lineEdit_3->text() == QString::fromUtf8((*iterator)->value.getWish())){
            QString way = QString::fromUtf8((*iterator)->value.getWish());
            QString wish = QString::fromUtf8((*iterator)->value.getWay());
            ui->listWidget_2->addItem(way + "\n" + wish);
            return;
        }
        QMessageBox* msg = new QMessageBox();
        msg->setWindowTitle("Предупреждение");
        msg->setText("Ничего не найдено");
        msg->exec();
        return;
    }
}


void nextWindowSixth::on_pushButton_6_clicked()        // найти путь достижения
{
    TreeIterator<wishNote> iterator(&wishes);
    iterator = *iterator.Begin();
    if(*(*(iterator.Begin())) == nullptr){
        QMessageBox* msg = new QMessageBox();
        msg->setWindowTitle("Предупреждение");
        msg->setText("У вас не имеется желаний");
        msg->exec();
        ui->lineEdit->clear();
        ui->textEdit->clear();
        return;
    }
    iterator = *iterator.Begin();

    if(*(*(iterator.Begin())) == *(*(iterator.End()))){
        if(ui->lineEdit_3->text() == QString::fromUtf8((*iterator)->value.getWay())){
            QString way = QString::fromUtf8((*iterator)->value.getWish());
            QString wish = QString::fromUtf8((*iterator)->value.getWay());
            ui->listWidget_2->addItem(way + "\n" + wish);
            return;
        }
        QMessageBox* msg = new QMessageBox();
        msg->setWindowTitle("Предупреждение");
        msg->setText("Ничего не найдено");
        msg->exec();
        return;
    }
    else{
        for(iterator = *iterator.Begin(); iterator != *iterator.End(); iterator++){
            if(ui->lineEdit_3->text() == QString::fromUtf8((*iterator)->value.getWay())){
                QString way = QString::fromUtf8((*iterator)->value.getWish());
                QString wish = QString::fromUtf8((*iterator)->value.getWay());
                ui->listWidget_2->addItem(way + "\n" + wish);
                return;
            }
        }
        if(ui->lineEdit_3->text() == QString::fromUtf8((*iterator)->value.getWay())){
            QString way = QString::fromUtf8((*iterator)->value.getWish());
            QString wish = QString::fromUtf8((*iterator)->value.getWay());
            ui->listWidget_2->addItem(way + "\n" + wish);
            return;
        }
        QMessageBox* msg = new QMessageBox();
        msg->setWindowTitle("Предупреждение");
        msg->setText("Ничего не найдено");
        msg->exec();
        return;
    }
}

