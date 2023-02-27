#include "phoneBook.h"

void phoneBook::addPhone(QString key, QString value){
    phone[key] = value;
}

QList<QString> phoneBook::getPhoneKeys(){
    return phone.keys();
}

QString phoneBook::getPhone(QString key){
    return phone[key];
}

QMap<QString, QString> phoneBook::getMap(){
    return phone;
}

bool phoneBook::phoneContain(QString key){
    return phone.contains(key);
}

void phoneBook::addToOtherPhoneBook1(phoneBook& object, QString key){

    return;
}

ofstream& operator<<(ofstream& out, phoneBook& object)   // запись в файл
{
    QMap<QString,QString>::iterator iter;
    out << object.phone.count() << endl;
    out << "ФИО" << "\t" << "Телефон" << endl;
    int i = 0;
    for (iter = object.phone.begin(); iter != object.phone.end(); iter++, i++){
        out << iter.key().toStdString() << "\t" << iter.value().toStdString() << endl;
    }
    return out;
}

ifstream& operator>>(ifstream& in, phoneBook& object){
    char temp[40];
    //int buffer;
    int count;
    in >> count;
    in.get();
    in.getline(temp, 120, '\n');

    for(int i = 0; i != count; i++){
        char first[40];
        char second[40];
        in.getline(first, 40, '\t');
        in.getline(second, 40, '\n');
        QString* key = new QString(first);
        QString* value = new QString(second);

        object.phone.insert(*key, *value);
    }
    return in;
}

void phoneBook::clearPhones(){
    phone.clear();
}
