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

    fmt::print("Count: {}\n", counter);

    // Generate random numbers
    std::random_device r;
    std::default_random_engine e1(r());
    std::uniform_int_distribution<int> uniform_dist(1, 100);

    // Store random numbers in a vector
    fmt::println("-------------------------");
    fmt::println("random numbers:");

    std::vector<int> random_vec;
    for (int i = 1; i <= counter; ++i) {
        random_vec.push_back(uniform_dist(e1));
        fmt::print("{}\n", random_vec.back());
    }

    //sort and print the numbers
    fmt::println("-------------------------");
    fmt::println("sorted numbers:");

    std::vector<int> sorted_vec = random_vec;
    std::sort(sorted_vec.begin(), sorted_vec.end());

    for (const auto& num : sorted_vec) {
        fmt::print("{}\n", num);
    }

    fmt::println("-------------------------");

    

    return 0; /* exit gracefully*/
}
