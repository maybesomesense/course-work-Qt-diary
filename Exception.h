#pragma once
#include "Header.h"

class Exception {											//класс ошибки
protected:
    int Code;												//код ошибки
    char Message[MESSAGE_LEN];								//сообщение
public:
    //конструктор с параметрами
    Exception(int Code, const char* Message = "Exception") {
        strcpy_s(this->Message, MESSAGE_LEN, Message);		//копирование строки
        this->Code = Code;
    }
    //оператор вывода
    friend ostream& operator<<(ostream& out , Exception& exc) {
        out << exc.Message << endl;
        out << "Программа завершилась с кодом  " << exc.Code << endl;
        return out;
    }
};
