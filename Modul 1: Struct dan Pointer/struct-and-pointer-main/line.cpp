#include "line.h"
#include <cmath>
using namespace std;

double gradient(const Line * l, const Point * p) {
    return (l->a * p->x) + (l->b * p->y) + (l->c);
}

string CheckPointPosition(double gradient) {
    if (abs(gradient) < EPSILON) {
        return "On Line";
    } else if (gradient > 0) {
        return "Left";
    } else {
        return "Right";
    }
}