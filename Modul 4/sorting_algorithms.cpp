#include "sorting_algorithms.h"
#include <algorithm>
#include <chrono>

using Clock = std::chrono::high_resolution_clock;

void bubble_sort(std::vector<int>& data, Metrics& m) {
    int n = data.size();
    auto start = Clock::now();

    for (int i = 0; i < n - 1; i++) {
        bool flag = false;

        for (int j = 0; j < n - i - 1; j++) {
            m.comparisons++;
            if (data[j] > data[j + 1]) {
                std::swap(data[j], data[j + 1]);
                m.swaps++;
                flag = true;
            }
        }

        if (!flag) break;
    }

    m.time_ms = std::chrono::duration<double, std::milli>(Clock::now() - start).count();
}



void selection_sort(std::vector<int>& data, Metrics& m) {
    int n = data.size();
    auto start = Clock::now();

    for (int i = 0; i < n - 1; ++i) {
        int min_idx = i;

        for (int j = i + 1; j < n; ++j) {
            m.comparisons++;
            if (data[j] < data[min_idx]) {
                min_idx = j;
            }
        }
    std::swap(data[i], data[min_idx]);
    m.swaps++;
    }

    m.time_ms = std::chrono::duration<double, std::milli>(Clock::now() - start).count();
}



void insertion_sort(std::vector<int>& data, Metrics& m) {
    int n = data.size();
    auto start = Clock::now();

    for (int i = 1; i < n; ++i) {
        int key = data[i];
        int j = i - 1;

        while (j >= 0) {
            m.comparisons++;

            if (data[j] > key) {
                data[j + 1] = data[j];
                m.shifts++;
                j = j - 1;
            } else {
                break;
            }
        }
        data[j + 1] = key;
    }

    m.time_ms = std::chrono::duration<double, std::milli>(Clock::now() - start).count();
}



void merge(std::vector<int>& data, int left, int mid, int right, Metrics& m) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> leftVec(n1), rightVec(n2);

    for (i = 0; i < n1; i++) leftVec[i] = data[left + i];
    for (j = 0; j < n2; j++) rightVec[j] = data[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        m.comparisons++;
        if (leftVec[i] <= rightVec[j]) {
            data[k] = leftVec[i];
            i++;
        } else {
            data[k] = rightVec[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        data[k] = leftVec[i];
        i++;
        k++;
    }

    while (j < n2) {
        data[k] = rightVec[j];
        j++;
        k++;
    }
}

void merge_sort_help(std::vector<int>& data, int left, int right, Metrics& m) {
    m.recursive_calls++;

    if (left < right) {
        int mid = left + (right - left) / 2;

        merge_sort_help(data, left, mid, m);
        merge_sort_help(data, mid + 1, right, m);

        merge(data, left, mid, right, m);
    }
}

void merge_sort(std::vector<int>& data, Metrics& m) {
    auto start = Clock::now();

    int n = data.size();
    if (n > 0) {
        merge_sort_help(data, 0, n - 1, m);
    }

    m.time_ms = std::chrono::duration<double, std::milli>(Clock::now() - start).count();
}



int partition(std::vector<int>& data, int low, int high, Metrics& m) {
    int pivot = data[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        m.comparisons++;
        if (data[j] <= pivot) {
            i++;
            if (i != j) {
                std::swap(data[i], data[j]);
                m.swaps++;
            }
        }
    }
    if (i + 1 != high) {
        std::swap(data[i + 1], data[high]);
        m.swaps++;
    }

    return (i + 1);
}

void quick_sort_help(std::vector<int>& data, int low, int high, Metrics& m) {
    m.recursive_calls++;
    if (low < high) {
        int pi = partition(data, low, high, m);

        quick_sort_help(data, low, pi - 1, m);
        quick_sort_help(data, pi + 1, high, m);
    }
}

void quick_sort(std::vector<int>& data, Metrics& m) {
    auto start = Clock::now();

    int n = data.size();
    if (n > 0) {
        quick_sort_help(data, 0, n - 1, m);
    }

    m.time_ms = std::chrono::duration<double, std::milli>(Clock::now() - start).count();
}



void count_sort(std::vector<int>& data, int n, int pos, Metrics& m) {
    int count[10] = { 0 };

    for (int i = 0; i < n; i++) {
        m.array_accesses++;
        count[(data[i] / pos) % 10]++;
    }

    for (int i = 1; i < 10; i++) {
        m.array_accesses++;
        count[i] = count[i] + count[i - 1];
    }

    std::vector<int> ans(n);
    for (int i = n - 1; i >= 0; i--) {
        m.array_accesses += 2;
        ans[--count[(data[i] / pos) % 10]] = data[i];
    }

    for (int i = 0; i < n; i++) {
        m.array_accesses++;
        data[i] = ans[i];
    }
}

void radix_sort(std::vector<int>& data, Metrics& m) {
    if (data.empty()) return;
    auto start = Clock::now();

    int n = data.size();
    int k = *std::max_element(data.begin(), data.end());

    for (int pos = 1; (k / pos) > 0; pos*= 10) {
        count_sort(data, n, pos, m);
    }

    m.time_ms = std::chrono::duration<double, std::milli>(Clock::now() - start).count();
}