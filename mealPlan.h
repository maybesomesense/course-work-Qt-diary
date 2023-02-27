#include "table.h"
#include <map>
using namespace std;
class mealPlan: public table{
protected:
    multimap<pair<string, string>, string> foods;
    string meal;
    string day;
public:
    // геттеры и сеттеры

    string getMeal() const;
    void setMeal(string meal);
    string getDay() const;
    void setDay(string day);

    void operator=(mealPlan& object);

    friend istream& operator>>(istream& in, mealPlan& object);
    friend ostream& operator<<(ostream& out, mealPlan& object);

    void showFood(); // вывести еду на экран

    //

    virtual void edit() {                        //редактирование
        std::cout << "Enter 1 to edit";
        int choice;
        std::cin >> choice;
        if (choice != 1) { return; }                   //отказ редактирования
        while (true) {
            std::cout << "1 - change meal" << std::endl
                      << "2 - change day" << std::endl
                      << "0 - end edit" << std::endl;
            std::cin >> choice;
            if(choice == 0){break;}
            switch (choice) {                                //выбор действия

                case 1:                                      //изменить название
                    std::cout << "New meal: ";
                                                 //строка для ввода
                    cin >> meal;
                    break;
                case 2:                                        //изменить дату
                    std::cout << "New day: ";
                                                 //строка для ввода
                    cin >> day;
                    break;

            }
        }
    }

};
