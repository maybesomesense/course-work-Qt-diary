#pragma once
#include "LanguageException.h"
#include "FormatException.h"
#include "ArrayBoundsException.h"
#include "NodeNotFoundException.h"
#include "NullValueException.h"
#include "FileIncorrectModeException.h"
#include "FileNotOpenException.h"
#include "FileNotExistException.h"

class ExceptionInterface {									//функции  для исключений
public:
    char* input_str(char Mode) {					//проверка на язык ввода
        char* str = new char[MAX_LEN_OF_STRING];
        while (true) {
            rewind(stdin);
            cin.getline(str, MAX_LEN_OF_STRING);							//ввод строки
            rewind(stdin);
            try {
                if (Mode == 'r')
                    str_check_language_russian(str);		//проверка на язык ввода
                else str_check_language_english(str);
                return str;
            }
            catch (LanguageException* exc) {				//обработка исключения языка ввода
                system("cls");
                cout << *exc;								//вывод информации об исключении
                cout << endl << "Введите снова:";
            }
        }
    }
    void str_check_language_english(char* str) {			//проверка языка ввода
        int i = 0;
        while (i < LEN && str[i] != '\0') {					//цикл проверки символов строки
            if (!((str[i] >= 'A' && str[i] <= 'Z') ||
                (str[i] >= 'a' && str[i] <= 'z') || (str[i] >= '0' && str[i] <= '9')))
                throw new LanguageException(str, i, 2, "Ошибка языка ввода");
            i++;
        }
    }
    void str_check_language_russian(char* str) {			//проверка языка ввода
        int i = 0;
        while (i < LEN && str[i] != '\0') {					//цикл проверки символов строки
            if ((str[i] >= 'A' && str[i] <= 'Z') ||
                (str[i] >= 'a' && str[i] <= 'z')) {
                throw new LanguageException(str, i, 2, "Ошибка языка ввода");
            }
            i++;
        }
    }
    //проверка формата ввода
    template<typename Value> void input_checking_format(Value& value, istream& in) {
        while (true) {
            try {
                in >> value;								//ввод
                //проверка на правильность
                if (!in.good()) throw new FormatException(1, "Некорректный формат");
                return;
            }
            catch (FormatException* exc) {					//обработка исключеия
                rewind(stdin);
                in.clear();									//очистка потока
                system("cls");
                cout << *exc;								//вывод информации об исключении
                cout << endl << "Введите снова:";
            }
        }
    }
};
