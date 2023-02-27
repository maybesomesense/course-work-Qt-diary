#pragma once
#include "AlhoritmException.h"

class ArrayBoundsException : public AlhoritmException {		//класс ошибки выхода за границы массива
private:
    int index;												//индекс элемента за границей массива
public:
    //контруктор с параметрами
    ArrayBoundsException(int index , const char* alhoritm, int Code = 1, const char* Message = "Exception") :
        AlhoritmException(alhoritm ,Code, Message) {		//конструктор базового класса
    }
    //оператор вывода
    friend ostream& operator<<(ostream& out,ArrayBoundsException& exc) {
        out << "Не существует "<< exc.index << "-го элемента в контейнере" << endl;
        out << dynamic_cast<AlhoritmException&>(exc);		//оператор базового класса
        return out;
    }
};
