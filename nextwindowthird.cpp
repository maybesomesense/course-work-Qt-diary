#include "nextwindowthird.h"
#include "./ui_nextwindowthird.h"


#include "financeNote.h"
#include <QStack>
// FINANCE NOTE
financeNote* finances = new financeNote();
QStack<financeNote*> takenActions4;
int x01 = 50;
int y01 = 295;
float prew = 0;

nextWindowThird::nextWindowThird(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::nextWindowThird)
{
    ui->setupUi(this);

    initUI();

    money_change();
}

void nextWindowThird::initUI()
{
    view = new QGraphicsView();
    view->setFixedHeight(590);
    view->setFixedWidth(1031);
// создаём scene
scene_ = new QGraphicsScene();
// создаём view, делаем его центральным виджетом и устанавливаем сцену
view->setScene(scene_);
// создаём объект линии и добавляем его в сцену. 1031 291
QPen pen(Qt::black);
pen.setWidth(3);//это установит нужную толщину
scene_->addLine(50, 50, 50, 320, pen);
scene_->addLine(50, 295, 1030, 295, pen);
for(int i = 0; i < QDate(ui->calendar->selectedDate()).daysInMonth(); i++)
{
    QGraphicsTextItem * io = new QGraphicsTextItem;
    io->setPos(50 + (1030/ QDate(ui->calendar->selectedDate()).daysInMonth() - 1) * i,300);
    io->setPlainText(QString::number(i+1));
    scene_->addItem(io);
    scene_->addLine(50 + (1030/ QDate(ui->calendar->selectedDate()).daysInMonth() - 1) * i, 50, 50 +
                    (1030/ QDate(ui->calendar->selectedDate()).daysInMonth() - 1) * i, 320);
}
}

nextWindowThird::~nextWindowThird()
{
    delete ui;
}


void nextWindowThird::on_pushButton_clicked()
{
    this->close();      // Закрываем окно
    emit thirdWindow(); // И вызываем сигнал на открытие главного окна
}

void nextWindowThird::money_change(){
    for( int i = 1; i <= QDate(ui->calendar->selectedDate()).daysInMonth(); i++)
        if(finances->getMoney(QDate(ui->calendar->selectedDate().year(), ui->calendar->selectedDate().month(), i)) == NULL)
            finances->setMoney(QDate(ui->calendar->selectedDate().year(), ui->calendar->selectedDate().month(), i), 0);
    scene_->clear();
    QPen pen(Qt::black);
    pen.setWidth(3);//это установит нужную толщину
    scene_->addLine(50, 540, 50, 50, pen);
    scene_->addLine(50, 295, 1030, 295, pen);
    for(int i = 0; i < QDate(ui->calendar->selectedDate()).daysInMonth(); i++)
    {
        QGraphicsTextItem * io = new QGraphicsTextItem;
        io->setPos(50 + (1030/ QDate(ui->calendar->selectedDate()).daysInMonth() - 1) * i,300);
        io->setPlainText(QString::number(i+1));
        scene_->addItem(io);
        scene_->addLine(50 + (1030/ QDate(ui->calendar->selectedDate()).daysInMonth() - 1) * i, 50, 50 +
                        (1030/ QDate(ui->calendar->selectedDate()).daysInMonth() - 1) * i, 540);
    }
    QDate temp1;
    float max = 1;
    foreach (temp1, finances->getKeysMoney()) {
        if(temp1.month() == ui->calendar->selectedDate().month() && std::abs(finances->getMoney(temp1)) > max){
            max = std::abs(finances->getMoney(temp1));
        }
    }
    for(int i = 0; i < 11; i++)
    {
        QGraphicsTextItem * io = new QGraphicsTextItem;
        io->setPos(10, 280 - i * 24);
        io->setPlainText(QString::number(i * max / 10));
        scene_->addItem(io);
        scene_->addLine(50, 295 - i * 24, 1030, 295 - i * 24);
    }
    for(int i = 0; i < 11; i++)
    {
        QGraphicsTextItem * io = new QGraphicsTextItem;
        io->setPos(10, 280 + i * 24);
        io->setPlainText(QString::number(-i * max / 10));
        scene_->addItem(io);
        scene_->addLine(50, 295 + i * 24, 1030, 295 + i * 24);
    }
    foreach (temp1, finances->getKeysMoney()) {
        QPen pen1(Qt::yellow);
        pen1.setWidth(4);
        if(temp1.month() == ui->calendar->selectedDate().month()){
            if(finances->getMoney(temp1) < 0 || prew < 0 && finances->getMoney(temp1) == 0 || prew == 0 && finances->getMoney(temp1) < 0)
                pen1.setColor(Qt::red);
            if(finances->getMoney(temp1) > 0 || prew > 0 && finances->getMoney(temp1) == 0 || prew == 0 && finances->getMoney(temp1) > 0)
                pen1.setColor(Qt::green);
            if(prew > 0 && finances->getMoney(temp1) < 0){
                pen1.setColor(Qt::green);
                scene_->addLine(x01,
                                y01,
                                x01 + 25 + ((1030/ QDate(ui->calendar->selectedDate()).daysInMonth() - 1) * (temp1.day() - 1) - x01)/2,
                                295,
                                pen1);
                pen1.setColor(Qt::red);
                scene_->addLine(x01 + 25 + ((1030/ QDate(ui->calendar->selectedDate()).daysInMonth() - 1) * (temp1.day() - 1) - x01)/2,
                                295,
                                50 + (1030/ QDate(ui->calendar->selectedDate()).daysInMonth() - 1) * (temp1.day() - 1),
                                295 - (finances->getMoney(temp1) * 245 / max),
                                pen1);
            } else
            if(prew < 0 && finances->getMoney(temp1) > 0){
                pen1.setColor(Qt::red);
                scene_->addLine(x01,
                                y01,
                                x01 + 25 + ((1030/ QDate(ui->calendar->selectedDate()).daysInMonth() - 1) * (temp1.day() - 1) - x01)/2,
                                295,
                                pen1);
                pen1.setColor(Qt::green);
                scene_->addLine(x01 + 25 + ((1030/ QDate(ui->calendar->selectedDate()).daysInMonth() - 1) * (temp1.day() - 1) - x01)/2,
                                295,
                                50 + (1030/ QDate(ui->calendar->selectedDate()).daysInMonth() - 1) * (temp1.day() - 1),
                                295 - (finances->getMoney(temp1) * 245 / max),
                                pen1);
            } else
            scene_->addLine(x01,
                            y01,
                            50 + (1030/ QDate(ui->calendar->selectedDate()).daysInMonth() - 1) * (temp1.day() - 1),
                            295 - (finances->getMoney(temp1) * 245 / max),
                            pen1);
            x01 = 50 + (1030/ QDate(ui->calendar->selectedDate()).daysInMonth() - 1) * (temp1.day() - 1);
            y01 = 295 - (finances->getMoney(temp1) * 245 / max);
            prew = finances->getMoney(temp1);
        }
    }
    x01 = 50;
    y01 = 295;
    prew = 0;
}


void nextWindowThird::on_pushButton_3_clicked()
{
    takenActions4.push(finances);
    finances->addMoney(ui->calendar->selectedDate(), ui->doubleSpinBox->value());
    //money[ui->calendar->selectedDate()] += ui->doubleSpinBox->value();
    ui->doubleSpinBox->clear();
    money_change();
}


void nextWindowThird::on_pushButton_5_clicked()
{
    takenActions4.push(finances);
    finances->reduceMoney(ui->calendar->selectedDate(), ui->doubleSpinBox_2->value());
    ui->doubleSpinBox_2->clear();
    money_change();
}


//изменение даты календаря
void nextWindowThird::on_calendar_selectionChanged()
{
        ui->listWidget->clear();
    ui->label->setText(ui->calendar->selectedDate().toString());
    QString temp;

    foreach(temp, finances->getPage(ui->calendar->selectedDate().toString()))
    ui->listWidget->addItem(temp);
    money_change();
}


void nextWindowThird::on_pushButton_2_clicked()
{
    ui->listWidget->clear();

    finances->appendPage(ui->calendar->selectedDate().toString(), QString::number(finances->getPage(ui->calendar->selectedDate().toString()).count() + 1) +
            ". " + ui->lineEdit->text() + "\n" + ui->textEdit->toPlainText() + "\n");

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
    QString temp;

    foreach(temp, finances->getPage(ui->calendar->selectedDate().toString()))
        ui->listWidget->addItem(temp);
}


void nextWindowThird::on_pushButton_4_clicked()
{
    view->show();
}


void nextWindowThird::on_pushButton_13_clicked()            // Запись в файл
{
    ifstream in;
    finances->clearAllPages();
    in.open("D:\\My shit)\\coursachTry\\finances.txt");
    in >> *finances;
    in.close();
}


void nextWindowThird::on_pushButton_14_clicked()            // Чтение из файла
{
    ofstream out;          // поток для записи
    out.open("D:\\My shit)\\coursachTry\\finances.txt"); // окрываем файл для записи
    out << *finances;
    out.close();
}


void nextWindowThird::on_pushButton_15_clicked()            // Установка названия
{
    if(ui->lineEdit_3->text().isEmpty()){
        QMessageBox* msg = new QMessageBox();
        msg->setWindowTitle("Предупреждение");
        msg->setText("Вы ничего не ввели");
        msg->exec();
        return;
    }
    finances->setDescription(ui->lineEdit_3->text().toStdString());
    ui->label_6->setText(ui->lineEdit_3->text());
}

