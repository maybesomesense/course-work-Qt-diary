#pragma once
#include "Tree.cpp"
#include "Massive.cpp"

template<typename T> struct StackElement {		//элемент стека
    Node<T>* node;								//сораненный узел
    char Operation;								//операция
    Tree<T>* tree;								//сохраненное дерево
    int InsertionMode;							//параметр построения дерева
    StackElement<T>* Next;						//следующий элемент
    StackElement(Node<T>* n, char o) {			//конструктор с параметрами
        node = n;								//адрес узла
        //если узел был удален - зануление указателей на его наследников
        if(o != 'i') node->left = node->right = nullptr;
        Operation = o;							//операция с узлом
        tree = nullptr;							//дерево не передано
        Next = nullptr;
    }
    StackElement(Tree<T>* t, int Mode) {		//конструктор с параметрами
        t = tree;								//адрес дерева
        InsertionMode = Mode;					//параметр построения дерева
        node = nullptr;							//узел не передан
        Next = nullptr;
    }
    ~StackElement() {							//деструктор
        tree = nullptr;
        node = nullptr;
    }
};


template<typename T> class Stack {				//стек
private:
    StackElement<T>* Top;						//вершина чтека
public:
    Stack() {									//конструктор
        Top = nullptr;
    }
    ~Stack() {									//деструктор
        if (Top != nullptr) {
            DeleteStack(Top);					//удаление стека
            Top = nullptr;
        }
    }
    bool IsEmpty();								//является ли стек пустым
    void Push(StackElement<T>* NewElement);		//занесение в стек
    StackElement<T>* Pop();						//удаление из стека
    void DeleteStack(StackElement<T>* current);	//удаление стека
};
