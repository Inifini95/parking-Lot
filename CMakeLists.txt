cmake_minimum_required(VERSION 3.10)
project(URLShortener VERSION 1.0.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set pkg-config path for Homebrew
set(ENV{PKG_CONFIG_PATH} "/opt/homebrew/lib/pkgconfig:/opt/homebrew/Cellar/libpq/18.1/lib/pkgconfig:/usr/local/lib/pkgconfig")

# Include pkg-config module
list(APPEND CMAKE_MODULE_PATH /usr/local/lib/cmake /opt/homebrew/lib/cmake)

# Include directories
include_directories(${CMAKE_SOURCE_DIR})
include_directories(/usr/local/include)
include_directories(/opt/homebrew/include)

# Link directories for Homebrew libraries
link_directories(/opt/homebrew/lib)
link_directories(/opt/homebrew/Cellar/libpqxx/7.10.5/lib)
link_directories(/opt/homebrew/Cellar/libpq/18.1/lib)

# Add source files
set(SOURCES
    src/main.cpp
)

# Create executable
add_executable(url_shortener ${SOURCES})

# Optional: Add compile options for better warnings
if(MSVC)
    target_compile_options(url_shortener PRIVATE /W4)
else()
    target_compile_options(url_shortener PRIVATE -Wall -Wextra -Wpedantic)
endif()

# Find and link pqxx using pkg-config (optional - only if using database)
# include(FindPkgConfig)
# pkg_check_modules(PQXX REQUIRED libpqxx)
# target_include_directories(url_shortener PRIVATE ${PQXX_INCLUDE_DIRS})
# target_link_libraries(url_shortener ${PQXX_LIBRARIES})

# Optional: Add testing support
enable_testing()

# Example test target (you can add actual tests later)
add_test(NAME BasicTest COMMAND url_shortener)