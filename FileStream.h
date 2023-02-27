#pragma once
#include "Node.cpp"


class FileStream {									//класс файлового потока
public:
    char CurrentFile[MAX_LEN_OF_STRING];			//название файла
    ifstream infile;								//поток считывания из файла
    ofstream outfile;								//поток записив файл
    //конструктор по умолчанию
    FileStream() = default;
    //деструктор
    ~FileStream() {
        if (infile.is_open()) infile.close();		//закрытие открытого фйла
        if (outfile.is_open()) outfile.close();		//закрытие открытого файла
    }
    //достигнут ли конец файла
    bool EndOfStream() {
        if (infile.is_open()) return infile.eof();	//если конец достигнут
        //исключение неверного режима файла
    }
    //открытие файла
    void Open(const char* file, int Mode) {
        strcpy_s(CurrentFile, MAX_LEN_OF_STRING, file);	//копирование имени файла
        if (infile.is_open()) infile.close();		//закрытие открытого файла
        if (outfile.is_open()) outfile.close();		//закрытие открытого файла
        if (Mode == 1) {							//открытие файла для считывания
            infile.open(file);
            if (!infile) {
                infile.close();
                throw new FileNotExistException(file);
            }
        }
        else outfile.open(file);					//открытие файла для записи
    }
    //открыт ли файл
    int IsOpen() {
        if (infile.is_open()) return 1;				//файл открыт для считывания
        else if (outfile.is_open()) return 2;		//файл открыт для записи
        else return 0;								//файл закрыт
    }
    //закрытие файла
    void Close() {
        if (infile.is_open()) infile.close();		//закрытие потока считывания
        if (outfile.is_open()) outfile.close();		//закрытие потока записи
    }

    template<typename Type>
    friend FileStream& operator>>(FileStream& stream, Type& val) {
        stream.infile >> val;
        return stream;
    }
    template<typename Type>
    friend FileStream& operator<<(FileStream& stream, Type& val) {
        stream.outfile << val;
        return stream;
    }
};
