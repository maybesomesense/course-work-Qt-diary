#include "Alhoritm.h"

//чтение из файла в дерево
template<typename T> void Alhoritm<T>::ReadFromFile(TreeIterator<T>& start, TreeIterator<T>& finish, Tree<T>* tree, const char* filename , Stack<T>& stack) {
    try {
        FileStream stream;																		//поток считывания
        stream.Open(filename, 1);																//открытие потока
        switch (stream.IsOpen()) {																//проверка режима работы файла
        case 0: throw new FileNotOpenException((const char*)stream.CurrentFile);				//файл закрыт
        case 2: throw new FileIncorrectModeException(2 ,(const char*)stream.CurrentFile);		//файл открыт для записи
        }
        Node<T>* NewNode = nullptr;																//узел для считывания
        while (!stream.EndOfStream()) {															//цикл считывания
            NewNode = new Node<T>();															//выделение памяти
            stream >> NewNode->value;															//считывание в узел
            if (NewNode->IsDefault()) break;													//проверка узла на пустоту
            Alhoritm<T>::Insert(*start.Begin(), *finish.End(), tree, NewNode, stack);			//вставка узла в дерево
        }
    }
    //перехват исключения закрытого файла
    catch (FileNotOpenException* exc) {
        system("cls");
        cout << *exc;
    }
    //перехват исключения некорректного режима файла
    catch (FileIncorrectModeException* exc) {
        system("cls");
        cout << *exc;
    }
    //перехват искючения несуществующего файла
    catch (FileNotExistException* exc) {
        system("cls");
        cout << *exc;
    }
}

//запись дерева в файл
template<typename T> void Alhoritm<T>::WriteToFile(Tree<T>* tree, const char* filename) {
    try {
        FileStream stream;																		//поток для записи
        stream.Open(filename, 2);																//открытие потока
        switch (stream.IsOpen()) {																//проверка режима работы файла
        case 0: throw new FileNotOpenException((const char*)stream.CurrentFile);				//файл закрыт
        case 1: throw new FileIncorrectModeException(1 ,(const char*)stream.CurrentFile);		//файл открыт для записи
        }
        tree->WriteToFile(stream);																//запись дерева в файл
        tree->DeleteTree();																		//удаление дерева
    }
    //перехват исключения закрытого файла
    catch (FileNotOpenException* exc) {
        system("cls");
        cout << *exc;
    }
    //перехват исключения некорректного режима файла
    catch (FileIncorrectModeException* exc) {
        system("cls");
        cout << *exc;
    }
}


//вставка нового узла в дерево
template<typename T> void Alhoritm<T>::Insert(TreeIterator<T>& start, TreeIterator<T>& finish, Tree<T>* tree, Node<T>* NewNode, Stack<T>& stack) {
    int InsertionMode = tree->GetInsertionMode();											//получение параметра для вставки узла в дерево
    StackElement<T>* saved = new StackElement<T>(NewNode , 'i');							//сохранение добавляемого узла
    stack.Push(saved);
    if (*start == nullptr) {																//если дерево пустое
        tree->Insert(NewNode);
    }
    else if (NewNode->Compare(*start, InsertionMode)) (*start)->left = NewNode;				//если новый узел наименьший в дереве
    else if ((*finish)->Compare(NewNode, InsertionMode)) (*finish)->right = NewNode;		//если новый узел наибольший в дереве
    else {																					//если новый узел не является экстремальным
        TreeIterator<T> current = start;													//итератор по дереву
        current++;
        //поиск места вставки(новый узел должен быть вставлен между 2 узлами дерева)
        while (start != finish && !((*start)->Compare(NewNode, InsertionMode) && NewNode->Compare(*current, InsertionMode))) {
            start++;
            current++;
        }
        if (start == finish) return;
        else {
            if ((*start)->right == nullptr) (*start)->right = NewNode;						//вставка справа от узла
            else (*current)->left = NewNode;												//вставка слева от узла
        }
    }
    start.AddCount();																		//в дереве на 1 узел больше
}

//поиск узлов в дереве
template<typename T> Massive<T>* Alhoritm<T>::Search(TreeIterator<T>& start, TreeIterator<T>& finish, Tree<T>* tree, Stack<T>& stack) {
    try {
        //проверка дерева на пустоту
        if(*start == nullptr) throw new NullValueException("tree.root" , "Alhoritm<T>::Search()");
        Massive<T>* finded = new Massive<T>(tree->GetCount());					//массив найденных узлов
        while (start != finish) {												//запись узлов в массив
            finded->Insert(*start);
            start++;
        }
        finded->Insert(*finish);
        finded->Filter();														//удаление ненужных узлов из массива
        //проверка массива на пустоту
        if (finded->IsEmpty()) throw new NodeNotFoundException("узлы с такими праметрами", "Alhoritm<T>::Search()");
        return finded;
    }
    //перехват исключения пустого дерева
    catch (NullValueException* exc) {
        system("cls");
        cout << *exc << "Дерево пустое" << endl << endl;
        return nullptr;
    }
}

//сортировка дерева по другому параметру
template<typename T> void Alhoritm<T>::Sort(TreeIterator<T>& start, TreeIterator<T>& finish, Tree<T>* tree, Stack<T>& stack, int IMode) {
    try {
        //если дерево пустое - генерация исключения
        if (*start == nullptr) throw new NullValueException("tree.root" , "Alhoritm<T>::Sort()");
        Massive<T>* mas = new Massive<T>(tree->GetCount());						//массив для перевода дерева в него
        int InsertionMode;														//новый параметр построения дерева
        if (IMode == -1) {														//если параметр не задан
            T obj;
            InsertionMode = obj.GetSearchMode();								//выбор нового параметра
            stack.Push(new StackElement<T>(tree, tree->GetInsertionMode()));	//занесение параметра в стек
        }
        else InsertionMode = IMode;
        while (start != finish) {												//цикл записи дерева в массив
            mas->Insert(*start);
            start++;
        }
        mas->Insert(*finish);
        tree->SetInsertionMode(InsertionMode);									//установка нового параметра построения
        tree->AllNull(tree->GetRoot());											//разрушение связей между узлами дерева
        tree->NullRoot();														//зануление корня дерева
        mas->Sort(InsertionMode);												//сортировка массива по новому параметру
        mas->ToTree(tree);														//перевод массива в дерево
        mas->~Massive();														//уничтожение массива
    }
    //перехват исключения пустого дерева
    catch (NullValueException* exc) {
        system("cls");
        cout << *exc << "Дерево пустое" << endl << endl;
    }
}

//отмена последнего действия
template<typename T> void Alhoritm<T>::Cancellation(Tree<T>* tree, Stack<T>& stack) {
    try {
        if (stack.IsEmpty()) throw new NullValueException("stack.Top", "Alhoritm<T>::Cancellation()");
        StackElement<T>* saved = stack.Pop();
        TreeIterator<T> iter(tree);
        if (saved->node != nullptr) {
            if (saved->Operation == 'i') tree->Pop(saved->node);
            else {
                tree->Insert(saved->node);
                tree->AddCount();
            }
        }
        else Sort(*(iter.Begin()), *(iter.End()), tree , *(new Stack<T>()) , saved->InsertionMode);
    }
    catch (NullValueException* exc) {
        system("cls");
        cout << *exc << "Предыдущих действий не было";
    }
}
