#include "financeNote.h"
//#include "dayAndMonthTab.h"


void financeNote::setMoney(QDate date, float number){
    money[date] = number;
}

float financeNote::getMoney(QDate date){
    return money[date];
}

QList<QDate> financeNote::getKeysMoney(){
    return money.keys();
}

void financeNote::addMoney(QDate date, float number){
    money[date] += number;
}

void financeNote::reduceMoney(QDate date, float number){
    money[date] -= number;
}

void financeNote::clearFinances(){
    clearAllPages();
    money.clear();
}

financeNote::~financeNote(){
    clearAllPages();
    money.clear();
}

istream& operator>>(istream& in, financeNote& object){

    return in;
}

ostream& operator<<(ostream& out, financeNote& object){
    QMap<QDate, float>::iterator iter1;
    QMap<QString, QStringList>::iterator iter2;
    out << object.page.count() << endl;
    out << "Заголовок заметки" << "\t" << "Заметка" << "\t" << "Прибыль" << "\t" << "Траты" << "\t"  << "Дата заметки" << "Даты траты и прибыли" << endl;
    int i = 0;
    QStringList::iterator iterQList;


//    for (iter1 = object.money.begin(), iter2 = object.page.begin(); iter1 != object.money.end() && iter2 != object.page.end() ; iter1++, iter2++){
//        int mode;
//        if(iter1{

//        }
//        if(){mode = 1;}
//        if(){mode = 2;}

//        for(){

//        }
//        for(){

//        }
//        for(iterQList = iter1.value().begin(); iterQList != iter1.value().end(); iterQList++){
//            iterQList->replace(QString('\n'), QString('\t'));
//            out << iterQList->toStdString();
//            out << iter1.key().toString().toStdString() << endl;
//        }
//    }

//    for (iter2 = object.finances.begin(); iter2 != object.page.end(); iter2++){
//        for(iterQList = iter.value().begin(); iterQList != iter.value().end(); iterQList++){
//            iterQList->replace(QString('\n'), QString('\t'));
//            out << iterQList->toStdString();
//            out << iter.key().toStdString() << endl;
//        }
//    }
    return out;
}
