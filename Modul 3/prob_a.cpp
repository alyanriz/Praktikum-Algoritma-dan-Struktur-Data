#include "single_linked_list.h"
#include <iostream>
using namespace std;

int main()
{
    int N;
    long long K;
    cin >> N >> K;

    long long initial_K = K;

    SingleLinkedList list;
    list.init();

    for (int i = 0; i < N; i++)
    {
        int val;
        cin >> val;
        list.add_back(val);
    }

    int current_idx = 0;

    while (list.size > 1)
    {
        int target_idx = (current_idx + (K - 1)) % list.size;

        int stone_val = list.get(target_idx);

        list.delete_idx(target_idx);

        current_idx = target_idx % list.size;

        if (stone_val % 2 == 0)
        {
            K++;
        }
        else
        {
            K--;
        }

        if (K <= 0)
        {
            K = initial_K;
        }
    }

    cout << list.get(0) << "\n";

    list.clear();

    return 0;
}