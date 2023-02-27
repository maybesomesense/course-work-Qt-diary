#ifndef NEXTWINDOWFOURTH_H
#define NEXTWINDOWFOURTH_H

#include <QMainWindow>

#include <QMainWindow>
#include <QCalendarWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsLineItem>

QT_BEGIN_NAMESPACE
namespace Ui { class nextWindowFourth; }
QT_END_NAMESPACE

class nextWindowFourth : public QMainWindow
{
    Q_OBJECT
signals:
    void fourthWindow();
public:
    nextWindowFourth(QWidget *parent = nullptr);
    ~nextWindowFourth();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_8_clicked();

    void on_calendar_selectionChanged();

private:
    Ui::nextWindowFourth *ui;
    QGraphicsLineItem * lineItem_;
    QGraphicsScene * scene_;
    void initUI();
};
#endif // NEXTWINDOWFOURTH_H
