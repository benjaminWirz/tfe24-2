// For HTML requests
#include <curl/curl.h>
#include <fmt/chrono.h>
#include <fmt/format.h>
#include <fstream>
#include <iostream>
#include <filesystem>

#include <nlohmann/json.hpp>

#include "CLI/CLI.hpp"
#include "project_config.h"
#include "functions/get_geolog.hpp"

// for convenience
using json = nlohmann::json;



auto main(int argc, char **argv) -> int
{
    
    get_geolog("Berlin");




    

    curl_global_cleanup();

    return 0; /* exit gracefully*/
}