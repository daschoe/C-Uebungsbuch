//
// Created by daschoe on 10/2/26.
//

#include "Datum.h"

#include <iostream>
#include <ctime>

void Datum::print() {
    std::cout<<tag<<"."<<monat<<"."<<jahr<<std::endl;
}

void Datum::init(int tag, int monat, int jahr) {
    Datum::tag = tag;
    Datum::monat = monat;
    Datum::jahr = jahr;
}

void Datum::init() {
    struct tm *zeit; // Zeiger auf Struktur tm.
    time_t sec; // Für die Sekunden.
    time(&sec); // Aktuelle Zeit holen.
    zeit = localtime(&sec); // Eine Struktur vom Typ tm
    // initialisieren und Zeiger
    // darauf zurückgeben.
    tag = zeit->tm_mday + 1;
    monat = zeit->tm_mon + 1;
    jahr = zeit->tm_year + 1900;
}
