#include <fmt/chrono.h>
#include <fmt/format.h>
#include <random>

#include "CLI/CLI.hpp"
#include "config.h"

auto main(int argc, char** argv) -> int
{
    auto counter = 5;
    /**
     * CLI11 is a command line parser to add command line options
     * More info at https://github.com/CLIUtils/CLI11#usage
     */
    CLI::App app{PROJECT_NAME};
    try
    {
        app.set_version_flag("-V,--version", fmt::format("{} {}", PROJECT_VER, PROJECT_BUILD_DATE));
        app.add_option("-c,--count", counter, "Counter Option")->default_val("20");
        app.parse(argc, argv);
    }
    catch (const CLI::ParseError& e)
    {
        return app.exit(e);
    }

    /**
     * The {fmt} lib is a cross platform library for printing and formatting text
     * it is much more convenient than std::cout and printf
     * More info at https://fmt.dev/latest/api.html
     */
    /* INSERT YOUR CODE HERE */

    //fmt::print("Count: {}\n", counter);

    fmt::println("");

    // Generate random numbers
    std::random_device r;
    std::default_random_engine e1(r());
    std::uniform_int_distribution<int> uniform_dist(1, 100);

    // Store random numbers in a vector
    std::vector<int> random_vec;
    auto start = std::chrono::system_clock::now();
    for (int i = 1; i <= counter; ++i) {
        random_vec.push_back(uniform_dist(e1));
    }
    auto end = std::chrono::system_clock::now();
    auto elapsed = end - start;

    fmt::println("Random Vector: [{}]", fmt::join(random_vec, ", "));
    fmt::println("Time taken to generate: {}", elapsed);

    fmt::println("");

    //sort and print the numbers
    std::vector<int> sorted_vec = random_vec;
    auto sort_start = std::chrono::system_clock::now();

    std::sort(sorted_vec.begin(), sorted_vec.end());
    auto sort_end = std::chrono::system_clock::now();
    auto sort_elapsed = sort_end - sort_start;

    fmt::println("Sorted Vector: [{}]", fmt::join(sorted_vec, ", "));
    fmt::println("Time taken to sort: {}", sort_elapsed);




    return 0; /* exit gracefully*/
}
