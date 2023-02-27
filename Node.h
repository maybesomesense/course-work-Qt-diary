#pragma once
#include "wishNote.h"

template<typename T> class Node {									//узел дерева
public:
    T value;														//объект
    Node<T>* left;													//левый сын
    Node<T>* right;													//правый сын
    Node() { left = right = nullptr; }								//конструктор по умолчанию
    Node(T value) {													//конструктор с параметром
        this->value = value;
        left = right = nullptr;
    }
    ~Node() { }														//деструктор
    bool IsDefault();												//является ли объект неинициализированным
    bool Compare(Node<T>* obj, int Mode);							//сравнение по полю
    bool IsBetween(Node<T>* obj1, Node<T>* obj2, int Mode);			//сравнение по полю
    friend ifstream& operator>>(ifstream& in, Node<T>& object);		//оператор считывания из файла
    friend ofstream& operator<<(ofstream& out, Node<T>& object);	//оператор записи в файл
};
