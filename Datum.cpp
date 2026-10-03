//
// Created by daschoe on 10/2/26.
//

#include "Datum.h"

#include <iostream>
#include <ctime>
#include <iomanip>

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
    tag = zeit->tm_mday;
    monat = zeit->tm_mon + 1;
    jahr = zeit->tm_year + 1900;
}


Datum::Datum() {
    tag=1;
    monat=1;
    jahr=1;
}

Datum::Datum(int tag, int monat, int jahr) {
    setDatum(tag, monat, jahr);
    //this->tag = tag;
    //this->monat = monat;
    //this->jahr = jahr;
}

void Datum::setDatum() {
    struct tm *zeit; // Zeiger auf Struktur tm.
    time_t sec; // Für die Sekunden.
    time(&sec); // Aktuelle Zeit holen.
    zeit = localtime(&sec); // Eine Struktur vom Typ tm
    // initialisieren und Zeiger
    // darauf zurückgeben.
    tag = zeit->tm_mday;
    monat = zeit->tm_mon + 1;
    jahr = zeit->tm_year + 1900;
}

void Datum::setDatum(int tg, int mn, int jr) {
    if (tag < 1 || monat < 1 || jahr < 1 || tag > 31 || monat > 12)
        tag=monat=jahr=1; //ungültige Eingabe
    else {
        switch (mn) {
            case 2: {
                // tag <= 28 oder tag <= 29, wenn Schaltjahr
                if ((tag > 28 && !isLeapYear(jr)) || (tag > 29 && isLeapYear(jr)))
                    tag=monat=jahr=1;
                else {
                    tag=tg;
                    monat=mn;
                    jahr=jr;
                }
                break;
            }
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                {
                    tag=tg;
                    monat=mn;
                    jahr=jr;
                    break;
                }
            case 4:
            case 6:
            case 9:
            case 11: {
                if (tag > 30)
                    tag=monat=jahr=1;
                else {
                    tag=tg;
                    monat=mn;
                    jahr=jr;
                }
                break;
            }
            default:
                tag=monat=jahr=1; //ungültige Eingabe
        }
    }

}

const std::string& Datum::asString() const {
    static std::string str; // Zielstring
    std::stringstream iostream; // Zur Konvertierung Zahl -> String.
    iostream << std::setfill('0')<< std::setw(2) << tag << '.'; // In den Stream schreiben.
    iostream << std::setw(2) << monat << '.';
    iostream << std::setw(4) << jahr;
    iostream >> str; // Aus dem Stream lesen.
    return str;
}

int Datum::getTag() const {
    return tag;
}

int Datum::getMonat() const {
    return monat;
}

int Datum::getJahr() const {
    return jahr;
}

bool Datum::isEqual(const Datum& other) const {
    if (tag==other.tag && monat==other.monat && jahr==other.jahr)
        return true;
    return false;
}

bool Datum::isLess(const Datum& other) const {
    if (jahr <= other.jahr) {
        if (monat <= other.monat) {
            if (tag <= other.tag && !isEqual(other))
                return true;
        }
    }
    return false;
}

void Datum::print() const {
    std::cout<<asString()<<std::endl;
}
