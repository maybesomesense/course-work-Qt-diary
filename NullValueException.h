#pragma once
#include "AlhoritmException.h"

class NullValueException : public AlhoritmException {		//ошибка обращения к NULL указателю
private:
    char NullValue[MESSAGE_LEN];							//имя NULL указателя
public:
    //конструктор с параметрами
    NullValueException(const char* NullValue, const char* alhoritm,
        int Code = 7, const char* Message = "NullValueExcepton") :
        AlhoritmException(alhoritm ,Code, Message) {		//конструктор базового класса
        strcpy_s(this->NullValue, MESSAGE_LEN, NullValue);	//копирование строки
    }
    //оператор вывода
    friend ostream& operator<<(ostream& out, NullValueException& exc) {
        out << exc.NullValue << " имел значение NULL" << endl;
        out << dynamic_cast<AlhoritmException&>(exc);		//оператор базового класса
        return out;
    }
};
