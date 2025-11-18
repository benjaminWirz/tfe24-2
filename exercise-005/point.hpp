#pragma once
#include <fmt/format.h>

class Point {

    public:
    int x_m;
    int y_m;

    Point();
    Point(int x, int y);
    ~Point() = default;

    void move(int dx, int dy);
    void print() const;

    double distance_to(const Point& other) const;

};