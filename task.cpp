#include "task.h"

QList<QString> task::getTasks(){
    return tasks;
}

void task::appendTask(QString task){
    tasks.append(task);
}

QList<QString> task::getEndedTasks(){
    return endedTasks;
}

bool task::containTask(QString task){
    return tasks.contains(task);
}

bool task::containEndedTask(QString task){
    return endedTasks.contains(task);
}

void task::sortTasks(){
    tasks.sort();
}

void task::sortEndedTasks(){
    endedTasks.sort();
}

void task::appendEndedTasks(QString task){
    endedTasks.append(task);
}

void task::clearAllTasks(){
    tasks.clear();
    endedTasks.clear();
}


ifstream& operator>>(ifstream& in, task& object){
    char temp[40];
    int firstCount, secondCount;
    in >> firstCount;       // считывание количества задач
    in.get();
    in >> secondCount;      // считывание количества выполненных задач
    in.get();
    in.getline(temp, 120, '\n');
    int count = max(firstCount, secondCount);
    for(int i = 0; i != count; i++){
        char first[40];
        char second[40];
        in.getline(first, 40, '\t');
        in.getline(second, 40, '\n');
        QString* firstString = new QString(first);
        QString* secondString = new QString(second);

        object.tasks.append(*firstString);
        object.endedTasks.append(*secondString);
    }
    return in;
}

ofstream& operator<<(ofstream& out, task& object){

    QList<QString> trueTasks = object.tasks;
    QString temp;
    foreach(temp, object.tasks){
        if(object.endedTasks.contains(temp)){   // если находим - удаляем
            trueTasks.removeOne(temp);
            continue;
        }
        else{   // не находим - переходим на следующую итерацию
            continue;
        }
    }

    QList<QString>::iterator iterTasks;
    QList<QString>::iterator iterEndedTasks = object.endedTasks.begin();
    out << trueTasks.count() << '\t' << object.endedTasks.count() << endl;
    out << "Задачи" << "\t" << "Выполненные задачи" << endl;


//     исключить из задач выполненные задачи
    iterTasks = trueTasks.begin();

    do{
        if(iterTasks == trueTasks.end()){
            out << " " << '\t' << iterEndedTasks->toStdString() << endl;
            iterEndedTasks++;
            continue;
        }
        else if(iterEndedTasks == object.endedTasks.end()){
            out << iterTasks->toStdString() << '\t' << " " << endl;
            iterTasks++;
            continue;
        }
        if(iterTasks == trueTasks.end() && iterEndedTasks == object.endedTasks.end()) break;
        out << iterTasks->toStdString() << '\t' << iterEndedTasks->toStdString() << endl;
        iterTasks++, iterEndedTasks++;
    }while(iterTasks != trueTasks.end() && iterEndedTasks != object.endedTasks.end());
    return out;
}

task::~task(){
    clearAllTasks();
}
