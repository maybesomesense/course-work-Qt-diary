#ifndef NEXTWINDOWTHIRD_H
#define NEXTWINDOWTHIRD_H

#include <QMainWindow>

#include <QMainWindow>
#include <QCalendarWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsLineItem>

QT_BEGIN_NAMESPACE
namespace Ui { class nextWindowThird; }
QT_END_NAMESPACE

class nextWindowThird : public QMainWindow
{
    Q_OBJECT
signals:
    void thirdWindow();
public:
    nextWindowThird(QWidget *parent = nullptr);
    ~nextWindowThird();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void money_change();

    void on_calendar_selectionChanged();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_15_clicked();

private:
    Ui::nextWindowThird *ui;

    QGraphicsLineItem * lineItem_;
    QGraphicsScene * scene_;
    void initUI();

    QGraphicsView* view;
};
#endif // NEXTWINDOWTHIRD_H
