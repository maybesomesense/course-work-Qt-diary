#pragma once
#include "calendar.h"
#include <map>

using namespace std;
class holidayCalendar : public calendar{
private:
    multimap<string, string> dayOfBirthday;
    string birthdayName;
    string birthdayDate;
public:
    // геттеры и сеттеры
    string getBirthdayName() const;
    void setBirthdayName(string birthdayName);
    string getBirthdayDate() const;
    void setBirthdayDate(string birthdayDate);
    // -----------------

    void operator=(holidayCalendar& object);

    friend istream& operator>>(istream& in, holidayCalendar& object);
    friend ostream& operator<<(ostream& out, holidayCalendar& object);

    //

    virtual void edit() {                        //редактирование
        std::cout << "Enter 1 to edit";
        int choice;
        std::cin >> choice;
        if (choice != 1) { return; }                   //отказ редактирования
        while (true) {
            std::cout << "1 - change birthday months" << std::endl
                      << "2 - change birthday date" << std::endl
                      << "0 - end edit" << std::endl;
            std::cin >> choice;
            if(choice == 0){break;}
            switch (choice) {                                //выбор действия
                case 1:                                      //изменить название
                    std::cout << "New months: ";
                    cin >> birthdayName;                             //ввод строки
                    break;
                case 2:                                        //изменить дату
                    std::cout << "New date: ";
                    cin >> birthdayDate;                             //ввод строки
                    break;
            }
        }
    }
};
