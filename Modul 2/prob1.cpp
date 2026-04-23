#include "stack.h"
#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

int main() {
    int n;
    cin >> n;

    Stack s;
    init(&s);

    for (int i = 0; i < n; i++) {
        string token;
        cin >> token;

        if (token == "+" || token == "-" || token == "*" || token == "/") {
            int angka2 = peek(&s); 
            pop(&s);
            int angka1 = peek(&s); 
            pop(&s);

            int hasil = 0;

            if (token == "+") {
                hasil = angka1 + angka2;
            } else if (token == "-") {
                hasil = angka1 - angka2;
            } else if (token == "*") {
                hasil = angka1 * angka2;
            } else if (token == "/") {
                hasil = angka1 / angka2;
            }
            push(&s, hasil);
        } else {
            int angka = stoi(token);
            push(&s, angka);
        }
    }

    cout << peek(&s) << endl;

    return 0;
}