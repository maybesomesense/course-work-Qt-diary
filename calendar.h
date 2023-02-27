#pragma once
#include "paragraph.h"

class calendar : public paragraph{
protected:
    unsigned short year;
    unsigned short month;
    unsigned short day;
public:
    // геттеры и сеттеры
    unsigned short getYear() const;
    void setYear(unsigned short value);

    unsigned short getMonth() const;
    void setMonth(unsigned short value);

    unsigned short getDay() const;
    void setDay(unsigned short value);
    // -----------------

    string getDayWeek() const;
    void showDate() const;

    int dateCheck();       // проверка даты

    void showCalendarThisYear(int year);

    calendar();
    calendar(unsigned short day, unsigned short month, unsigned short year);

};
