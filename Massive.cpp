#include "Tree.h"

//удаление ненужных элементо из массива
template<typename T> void Massive<T> ::Filter() {
    try {
        if (IsEmpty()) throw new NullValueException("mas", "Massive<T>::Filter()");						//если массив пуст - конец
        Node<T>* obj1 = new Node<T>();				//узел для сравнения
        Node<T>* obj2 = new Node<T>();				//узел для сравнения
        int SearchMode;								//параметр поиска
        while (true) {
            cout << "Выберите параметр поиска\n0 - окончить выбор параметров\n";
            SearchMode = obj1->value.GetSearchMode();//выбор параметра поиска
            if (SearchMode == 0) return;			//конец фильтрации
            //инициализаци полей узлов для сравнения
            obj1->value.SetSearchParametres(obj1->value, obj2->value, SearchMode);
            //цикл удаления неподходящих эузлов
            for (int i = 0; i < putloc && mas[i] != nullptr; i++) {
                if (!(mas[i]->IsBetween(obj1, obj2, SearchMode))) {
                    Pop(i);							//удаление узла
                    i--;							//возврат назад
                }
            }
            if (IsEmpty()) return;					//если массив пуст - конец
            else {
                cout << endl;
                system("cls");
                Show();								//вывод найденных узлов
            }
        }
    }
    catch (NullValueException* exc) {
        system("cls");
        cout << *exc;
    }
}

//действия с эементами массива
template<typename T> Massive<T>* Massive<T>::Menu() {
    Massive<T>* deleted = new Massive<T>(putloc + 1);//массив для сохранения удаленных узлов
    system("cls");								//очистка консоли
    while (true) {
        cout << "\n1 - Вывод\n2 - Сортировка\n3 - Удаление\n"
            << "4 - Редактирование\nИначе - Выход\n";
        switch (_getch()) {						//выбор действия
        case '1':								//вывод массива
            try { Show(); }
            //пперехват исключения пустого дерева
            catch (NullValueException* exc) {
                system("cls");
                cout << *exc << endl;
            }
            break;
        case '2':								//сортировка
            try { Sort(); }
            //перехват исключения пустого дерева
            catch (NullValueException* exc) {
                cout << *exc << endl;
            }
            system("cls");
            break;
        case '3':								//удаление элемента
            try {
                cout << "Позиция:";
                int position;					//позиция узла
                cin >> position;
                //проврка на корректный ввод
                if (position >= 0 && position < putloc) {
                    deleted->Insert(mas[position]);//сохранение узла
                    Pop(position);				//удаление узла
                }
                else throw new ArrayBoundsException(position, "Massive::Pop()");
            }
            //перехват исключения нарушения границ массива
            catch (ArrayBoundsException* exc) {
                cout << *exc << endl;
            }
            system("cls");
            break;
        case '4':								//редактирование узла
            try {
                cout << "Позиция:";
                int position;					//позиция элемента
                cin >> position;
                //проверка на корректный ввод
                if (!(position < 0 || position >= putloc)) {
                    mas[position]->PrintHeader();
                    mas[position]->redact();	//редактирование
                }
                else throw new ArrayBoundsException(position, "Massive::Menu()");
            }
            //перехват исключения нарушения границ массива
            catch (ArrayBoundsException* exc) {
                cout << *exc << endl;
            }
            system("cls");
            break;
        default: return deleted;				//выход
        }
    }
}

//пуст ли массив
template<typename T> bool Massive<T>::IsEmpty() { return (mas[0] == nullptr || putloc == 0); }

//вставка узла в массив
template<typename T> void Massive<T>::Insert(Node<T>* newNode) { mas[putloc++] = newNode; }

//удаление узла из массива
template<typename T> void Massive<T>::Pop(int position) {
    //прверка на корректную позицию
    if (position < 0 || position >= putloc) throw new ArrayBoundsException(position, "Massive::Pop(int position)");
    for (int i = position; i < putloc - 1; i++) {	//цикл сдвига
        mas[i] = mas[i + 1];
    }
    mas[putloc - 1] = nullptr;
    --putloc;										//на 1 узел меньше
}

//удаление последнего элемента массива
template<typename T> Node<T>* Massive<T>::Pop() {
    //проверка на пустоту
    if (IsEmpty()) throw new NullValueException("massive[0]", "Massive::Pop()");
    Node<T>* temp = mas[putloc - 1];				//сохранение элемента
    mas[putloc - 1] = nullptr;						//удаление
    --putloc;										//на 1 узел меньше
    return temp;
}

//вывод массива
template<typename T> void Massive<T>::Show() {
    //проверка на пустоту
    if (IsEmpty()) throw new NullValueException("massive[0]", "Massive::Show()");
    mas[0]->PrintHeader();							//вывод шапки таблицы
    //цикл вывода
    for (int i = 0; i < putloc && mas[i] != nullptr; i++) {
        cout << i << "|  " << (mas[i])->value;
    }
}

//превод массива в дерево
template<typename T> void Massive<T>::ToTree(Tree<T>* tree) { ToTree(tree, 0, size - 1); }

//перевод массива в дерево
template<typename T> void Massive<T>::ToTree(Tree<T>* tree, int left, int right) {
    if (left == right) {							//остался 1 невставленный узел
        tree->Insert(mas[left]);					//вставка этоого узла
        return;
    }
    else if (right - left == 1) {					//осталось 2 невставленных узла
        tree->Insert(mas[left]);					//вставка узла
        tree->Insert(mas[right]);
        return;
    }
    int middle = (left + right) / 2;				//центральный узел
    tree->Insert(mas[middle]);						//вставка центрального узла в дерево
    ToTree(tree, left, middle - 1);					//повтор для левой части
    ToTree(tree, middle + 1 , right);				//повтор для правой части
}

//сортировка массива
template<typename T> void Massive<T>::Sort(int Mode) {
    //проверка на пустоту
    if (IsEmpty()) throw new NullValueException("massive[0]", "Massive::Sort()");
    SelectionSort(1);							//сортировка массива через отбор
}

//сортировка массива методом через отбор
template<typename T> void Massive<T>::SelectionSort(int Mode) {
    int min;										//индекс минимального элемента
    for (int i = 0; i < putloc - 1; i++) {			//сортировка массива через отбор
        min = i;
        for (int j = i + 1; j < putloc; j++) {		//поиск минимального элемента
            if (mas[j]->Compare(mas[min], Mode)) min = j;
        }
        Swap(i, min);								//обмен значений в позициях массива
    }
}


//обмен значений в позициях массива
template<typename T> void Massive<T>::Swap(int i, int j) {
    if (i == j) return;
    Node<T>* temp = mas[i];
    mas[i] = mas[j];
    mas[j] = temp;
}
