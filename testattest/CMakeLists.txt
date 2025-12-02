cmake_minimum_required (VERSION 3.10.2)

# Set the project name to your project name, template isn't very descriptive
project (testattest VERSION 0.0.1 LANGUAGES CXX)
string(TIMESTAMP BUILD_DATE "%Y-%m-%dT%H:%M:%S")

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include dependencies
find_package(fmt REQUIRED)
find_package(nlohmann_json REQUIRED)
find_package(CLI11 CONFIG REQUIRED)
find_package(Catch2 3 REQUIRED)
find_package(CURL REQUIRED)

configure_file("${CMAKE_CURRENT_SOURCE_DIR}/config.h.in" "${CMAKE_CURRENT_BINARY_DIR}/project_config.h" @ONLY)

# (Removed invalid call) target_include_directories requires a target and visibility (e.g. target_include_directories(<target> PUBLIC|PRIVATE|INTERFACE <dirs>))
# add the executable
add_executable(${PROJECT_NAME} main.cpp functions/get_geolog.cpp)

# Ensure the binary dir (with generated headers) is included
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_BINARY_DIR})

include_directories("${CMAKE_CURRENT_BINARY_DIR}/functions") # add the output path to the include PATH


# Add libraries
target_link_libraries(${PROJECT_NAME} PRIVATE
                                        fmt::fmt
                                        CLI11::CLI11
                                        nlohmann_json::nlohmann_json
                                        CURL::libcurl)