#pragma once
#include "TreeIterator.cpp"

template<typename T> class Alhoritm {	//класс алгоритма
public:
    //чтение из файла в дерево
    static void ReadFromFile(TreeIterator<T>& start , TreeIterator<T>& finish , Tree<T>* tree, const char* filename, Stack<T>& stack);
    //запись дерева в файл
    static void WriteToFile(Tree<T>* tree, const char* filename);
    //вставка нового узла в дерево
    static void Insert(TreeIterator<T>& start, TreeIterator<T>& finish, Tree<T>* tree, Node<T>* NewNode , Stack<T>& stack);
    //поиск узлов в дереве
    static Massive<T>* Search(TreeIterator<T>& start, TreeIterator<T>& finish, Tree<T>* tree , Stack<T>& stack);
    //сортировка дерева по другому параметру
    static void Sort(TreeIterator<T>& start, TreeIterator<T>& finish, Tree<T>* tree, Stack<T>&stack , int IMode = -1);
    //отмена действия
    static void Cancellation(Tree<T>* tree, Stack<T>& stack);
};
