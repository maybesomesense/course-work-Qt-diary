#pragma once
#include "FileException.h"

class FileIncorrectModeException : public FileException {	//ошибка некорректного режима файла
private:
    int FileMode;											//режим файла
public:
    //конструктор с параметрами
    FileIncorrectModeException(int FileMode, const char* FileName ,
        int Code = 2,const char* Message = "FileIncorrectModeException") :
        FileException(Code, Message, FileName) {			//конструктор базового класса
        this->FileMode = FileMode;
    }
    //оператор вывода
    friend ostream& operator<<(ostream& out, FileIncorrectModeException& exc) {
        out << "Некорректный доступ к файлу " << exc.FileMode << endl;
        out << dynamic_cast<FileException&>(exc);			//оператор базового класса
        return out;
    }
};
