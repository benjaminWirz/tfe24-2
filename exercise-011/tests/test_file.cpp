#include <fmt/chrono.h>
#include <fmt/format.h>

#include <nlohmann/json.hpp>
#include <string>
#include <fstream>
#include <filesystem>

#include <catch2/catch_test_macros.hpp>

#include "CLI/CLI.hpp"
#include "config.h"

using json = nlohmann::json;
namespace fs = std::filesystem;

TEST_CASE("Check JSON file")
{
    // Notwendige Vorbereitungen zum Einlesen der JSON-Datei
    const auto path = fs::path{config::json_tests};
    std::ifstream in(path);
    REQUIRE(in.is_open());

    std::string text(std::istreambuf_iterator<char>{in}, std::istreambuf_iterator<char>{});

    json doc = json::parse(text);
    REQUIRE(doc.contains("cases")); 

    // Erstelle einen dynamischen Testfall für jede Testcase in der JSON-Datei
    for (const auto& tc : doc["cases"]) {
        DYNAMIC_SECTION(tc.value("name", "<unnamed>"))
        {
            std::vector<int> v;
            
            for (const auto& val : tc["initial_values"]) {
                v.push_back(val.get<int>());
            }
            
            CHECK(v.size() == tc["expect"]["final_size"].get<size_t>());

            // Check Push back values
            for (size_t i = 0; i < tc["expect"]["final_size"].get<size_t>(); i++) {
                CHECK(v[i] == tc["initial_values"][i].get<int>());
            }

            // Check Resize
            v.resize(tc["resize_to"].get<size_t>());
            CHECK(v.size() == tc["resize_to"].get<size_t>());

        }
    }
}
