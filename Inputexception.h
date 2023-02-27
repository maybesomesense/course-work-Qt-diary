#pragma once
#include "Exception.h"

class InputException : Exception {				//ошибка ввода
public:
    //констрктор с параметрами
    InputException(int Code, const char* Message) :
        Exception(Code, Message) {				//конструктор базового класса
    }
    //оператор вывода
    friend ostream& operator<<(ostream& out, InputException& exc) {
        out << dynamic_cast<Exception&>(exc);	//оператор базового класса
        return out;
    }
};

