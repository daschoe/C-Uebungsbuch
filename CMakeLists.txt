cmake_minimum_required(VERSION 4.3)
project(Übungsbuch)

set(CMAKE_CXX_STANDARD 20)

set(PROJECT_HEADERS
        summe.h
        myMakros.h
        tool1.h
        tool2.h
        Datum.h
        Artikel.h
        Mitglied.h
        Ampel.h
        DayTime.h
        telList.h
)
set(PROJECT_SOURCES
        main.cpp
        summe.cpp
        Passw2.cpp
        Datum.cpp
        Artikel.cpp
        Mitglied.cpp
        telList.cpp
)

add_executable(Uebungsbuch ${PROJECT_SOURCES} ${PROJECT_HEADERS})
