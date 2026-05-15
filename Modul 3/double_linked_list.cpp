#include "double_linked_list.h"
#include <iostream>
using namespace std;

void DoubleLinkedList::init()
{
    head = nullptr;
    tail = nullptr;
    size = 0;
}

bool DoubleLinkedList::is_empty()
{
    if (size == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void DoubleLinkedList::add_front(char val)
{
    Node *newNode = new Node;
    newNode->data = val;

    if (is_empty())
    {
        head = newNode;
        tail = newNode;
        head->next = head;
        head->prev = head;
    }
    else
    {
        newNode->next = head;
        newNode->prev = tail;

        head->prev = newNode;
        tail->next = newNode;

        head = newNode;
    }
    size++;
}

void DoubleLinkedList::add_back(char val)
{
    Node *newNode = new Node;
    newNode->data = val;

    if (is_empty())
    {
        head = newNode;
        tail = newNode;
        head->next = head;
        head->prev = head;
    }
    else
    {
        newNode->prev = tail;
        newNode->next = head;

        tail->next = newNode;
        head->prev = newNode;

        tail = newNode;
    }
    size++;
}

void DoubleLinkedList::add_idx(char val, int idx)
{
    if (idx <= 0)
    {
        add_front(val);
    }
    else if (idx >= size)
    {
        add_back(val);
    }
    else
    {
        Node *newNode = new Node;
        newNode->data = val;

        Node *curr = head;
        for (int i = 0; i < idx - 1; i++)
        {
            curr = curr->next;
        }

        newNode->next = curr->next;
        newNode->prev = curr;

        curr->next->prev = newNode;
        curr->next = newNode;

        size++;
    }
}

void DoubleLinkedList::delete_front()
{
    if (is_empty())
        return;

    Node *toDelete = head;

    if (size == 1)
    {
        head = nullptr;
        tail = nullptr;
    }
    else
    {
        head = head->next;
        head->prev = tail;
        tail->next = head;
    }

    delete toDelete;
    size--;
}

void DoubleLinkedList::delete_back()
{
    if (is_empty())
        return;

    if (size == 1)
    {
        delete_front();
    }
    else
    {
        Node *toDelete = tail;

        tail = tail->prev;
        tail->next = head;
        head->prev = tail;

        delete toDelete;
        size--;
    }
}

void DoubleLinkedList::delete_idx(int idx)
{
    if (is_empty() || idx < 0 || idx >= size)
        return;

    if (idx == 0)
    {
        delete_front();
    }
    else if (idx == size - 1)
    {
        delete_back();
    }
    else
    {
        Node *curr = head;
        for (int i = 0; i < idx; i++)
        {
            curr = curr->next;
        }

        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;

        delete curr;
        size--;
    }
}

void DoubleLinkedList::display()
{
    if (is_empty())
    {
        cout << "EMPTY" << endl;
        return;
    }

    Node *curr = head;
    do
    {
        cout << curr->data;
        curr = curr->next;
    } while (curr != head);
    cout << endl;
}

char DoubleLinkedList::get(int idx)
{
    if (is_empty() || idx < 0 || idx >= size)
    {
        return '\0';
    }

    Node *curr = head;
    for (int i = 0; i < idx; i++)
    {
        curr = curr->next;
    }
    return curr->data;
}

void DoubleLinkedList::set(char val, int idx)
{
    if (is_empty() || idx < 0 || idx >= size)
    {
        return;
    }

    Node *curr = head;
    for (int i = 0; i < idx; i++)
    {
        curr = curr->next;
    }
    curr->data = val;
}

void DoubleLinkedList::clear()
{
    while (!is_empty())
    {
        delete_front();
    }
}