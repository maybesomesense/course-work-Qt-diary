#include "TreeIterator.h"

template<typename T> int TreeIterator<T>::GetInsertionMode() { return InsertionMode; }	//получение параметра вставки в дерево

template<typename T>void TreeIterator<T>::AddCount() { tree->AddCount(); }				//получение количества узлов в дереве

//template<typename T>void TreeIterator<T>::operator=(Node<T>* node);						//оператор присваивания


//оператор присваивания
template<typename T> void TreeIterator<T>::operator=(Node<T>* node) {
    Current = tree->GetRoot();				//установка итератора на корень дерева
    //проверка на установку в начало дерева
    while (Current->left != nullptr) Current = Current->left;
    if (Current == node) {
        Index = 0;
        return;
    }
    Current = tree->GetRoot();				//установка итератора на корень дерева
    //проверка на установку в конец дерева
    while (Current->right != nullptr) Current = Current->right;
    if (Current == node) {
        Index = tree->GetCount();
        return;
    }
    Current = node;
}

//оператор сравнения
template<typename T>
bool TreeIterator<T>::operator==(Node<T>* node) { return Current == node; }

//оператор сравнения
template<typename T>
bool TreeIterator<T>::operator!=(Node<T>* node) { return Current != node; }

//оператор разадрессации
template<typename T>
Node<T>* TreeIterator<T>::operator*() {
    return Current;
}

//оператор присваивания
template<typename T> void TreeIterator<T>::operator=(TreeIterator<T>& iter) {
    Current = iter.Current;								//присваивание полей
    tree = iter.tree;
    Index = iter.Index;
}

//оператор сравнения
template<typename T> bool TreeIterator<T>::operator==(TreeIterator<T>& iter) {
    return (Current == iter.Current);
}

//оператор сравнения
template<typename T> bool TreeIterator<T>::operator!=(TreeIterator<T>& iter) {
    return (Current != iter.Current);
}

//инкремент
template<typename T> void TreeIterator<T>::operator++(int) {
    //проверка на нахождение в конце
    if (Index == tree->GetCount() - 1) Current = nullptr;
    //установка в начало
    else if (Current == nullptr) Current = (Begin())->Current;
    //переход к следующему узлу
    else {
        int NewIndex = Index + 1;							//индекс следующего узла
        Index++;
        Node<T>* successor = nullptr;
        Step(tree->GetRoot() ,&successor , NewIndex);
        Current = successor;
    }
}

//декремент
template<typename T> void TreeIterator<T>::operator--(int) {
    //проверка на нахождение в начале дерева
    if (Index == 0) Current = nullptr;
    //установка в начало дерева
    else if (Current == nullptr) Current = (End())->Current;
    //переход к предыдущему узлу дерева
    else {
        int NewIndex = Index - 1;							//индекс предыдущего узла
        Index--;
        Node<T>* successor = nullptr;
        Step(tree->GetRoot(), &successor, NewIndex);
        Current = successor;
    }
}

//установка в начало
template<typename T> TreeIterator<T>* TreeIterator<T>::Begin() {
    TreeIterator<T>* NewIter = new TreeIterator<T>(tree);					//новый итератор
    Node<T>* temp = tree->GetRoot();
    if (temp == nullptr) {
        NewIter->Current = nullptr;
        NewIter->Index = 0;
        return NewIter;
    }
    while (temp->left != nullptr) temp = temp->left;						//преход в крайний левый узел дерева
    NewIter->Current = temp;
    NewIter->Index = 0;
    return NewIter;
}

//установка в конец дерева
template<typename T> TreeIterator<T>* TreeIterator<T>::End() {
    TreeIterator<T>* NewIter = new TreeIterator<T>(tree);					//новый итератор
    Node<T>* temp = tree->GetRoot();
    if (temp == nullptr) {
        NewIter->Current = nullptr;
        NewIter->Index = 0;
        return NewIter;
    }
    while (temp->right != nullptr) temp = temp->right;						//переход к крайнему правому узлу дерева
    NewIter->Current = temp;
    NewIter->Index = tree->GetCount() - 1;
    return NewIter;
}

//конец дерева
template<typename T> TreeIterator<T>* TreeIterator<T>::Last() {
    TreeIterator<T>* NewIter = new TreeIterator<T>(nullptr);
    return NewIter;
}

//поиск узла с индексом
template<typename T>
void TreeIterator<T>::Step(Node<T>* current,Node<T>** successor, int& NewIndex) {
    if (current != nullptr && *successor == nullptr) {
        Step(current->left, successor, NewIndex);							//поиск слева
        --NewIndex;
        if (NewIndex == -1) *successor = current;
        Step(current->right, successor, NewIndex);							//поиск справа
    }
}

//оператор вывода
template<typename T>
ostream& operator<<(ostream& out, TreeIterator<T>& iterator) {
    out << *(iterator->Current);											//оператор узла
    return out;
}
