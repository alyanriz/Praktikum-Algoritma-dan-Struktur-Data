#include <iostream>
#include "line.h"
#include "point.h"
using namespace std;

int main() {
    Line l;
    Point p;

    cin >> l.a >> l.b >> l.c >> p.x >> p.y;
    double hasil = gradient(&l, &p);
    cout << CheckPointPosition(hasil) << endl;
    
    return 0;
}