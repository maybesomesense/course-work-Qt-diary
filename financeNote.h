#include "note.h"
#include <QMessageBox>
#include <QCalendarWidget>
#include <QPainter>
#include <QGraphicsWidget>

class financeNote: public note{
private:
    //контейнер трат
    QMap<QDate, float> money;
public:
    // геттеры и сеттеры
    float getMoney(QDate date);
    void setMoney(QDate date, float number);
    // -----------------

    QList<QDate> getKeysMoney();
    void addMoney(QDate date, float number);
    void reduceMoney(QDate date, float number);
    void clearFinances();

    financeNote() = default;
    ~financeNote();

    friend istream& operator>>(istream& in, financeNote& object);
    friend ostream& operator<<(ostream& out, financeNote& object);

};
