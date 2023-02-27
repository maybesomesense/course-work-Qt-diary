#pragma once
#include "Stack.cpp"


template<typename T> class TreeIterator {									//итератор дерева
private:
    Tree<T>* tree;															//дерево
    Node<T>* Current;														//текущий узел
    int Index;																//индекс текущего узла
    int InsertionMode;														//параметр вставки в дерево
public:
    TreeIterator(Tree<T>* tree) {											//конструктор с параметром
        this->tree = tree;
        InsertionMode = 1;
    }
    ~TreeIterator() { tree = nullptr; Current = nullptr; }					//деструктор
    int GetInsertionMode();													//получение параметра вставки в дерево
    void AddCount();														//получение количества узлов в дереве
    void operator=(Node<T>* node);											//оператор присваивания
    bool operator==(Node<T>* node);											//оператор сравнения
    bool operator!=(Node<T>* node);											//оператор сравнения
    void operator=(TreeIterator<T>& iter);									//оператор сравнения
    bool operator==(TreeIterator<T>& iter);									//оператор сравнения
    bool operator!=(TreeIterator<T>& iter);									//оператор сравнения
    Node<T>* operator*();													//оператор разатрессации
    void operator++(int);													//инкремент
    void operator--(int);													//декремент
    TreeIterator<T>* Begin();												//установка итератора на начало дерева
    TreeIterator<T>* End();													//установка итератора на конец дерева
    TreeIterator<T>* Last();												//конец дерева
    Node<T>* Step(int& NewIndex);											//переход к узлу с индексом
    void Step(Node<T>* current, Node<T>** successor, int& NewIndex);		//поиск узла с индексом
    friend ostream& operator<<(ostream& out, TreeIterator<T>& iterator);	//оператор вывода
};
