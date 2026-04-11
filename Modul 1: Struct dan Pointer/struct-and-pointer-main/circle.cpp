#include "circle.h"
#include <cmath>
using namespace std;

double distance(const Circle * c, const Point * p) {
    return sqrt(pow(p->x - c->centre.x, 2) + pow(p->y - c->centre.y, 2));
}

string CheckPointInCircle(double distance) {
    if (abs(distance) < EPSILON) {
        return "On Circle";
    } else if (distance < 0) {
        return "Inside";
    } else {
        return "Outside";
    }
}