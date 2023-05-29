
#include <iostream>
#include "container_list.h"

using namespace std;

void test_base();
void test_base_extra();
void test_add();
void test_add_extra();

void test_base_elems();
void test_extra_elems();
void test_combine();
void test_sort();
int comp(int &r1, int &r2);
void test_index();
void test_array();
void test_iterators();
void test_inizalisation();
void test_joke();

template<typename T>
bool comp(T &r1, T &r2);

int main()
{
    test_base(); //+
    test_joke();
    test_base_extra(); //+
    test_inizalisation(); //+
    test_add(); //+
    test_add_extra(); //+
    test_base_elems();
    test_extra_elems();
    test_combine(); //+
    test_sort(); //+
    test_index(); //+
    test_array(); //+
    test_iterators(); // +
    return 0;
}

void test_joke(){
    container_list<int> a4{1,2,3,4,5};
    container_list<int> a7 = a4;
    cout << "Lenght 'a7' - " << a7.get_length() << endl;
    cout << "elements of list 'a7': " << endl;
    for (int i = 0; i < a7.get_length(); i++){
        cout << a7[i] << " ";
    }
}

void test_base()
{
    cout << "----------------------------" << endl;
    cout << "1) Test base  class container_list" << endl;
    container_list<int> b;
    cout << "1. List was made by comporator" << endl;
    container_list<int> a(2);
    cout << "2. List made bt lenght" << endl;
    cout << "Lenght 'a' - " << a.get_length() << endl;
    cout << "elements of list 'a': " << endl;
    for (int i = 0; i < a.get_length(); i++)
        cout << a[i] << " ";
    cout << endl;
    container_list<int> a2 = a;
    cout << "3. List 'a2' copy list 'a'" << endl;
    cout << "Lenght 'a2' - " << a2.get_length() << endl;
    cout << "elements of list 'a2': " << endl;
    for (int i = 0; i < a2.get_length(); i++)
        cout << a2[i] << " ";
    cout << endl;

    container_list<int> b1 = b;
    cout << "Lenght 'b1' - " << b1.get_length() << endl;
    cout << "elements of list 'b1': " << endl;
    for (int i = 0; i < b1.get_length(); i++)
        cout << b1[i] << " ";
    cout << endl;
    cout << "----------------------------" << endl;
}

void test_base_extra(){
    cout << "----------------------------" << endl;
    cout << "2) Extra test for base containter_list class" << endl;
    try {
        container_list<int> a{};
        cout << 2;
        container_list<int> b;
        cout << "1";
        container_list<int> a2 =a;
        container_list<int> a3 = std::move(a2);
        cout << "1. a list 'a3' is moved from 'a2'" << endl;
        cout << "Lenght  'a3' - " << a3.get_length() << endl;
        cout << "elemets of list 'a3': " << endl;
        for (int i = 0; i < a3.get_length(); i++)
            cout << a3[i] << " ";
        cout << endl;
        container_list<int> a4{1,2,3,4,5};

        a3 = std::move(a4);
        cout << "1. a list 'a3' is moved from 'a2'" << endl;
        cout << "Lenght  'a3' - " << a3.get_length() << endl;
        cout << "elemets of list 'a3': " << endl;
        for (int i = 0; i < a3.get_length(); i++)
            cout << a3[i] << " ";
        cout << endl;

    } catch (...) {
        cout << "smth wrong";
    }

    cout << "----------------------------" << endl;
}
void test_inizalisation(){
    cout << "----------------------------" << endl;
    cout << "3) Test init list" << endl;
    container_list<int> a4{1,2,3,4,5};//список инициализации
    cout << "1. List 'a4' is initialized by numbers (1,2,3,4,5)" << endl;
    cout << "Lenght 'a4' - " << a4.get_length() << endl;
    cout << "elemets of list 'a4': " << endl;
    for (int i = 0; i < a4.get_length(); i++)
        cout << a4[i] << " ";
    cout << endl;
    container_list<int> a5;
    a5 = a4;
    cout << "2. List 'a5' is assigned by 'a4'" << endl;
    cout << "Lenght 'a5' - " << a5.get_length() << endl;
    cout << "elemets of list 'a5': " << endl;
    for (int i = 0; i < a5.get_length(); i++)
        cout << a5[i] << " ";
    cout << endl;
    cout << "----------------------------" << endl;
}
void test_add(){
    cout << "----------------------------" << endl;
    cout << "4) Test methods to add" << endl;
    container_list<int> a6{1,2,3,4};
    cout << "1. List 'a6' is initialized with (1,2,3,4)" << endl;
    a6.add(2223);
    cout << "2223 is added to list 'a6'" << endl;
    cout << "elemets of list 'a6': " << endl;
    for (int i = 0; i < a6.get_length(); i++)
        cout << a6[i] << " ";
    cout << endl;
    container_list<int> a7{1,2,3};
    container_list<int> a8{4,5};
    cout << "----------------------------" << endl;
    cout << "2. List 'a7' is initialized with (1,2,3) " << endl;
    cout << "3. List 'a8' is initialized with (4,5) " << endl;
    a7.add_range(a8);//a7 add range пустой
    cout << "Elemets of list 'a7' + 'a8': " << endl;
    for (int i = 0; i < a6.get_length(); i++)
        cout << a7[i] << " ";
    cout << endl;
    container_list<int> a10{};
    a7.add_range(a10);
    cout << "Elemets of list 'a7' + 'a10': " << endl;
    for (int i = 0; i < a7.get_length(); i++)
        cout << a7[i] << " ";
    cout << endl;
    cout << "----------------------------" << endl;
}

void test_add_extra(){
    try {
        cout << "----------------------------" << endl;
        cout << "5) Test methods to add_extra" << endl;
        container_list<int> a9{1,2};
        cout << "1. List 'a9' is initialized with (1,2) " << endl;
        cout << "Arr is with (-1,-2,-3,-4) " << endl;
        int arr[4]{-1,-2,-3,-4};
        a9.add_range(arr, 3);
        cout << "Elements of list 'a9' + 'arr':" << endl;
        for (int i = 0; i < a9.get_length(); i++)
            cout << a9[i] << " ";
        cout << endl;
        a9.add_range({},0);
        a9.add_range(arr, -3);

    }catch(Exceptionlist& ex) {
        cout << ex.what() << endl;
        cout << "----------------------------" << endl;
    }
}
void test_base_elems(){
    try {
        cout << "----------------------------" << endl;
        cout << "6) Test methods for base_elems" << endl;
        container_list<int> a10{1,2,3,4};
        cout << "1. List 'a10' is initialized with (1,2,3,4) " << endl;
        cout << "The first element is changed to '0'" << endl;
        a10.set_elem(0,0);
        cout << "Elements of list 'a10':" << endl;
        for (int i = 0; i < a10.get_length(); i++)
            cout << a10[i] << " ";
        cout << endl;
        cout << "----------------------------" << endl;
        a10.set_elem(-1,-1);
    }catch (Exceptionlist& ex) {
        cout << ex.what() << endl;
    }
}
void test_extra_elems(){
    try{
        cout << "----------------------------" << endl;
        cout << "7) Test methods for base_elems_extra" << endl;
        container_list<int> a11{1,2,3,4,5};
        cout << "1. List 'a11' is initialized with (1,2,3,4,5) " << endl;
        cout << "The first element is - " << a11.get_elem(0) << endl;
        cout << "----------------------------" << endl;
        a11.get_elem(-900);
    } catch (Exceptionlist &ex){
        cout << ex.what() << endl;
    }
    try {
        container_list<int> a12{1,2,3,4};
        cout << "2. a list 'a12' is initialized with (1,2,3,4) " << endl;
        cout << "The second element is removed" << endl;
        a12.remove_elem(1);
        cout << "Elements of list 'a12':" << endl;
        for (int i = 0; i < a12.get_length(); i++)
            cout << a12[i] << " ";
        cout << endl;
        a12.remove_elem(-69);
    }catch (Exceptionlist& ex) {
        cout << ex.what() << endl;
    }
}


void test_combine(){
    cout << "----------------------------" << endl;
    cout << "8) Test method combine" << endl;
    container_list<int> a13 {1,2,3};
    container_list<int> a14 {4,5};
    cout << "1. List 'a13' is initialized with (1,2,3) " << endl;
    cout << "List 'a14' is initialized with (4,5) " << endl;
    a13.combine(a14);
    container_list<int> a16 {};
    a13.combine(a16);
    cout << "Elements of list 'a13', which was combined with 'a14':" << endl;
    for (int i = 0; i < a13.get_length(); i++)
        cout << a13[i] << " ";
    cout << endl;

}

int comp(const int &r1, const int &r2)
{
    return r1 > r2;
}

void test_sort(){
    cout << "----------------------------" << endl;
    cout << "9) Test for methods sorting by compare in container class" << endl;
    container_list<int> a15 {5,2,1,4,3};
    cout << "1. List 'a15' is initialized with (5,2,1,4,3) " << endl;
    cout << "List 'a15' is sorted " << endl;
    a15.sort(comp);
    cout << "Elements of list 'a15':" << endl;
    for (int i = 0; i < a15.get_length(); i++)
        cout << a15[i] << " ";
    cout << endl;
    cout << "----------------------------" << endl;
}

void test_index(){
    try {
        cout << "----------------------------" << endl;
        cout << "10) Test for methods INDEX in container class" << endl;
        container_list<int> a16 {1,2,3,4,5};
        cout << "1. List 'a16' is initialized with (1,2,3,4,5) " << endl;
        cout << "Element '2' has index " << a16.get_index(2);
        cout << endl;
        cout << "Element '2' has index " << a16.get_index(-999);
        cout << endl;
    }catch(Exceptionlist& ex) {
        cout << ex.what() << endl;
    }
    cout << "----------------------------" << endl;
}

void test_array(){
    cout << "----------------------------" << endl;
    cout << "10) Test for methods array" << endl;
    container_list<int> a17 {1,2,3,4,5};
    container_list<int> a18 {};
    cout << "1. List 'a17' is initialized with (1,2,3,4,5) " << endl;
    int *array = a17.to_array();
    int *array2 = a18.to_array();
    cout << "Elements of list 'a17' are moved to array" << endl;
    cout << "Elements of array:" << endl;
    for (int i = 0; i < a17.get_length(); i++)
        cout << array[i] << " ";
    cout << endl;
    a17[4] = 15;
    cout << "Change element in list a17 in index four"<<endl;
    cout << "Elements of array in list a17:" << endl;
    for (int i = 0; i < a17.get_length(); i++)
        cout << a17[i] << " ";
    cout << endl;
    cout << "Elements of list 'a18' are moved to array" << endl;
    cout << "Elements of array:" << endl;
    for (int i = 0; i < a18.get_length(); i++)
        cout << array2[i] << " ";
    cout << endl;
    cout << "----------------------------" << endl;
}

void test_iterators(){
    cout << "----------------------------------------------------------------------" << endl;
    cout << "12) Test for iterators method" << endl;
    container_list<int> a18{1,2,3,4,5,6,7,8,9,10};
    cout << "1. List 'a18' is initialized with (1,2,3,4,5,6,7,8,9,10) " << endl;
    Iterator<int> iterator(a18);
    cout << "\nCurrent value of iterator is - " << iterator.value() << endl;
    cout << "\nNext value of iterator after next() is - " << iterator.next().value() << endl;
    cout << " \nIterator End? - " << iterator.is_end() << endl;
    auto a19 = a18.begin();
    ++a19;
    cout << "\nList 'a19' is made and iterator is moved to second element" << endl;
    if (iterator == a19){
        cout << "\nThe position of iterator and element is similar" << endl;
        cout << *iterator << " == " << a19.value() << endl;}
    else{
        cout << "\nThe position of iterator and element is different" << endl;
        cout << *iterator << " != " << *a19 << endl;}
    auto a20 = a18.end();
    if (a19 != a20){
        cout << "\nThe end of list 'a18' is not similar as position of iterator" << endl;
        cout << *a19 << " != " << a20.value() << endl;}
    else{
        cout << "\nThe end of list 'a18' is similar as position of iterator" << endl;
        cout << *a19 << " == " << *a20 << endl;}
    cout << "----------------------------------------------------------------------" << endl;
}

template<typename T>
bool container_list<T>::comp(T &r1, T &r2){
    return r1 < r2;
}
