#pragma once
#include "paragraph.h"
#include "QList"
class task : public paragraph
{
protected:
    QList<QString> tasks;
    QList<QString> endedTasks;
public:
    // геттеры и сеттеры

    QList<QString> getTasks();
    void appendTask(QString task);

    QList<QString> getEndedTasks();
    void appendEndedTasks(QString task);
    // -----------------
    bool containTask(QString task);
    bool containEndedTask(QString task);
    void clearAllTasks();
    void sortTasks();
    void sortEndedTasks();
    task() = default;
    ~task();
    void operator=(task& object);

    friend ifstream& operator>>(ifstream& in, task& object);
    friend ofstream& operator<<(ofstream& out, task& object);

};
