#include "wishNote.h"
#include <utility>
#include "TreeIterator.h"

string wishNote::getWish(){
    return wish;
}

void wishNote::setWish(string wish){
    this->wish = wish;
}

string wishNote::getWay(){
    return way;
}

void wishNote::setWay(string way){
    this->way = way;
}

void wishNote::operator=(wishNote& object){
    this->description = object.description;
    this->way = object.way;
    this->wish = object.wish;
}

//сравнение по полю
bool wishNote::Compare(wishNote& obj, int Mode) {
    switch (Mode) {
    case 1:												//сравнение по желанию
        return (wish <= obj.wish);
    case 2:												//сравнение по пути достижения
        return (way <= obj.way);
    }
}

wishNote::wishNote(string w, string wa, string d){
    wish = w;
    way = wa;
    date = d;
}

//является ли объект неинициализированным
//bool wishNote::IsDefault() { return strcmp(Name.str, "") == 0; }

string wishNote::getDate(){
    return date;
}
void wishNote::setDate(string date){
    this->date = date;
}

//сравнение по полю
bool wishNote::IsBetween(wishNote& obj1, wishNote& obj2, int Mode) {
    switch (Mode) {
    case 1:                                                 //сравнение по названию
        return (obj1.wish <= wish && wish <= obj2.wish);
    case 2:                                                 //сравнение по формуле
        return (obj1.way <= way && way <= obj2.way);
    }
}

ifstream& operator>>(ifstream& in, wishNote& object){         // чтение из файла
    in >> object.wish;
    in.get();
    in >> object.way;
    in.get();
    return in;
}

ofstream& operator<<(ofstream& out, wishNote& object){        // запись в файл
    out << object.wish << '\t' << object.way << '\n';
    return out;
}

bool wishNote::IsDefault(){   //является ли объект неинициализированным
    return wish == "";
}

//получение поля для сравнения
int wishNote::GetSearchMode() {
    cout << "1 - Название\n2 - Формула\n3 - Масса\n"
        << "4 - Количество\n5 - растворимость\n6 - Температура плавленя\n";
    while (true) {
        rewind(stdin);										//очистка буфера
        char choice = _getch();								//выбор поля
        //проверка на некорректный ввод
        if (48 <= choice && choice <= 54) return (int)(choice - 48);
        else cout << "\nНекорректный ввод\n";
    }
}
