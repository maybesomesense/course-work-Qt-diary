#pragma once
#include "AlhoritmException.h"

class NodeNotFoundException : public AlhoritmException {		//ошибка ненайденного элемента
protected:
    char SearchedValue[MESSAGE_LEN];							//искомое значение
public:
    //конструктор с параметрами
    NodeNotFoundException(const char* SearchedValue, const char* alhoritm ,
        int Code = 6, const char* Message = "NodeNotFoundExcepton"):
        AlhoritmException(alhoritm ,Code, Message) {			//контсруткор базового класса
        strcpy_s(this->SearchedValue, MESSAGE_LEN, SearchedValue);//копирование строки
    }
    //оператор вывода
    friend ostream& operator<<(ostream& out, NodeNotFoundException& exc) {
        out << "Невозможно найти  " << exc.SearchedValue << endl;
        out << dynamic_cast<AlhoritmException&>(exc);			//оператор базового класса
        return out;
    }
};
