#pragma once
#include "FileException.h"

class FileNotOpenException : public FileException {		//ошибка неоткрытого файла
public:
    //конструктор с параметрами
    FileNotOpenException(const char* FileName ,int Code = 3,
        const char* Message = "FileNotOpenException") :
        FileException(Code, Message, FileName) {		//конструктор базового класса
    }
    //оператор вывода
    friend ostream& operator<<(ostream& out, FileNotOpenException& exc) {
        out << "Невозможно открыть файл " << exc.FileName << endl;
        out << dynamic_cast<FileException&>(exc);		//оператор базового класса
        return out;
    }
};
