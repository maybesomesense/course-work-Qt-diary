#include "holidayCalendar.h"

#include <utility>

string holidayCalendar::getBirthdayName() const { return birthdayName;}
void holidayCalendar::setBirthdayName(string birthdayName) {this->birthdayName = std::move(birthdayName);}

string holidayCalendar::getBirthdayDate() const {return birthdayDate;}
void holidayCalendar::setBirthdayDate(string birthdayDate) {this->birthdayDate = std::move(birthdayDate);}

