#pragma once
#include "InputException.h"

class FormatException :public InputException {			//ошибка формтаа ввода
public:
    //конструктор с параметрами
    FormatException(int Code = 4, const char* Message = "Некорректный формат ввода"):
        InputException(Code, Message) {					//конструктор базового класса
    }
    //оператор вывода
    friend ostream& operator<<(ostream& out, FormatException& exc) {
        out << dynamic_cast<InputException&>(exc);		//оператор базового класса
        return out;
    }
};
