#include "single_linked_list.h"
#include <iostream>
using namespace std;

void SingleLinkedList::init() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}

bool SingleLinkedList::is_empty() {
    if (size == 0) {
        return true;
    } else {
        return false;
    }
}

void SingleLinkedList::add_front(int val) {
    Node *newNode = new Node;
    newNode->data = val;
    newNode->next = nullptr;

    if (is_empty()) {
        head = newNode;
        tail = newNode;
        tail->next = head;
    } else {
        newNode->next = head;
        head = newNode;
        tail->next = head;
    }
    size++;
}

void SingleLinkedList::add_back(int val) {
    Node *newNode = new Node;
    newNode->data = val;
    newNode->next = nullptr;

    if (is_empty()) {
        head = newNode;
        tail = newNode;
        tail->next = head;
    } else {
        tail->next = newNode;
        tail = newNode;
        tail->next = head;
    }
    size++;
}

void SingleLinkedList::add_idx(int val, int idx) {
    if (idx <= 0) {
        add_front(val);
    } else if (idx >= size) {
        add_back(val);
    } else {
        Node *newNode = new Node;
        newNode->data = val;

        Node *curr = head;
        for (int i = 0; i < idx - 1; i++) {
            curr = curr->next;
        }

        newNode->next = curr->next;
        curr->next = newNode;
        size++;
    }
}

void SingleLinkedList::delete_front() {
    if (is_empty()) {
        cout << "List kosong." << endl;
        return;
    }

    Node *toDelete = head;

    if (size == 1) {
        head = nullptr;
        tail = nullptr;
    } else {
        head = head->next;
        tail->next = head;
    }

    delete toDelete; 
    size--;
}

void SingleLinkedList::delete_back() {
    if (is_empty()) {
        cout << "List kosong." << endl;
        return;
    }

    if (size == 1) {
        delete_front();
    } else {
        Node *toDelete = tail;

        Node *curr = head;
        while (curr->next != tail) {
            curr = curr->next;
        }

        tail = curr;
        tail->next = head; 

        delete toDelete; 
        size--;
    }
}

void SingleLinkedList::delete_idx(int idx) {
    if (is_empty()) return;

    if (idx <= 0) {
        delete_front();
    } else if (idx >= size - 1) {
        delete_back();
    } else {
        Node *curr = head;
        for (int i = 0; i < idx - 1; i++) {
            curr = curr->next;
        }

        Node *toDelete = curr->next;
        curr->next = toDelete->next; 

        delete toDelete; 
        size--;
    }
}

void SingleLinkedList::display() {
    if (is_empty()) {
        cout << "List kosong." << endl;
        return;
    }

    Node *curr = head;
    do {
        cout << curr->data << " ";
        curr = curr->next;
    } while (curr != head); 
    cout << endl;
}

int SingleLinkedList::get(int idx) {
    if (is_empty() || idx < 0 || idx >= size) {
        return -1; 
    }

    Node *curr = head;
    for (int i = 0; i < idx; i++) {
        curr = curr->next;
    }
    return curr->data;
}

void SingleLinkedList::set(int val, int idx) {
    if (is_empty() || idx < 0 || idx >= size) {
        return;
    }

    Node *curr = head;
    for (int i = 0; i < idx; i++) {
        curr = curr->next;
    }
    curr->data = val;
}

void SingleLinkedList::clear() {
    while (!is_empty()) {
        delete_front();
    }
}