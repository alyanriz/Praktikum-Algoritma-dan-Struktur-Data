#include "double_linked_list.h"
#include <iostream>
using namespace std;

// use this file to test your implementation of double linked list

int main()
{
    DoubleLinkedList list;
    list.init();

    cout << "Tes tambah data:" << endl;
    list.add_back('A');
    list.add_back('B');
    list.add_front('X');
    list.add_idx('Y', 2);

    cout << "Isi list sekarang: ";
    list.display();

    cout << "\nTes hapus data:" << endl;
    list.delete_front();
    list.delete_back();

    cout << "Setelah hapus depan & belakang: ";
    list.display();

    cout << "\nTes clear:" << endl;
    list.clear();
    cout << "Setelah di-clear: ";
    list.display();

    return 0;
}