cmake_minimum_required(VERSION 4.3)
project(Übungsbuch)

set(CMAKE_CXX_STANDARD 20)

set(PROJECT_HEADERS
        summe.h
        myMakros.h
)
set(PROJECT_SOURCES
        main.cpp
        summe.cpp
)

add_executable(Uebungsbuch ${PROJECT_SOURCES} ${PROJECT_HEADERS})
