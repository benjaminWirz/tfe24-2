#include "get_geolog.hpp"

#include <curl/curl.h>
#include <fmt/chrono.h>
#include <fmt/format.h>
#include <fstream>
#include <iostream>
#include <filesystem>

#include <nlohmann/json.hpp>

#include "CLI/CLI.hpp"
#include "project_config.h"

// Callback for CURL
    static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
    {
        ((std::string *)userp)->append((char *)contents, size * nmemb);
        return size * nmemb;
    }

void get_geolog(std::string location)
{
    // create URL with location parameter
    std::string url = "https://photon.komoot.io/api/?q=" + location + "&limit=1";

    // CURL stuff
    CURL *curl;
    CURLcode res;

    // Perform an HTTP request

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if (curl)
    {
        std::string readBuffer;
        
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

        /* cache the CA cert bundle in memory for a week */
        curl_easy_setopt(curl, CURLOPT_CA_CACHE_TIMEOUT, 604800L);

        /* Perform the request, res will get the return code */
        res = curl_easy_perform(curl);
        /* Check for errors */
        if (res != CURLE_OK)
        {
            fmt::println("curl_easy_perform() failed: {}", curl_easy_strerror(res));
        }
        else
        {
            //fmt::println("{}", readBuffer);
        }
        
        std::filesystem::path dir_path(config::data_dir);
        if (!std::filesystem::exists(dir_path)) {
            std::filesystem::create_directories(dir_path);
        }
        std::filesystem::path file_path = dir_path / "geolog.json";
        std::ofstream outfile(file_path);

        if (outfile.is_open()) {
        outfile << readBuffer << std::endl; // Daten schreiben
        outfile.close();
            std::cout << "Daten in 'geolog.json' geschrieben." << std::endl;
        } else {
            std::cerr << "Fehler beim Öffnen der Datei zum Schreiben!" << std::endl;
        }

        /* always cleanup */
        curl_easy_cleanup(curl);
    }
}

auto get_coordinates(); -> std::pair<double, double>;
{
    std::ifstream in(path);
        if (!in.is_open())
        {
            fmt::print("Fehler: konnte JSON-Datei nicht öffnen: {}\n", path.string());
            return 1;
     }

}




