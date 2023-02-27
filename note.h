#pragma once
#include "paragraph.h"
#include <QString>
#include <QList>
#include <QMap>
class note :
        public paragraph
{
protected:
    QMap<QString, QStringList> page;    //контейнер заметок
public:
    // геттеры и сеттеры

    QStringList getPage(QString date);
    //------------------
    void appendPage(QString date,QString note);

    void operator=(note& object);
    void clearAllPages();

    note() = default;
    ~note();

    friend istream& operator>>(istream& in, note& object);
    friend ostream& operator<<(ostream& out, note& object);
};

