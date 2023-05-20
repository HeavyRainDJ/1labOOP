#ifndef ITERATOR_H
#define ITERATOR_H

#include <iostream>

template <typename Type> // шаблонный класс container_list с универсальным типом Type
class container_list;

template <typename Type> // объявляем итератор шаблонным классом
class Iterator {
private:
    container_list<Type>* container_obj; // указатель на контейнер лист
    Type* pointer; // указатель типовой поинтер
public:
    Iterator(container_list<Type>& container_obj);
    Iterator(container_list<Type>& container_obj, int index);
    Iterator<Type> next(); //Функция next() возвращает объект-итератор, указывающий на следующий элемент в контейнере
    Type value(); // Функция value() возвращает значение, на которое указывает итератор.
    bool is_end(); // достиг ли оператор конца или нет
    // перегруженные операторы
    Iterator<Type>& operator++();//  Функция operator++() - это оператор предварительного увеличения, который перемещает итератор к следующему элементу
    Type& operator*(); // Функция operator*() - это оператор разыменования, который возвращает ссылку на значение, на которое указывает итератор
    bool operator==(Iterator& b); // операторы на равенство и неравенство переменных
    bool operator!=(Iterator& b);
};

template <typename Type> // конструктор иниц объект итератора ссылкой на объект листа
Iterator<Type>::Iterator(container_list<Type>& container_obj) {
    this->container_obj = &container_obj; // переменная член указывающая на объект контейнера
    this->pointer = &(container_obj[0]); // переменная член указывающая на первый элемент контейнера
}

template <typename Type>
Iterator<Type>::Iterator(container_list<Type>& container_obj, int index) {
    this->container_obj = &container_obj; //переменная член указывающая на объект контейнера
    this->pointer = &(container_obj[index]);  //переменная член указывающая на элемент с указанным индекс в листе
}

template <typename Type>
Iterator<Type> Iterator<Type>::next() {
    Iterator<Type> a = *this;
    if (!a.is_end()) // увеличивает указатель скопированного итератора если тот не достиг конца
        ++a.pointer;
    return a; // возвращает скопированный итератор
}

template <typename Type>
Type Iterator<Type>::value() {
    return **this; // возвращает значение, на которое указывает итератор, путем разыменования итератора дважды.
}
// проверяет, достиг ли итератор конца контейнера. Он делает это путем сравнения указателя итератора с адресом последнего элемента в контейнере.
template <typename Type>
bool Iterator<Type>::is_end() {
    int length = container_obj->get_length(); // Он извлекает длину контейнера с помощью функции get_length()
    return (pointer > &((*container_obj)[length - 1]));
}

template <typename Type>
Iterator<Type>& Iterator<Type>::operator++() {
    *this = this->next(); // перемещает итератор к следующему элементу, присваивая результат функции next() самому текущему итератору.
    return *this;
    // Затем он возвращает ссылку на обновленный итератор.
}

template <typename Type>
Type& Iterator<Type>::operator*() {
    return *pointer; // возвращает ссылку на значение, на которое указывает итератор, путем разыменования указателя итератора
}

template <typename Type>
bool Iterator<Type>::operator==(Iterator& b) {
    return this->pointer == b.pointer;
    //сравнивает два итератора на предмет равенства путем сравнения их указателей. Он возвращает значение true, если указатели равны
}

template <typename Type>
bool Iterator<Type>::operator!=(Iterator& b) {
    return !(*this == b);
    // Оператор неравенства operator!= сравнивает два итератора для определения неравенства, отрицая результат оператора равенства operator==. Он возвращает значение true, если итераторы не равны, указывая на то, что они указывают на разные элементы.
}

#endif // ITERATOR_H
