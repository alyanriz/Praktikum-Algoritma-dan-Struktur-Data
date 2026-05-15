#include "single_linked_list.h"
#include <iostream>
using namespace std;

// use this file to test your implementation of single linked list

int main()
{
    SingleLinkedList list;
    list.init();

    cout << "Tes nambah data:" << endl;
    list.add_front(10);
    list.add_back(20);
    list.add_back(30);
    list.display();

    cout << "Tes hapus data:" << endl;
    list.delete_front();
    list.display();

    return 0;
}