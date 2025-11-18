#include <fmt/chrono.h>
#include <fmt/format.h>

#include "CLI/CLI.hpp"
#include "config.h"
#include "myvector.hpp"

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
    fmt::print("Hello, {}!\n", app.get_name());


    // {
    //     MyVector vec;
    // }

    // MyVector vec2(27);
    // fmt::println("Hello exercise number 3 after Vector");

    /*
    
    myvector<int> vec3(3);

    vec3.status();

    vec3.push_back(20);
    vec3.push_back(34);
    vec3.push_back(50);
    vec3.push_back(22);
    vec3.push_back(13);
    vec3.push_back(53); // this should print an error message

    vec3.status();

    fmt::println("Element at index 0: {}", vec3.at(0));
    fmt::println("Element at index 1: {}", vec3.at(1));
    fmt::println("Element at index 2: {}", vec3.at(2));
    fmt::println("Element at index 3: {}", vec3.at(3));
    fmt::println("Element at index 4: {}", vec3.at(4));
    fmt::println("Element at index 5: {}", vec3.at(5));

    vec3.status();

    */

    tfe24::myvector<int> vec3(4);
    vec3.status();

    vec3.push_back(12);
    vec3.push_back(13);
    vec3.push_back(14);
    vec3.push_back(15);

    vec3.status();

    vec3.resize(5);

    vec3.status();

    tfe24::myvector<int> vec4(vec3);

    vec3.print_all(); 
    vec4.print_all();  
    
    fmt::println("Element at index 2: {}", vec3.at(45));

    return 0; /* exit gracefully*/
}
