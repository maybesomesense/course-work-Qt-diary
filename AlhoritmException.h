#pragma once
#include "Exception.h"

class AlhoritmException :public Exception {				//класс ошибки алгоритма
private:
    char alhoritm[MESSAGE_LEN];							//название алгоритма
public:
    //конструктор с параметрами
    AlhoritmException(const char* alhoritm, int Code, const char* Message = "Exception") :
        Exception(Code, Message) {						//конструктор базового класса
        strcpy_s(this->alhoritm, MESSAGE_LEN, alhoritm);//копиррование названия алгоритма
    }
    //оператор вывода
    friend ostream& operator<<(ostream& out, AlhoritmException& exc) {
        out << "Невозможно выполнить алгоритм " << exc.alhoritm << endl;
        out << dynamic_cast<Exception&>(exc);			//оператор вывода базового класса
        return out;
    }
};
