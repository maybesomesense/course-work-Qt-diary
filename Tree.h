#pragma once
//#include "Massive.cpp"
#include "FileStream.h"

template<typename T> class Massive;

template<typename T>class Tree {								//дерево
private:
    Node<T>* root;												//корень дерева
    int leaf_count;												//количество узлов
    int InsertionMode;											//параметр построения дерева

    Node<T>* getSuccessor(Node<T>* deleted);					//поиск наследника для удаления
public:
    Tree() {													//конструктор по умолчанию
        root = NULL;
        leaf_count = 0;
        InsertionMode = 1;
    }
    ~Tree() {													//деструктор
        if (root != nullptr) DeleteTree(root);
        root = nullptr;
    }
    void AddCount();											//увеличение кол-ва узлов в дереве
    void DecCount();											//уменьшение кол-ва узлов в дереве
    Node<T>* GetRoot();											//получение вершины
    void NullRoot();											//зануление корня
    int GetCount();												//получение количества узлов
    int GetInsertionMode();										//получение поля построения дерева
    void SetInsertionMode(int NewMode);							//установка нового параметра построения дерева
    void Insert(Node<T>* newNode);								//вставка узла в дерево
    Massive<T>* Search();										//поиск узлов в дереве
    void Pop(Node<T>* deleted);									//удаление узла из дерева
    void Display();												//вывод дерева
    void Display(Node<T>* current);								//симметричный обход дерева
    void WriteToFile(FileStream& stream);						//запись дерева в файла
    void WriteToFile(Node<T>* current, FileStream& stream);		//запись дерева в файл прямым обходом
    void Reconfiguration(int Mode = -1);						//перестройка дерева по новому полю
    void ToMas(Node<T>* current, Massive<T>* mas);				//перевод дерева в массив
    void AllNull(Node<T>* current);								//разрушение дерева
    void DeleteTree();											//удаление дерева
    void DeleteTree(Node<T>* current);							//удаление дерева
};





template<typename T> class Massive {							//класс массива
private:
    Node<T>** mas;												//массив узлов
    int size;													//размер массива
    int putloc;													//позиция для вставки
public:
    Massive(int size) {											//конструктор с параметром
        this->size = size;
        putloc = 0;
        mas = new Node<T>*[size];
        for (int i = 0; i < size; i++)							//заполнение массива нулями
            mas[i] = nullptr;
    }
    ~Massive() {												//деструктор
        for (int i = 0; i < size; i++)							//заполнение массива нулями
            mas[i] = nullptr;
        delete[] mas;
    }
    Massive<T>* Menu();											//выбор действий с элементами массива
    void Insert(Node<T>* newNode);								//вставка узла в массив
    void Pop(int position);										//удаление узла по позиции
    Node<T>* Pop();												//удаление последнего узла
    void Show();												//вывод массива
    void Filter();												//фильтрация массива по полям узлов
    bool IsEmpty();												//проверка массива на пустоту
    void ToTree(Tree<T>* tree);									//перевод массива в дерево
    void ToTree(Tree<T>* tree, int left, int right);			//перевод массива в дерево
    void Sort(int Mode = 0);									//сортировка массива по полю узла
    void SelectionSort(int Mode);								//сортировка масива через отбор
    void Swap(int i, int j);									//обмен узлов
};
