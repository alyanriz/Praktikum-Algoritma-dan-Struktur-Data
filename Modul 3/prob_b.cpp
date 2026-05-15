#include <iostream>
#include "double_linked_list.h"
using namespace std;

int main()
{
    int N, R;
    cin >> N >> R;

    DoubleLinkedList list;
    list.init();

    for (int i = 0; i < N; i++)
    {
        char c;
        cin >> c;
        list.add_back(c);
    }

    if (list.size == 0)
    {
        cout << "EMPTY" << endl;
        return 0;
    }

    Node *alpha = list.head;
    Node *beta = list.tail;

    for (int i = 0; i < R; i++)
    {
        long long X, Y;
        cin >> X >> Y;

        if (list.size <= 0)
            break;

        if (list.size == 1)
        {
            list.clear();
            break;
        }

        int alpha_jump = X % list.size;
        int beta_jump = Y % list.size;

        for (int j = 0; j < alpha_jump; j++)
        {
            alpha = alpha->next;
        }

        for (int j = 0; j < beta_jump; j++)
        {
            beta = beta->prev;
        }

        if (alpha == beta)
        {
            Node *toDelete = alpha;

            alpha = toDelete->next;
            beta = toDelete->prev;

            int index = 0;
            Node *curr = list.head;
            while (curr != toDelete)
            {
                curr = curr->next;
                index++;
            }

            list.delete_idx(index);
        }
        else if (alpha->next == beta || alpha->prev == beta)
        {
            char temp = alpha->data;
            alpha->data = beta->data;
            beta->data = temp;
        }
    }

    list.display();

    list.clear();
    return 0;
}