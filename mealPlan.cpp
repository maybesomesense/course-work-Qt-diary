#include "mealPlan.h"

void mealPlan::showFood() {
    for (auto & food : foods) ///вывод на экран
    {
        cout << food.second << endl;
    }
}


string mealPlan::getMeal() const {return meal;}
void mealPlan::setMeal(string meal) {this->meal = meal;}

string mealPlan::getDay() const {return day;}
void mealPlan::setDay(string day) {this->day = day;}

