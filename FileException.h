#pragma once
#include "Exception.h"

class FileException : public Exception {		//ошибка файла
protected:
    char FileName[MESSAGE_LEN];					//имя файла
public:
    //конструктор с параметрами
    FileException(int Code, const char* Message = "FileException", const char* FileName = "") :
        Exception(Code, Message) {				//конструктор базового класса
        strcpy_s(this->FileName, MESSAGE_LEN, FileName);
    }
    //оператор вывода
    friend ostream& operator<<(ostream& out , FileException& exc) {
        out << "невозможно использовать файл " << exc.FileName << endl;
        out << dynamic_cast<Exception&>(exc);	//оператор базового класса
        return out;
    }
};
