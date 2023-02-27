#pragma once
#include "paragraph.h"

class wishNote : public paragraph{
private:
    string wish; // заголовок
    string way;  // путь достижения
    string date; // дата
public:
    // геттеры и сеттеры
    string getWish();
    void setWish(string wish);
    string getWay();
    void setWay(string way);
    string getDate();
    void setDate(string date);
    //------------------
    int GetSearchMode();  //получение поля для сравнения
    void SetSearchParametres(wishNote& obj1, wishNote& obj2, int Mode); // инициализация поля для сравнения
    bool Compare(wishNote& obj, int Mode); // сравнение по полю
    bool IsBetween(wishNote& obj1, wishNote& obj2, int Mode); // сравнение по полю
    int GetMode();          //получение поля для сравнения
    bool IsDefault();		//является ли объект неинициализированным
    wishNote() = default;
    ~wishNote() = default;
    wishNote(string w, string wa, string d);

    void operator=(wishNote& object);

    friend ifstream& operator>>(ifstream& in, wishNote& object);
    friend ofstream& operator<<(ofstream& out, wishNote& object);
};
