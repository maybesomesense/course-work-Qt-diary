#include "Stack.h"

//занесение в стек
template<typename T> void Stack<T>::Push(StackElement<T>* NewElement) {
    if (Top == nullptr) Top = NewElement;		//если стек пуст
    else {										//еслистек не пуст
        NewElement->Next = Top;
        Top = NewElement;
    }
}

//удаление из стека
template<typename T> StackElement<T>* Stack<T>::Pop() {
    StackElement<T>* temp = Top;				//удаляемый элемент
    if (Top == nullptr)							//проверка стека на пустоту
        throw new NullValueException("Top" , "Stack::Pop()");
    else Top = Top->Next;						//перемещение вершины
    return temp;
}

//является ли стек пустым
template<typename T> bool Stack<T>::IsEmpty() {
    return Top == nullptr;
}

//удаление стека
template<typename T> void Stack<T>::DeleteStack(StackElement<T>* current) {
    if (current->Next != nullptr) {
        DeleteStack(current->Next);				//переход к следующему элементу
        delete current;							//удаление элемента
    }
}
