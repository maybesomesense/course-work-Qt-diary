#include "note.h"


QStringList note::getPage(QString date){
    return page[date];
}

void note::appendPage(QString date,QString note){
    page[date].append(note);
}

istream& operator>>(istream& in, note& object){
//    char temp[40];
//    int firstCount, secondCount;
//    in >> firstCount;       // считывание количества задач
//    in.get();
//    in >> secondCount;      // считывание количества выполненных задач
//    in.get();
//    in.getline(temp, 120, '\n');
//    int count = max(firstCount, secondCount);
//    for(int i = 0; i != count; i++){
//        char first[40];
//        char second[40];
//        in.getline(first, 40, '\t');
//        in.getline(second, 40, '\n');
//        QString* firstString = new QString(first);
//        QString* secondString = new QString(second);

//        object.page.insert(first,second);
//    }
//    return in;
}

ostream& operator<<(ostream& out, note& object){
    QMap<QString, QStringList>::iterator iter;
    out << object.page.count() << endl;
    out << "Заголовок заметки" << "\t" << "Заметка" << "\t" << "Дата заметки" << endl;
    int i = 0;
    QStringList::iterator iterQList;

    for (iter = object.page.begin(); iter != object.page.end(); iter++){
        for(iterQList = iter.value().begin(); iterQList != iter.value().end(); iterQList++){
            iterQList->replace(QString('\n'), QString('\t'));
            out << iterQList->toStdString();
            out << iter.key().toStdString() << endl;
        }
    }


    return out;
}

void note::clearAllPages(){
    page.clear();
}

note::~note(){
    page.clear();
}
