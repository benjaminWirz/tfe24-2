#include "point.hpp"

Point::Point(int x, int y) : x_m(x), y_m(y) {}
Point::~Point() = default;

void Point::move(int dx, int dy)
{
    x_m += dx;
    y_m += dy;
}

void Point::print() const
{
    fmt::print("Point({}, {})\n", x_m, y_m);
}

double Point::distance_to(const Point& other) const
{
    int dx = x_m - other.x_m;
    int dy = y_m - other.y_m;
    return std::sqrt(dx * dx + dy * dy);
}
