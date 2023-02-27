#include "calendar.h"
#include "dayAndMonthTab.h"

calendar::calendar() : year(2000), month(1), day(1) {
    //The empty body of the default constructor
}

calendar::calendar(unsigned short day, unsigned short month, unsigned short year)
        : day(day), month(month), year(year) {
}

unsigned short calendar::getYear() const {

    return year;
}

unsigned short calendar::getMonth() const {

    return month;

}

unsigned short calendar::getDay() const {

    return day;

}

void calendar::setYear(unsigned short value) {

    year = value;

}

void calendar::setMonth(unsigned short value) {

    month = value;

}

void calendar::setDay(unsigned short value) {

    day = value;

}

string calendar::getDayWeek() const {

    string dayOfWeek[7] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
    short countDayOfWeek[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    int a = (14 - month) / 12;
    int y = year - a;
    int m = month + 12 * a - 2;

    return dayOfWeek[(day + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12) % 7];

}

void calendar::showDate() const {
    cout
            << day
            << "."
            << month
            << "."
            << year;
}

void calendar::showCalendarThisYear(int year){
    int i, leap;
    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;     // проверка на високосный год

    for(i = 1; i < 13; i++) {
        cout << months[i] << endl;
        for(int j = 1; j < daytab[leap][i] + 1; j++){
            cout << setw(3) << j << " ";
            if(j % 7 == 0) cout << endl;
        }
        cout << endl;
    }
}


int calendar::dateCheck()
{
    int i, leap;
    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    if(month < 1 || month > 12)
        return -1;
    if(day < 1 || day > daytab[leap][month])
        return -1;
    for(i = 1; i < month; i++)
        day += daytab[leap][i];
    return day;
}
