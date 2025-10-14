#include <fmt/chrono.h>
#include <fmt/format.h>

#include "CLI/CLI.hpp"
#include "config.h"

int globalVar = 1;
void foo() { fmt::print("Hello from foo!\\n"); }


auto main(int argc, char **argv) -> int
{
    /**
     * CLI11 is a command line parser to add command line options
     * More info at https://github.com/CLIUtils/CLI11#usage
     */
    CLI::App app{PROJECT_NAME};
    try
    {
        app.set_version_flag("-V,--version", fmt::format("{} {}", PROJECT_VER, PROJECT_BUILD_DATE));
        app.parse(argc, argv);
    }
    catch (const CLI::ParseError &e)
    {
        return app.exit(e);
    }

    /**
     * The {fmt} lib is a cross platform library for printing and formatting text
     * it is much more convenient than std::cout and printf
     * More info at https://fmt.dev/latest/api.html
     */

    // Part 1 : Global Variable
    fmt::print("Address of globalVar: {}\nValue of globalVar: {}\n", fmt::ptr(&globalVar), globalVar);

    // Part 2: Local Variable
    int localVar = 2;
    fmt::print("Address of localVar: {}\nValue of localVar: {}\n", fmt::ptr(&localVar), localVar);
   
    // Part 3: dynamic allocated Variable   
    int* heapVar = new int(3);
    fmt::print("Address of heapVar: {}\nValue of heapVar: {}\n", fmt::ptr(&heapVar), *heapVar);
    delete heapVar;

    // Part 4: Function
    fmt::print("Adresse von foo: {}\n", fmt::ptr(&foo));

    // Fazit
    /* */


    return 0; /* exit gracefully*/
}
