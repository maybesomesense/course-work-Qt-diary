#include "Tree.h"

template<typename T> void Tree<T>::AddCount() { leaf_count++; }								//увеличение количества узлов

template<typename T> void Tree<T>::DecCount() { leaf_count--; }								//уменьшение количества узлов

template<typename T> Node<T>* Tree<T>::GetRoot() { return root; }							//получение вершины

template<typename T> void Tree<T>::NullRoot() { root = nullptr; }							//зануление корня дерева

template<typename T> int Tree<T>::GetInsertionMode() { return InsertionMode; }				//получение поля построения дерева

template<typename T> void Tree<T>::SetInsertionMode(int NewMode) { InsertionMode = NewMode; }//установка нового параметра построения дерева


//получение наследника для узла с 2 поомками
template<typename T> Node<T>*  Tree<T>::getSuccessor(Node<T>* deleted) {
    Node<T>* successorParent = deleted;				//отец наследника
    Node<T>* successor = deleted;					//наследник
    Node<T>* current = deleted->right;				//бегунок по дереву
    while (current) {								//цикл поиска наследника
        successorParent = successor;
        successor = current;
        current = current->left;
    }
    if (successor != deleted->right) {				//если наследник - правый сын удаляемого узла
        successorParent->left = successor->right;
        successor->right = deleted->right;
    }
    return successor;
}

//количество узлов в дереве
template<typename T> int Tree<T> :: GetCount() { return leaf_count; }

//вставка элемента в дерево
template<typename T> void Tree<T>::Insert(Node<T>* newNode) {
    if (root == NULL) root = newNode;				//если дерево пустое
    else {
        Node<T>* current = root;					//бегунок по дереву
        while (true) {								//цикл поиска места вставки
            //найден дубликат - переход вправо
            if (newNode->IsBetween(current, current, InsertionMode)) {
                if (current->right == NULL) {
                    current->right = newNode;
                    return;
                }
                current = current->right;
            }
            //добавляемый узел меньше текущего - переход влево
            else if (newNode->Compare(current , InsertionMode) == true) {
                if (current->left == NULL) {
                    current->left = newNode;
                    return;
                }
                current = current->left;
            }
            //добавляемый узел больше текущего - переход влево
            else {
                if (current->right == NULL) {
                    current->right = newNode;
                    return;
                }
                current = current->right;
            }
        }
    }
}

//поиск узлов в дереве
template<typename T> Massive<T>* Tree<T>::Search() {
    Massive<T>* finded = new Massive<T>(leaf_count);				//массив для перевода дерева в него
    ToMas(root, finded);											//перевод дерева в массив симметричным обходом
    finded->Filter();												//фильтрация массива
    //проверка массива на пустоту
    if (finded->IsEmpty()) throw new NodeNotFoundException("узлы с такими праметрами", "Tree::Search()");
    return finded;
}

//удаление узла из дерева
template<typename T> void Tree<T> :: Pop(Node<T>* deleted) {
    Node<T>* parent = root;											//родитель удаляемого узла
    //цикл поиска удаляемого узла
    while (parent->left != deleted && parent->right != deleted && deleted != root) {
        if(parent->Compare(deleted , InsertionMode)) parent = parent->right;
        else parent = parent->left;
    }
    //является ли удаляемый узел левым сыном
    bool isLeftChild = (deleted == parent->left) ? true : false;
    if (deleted->left == NULL && deleted->right == NULL) {						//удаляемый узел не имеет потомков
        if (deleted->IsBetween(root , root , InsertionMode)) root = NULL;
        else if (isLeftChild) parent->left = NULL;
        else parent->right = NULL;
    }
    else if (deleted->left == NULL) {										//удаляемый узел не имеет левого потомка
        if (deleted->IsBetween(root, root, InsertionMode)) root = root->right;
        else if (isLeftChild) parent->left = deleted->right;
        else parent->right = deleted->right;
    }
    else if (deleted->right == NULL) {										//удаляемый узел не имеет правого потомка
        if (deleted->IsBetween(root, root, InsertionMode)) root = root->left;
        else if (isLeftChild) parent->left = deleted->left;
        else parent->right = deleted->left;
    }
    else {															//удаляемый узел имеет 2 потомков
        Node<T>* successor = getSuccessor(deleted);					//получение наследника
        if (deleted->IsBetween(root, root, InsertionMode)) root = successor;
        else if (isLeftChild) parent->left = successor;
        else parent->right = successor;
    }
    leaf_count--;													//в дереве на 1 элемент больше
}

//запись дерева в файл
template<typename T> void Tree<T>::WriteToFile(FileStream& stream) {
    //проверка дерева на пустоту
    if (root == nullptr) throw new NullValueException("root", "Tree::WriteToFile()");
    WriteToFile(root, stream);										//запись дерева в файл прямым обходом
}

//запись дерева в файл прямым обходом
template<typename T> void Tree<T>::WriteToFile(Node<T>* current, FileStream& stream) {
    if (current != nullptr) {
        stream << current->value;									//запись узла в файл
        WriteToFile(current->left, stream);							//посещение левого сына
        WriteToFile(current->right, stream);						//посещение правого сына
    }
}

//вывод дерева
template<typename T> void Tree<T>::Display() {
    root->PrintHeader();											//вывод шапки таблицы
    Display(root);													//вывод дерева симметричным обходом
}

//вывод дерева симметричным обходом
template<typename T>  void Tree<T> :: Display(Node<T>* current) {
    if (current != nullptr) {
        Display(current->left);										//посещение левого сына
        cout << current->value;										//вывод узла
        Display(current->right);									//посещение правого сына
    }
}

//перестройка дерева н=по новому параметру
template<typename T> void Tree<T> :: Reconfiguration(int Mode) {
    Massive<T>* mas = new Massive<T>(leaf_count);					//массив для перевода дерева в него
    T obj;
    if (Mode == -1) InsertionMode = obj.GetMode();					//выбор параметра перестройки
    else InsertionMode = Mode;
    ToMas(root, mas);												//перевод дерева в массив симметричным обходом
    AllNull(root);													//разрушение связей между узлами дерева
    root = nullptr;
    mas->Sort(InsertionMode);										//сортировка массива
    mas->ToTree(this);												//перевод массива в дерево
    mas->~Massive();												//разрушние массива
}

//перевод дерева в массив симметричным обходом
template<typename T> void Tree<T> :: ToMas(Node<T>* current, Massive<T>* mas) {
    if (current) {
        ToMas(current->left , mas);									//посещение левого сына
        ToMas(current->right , mas);								//посещение правого сына
        mas->Insert(current);										//добавление узла в массив
    }
}

//разрушение связей между узлами дерева обратным обходом
template<typename T> void Tree<T> :: AllNull(Node<T>* current) {
    if (current !=  nullptr) {
        AllNull(current->left);										//посещение левого сына
        AllNull(current->right);									//посещение правого сына
        current->left = nullptr;									//зануление указателей
        current->right = nullptr;
    }
}

template<typename T> void Tree<T>::DeleteTree() {					//удаление дерева
    DeleteTree(root);
    root = nullptr;
    leaf_count = 0;
}

//удаление дерева обратным обходом
template<typename T> void Tree<T>::DeleteTree(Node<T>* current) {
    if (current != nullptr) {
        DeleteTree(current->left);									//посещение левого сына
        DeleteTree(current->right);									//посещение правого сына
        delete current;												//удаление узла
    }
}
