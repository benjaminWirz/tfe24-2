#include <fmt/chrono.h>
#include <fmt/format.h>

#include "config.h"

/* Part 2: Functions with References */

void changeValueByParameter(int value)
{
    value = 99;
    fmt::print("new Value: {}\n", value);
};

void changeValueByReference(int& ref)
{
    ref = 77;
    fmt::print("new Value: {}\n", ref);
};

auto main(int argc, char **argv) -> int
{
    /* Part 1: Reference Basics */

    int x = 10;
    int& r = x;
    fmt::print("Value of x->r: {}\n", r);
    r = 42;
    fmt::print("Value of x->r after change: {}\n", r);
    fmt::print("\n");

    /* Part 3: Comparison */

    int y = 5;
    fmt::print("Value of y before function: {}\n", y);
    changeValueByParameter(y);
    fmt::print("Value of y after changeValueByParameter: {}\n", y);
    changeValueByReference(y);
    fmt::print("Value of y after changeValueByReference: {}\n", y);

    return 0; /* exit gracefully*/
}
