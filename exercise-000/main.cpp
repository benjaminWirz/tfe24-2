#include <fmt/chrono.h>
#include <fmt/format.h>

#include "config.h"

auto main(int argc, char **argv) -> int //argc -> argument count, argv -> argument vector
{
 
    /**
     * The {fmt} lib is a cross platform library for printing and formatting text
     * it is much more convenient than std::cout and printf
     * More info at https://fmt.dev/latest/api.html
     */
    fmt::print("Hello World, {}!\n", tfe24::PROJECT_NAME);

    /* INSERT YOUR CODE HERE */

    int x = 10;
    int *p = &x; // & als Adressoperator -> Adresse of x
    fmt::print("Address of x: {}\nValue of x: {}\n", fmt::ptr(&x), x);
    //fmt::print("Value of x: {}\n", x);

    return 0; /* exit gracefully*/
}
