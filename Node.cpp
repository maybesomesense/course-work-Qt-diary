#include "Node.h"

//является ли объект неинициализированным
template<typename T> bool Node<T>::IsDefault() { return value.IsDefault(); }

//сравнение по полю объекта
template<typename T>
bool Node<T>::Compare(Node<T>* obj, int Mode) {
    return value.Compare(obj->value, Mode);
}

//сравнение по полю объекта
template<typename T>
bool Node<T>::IsBetween(Node<T>* obj1, Node<T>* obj2, int Mode) {
    return value.IsBetween(obj1->value, obj2->value, Mode);
}

//опеаратор считывания из файла
template<typename T>
ifstream& operator>>(ifstream& in, Node<T>& object) {
    in >> object.value;								//оператор объекта
    return in;
}

//оператор записи в файл
template<typename T>
ofstream& operator<<(ofstream& out, Node<T>& object) {
    out << object.value;							//оператор объекта
    return out;
}

