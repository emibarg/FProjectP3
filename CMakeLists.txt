cmake_minimum_required(VERSION 3.26)
project(FProjectP3)
include(FetchContent)
set(BUILD_SHARED_LIBS OFF)
FETCHCONTENT_DECLARE(SFML GIT_REPOSITORY https://github.com/SFML/SFML.git GIT_TAG 2.5.1)
FETCHCONTENT_MAKEAVAILABLE(SFML)

set(CMAKE_CXX_STANDARD 14)

add_executable(FProjectP3
        src/main.cpp
        src/mainMenu.cpp
        src/loop.cpp)
target_link_libraries(FProjectP3 sfml-graphics sfml-audio sfml-window sfml-system)