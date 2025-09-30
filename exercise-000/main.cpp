#include <fmt/chrono.h>
#include <fmt/format.h>

#include "config.h"

    void changeValueByParameter(int value)
    {
        value = 99;
        fmt::print("new Value: {}\n", value);
    };

    void changeValueByPointer(int* ptr)
    {
        *ptr = 77;
        fmt::print("new Value: {}\n", *ptr);
    };

auto main(int argc, char **argv) -> int //argc -> argument count, argv -> argument vector
{
 
    /**
     * The {fmt} lib is a cross platform library for printing and formatting text
     * it is much more convenient than std::cout and printf
     * More info at https://fmt.dev/latest/api.html
     */
    fmt::print("Hello World, {}!\n", tfe24::PROJECT_NAME);

    /* Part 1: Pointer-Basics */

    int x = 10;
    int *p = &x; // & als Adressoperator -> Adresse of x
    fmt::print("Address of x: {}\nValue of x: {}\n", fmt::ptr(&x), x);
    fmt::print("Address of p: {}\nValue of p: {}\n\n", fmt::ptr(p), *p);
    *p = 42;
    fmt::print("Address of x: {}\nValue of x: {}\n", fmt::ptr(&x), x);
    fmt::print("Address of p: {}\nValue of p: {}\n", fmt::ptr(p), *p);
    fmt::print("\n");

    /* Part 2: Dynamic Memory */

    double *pi = new double(3.1415);
    fmt::print("Address of pi: {}\nValue of pi: {}\n", fmt::ptr(pi), *pi);
    delete pi; // free memory
    fmt::print("\n");

    /* Part 3: Functions with Pointers */

    int y = 5;
    fmt::print("Value of y before function: {}\n", y);
    changeValueByParameter(y);
    fmt::print("Value of y after changeValueByParameter: {}\n", y);
    changeValueByPointer(&y);
    fmt::print("Value of y after changeValueByPointer: {}\n", y);

    return 0; /* exit gracefully*/
}
