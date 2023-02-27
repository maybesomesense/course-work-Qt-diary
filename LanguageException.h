#pragma once
#include "InputException.h"

class LanguageException :public InputException {		//ошибка языка ввода
private:
    int index;											//индекс некоректного символа
    char str[MESSAGE_LEN];								//строка с ошибкой
public:
    //конструктор с параметрами
    LanguageException(char* str, int position, int Code = 5,
        const char* Message = "Language exception"):
        InputException(Code, Message) {					//конструктор базового класса
        strcpy_s(this->str, MESSAGE_LEN, str);			//копирование сроки
        index = position;
    }
    //оператор вывода
    friend ostream& operator<<(ostream& out, LanguageException& exc) {
        out << "Ошибка языка ввода в строке \"" << exc.str
            << "\"(позиция " << exc.index << ")" << endl;
        out << dynamic_cast<InputException&>(exc);		//оператор базового класса
        return out;
    }
};
