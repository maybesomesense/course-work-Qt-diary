#pragma once
#include "paragraph.h"
#include <map>
#include "QMap"


using namespace std;
class phoneBook: public paragraph{
private:
    QMap<QString, QString> phone;
public:
    //геттеры и сеттеры

    void addPhone(QString key, QString value);
    QString getPhone(QString key);
    //-----------------
    bool phoneContain(QString key);
    QMap<QString, QString> getMap();
    QList<QString> getPhoneKeys();
    void clearPhones();
    void addToOtherPhoneBook1(phoneBook& object, QString key);


    phoneBook() = default;

    void operator=(phoneBook& object);

    friend ofstream& operator<<(ofstream& out, phoneBook& object);
    friend ifstream& operator>>(ifstream& in, phoneBook& object);
};
