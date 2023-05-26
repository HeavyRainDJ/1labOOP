#ifndef CONTAINER_LIST_H
#define CONTAINER_LIST_H
// c++ книжка шилд
#include <initializer_list>
#include "Exceptionlist.h"
#include "Iterator.h"
template <typename T>
class container_list{
private:
    T *list;
    int amount;
    void resize(int amount); // изменения размера списка на 1 (+)
public:
    container_list() = default; //конструктор по умолчанию (+)
    ~container_list() = default;//(+)
    container_list(const container_list <T>&lst);//констурктор копирования (+)
    container_list(container_list<T>&&list);//конструткор перемещения (+)
    explicit container_list(std::initializer_list<T> lst);//конструктор со списком инициализации (+)
    container_list<T>&operator = (const container_list<T>&lst);//перегрузка оператора (+)


    int get_length() const{return amount;} // получение размера списка (+)
    T& operator[](int index); //  доступ к элементу аналогично массиву (+)
    void add(const T &elem); // добавление элемента в конец (+)
    container_list(int length); // инициализация списка (+)
    void add_range(const container_list <T> &lst); //добавления списка элементов в конец (+)
    void add_range(T *arr, int size); // добавление массива элементов (+)
    void set_elem(int index, const T& elem); // изменения элемента по индексу (+)
    T &get_elem(int index); // получения элемента списка по индексу (+)
    void remove_elem(int index); // удаление элемента списка по индексу (+)
    container_list<T> &combine(const container_list<T> &lst); //  объединение двух разных списков
    void sort(int (*comp)(const T &r1, const T &r2));
     bool comp(T &r1, T &r2);
    int get_index(T elem)const;
    T* to_array();
    Iterator<T> begin();
    Iterator<T> end();

};
template<typename T>
T* container_list<T>::to_array(){
    T* new_array = new T[amount];
    for (size_t i = 0; i < amount; i++)
        new_array[i] = list[i];
    return new_array;
}
template  <typename  T>
container_list<T>::container_list(const container_list <T> &lst){
    amount=lst.amount; // из лст берем амоунт
    try {
        list=new T[amount];
        for(int i=0;i<amount;i++){
            list[i]=lst.list[i];
        }

    }  catch (bad_alloc ex) {
        throw Exceptionlist("Bad Alloc\n");

    }

}
template  <typename  T>
container_list<T>::container_list(container_list <T> &&lst){
    amount=lst.amount;

    list=lst.list; // значения из лст в лист
    lst.list=nullptr; // чтобы удостоверятся не является динам присваиваем нуллптр чтобы он не удалился диструктором
    amount=0;
}
template  <typename T>
container_list<T>::container_list(std::initializer_list<T> lst){
    amount=lst.size();
    try{
        list=new T[amount]{};
        int i=0;
        for(T item: lst)
            list[i++]=item;

    } catch (bad_alloc ex){
        list=nullptr;
        amount=0;
        throw Exceptionlist("Not Memory");
    }
}

template <typename T>
container_list<T> &container_list<T>::operator=(const container_list<T> &lst){
    *this=container_list<T>;
    for(int i=0; i<lst.amount;i++)
        list[i]=lst.list[i];
    return *this; // Возвращается ссылка на текущий объект (*this) для создания нескольких назначения выполнения в одном операторе
}
template  <typename  T>
void container_list<T>::resize(int amount){
    list =(T*)realloc(list,sizeof(T)*amount);
    if(list==nullptr){
        amount=0;
        throw Exceptionlist("Not realloced memory\n");

    }

}
template  <typename  T>
container_list<T>::container_list(int length){
    try {
        list=new T[length]{};
        amount=length;
    } catch (bad_alloc) {
        Exceptionlist("bad allocation\n");
    }
}
template <typename T>
void container_list<T>::add(const T&elem){
    amount++; // увеличение амоунт на 1 для добавления
    resize(amount); // перевыделение памяти листа
    list[amount-1]=elem; // на последнию позицию
}

template <typename T>
void container_list<T>::add_range(const container_list <T> &lst){
    amount+=lst.amount; // увел на количество из лст
    resize(amount); // перевыделение
    int tmp=amount-lst.amount; // разница длин
    for(int i=tmp; i<amount;i++){ // для того чтобы пройтись и добависть новые элемегнты в список
        list[i]=lst.list[i-tmp];
    }
}

template <typename T>
void container_list<T>::add_range(T *arr,int size){
    if(size<0|| size*sizeof(T) <=sizeof(arr)){ // проверка размер отрицательным или размер массива (в байтах) меньше или равен размеру указателя arr.
        throw Exceptionlist("Out range arr\n");
     }
     amount+=size;
     resize(amount);
     int tmp=amount-size;
     for(int i=tmp;i<amount;i++)
        list[i]=arr[i-tmp];
}
template <typename T>
T& container_list<T>::get_elem(int index){
    if(index<amount && index>=0){
        return *(list + index);
    }else{
        throw Exceptionlist("Out of range list\n");
    }

}
template <typename T>
void container_list<T>::set_elem( int index, const T& elem){
    if(index<amount && index>=0){
        list[index]=elem;
    }else{
        throw Exceptionlist("Out of range list\n");
    }

}
template <typename T>
T& container_list<T>::operator[](int index){
    return get_elem(index);
}


template<typename T>
void container_list<T>::remove_elem(int index){
    if (index < amount && index >= 0){ // Цикл используется для сдвига элементов в массиве списка на одну позицию влево, начиная с позиции индекса
        for (int i = index; i < amount; i++)
            list[i] = list[i+1];
        amount--;
        resize(amount);
    }
    else
        throw Exceptionlist(" - out of range!/n");
}

template<typename T>
container_list<T>& container_list<T>::combine(const container_list<T>&lst){
    container_list<int> local(*this);
    local.add_range(lst);
    return local;
}

template<typename T>
void container_list<T>::sort(int (*comp)(const T &r1, const T &r2)){
    int tmp;
    for (int i = 0; i < amount - 1; i++)
        for (int j = 0; j < amount - 1; j++)
            if (comp(list[j + 1], list[j])){
                tmp = list[j + 1];
                list[j + 1] = list[j];
                list[j] = tmp;
            }
}

template<typename T>
int container_list<T>::get_index(T elem) const{
     int a = -1;
    for (int i = 0; i < amount; i++)
        if (list[i] == elem){
            a=i;
            break;
        }

    return a;
}

template<typename T>
Iterator<T> container_list<T>::begin()
{
    return Iterator<T>(*this);
}

template<typename T>
Iterator<T> container_list<T>::end() {
    return Iterator<T>(*this, (this->amount) - 1);
}

#endif // CONTAINER_LIST_H
