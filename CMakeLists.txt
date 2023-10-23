cmake_minimum_required(VERSION 3.25.2)
project(FProjectP3)
include(FetchContent)
set(BUILD_SHARED_LIBS OFF)
FETCHCONTENT_DECLARE(SFML GIT_REPOSITORY https://github.com/SFML/SFML.git GIT_TAG 2.5.1)
FETCHCONTENT_MAKEAVAILABLE(SFML)

set(CMAKE_CXX_STANDARD 14)

add_executable(FProjectP3
        src/main.cpp
        src/mainMenu.cpp
        lib/CantArtDif.h
        src/CantArtDif.cpp
        lib/CantArt.h
        src/CantArt.cpp
        lib/MinStock.h
        src/MinStock.cpp
        lib/Producto.h
        src/Gestor.cpp
        src/min_stock_depositos-NoTENERmuchoEnCuenta.cpp
        lib/min_stock_depositos-NoTENERmuchoEnCuenta.h
        src/Gestor.cpp)
target_link_libraries(FProjectP3 sfml-graphics sfml-audio sfml-window sfml-system)